#ifndef FLOOR_H
#define FLOOR_H
#include <QGraphicsRectItem>
#include <QPixmap>

class Floor : public QGraphicsRectItem {
public:
    explicit Floor(qreal xpos, qreal ypos,
                   qreal width = 300.0,     // 默认宽度 300
                   qreal thickness = 30.0,  // 默认厚度 30
                   QGraphicsItem *parent = nullptr);

    qreal gety() const;
    qreal getx() const;
    qreal gettopy() const;
    qreal getscenetopy() const;
    static constexpr qreal thickness = 30.0;
    static constexpr qreal width = 300.0;//地板宽度
    QPixmap taijie;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

private:

    qreal m_thickness;  // 存储实例厚度
};

#endif // FLOOR_H
