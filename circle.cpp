#include "circle.h"

circle::~circle() {}

// paintEvent
void circle::draw(QPainter* event)
{
   // QPainter *myCircle = new QPainter(this);

    setPen(getPen());

    // Draws the circle withing the defined dimensions
    event->drawEllipse(rect);

    show();
   // delete myCircle; // Clean up memory to prevent leaks
}

double circle::calculateArea() const
{
    return M_PI * rect.width() * rect.width() / 4;
}

double circle::calculatePerimeter() const
{
    return 2 * M_PI * rect.width() / 2;
}

