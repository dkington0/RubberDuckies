#include "square.h"

square::~square() {}

// paintevent()
void square::paintEvent(QPaintEvent* event)
{
    QPainter *mySquare = new QPainter(this);

    setPen(getPen());

    // Draws the circle withing the defined dimensions
    mySquare->drawRect(rect);

    show();
    delete mySquare; // Clean up memory to prevent leaks
}

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
