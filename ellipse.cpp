#include "ellipse.h"

ellipse::~ellipse() {}

// paintEvent
void ellipse::paintEvent(QPaintEvent* event)
{
    QPainter *myEllipse = new QPainter(this);

    // Draws the circle withing the defined dimensions
    myEllipse->drawEllipse(rect);

    show();
    delete myEllipse; // Clean up memory to prevent leaks
}

double ellipse::calculateArea() const
{
    double majorAxis = rect.width() / 2.0;
    double minorAxis = rect.height() / 2.0;

    return M_PI * majorAxis * minorAxis;
}

double ellipse::calculatePerimeter() const
{
    double a = rect.width() / 2.0;
    double b = rect.height() / 2.0;

    double perimeter = M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));

    return perimeter;
}
