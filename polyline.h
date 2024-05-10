#ifndef polyline_H
#define polyline_H
// #include "vector.h"
#include "shape.h"
#include "vector.h"

class polyline : public Shape
{
private:
    myStd::vector<QPoint> points;
    int id;

public:
    /**
     * @brief polyline default constructor
     */
    polyline() : points{} { id = num_shapes++ + 1; }

    /**
     * @brief polyline alternate constructor, to be used when creating shapes
     * @param p : vector of all QPoints which connect the polyline
     */
    polyline(myStd::vector<QPoint>& p) : points{p} { id = num_shapes++ + 1; } // Number of points

    /**
     * @brief polyline alternate constructor, to be used by the file parser
     * @param i : ID of the incoming shape
     * @param p : vector of all QPoints which connect the polyline
     */
    polyline(int i, myStd::vector<QPoint>& p) : points{p}, id{i} { }

    /**
     * @brief polyline default deconstructor
     */
    ~polyline();

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    void paintEvent(QPaintEvent *event) override;

    // void SetShape() override;
};

// const QPointF polyline::points[3] = { QPointF(10.0, 80.0), QPointF(20.0, 10.0), QPointF(80.0, 30.0) };

#endif // polyline_H
