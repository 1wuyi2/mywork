#include "bullet.h"
#include "player.h"
#include "enemy.h"
#include "floor.h"
#include <QGraphicsScene>
#include"lose.h"
Bullet::Bullet(QPointF startPos, QPointF targetPos, BulletOwner owner, QObject *parent)
    : QObject(parent), speed(10.0f), owner(owner) {
    setPixmap(QPixmap(":/images/bullet2.jpg").scaled(20, 10));
    setTransformOriginPoint(boundingRect().center());
    setPos(startPos);

    // 计算方向向量
    QPointF dir = targetPos - startPos;
    qreal length = std::hypot(dir.x(), dir.y());
    if (length > 0) {
        direction = dir / length;
    } else {
        direction = QPointF(1, 0);
    }

    // 设置旋转角度
    qreal angle = qRadiansToDegrees(std::atan2(dir.y(), dir.x()));
    setRotation(angle);

    // 定时器设置
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(20);
}

void Bullet::setSpeed(float speed) {
    this->speed = speed;
}

void Bullet::move() {
    setPos(pos() + direction * speed);
    checkCollisions();
}

void Bullet::checkCollisions() {
    // 检测所有碰撞项
    QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);

    foreach (QGraphicsItem* item, collidingItems) {
        //处理与地板碰撞
        if (dynamic_cast<Floor*>(item)) {
            // QSound::play(":/sounds/zhuangqiang.wav");
            scene()->removeItem(this);
            deleteLater();
            return;
        }
        // 根据子弹所有者处理不同逻辑
        switch (owner) {
        case BulletOwner::Enemy:
            if (Player* player = dynamic_cast<Player*>(item)) {
                player->takeDamage(1);
                scene()->removeItem(this);
                deleteLater();
                return;
            }
            break;
        case BulletOwner::Player:
            if (enemy* en = dynamic_cast<enemy*>(item)) {
                // QSound::play(":/sounds/shoushang2.wav");
                en->takeDamage(1);
                if (en->getHealth() <= 0) {
                    // QSound::play(":/sounds/death.wav");
                    scene()->removeItem(en);
                    delete en;
                }
                scene()->removeItem(this);
                deleteLater();
                return;
            }
            break;
        }
    }
}
