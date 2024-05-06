#include "rectangle.h"

//rectangle::rectangle() {}
rectangle::~rectangle() {}

double rectangle::calculateArea() const
{
    return rect.width() * rect.height();
}

double rectangle::calculatePerimeter() const
{
    return 2 * (rect.width() + rect.height());
}
