#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line  : public Shape
{
private:
    QLine line;
    int id;

public:

    /**
     * @brief Line default constructor
     */
    Line() : line{20, 90, 100, 20} { id = num_shapes++ + 1; }

    /**
     * @brief Line alternate constructor, for use when creating new shapes
     * @param l : QLine object to be stored in the line member
     */
    Line(QLine l) : line{l} { id = num_shapes++ + 1; }

    /**
     * @brief Line alternate constructor, to be used during file parsing
     * @param i : ID of incoming shape
     * @param l : QLine object to be stored in the line member
     */
    Line(int i, QLine l) : id{i}, line{l} {}

    /**
     * @brief default deconstructor
     */
    ~Line();

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    void paintEvent(QPaintEvent *event) override;

};

#endif // LINE_H
