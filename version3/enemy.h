#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QRandomGenerator>
#include "floor.h"
#include "player.h"
#include "bullet.h"
class enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
private:
    float speed;
    float attackRange = 400.0f;
    Floor* currentFloor;
    bool isAttacking = false;
    bool isTowardRight;
    Player* player;
    QTimer* moveTimer;
    QTimer* attackTimer;
    void shootAtPlayer();
    int health=3;
    QVector<QPixmap> walkFrames;
    int currentFrame = 0;
    qreal animAccumulator = 0.0;
public:
    explicit enemy(Floor* fl, Player* pl, QGraphicsItem* parent = nullptr);
    void move();
    void takeDamage(int damage) {
        health -= damage;
    }

    int getHealth() const {
        return health;
    }

private slots:
    void onMoveTimeout();
    void onAttackFinished();
};

#endif // ENEMY_H
