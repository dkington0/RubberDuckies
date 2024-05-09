#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Shape.h"

class ellipse : public Shape
{
private:
    QRect rect;
    int id;

public:
    ellipse() : rect{520, 200, 170, 100} { id = num_shapes++ + 1; }
    ellipse(QRect r) : rect{r} { id = num_shapes++ + 1; }
    ellipse(int i, QRect r) : id{i}, rect{r} { }
    ~ellipse();

    void paintEvent(QPaintEvent* event) override;

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
