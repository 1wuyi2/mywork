// #ifndef FLOOR_H
// #define FLOOR_H

// #include <QGraphicsRectItem>
// #include <QPainter>

// class Floor : public QGraphicsRectItem {
// public:
//     explicit Floor(qreal ypos, QGraphicsItem *parent = nullptr);//构造函数
//     qreal gety() const;//获取地板最上面的坐标

// // protected:
// //     void paint(QPainter *painter,
// //                const QStyleOptionGraphicsItem *option,
// //                QWidget *widget) override;

// private:
// static constexpr qreal width = 200.0;   // 地板宽度
// static constexpr qreal thickness = 30.0; // 地板厚度
// };

// #endif // FLOOR_H
#ifndef FLOOR_H
#define FLOOR_H

#include <QGraphicsRectItem>
#include <QPixmap>

class Floor : public QGraphicsRectItem {
public:
    // 新增xpos参数，保持小写命名
    explicit Floor(qreal xpos, qreal ypos, QGraphicsItem *parent = nullptr);
    qreal gety();
protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
private:
    // 保持原有小写命名
    static constexpr qreal width = 200.0;    // 地板宽度
    static constexpr qreal thickness = 20.0; // 地板厚度
    QPixmap texture;
};

#endif // FLOOR_H
