#include "player.h"
#include <QGraphicsScene>//scene使用
#include "bullet.h"
#include"floor.h"
#include <QDateTime>
#include"weapon.h"
Player::Player(QObject *parent) : QObject(parent) {
      m_weapon = new weapon ;
    m_healthBar = new QGraphicsRectItem(-25, -30, 50, 5, this);
    m_healthBar->setBrush(Qt::green);
    m_healthBar->setZValue(1001);
    normalPixmap = QPixmap(":/images/ct1.png");
    setPixmap(normalPixmap);
    ctrlPixmap=QPixmap(":/images/ct8.png");
    setPixmap(ctrlPixmap);
    setTransformOriginPoint(boundingRect().center());
    // 加载6张运动帧（ct2-ct7）
    for(int i=2; i<=7; ++i)
    {
        QString path = QString(":/images/ct%1.png").arg(i);
        QPixmap frame(path);
        if(!frame.isNull()) {
            m_runFrames.append(frame);
        }
    }
    }//实现构造函数
QPointF Player:: getpos()
{
    return scenePos();
}
qreal Player:: playerfeety() const {
    return scenePos().y() + playerheight;
}
qreal Player:: gety()
{
    return y();
}
bool Player::checkFloorCollision() {
    isonthefloor = false;
    const qreal epsilon = 1.0;
    // 动态检测区域高度
    qreal detectHeight = qAbs(verticalSpeed) + 5.0;
    QRectF playerFeet = QRectF(
        scenePos().x(),
        playerfeety(),
        pixmap().width(),
        detectHeight
        );
    foreach (QGraphicsItem* item, scene()->items(playerFeet)) {
        if (Floor* floor = dynamic_cast<Floor*>(item)) {
            qreal floorTop = floor->getscenetopy();
            // 玩家脚部是否接触或穿透地板？
            if (playerfeety() >= floorTop - epsilon) {
                // 仅在下落时修正位置（允许跳跃初速阶段不中断）
                if (verticalSpeed >= 0) {
                    qreal playerHeight = pixmap().height();
                    QPointF newScenePos(scenePos().x(), floorTop - playerHeight);
                    setPos(newScenePos);
                    verticalSpeed = 0;
                    isonthefloor = true;
                }
                break;
            }
        }
    }
    return isonthefloor;
}
void Player::updateMovement() {
    if (keys[3]) {
        setPixmap(ctrlPixmap);
    }
    // 横向移动逻辑（保持不变）
    QVector2D v(0, 0);
    if (keys[0]) v.setX(-1);
    if (keys[1]) v.setX(1);
    if (!v.isNull()) v.normalize();
    // 跳跃触发（仅在地面时生效）
    if (isonthefloor && keys[2]) {
        verticalSpeed = Player:: orginv; // 跳跃初速度
        isonthefloor = false;       // 立即离地
    }
    // 应用重力（离地时生效）
    if (!isonthefloor) {
        verticalSpeed += gravity;
    }
    qreal newy = y() + verticalSpeed;
    setPos(x() + v.x() * speed, newy);
    checkFloorCollision();
    bool wasMoving = m_isMoving;
    m_isMoving = keys[0] || keys[1];
    if(m_isMoving != wasMoving) {
        m_currentFrame = 0; // 重置动画序列
        if(!m_isMoving) {
            setPixmap(normalPixmap); // 恢复静止状态
        }
    }
    // 处理朝向
    if(keys[0]) { // A键左移
        m_facingRight = false;
        setTransform(QTransform().scale(-1, 1));
    } else if(keys[1]) { // D键右移
        m_facingRight = true;
        setTransform(QTransform());
    }
}
void Player::updateAnimation()
{
    if(!m_isMoving || m_runFrames.isEmpty()) return;

    // 控制动画帧率（100ms/帧）[1](@ref)
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
    if(currentTime - m_lastAnimTime < 100) return;

    // 更新动画帧
    m_currentFrame = (m_currentFrame + 1) % 6; // 循环6帧
    setPixmap(m_runFrames[m_currentFrame]);
    m_lastAnimTime = currentTime;
}
void Player::shoot(QPointF target) {//射击函数
    QPointF localCenter = boundingRect().center(); //得到包含角色图形项的矩形的几何中心
    QPointF playercenterposition = mapToScene(localCenter); // 把上述中心转换为场景坐标，方便统一
    Bullet *bullet = new Bullet(playercenterposition, target,BulletOwner::Player, this);
    m_weapon->m_shootSound.play();
    bullet->setSpeed();
    scene()->addItem(bullet);
    bullet->setPos(playercenterposition);
}
Player::~Player() {
    delete m_weapon;
}
