#ifndef ENEMY_H
#define ENEMY_H
#include<QObject>//信号与槽机制，对象树内存管理
#include<QGraphicsPixmapItem>//显示图片
#include<QTimer>//定时器
#include<QVector2D>
class enemy:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
   explicit enemy(QObject *parent = nullptr);
    void shoot(QPointF target);
};

#endif // ENEMY_H
