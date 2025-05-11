#ifndef ENEMY_H
#define ENEMY_H
#include<QGraphicsPixmapItem>//显示图片
#include<QTimer>//定时器
#include<QVector2D>
#include<floor.h>
#include<player.h>
#include<QObject>//信号与槽机制，对象树内存管理
class enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    float  speed=2.0f;//地板上移动速度，比角色小点，毕竟多打少
    int blood=4;//A1四枪死，没毛病，以后尝试添加爆头逻辑
    QTimer *shoottimer;  //射击计时器；
    int movedirection=1;//1左2右，触边改变

    Player*target;
public:
    explicit enemy (Player *pl, QGraphicsItem *parent = nullptr):QGraphicsPixmapItem(parent),target(pl){
        setPixmap(QPixmap()); // 加载角色图片
        setTransformOriginPoint(boundingRect().center()); }
    void shoot();//射击函数
    void isshezhong();//被射击到控制血量改变的函数
};
#endif // ENEMY_H
