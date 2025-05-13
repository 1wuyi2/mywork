
#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPointF>
#include <QTimer>
class Player;
class Enemy;
class Floor;

enum class BulletOwner { Player, Enemy };

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QPointF startPos, QPointF targetPos, BulletOwner owner, QObject *parent = nullptr);
    void setSpeed(float speed = 10.0f);

private slots:
    void move();

private:
    void checkCollisions();

    QPointF direction;
    float speed;
    QTimer* timer;
    BulletOwner owner;
};

#endif // BULLET_H
