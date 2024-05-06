#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class circle : public Shape
{
private:
    QRect rect;

public:
    circle() : rect{20, 200, 170, 100} {}
    circle(qreal x, qreal y, qreal sides) { rect.setRect(x, y, sides, sides); }
    ~circle();
};

#endif // CIRCLE_H
