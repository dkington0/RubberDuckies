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
    /**
     * @brief id : ID is the unique integer assigned to each instance of a derived Shape object.
     */
    int id;

public:

    /**
     * @brief Line default constructor
     */
    Line() : line{20, 90, 100, 20} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::LineType); }

    /**
     * @brief Line alternate constructor, for use when creating new shapes
     * @param l : QLine object to be stored in the line member
     */
    Line(QLine l) : line{l} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::LineType); }

    /**
     * @brief Line alternate constructor, to be used during file parsing
     * @param i : ID of incoming shape
     * @param l : QLine object to be stored in the line member
     */
    Line(int i, QLine l) : id{i}, line{l} { setShapeTypeFlag(Shape::LineType); }

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

};

#endif // LINE_H
