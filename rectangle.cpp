#include "rectangle.h"

//rectangle::rectangle() {}
rectangle::~rectangle() {}

// paintevent()
void rectangle::paintEvent(QPaintEvent* event)
{
    QPainter *myRect = new QPainter(this);

    setPen(getPen());

    // Draws the circle withing the defined dimensions
    myRect->drawRect(rect);

    show();
    delete myRect; // Clean up memory to prevent leaks
}

double rectangle::calculateArea() const
{
    return rect.width() * rect.height();
}

double rectangle::calculatePerimeter() const
{
    return 2 * (rect.width() + rect.height());
}

