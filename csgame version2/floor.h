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
