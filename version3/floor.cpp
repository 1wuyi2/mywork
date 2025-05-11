#include "floor.h"
#include <QPainter>
#include"chosemap.h"
Floor::Floor(qreal xpos, qreal ypos,
             qreal width, qreal thickness,
             QGraphicsItem *parent)
    : QGraphicsRectItem(0, 0, width, thickness, parent),
    m_thickness(thickness)  // 初始化厚度
{
    if(chosemap::x==1){
    taijie.load(":/images/FLOOR2.png");
    }
    else   if(chosemap::x==2){
        taijie.load(":/images/FLOOR.png");
    }
    else if(chosemap::x==3){
        taijie.load(":/images/FLOOR3.png");
    }
    setPos(xpos, ypos - thickness);  // 调整Y坐标位置
    setBrush(Qt::NoBrush);
    setPen(Qt::NoPen);
}
qreal Floor::gety() const {
    return y();
}
qreal Floor::getx() const {
    return x();
}
qreal Floor::gettopy() const {
    return y() - m_thickness;  // 使用实例厚度
}
qreal Floor::getscenetopy() const {
    return scenePos().y();
}
void Floor::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
    painter->drawPixmap(rect(), taijie, taijie.rect());
}
