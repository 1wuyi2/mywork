#ifndef PLAYER_H
#define PLAYER_H
#include<QObject>//信号与槽机制，对象树内存管理
#include<QGraphicsPixmapItem>//显示图片
#include<QKeyEvent>//键盘输入功能
#include<QTimer>//定时器
#include<QVector2D>
class Player : public QObject, public QGraphicsPixmapItem {//继承自此两个类,确保能调用必要的函数
    Q_OBJECT//类中声明了slots，需要启用此宏，以支持信号槽，动态属性等特性
private:
    QVector2D v;//二维速度向量
    float speed = 5.0f;//设置基础速率
    bool keys[2] = {false};//keys的四个元素首先设置为0，按下时变为1

public:
    void startJump()
    { if (!jumping) { // 防止空中二段跳
            jumping = true;
            verticalSpeed = orginv;}};
    bool jumping = false;//判断是否正跳跃
    float verticalSpeed = 0.0f;//竖直速度
    const float gravity = 0.8f;//重力效果，数值竖直向下，每帧更新
    const float orginv = -12.0f; // 初始速度向上
    float groundY = 500.0f;           // 地面Y坐标

    explicit Player(QObject *parent = nullptr);//构造函数，parent即指定了父对象
    void updateMovement()
    {
        v = QVector2D(0, 0);
        if (keys[0]) v.setX(-1);
        if (keys[1]) v.setX(1);  //左右移动
        if (!v.isNull())
        {v.normalize();}//单位化
       if (jumping) {
            verticalSpeed += gravity;
            float newY = y() + verticalSpeed;
            if (newY >= groundY) {
                newY = groundY;
                verticalSpeed = 0;
                jumping = false;
            }            // 落地检测
            setPos(x() + v.x() * speed, newY);
        } else {
            setPos(x() + v.x() * speed, y());
        }
    }// 处理跳跃效果
        /*  v = QVector2D(0, 0);//创建二维速度向量
        if (keys[0]) v.setY(-1); // W
        if (keys[1]) v.setX(-1); // A
        if (keys[2]) v.setY(1);  // S
        if (keys[3]) v.setX(1);  // D

        // 标准化速度向量（避免斜向移动更快）
        if (!v.isNull())
        {
            v.normalize();//使合成速度也为1
        }
        // 更新位置
        setPos(x() + v.x() * speed, y() + v.y() * speed);*/
    // }
    ;//更新运动状态的函数
    void shoot(QPointF target);//射击函数 参数为QpoinF类的target表示目标的坐标（考虑传入鼠标的实时位置作为目标）

public slots:
    void move()//
    {
        updateMovement();
    };
    void presskey(int keyIndex, bool isPressed) {//wsad移动
        if (keyIndex >= 0 && keyIndex < 4) {
            keys[keyIndex] = isPressed;
        }//当wsad任一键按下时，使其对应的key[?]变为true，当其为true时，改变对应方向速度
    }


};
#endif // PLAYER_H
