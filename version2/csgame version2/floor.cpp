#include "floor.h"
#include <QPainter>
Floor::Floor(qreal xpos, qreal ypos, QGraphicsItem *parent)
    : QGraphicsRectItem(0, 0, width, thickness, parent) // 使用小写width/thickness
{
    texture.load(":/images/taijie.jpg") ;
 // 台阶样式，先测试，后加入所需要的图片
    setPos(xpos, ypos - thickness); //  // 自定义的x和y
    setBrush(Qt::NoBrush);//透明显示
    setPen(Qt::NoPen);//不要轮廓
}
qreal Floor::gety() {
    return y();
}
// 保持绘制逻辑不变
void Floor::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
    painter->drawPixmap(rect(), texture, texture.rect());//texture的图案画到floor对应的矩形
}
