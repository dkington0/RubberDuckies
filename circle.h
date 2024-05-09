#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <cmath>
#include "vector.h"

class circle : public Shape
{
private:
    QRect rect;
    int id;

public:
    circle() : rect{20, 200, 170, 100} { id = num_shapes++ + 1; }
    circle(qreal x, qreal y, qreal sides) { rect.setRect(x, y, sides, sides); id = num_shapes++ + 1;}
    circle(int i, qreal x, qreal y, qreal sides) : id{i} { rect.setRect(x, y, sides, sides);}
    ~circle();

    void paintEvent(QPaintEvent* event) override;

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
