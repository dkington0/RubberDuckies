#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class rectangle : public Shape
{
private:
    QRect rect;
    int id;

public:
    /**
     * @brief rectangle default contstructor, creates a predefined QRect object
     */
    rectangle() : rect{20, 200, 170, 100} { id = num_shapes++ + 1; }

    /**
     * @brief rectangle alternate constructor, to be used when creating new shapes
     * @param r : QRect bounding rectangle of the shape
     */
    rectangle(QRect r) : rect{r} { id = num_shapes++ + 1; }

    /**
     * @brief rectangle alternate constructor, to be used by the file parser
     * @param i : ID of the incoming shape
     * @param r : QRect bounding rectangle of the shape
     */
    rectangle(int i, QRect r) : id{i}, rect{r}  { }

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
