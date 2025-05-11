#include "enemy.h"
#include <QGraphicsScene>
#include <QVector2D>
#include <QtMath>
enemy::enemy(Floor* fl, Player* pl, QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem(parent), currentFloor(fl), player(pl) {
    walkFrames << QPixmap(":/images/T1.png")
               << QPixmap(":/images/t2.png")
               << QPixmap(":/images/t3.png")
               << QPixmap(":/images/t4.png");
    setPixmap(walkFrames[0]);
    isTowardRight = QRandomGenerator::global()->bounded(2) == 0;
    speed = 1.0 + QRandomGenerator::global()->bounded(200) / 100.0f;
    setTransformOriginPoint(boundingRect().center());
    qreal Xen = fl->getx() + QRandomGenerator::global()->bounded(Floor::width - pixmap().width());
    qreal Yen = fl->gettopy() - pixmap().height();
    setPos(Xen, Yen);
    setTransform(QTransform::fromScale(isTowardRight ? 1 : -1, 1));
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &enemy::onMoveTimeout);
    moveTimer->start(50);
    attackTimer = new QTimer(this);
    attackTimer->setSingleShot(true);
    connect(attackTimer, &QTimer::timeout, this, &enemy::onAttackFinished);
}
void enemy::onMoveTimeout() {
    if (!isAttacking) {
        move();
    }
}
void enemy::move() {
    if (!currentFloor || !player) return;
    if (!isAttacking) {
        qreal deltaTime = 0.05;
        animAccumulator += deltaTime;
        if (animAccumulator >= 0.15f) {
            currentFrame = (currentFrame % 3) + 1;
            setPixmap(walkFrames[currentFrame]);
            animAccumulator = 0.0;
        }
    }
    QPointF enemyPos = scenePos();
    QPointF playerPos = player->scenePos();
    qreal distance = QLineF(enemyPos, playerPos).length();
    if (distance <= attackRange && !isAttacking)
    {
        isAttacking = true;
        moveTimer->stop();
        shootAtPlayer();
        attackTimer->start(1000); // 1秒后恢复移动
        return;
    }
    qreal floorLeft = currentFloor->getx();
    qreal floorRight = currentFloor->getx() + Floor::width;
    qreal enemyRight = enemyPos.x() + pixmap().width();
    if (isTowardRight) {
        if (enemyRight >= floorRight) {
            isTowardRight = false;
            setTransform(QTransform::fromScale(-1, 1));
        }
    } else {
        if (enemyPos.x() <= floorLeft) {
            isTowardRight = true;
            setTransform(QTransform::fromScale(1, 1));
        }
    }
    qreal dx = isTowardRight ? speed : -speed;
    setPos(x() + dx, y());
}

void enemy::shootAtPlayer() {
    isAttacking = true;
    currentFrame = 0; // 强制重置为静止帧
    setPixmap(walkFrames[0]);
    if (!scene() || !player) return;
    QPointF startPos = scenePos() + QPointF(pixmap().width()/2, pixmap().height()/2);
    QPointF targetPos = player->scenePos() + QPointF(player->pixmap().width()/2, player->pixmap().height()/2);
    Bullet* bullet = new Bullet(startPos, targetPos,BulletOwner::Enemy,this);
    bullet->setSpeed(10.0f);  // 设置子弹速度
    scene()->addItem(bullet);
}

void enemy::onAttackFinished() {
    isAttacking = false;
    moveTimer->start();  // 恢复移动
    bool playerOnRight = (player->scenePos().x() > scenePos().x());
    if (playerOnRight != isTowardRight) {
        isTowardRight = playerOnRight;
        setTransform(QTransform::fromScale(isTowardRight ? 1 : -1, 1));
    }
}
