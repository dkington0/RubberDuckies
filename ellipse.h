#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Shape.h"

class ellipse : public Shape
{
private:
    QRectF rect;

public:
    ellipse() : rect{520, 200, 170, 100} {}
    ellipse(qreal x, qreal y, qreal width, qreal height) { rect.setRect(x, y, width, height); }
    ~ellipse();
};

#endif // ELLIPSE_H
