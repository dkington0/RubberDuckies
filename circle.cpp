#include "circle.h"

circle::~circle() {}

double circle::calculateArea() const
{
    return M_PI * rect.width() * rect.width() / 4;
}

double circle::calculatePerimeter() const
{
    return 2 * M_PI * rect.width() / 2;
}
