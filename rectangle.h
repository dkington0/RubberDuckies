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
    /**
     * @brief id : ID is the unique integer assigned to each instance of a derived Shape object.
     */
    int id;

public:
    /**
     * @brief rectangle default contstructor, creates a predefined QRect object
     */
    rectangle() : rect{20, 200, 170, 100} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::RectangleType); }

    /**
     * @brief rectangle alternate constructor, to be used when creating new shapes
     * @param r : QRect bounding rectangle of the shape
     */
    rectangle(QRect r) : rect{r} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::RectangleType); }

    /**
     * @brief rectangle alternate constructor, to be used by the file parser
     * @param i : ID of the incoming shape
     * @param r : QRect bounding rectangle of the shape
     */
    rectangle(int i, QRect r) : id{i}, rect{r}  { setShapeTypeFlag(Shape::RectangleType); }

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
    void paintEvent(QPaintEvent* event) override;

    /**
     * @brief calculates area for shape, multiplies length and width
     */
    double calculateArea() const;

    /**
     * @brief calculates perimeter for shape, adds length+width and multiplies by two
     */
    double calculatePerimeter() const;
};

#endif // RECTANGLE_H
