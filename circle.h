#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#include <cmath>
#include "vector.h"

/**
 * @brief Circle class
 * @details derived from the Shape class, a circle object is confined by its bounding rectangle, which has equal lengths of width and height
 */
class circle : public Shape
{

private:
    /**
     * @brief rect : QRect is the bounding rectangle of the circle
     */
    QRect rect;

public:
    circle() : rect{250, 150, 200, 200} { setId(1 + num_shapes++); setShapeTypeFlag(Shape::CircleType);}
    /**
     * @brief : circle default constructor using predetermined values
     */

    /**
     * @brief : circle alternate constructor, for use when creating Circle objects
     * @param x : x coordinate of the top left corner for bounding rectangle
     * @param y : y coordinate of the top left corner for bounding rectangle
     * @param sides : length/width of bounding rectangle
     */
    circle(qreal x, qreal y, qreal sides) { rect.setRect(x, y, sides, sides); setId(1 + num_shapes++); setShapeTypeFlag(Shape::CircleType);}

    /**
     * @brief : circle alternate constructor, for use with file parser
     * @param i : ID of incoming Circle
     * @param x : x coordinate for top left corner of bounding rectangle
     * @param y : y coordinate for top left corner of bounding rectangle
     * @param sides : length/width of bounding rectangle
     */
    circle(int i, qreal x, qreal y, qreal sides) { setId(i), rect.setRect(x, y, sides, sides); setShapeTypeFlag(Shape::CircleType);}

    /**
     * @brief : default decontructor
     */
    ~circle();

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    void paintEvent(QPaintEvent* event) override;

    /**
     * @brief calculates area for circle
     * @param PI times width squared divided by 4
     */
    double calculateArea() const override;

    /**
     * @brief calculates perimeter  for circle
     *@param takes length and width and multiples them
     */
    double calculatePerimeter() const override;


    /**
     * @brief getRect will return the derived shape's bounding rectangle
     * @return : returns the derived shape's QRect bounding rectangle
     */
    QRect getRect() const { return rect; }


};

#endif // CIRCLE_H
