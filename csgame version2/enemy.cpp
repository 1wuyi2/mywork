#include "enemy.h"
#include <QGraphicsScene>
#include"bullet.h"
void enemy::shoot()
{
    QPointF enemycenterpos = mapToScene(boundingRect().center());
    Bullet *bullet = new Bullet(enemycenterpos, target->getpos(), nullptr);
    scene()->addItem(bullet);
    bullet->setPos(enemycenterpos);
}

