#include "square.h"

square::~square() {}

double square::calculateArea() const
{
    double side = rect.width();
    return side * side;
}

double square::calculatePerimeter() const
{
    double side = rect.width();
    return 4 * side;
}

void square::paintEvent(QPaintEvent* event)
{
    QPainter mySquare(this);

    setPen(getPen());

    mySquare.drawRect(rect);
}
