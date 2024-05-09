#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Shape.h"

class ellipse : public Shape
{
private:
    QRect rect;
    int id;

public:
    /**
     * @brief : default ellipse constructor, using predefined values for the bounding rectangle
     */
    ellipse() : rect{520, 200, 170, 100} { id = num_shapes++ + 1; }

    /**
     * @brief : alternate ellipse constructor, for use when creating new ellipse shapes
     * @param r : QRect for the bounding rectangle
     */
    ellipse(QRect r) : rect{r} { id = num_shapes++ + 1; }

    /**
     * @brief ellipse
     * @param i : ID of the incoming shape
     * @param r : QRect object for the bounding rectangle
     */
    ellipse(int i, QRect r) : id{i}, rect{r} { }

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
};

#endif // ELLIPSE_H
