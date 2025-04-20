#include "player.h"
#include <QGraphicsScene>//scene使用
#include "bullet.h"

Player::Player(QObject *parent) : QObject(parent) {
    setPixmap(QPixmap(":/images/ct.png")); // 加载角色图片
     setTransformOriginPoint(boundingRect().center());
}//实现构造函数


void Player::shoot(QPointF target) {//射击函数
    QPointF localCenter = boundingRect().center(); //得到包含角色图形项的矩形的几何中心
    QPointF playercenterposition = mapToScene(localCenter); // 把上述中心转换为场景坐标，方便统一
    // QPointF direction = target - playercenterposition;
    // float length = std::sqrt(direction.x() * direction.x() + direction.y() * direction.y());
    // if (length > 0) {
    //     direction /= length;
    // } else {
    //     direction = QPointF(1, 0);
    // }
    Bullet *bullet = new Bullet(playercenterposition, target, this);
    scene()->addItem(bullet);
    bullet->setPos(playercenterposition);
}
