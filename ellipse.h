#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Shape.h"

/**
 * @brief Ellipse class
 * @details derived from the Shape class, an ellipse object is confined by its bounding rectangle, which has differing lengths for width and height
 */
class ellipse : public Shape
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
     * @brief : default ellipse constructor, using predefined values for the bounding rectangle
     */
    ellipse() : rect{520, 200, 170, 100} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::EllipseType);}

    /**
     * @brief : alternate ellipse constructor, for use when creating new ellipse shapes
     * @param r : QRect for the bounding rectangle
     */
    ellipse(QRect r) : rect{r} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::EllipseType);}

    /**
     * @brief ellipse
     * @param i : ID of the incoming shape
     * @param r : QRect object for the bounding rectangle
     */
    ellipse(int i, QRect r) : id{i}, rect{r} { setShapeTypeFlag(Shape::EllipseType); }

    /**
     * @brief default destructor
     */
    ~ellipse();

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    void paintEvent(QPaintEvent* event) override;

    /**
     * @brief calculates area for ellipse
     * @param PI times major axis times minor axis
     */
    double calculateArea() const;

    /**
     * @brief calculates perimeter for ellipse
     * @param Perimeter of Ellipse Ramanujan's second approximation for the perimeter of an ellipse is P7(h) = π(a + b)(1 + 3h/10 + 4 - 3h)
     */
    double calculatePerimeter() const;

    /**
     * @brief getId will return the derived shape's unique ID
     * @return : returns the derived shape's unique ID
     */
    int getId() { return id; };
};

#endif // ELLIPSE_H
