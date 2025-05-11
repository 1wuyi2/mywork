#include "enemy.h"
#include <QGraphicsScene>
#include"bullet.h"

enemy::enemy(QObject *parent) : QObject(parent) {
    setPixmap(QPixmap()); // 加载角色图片
    setTransformOriginPoint(boundingRect().center());
}//实现构造函数
