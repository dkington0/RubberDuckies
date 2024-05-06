#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class square : public Shape
{
private:
    QRect rect;

public:
    square() : rect{750, 150, 200, 200} {}
    square(qreal x, qreal y, qreal sides) { rect.setRect(x, y, sides, sides); }
    ~square();

};

#endif // SQUARE_H
