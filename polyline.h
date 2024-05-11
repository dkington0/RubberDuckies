#ifndef polyline_H
#define polyline_H
// #include "vector.h"
#include "shape.h"
#include "vector.h"

/**
 * @brief Polyline class
 * @details derived from the Shape class, a polyline object is defined by any number of lines connected by QPoints.
 */
class polyline : public Shape
{
private:
    /**
     * @brief points : vector of QPoints which stores the coordinates of all of the different points where the lines of the polyline intersect
     */
    myStd::vector<QPoint> points;
    /**
     * @brief id : ID is the unique integer assigned to each instance of a derived Shape object.
     */
    int id;

public:
    /**
     * @brief polyline default constructor
     */
    polyline() : points{} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::PolylineType); }

    /**
     * @brief polyline alternate constructor, to be used when creating shapes
     * @param p : vector of all QPoints which connect the polyline
     */
    polyline(myStd::vector<QPoint>& p) : points{p} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::PolylineType); } // Number of points

    /**
     * @brief polyline alternate constructor, to be used by the file parser
     * @param i : ID of the incoming shape
     * @param p : vector of all QPoints which connect the polyline
     */
    polyline(int i, myStd::vector<QPoint>& p) : points{p}, id{i} { setShapeTypeFlag(Shape::PolylineType); }

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

    /**
     * @brief getId will return the derived shape's unique ID
     * @return : returns the derived shape's unique ID
     */
    int getId() const { return id; }

    /**
     * @brief getPoints will return a vector of the derived shape's points
     * @return : returns a vector of the derived shape's points
     */
    myStd::vector<QPoint> getPoints() const { return points; }
};

// const QPointF polyline::points[3] = { QPointF(10.0, 80.0), QPointF(20.0, 10.0), QPointF(80.0, 30.0) };

#endif // polyline_H
