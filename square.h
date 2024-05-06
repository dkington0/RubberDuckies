#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class square : public Shape
{
private:
    QRect rect;

public:
    square() : rect{750, 150, 200, 200} {}
    square(qreal x, qreal y, qreal sides) { rect.setRect(x, y, sides, sides); }
    ~square();

    /**
@brief calculates area for shape
*
@param takes length and width and multiples them
*/
    double calculateArea() const;

    /**
@brief calculates perimeter for shape
*
@param takes length and width, adds them and multiplies by two
*/
    double calculatePerimeter() const;
};

#endif // SQUARE_H
