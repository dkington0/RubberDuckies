#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

/**
 * @brief Square class
 * @details derived from the Shape class, a square object is confined by its bounding rectangle, which has equal lengths of width and height
 */
class square : public Shape
{
private:
    /**
     * @brief rect : QRect is the bounding rectangle of the square
     */
    QRect rect;
    /**
     * @brief id : ID is the unique integer assigned to each instance of a derived Shape object.
     */
    int id;

public:
    /**
     * @brief : Default constructor, creates a square at 750,150 with sides of 200 length
     */
    square() : rect{750, 150, 200, 200} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::SquareType); }

    /**
     * @brief : square constructor, creates a square with the incoming parameters
     *          to be used when creating new shapes
     * @param x : x coordinate of top-left corner
     * @param y : y coordinate of top-left corner
     * @param sides : length of height & width
     */
    square(qreal x, qreal y, qreal sides) { rect.setRect(x, y, sides, sides); id = num_shapes++ + 1; setShapeTypeFlag(Shape::SquareType); }

    /**
     * @brief : square constructor, creates a square with the incoming parameters
     *          to be used by the file parser
     * @param i : ID for the new shape
     * @param x : x coordinate of top-left corner
     * @param y : y coordinate of top-left corner
     * @param sides : length of height & width
     */
    square(int i, qreal x, qreal y, qreal sides) : id{i} { rect.setRect(x, y, sides, sides); setShapeTypeFlag(Shape::SquareType); }

    /**
     * @brief : square destructor
     */
    ~square();

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    void draw(QPainter* event) override;

    /**
    * @brief calculates area for shape
    * @param takes length and width and multiples them
    */
    double calculateArea() const override;

    /**
    * @brief calculates perimeter for shape
    * @param takes length and width, adds them and multiplies by two
    */
    double calculatePerimeter() const override;

    /**
     * @brief getId will return the derived shape's unique ID
     * @return : returns the derived shape's unique ID
     */
    int getId() { return id; };

    /**
     * @brief getRect will return the derived shape's bounding rectangle
     * @return : returns the derived shape's QRect bounding rectangle
     */
    QRect getRect() const { return rect; }
};

#endif // SQUARE_H
