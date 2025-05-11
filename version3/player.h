#ifndef PLAYER_H
#include<QDebug>
#define PLAYER_H
#include<QObject>//信号与槽机制，对象树内存管理
#include<QGraphicsPixmapItem>//显示图片
#include<QKeyEvent>//键盘输入功能
#include<QTimer>//定时器
#include<QVector2D>
#include<floor.h>
#include"c4.h"
#include"weapon.h"
#include <QGraphicsProxyWidget>
class Player : public QObject, public QGraphicsPixmapItem {//继承自此两个类,确保能调用必要的函数
    Q_OBJECT//类中声明了slots，需要启用此宏，以支持信号槽，动态属性等特性
private:
    QGraphicsRectItem* m_healthBar;
    float speed = 5.0f;//设置基础速率
    bool keys[4] = {false};//keys的3个元素首先设置为0，按下时变为1
  QPixmap  normalPixmap ;
    QPixmap ctrlPixmap;
  QList<QPixmap> m_runFrames;  // 运动动画帧序列
  int m_currentFrame = 0;      // 当前动画帧索引
  bool m_isMoving = false;     // 移动状态标志
  bool m_facingRight = true;   // 朝向控制
  qint64 m_lastAnimTime = 0;   // 上次动画更新时间[3](@ref)
public:
    ~Player();
   QVector2D v;//二维速度向量
    float verticalSpeed = 0.0f;//竖直速度
    const float gravity = 0.5f;//重力效果，数值竖直向下，每帧更新
    const float orginv = -12.0f; //初始速度向上
    float groundy = 500.0f; //地面Y坐标
   static constexpr qreal playerheight=155;
    explicit Player(QObject *parent = nullptr);//构造函数，parent即指定了父对象
     bool checkFloorCollision();
    void updateMovement();
    void shoot(QPointF target);//射击函数 参数为QpoinF类的target表示目标的坐标（考虑传入鼠标的实时位置作为目标）
    QPointF getpos();
    qreal playerfeety() const ;
    qreal gety();
    bool isonthefloor =1;
    int health=10;
    void takeDamage(int damage)
    {
        health -= damage;
        if(m_healthBar) {
            qreal width = 50 * (health / 4.0);
            m_healthBar->setRect(-25, -30, width, 5);
            m_healthBar->setBrush(health > 2 ? Qt::green : Qt::red);
        }
        if (health <= 0) {
            health = 0;
            emit playerDied(); //触发死亡信号
        }
    }

    bool m_eKeyHeld = false;//E键按住状态
    bool m_defusing = false;//实际拆除状态
    void setEKeyHeld(bool held)
    {
        m_eKeyHeld = held;
    }
    bool isDefusing() const
    {
        return m_defusing;
    }
    void updateDefusingState() {
        m_defusing = (m_eKeyHeld && v.isNull());
        emit defuseStatusChanged(m_defusing);
    }//更新拆除状态的函数，当按下e且角色静止且碰撞检测，即c4传来的canDefuse为1时可拆
private:
    weapon* m_weapon; // 成员变量
public slots:
    void move()
    {
        updateMovement();
    };
    void presskey(int keyIndex, bool isPressed) {//ad移动
        if (keyIndex >= 0 && keyIndex < 4) {
            keys[keyIndex] = isPressed;
        }//当ad按下时，使其对应的key[?]变为true，当其为true时，改变对应方向速度
    }
     void updateAnimation();     // 动画帧更新
signals:
    void defuseStatusChanged(bool isDefusing);
    void playerDied();//死亡信号

};
#endif
