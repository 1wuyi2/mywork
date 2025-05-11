#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPointF>
#include <QTimer>

class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QPointF startPos, QPointF targetPos, QObject *parent = nullptr);//构造函数,构造时刻即创建开始和目标方向，再进行计算移动

private slots:
    void move(); // 定时器触发的移动函数，源文件中定义

private:
    QPointF direction; // 移动方向
    float speed = 10.0f; // 速度
    QTimer *timer;      // 定时器
};
