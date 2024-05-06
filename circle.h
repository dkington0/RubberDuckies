#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <cmath>

class circle : public Shape
{
private:
    QRect rect;

public:
    circle() : rect{20, 200, 170, 100} {}
    circle(qreal x, qreal y, qreal sides) { rect.setRect(x, y, sides, sides); }
    ~circle();

    /**
@brief calculates area for circle
*
@param PI times width squared divided by 4
*/
    double calculateArea() const;

    /**
@brief calculates perimeter  for circle
*
@param takes length and width and multiples them
*/
    double calculatePerimeter() const;
};

#endif // CIRCLE_H
