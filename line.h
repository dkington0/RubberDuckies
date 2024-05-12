#ifndef LINE_H
#define LINE_H
#include "shape.h"

/**
 * @brief Line class
 * @details derived from the Shape class, a Line object is defined by the two QPoints on either end connected by a straight line.
 */
class Line  : public Shape
{
private:
    /**
     * @brief line : QLine which holds the points and parameters for the Line object
     */
    QLine line;


    public:

    /**
     * @brief Line default constructor
     */
    Line() : line{20, 90, 100, 20} { setId(1 + num_shapes++);  setShapeTypeFlag(Shape::LineType); }

    /**
     * @brief Line alternate constructor, for use when creating new shapes
     * @param l : QLine object to be stored in the line member
     */
    Line(QLine l) : line{l} { setId(1 + num_shapes++);  setShapeTypeFlag(Shape::LineType); }

    /**
     * @brief Line alternate constructor, to be used during file parsing
     * @param i : ID of incoming shape
     * @param l : QLine object to be stored in the line member
     */
    Line(int i, QLine l) : line{l} { setId(i); setShapeTypeFlag(Shape::LineType); }

    /**
     * @brief default deconstructor
     */
    ~Line();

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    void paintEvent(QPaintEvent *event) override;

    /**
     * @brief getId will return the derived shape's unique ID
     * @return : returns the derived shape's unique ID
     */
    int getId() { return id; };

    /**
     * @brief getLine will return the derived shape's line object
     * @return : returns the derived shape's QLine object
     */
    QLine getLine() const { return line; };
};

#endif // LINE_H
