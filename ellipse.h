#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Shape.h"

class ellipse : public Shape
{
private:
    QRect rect;

public:
    ellipse() : rect{520, 200, 170, 100} {}
    ellipse(QRect r) : rect{r} {}
    ~ellipse();

    /**
@brief calculates area for ellipse
*
@param PI times major axis times minor axis
*/
    double calculateArea() const;

    /**
@brief calculates perimeter for ellipse
*
@param Perimeter of Ellipse Ramanujan's
second approximation for the perimeter of an ellipse
is P7(h) = π(a + b)(1 + 3h/10 + 4 - 3h)
*/
    double calculatePerimeter() const;
};

#endif // ELLIPSE_H
