#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class rectangle : public Shape
{
private:
    QRect rect;
    int id;

public:
    rectangle() : rect{20, 200, 170, 100} { id = num_shapes++ + 1; }
    rectangle(QRect r) : rect{r} { id = num_shapes++ + 1; }
    rectangle(QRect r, int i) : rect{r}, id{i} { }
    ~rectangle();
    // void DrawShape() override;
    // void SetShape() override;

    void paintEvent(QPaintEvent* event) override {};

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

#endif // RECTANGLE_H
