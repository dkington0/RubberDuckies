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
    /**
     * @brief id : ID is the unique integer assigned to each instance of a derived Shape object.
     */
    int id;

public:
    circle() : rect{250, 150, 200, 200} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::CircleType);}
    /**
     * @brief : circle default constructor using predetermined values
     */

    /**
     * @brief : circle alternate constructor, for use when creating Circle objects
     * @param x : x coordinate of the top left corner for bounding rectangle
     * @param y : y coordinate of the top left corner for bounding rectangle
     * @param sides : length/width of bounding rectangle
     */
    circle(qreal x, qreal y, qreal sides) { rect.setRect(x, y, sides, sides); id = num_shapes++ + 1; setShapeTypeFlag(Shape::CircleType);}

    /**
     * @brief : circle alternate constructor, for use with file parser
     * @param i : ID of incoming Circle
     * @param x : x coordinate for top left corner of bounding rectangle
     * @param y : y coordinate for top left corner of bounding rectangle
     * @param sides : length/width of bounding rectangle
     */
    circle(int i, qreal x, qreal y, qreal sides) : id{i} { rect.setRect(x, y, sides, sides); setShapeTypeFlag(Shape::CircleType);}

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
    double calculateArea() const;

    /**
     * @brief calculates perimeter  for circle
     *@param takes length and width and multiples them
     */
    double calculatePerimeter() const;

    /**
     * @brief getId will return the derived shape's unique ID
     * @return : returns the derived shape's unique ID
     */
    int getId() const { return id; }

    /**
     * @brief getRect will return the derived shape's bounding rectangle
     * @return : returns the derived shape's QRect bounding rectangle
     */
    QRect getRect() const { return rect; }


};

#endif // CIRCLE_H
