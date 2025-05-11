#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>

Bullet::Bullet(QPointF startpos, QPointF targetpos, QObject *parent)
    : QObject(parent), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/images/bullet2.jpg"));  // 设置子弹贴图

    setPos(startpos);//把子弹位置设置到传入的startpos,即角色中心的位置
    setScale(0.05);
    QPointF dir = targetpos - startpos;
    qreal angle = qRadiansToDegrees(std::atan2(dir.y(), dir.x()));
    setRotation(angle);
    direction = targetpos - startpos;
    float length = sqrt(direction.x() * direction.x() + direction.y() * direction.y());
    if (length > 0) {
        direction /= length;
    } else {
        direction = QPointF(1, 0);
    } // 计算方向向量并单位化
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(60);    // 创建定时器（每 60ms 触发一次移动）

}

void Bullet::move() {
    setPos(pos() + direction * speed);
}    // 按方向更新位置

