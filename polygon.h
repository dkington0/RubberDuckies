#ifndef POLYGON_H
#define POLYGON_H
// #include "vector.h"
#include "shape.h"
#include "vector.h"


class polygon : public Shape
{
private:
    myStd::vector<QPoint> points;
    int id;
    //QPoint points [4] {};

public:
    /**
     * @brief polygon default constructor, initializes a n empty vector of QPoints
     */
    polygon(): points{myStd::vector<QPoint>()} { id = num_shapes++ + 1; }

    /**
     * @brief : polygon alternate constructor, to be used when creating new shapes
     * @param p : vector to hold all of the QPoints for the polygon
     */
    polygon(myStd::vector<QPoint>& p) : points{ p } { id = num_shapes++ + 1; }

    /**
     * @brief : polygon alternate constructor, to be used by the file parser
     * @param i : ID of the incoming shape
     * @param p : vector to hold all of the QPoints for the polygon
     */
    polygon(int i, myStd::vector<QPoint>& p) : points{ p } { id = num_shapes++ + 1; }

    /**
     * @brief : polygon default destructor
     */
    ~polygon();

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    void paintEvent(QPaintEvent *event) override;
    // void SetShape() override;
};

#endif // POLYGON_H

