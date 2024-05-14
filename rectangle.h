#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

/**
 * @brief rectangle class
 * @details derived from the Shape class, a rectangle object is confined by its bounding rectangle, which has differing lengths for width and height
 */
class rectangle : public Shape
{
private:
    /**
     * @brief rect : QRect is the bounding rectangle of the circle
     */
    QRect rect;


public:
    /**
     * @brief rectangle default contstructor, creates a predefined QRect object
     */
    rectangle() : rect{20, 200, 170, 100} { setId(1 + num_shapes++);  setShapeTypeFlag(Shape::RectangleType); }

    /**
     * @brief rectangle alternate constructor, to be used when creating new shapes
     * @param r : QRect bounding rectangle of the shape
     */
    rectangle(QRect r) : rect{r} { setId(1 + num_shapes++);  setShapeTypeFlag(Shape::RectangleType); }

    /**
     * @brief rectangle alternate constructor, to be used by the file parser
     * @param i : ID of the incoming shape
     * @param r : QRect bounding rectangle of the shape
     */
    rectangle(int i, QRect r) : rect{r}  { setId(i); setShapeTypeFlag(Shape::RectangleType); }

    /**
     * @brief rectangle default destructor
     */
    ~rectangle();
    // void DrawShape() override;
    // void SetShape() override;

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    void draw(QPainter* event) override;

    /**
     * @brief calculates area for shape, multiplies length and width
     */
    double calculateArea() const override;

    /**
     * @brief calculates perimeter for shape, adds length+width and multiplies by two
     */
    double calculatePerimeter() const override;

    /**
     * @brief getId will return the derived shape's unique ID
     * @return : returns the derived shape's unique ID
     */
    int getId() const { return id; };

    /**
     * @brief getRect will return the derived shape's bounding rectangle
     * @return : returns the derived shape's QRect bounding rectangle
     */
    QRect getRect() const { return rect; }
};

#endif // RECTANGLE_H
