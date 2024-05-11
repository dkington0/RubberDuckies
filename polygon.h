#ifndef POLYGON_H
#define POLYGON_H
// #include "vector.h"
#include "shape.h"
#include "vector.h"

/**
 * @brief Polygon class
 * @details derived from the Shape class, a polygon object is defined by any number of sides connected by QPoints which fully enclose a space.
 */
class polygon : public Shape
{
private:
    /**
     * @brief points : vector of QPoints which stores the coordinates of all of the different points where the sides of the polygon intersect
     */
    myStd::vector<QPoint> points;
    /**
     * @brief id : ID is the unique integer assigned to each instance of a derived Shape object.
     */
    int id;
    //QPoint points [4] {};

public:
    /**
     * @brief polygon default constructor, initializes a n empty vector of QPoints
     */
    polygon(): points{myStd::vector<QPoint>()} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::PolygonType); }

    /**
     * @brief : polygon alternate constructor, to be used when creating new shapes
     * @param p : vector to hold all of the QPoints for the polygon
     */
    polygon(myStd::vector<QPoint>& p) : points{ p } { id = num_shapes++ + 1; setShapeTypeFlag(Shape::PolygonType); }

    /**
     * @brief : polygon alternate constructor, to be used by the file parser
     * @param i : ID of the incoming shape
     * @param p : vector to hold all of the QPoints for the polygon
     */
    polygon(int i, myStd::vector<QPoint>& p) : points{ p } { id = num_shapes++ + 1; setShapeTypeFlag(Shape::PolygonType); }

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

    /**
     * @brief getId will return the derived shape's unique ID
     * @return : returns the derived shape's unique ID
     */
    int getId() const { return id; };

    /**
     * @brief getPoints will return a vector of the derived shape's points
     * @return : returns a vector of the derived shape's points
     */
    myStd::vector<QPoint> getPoints() const { return points; }
};

#endif // POLYGON_H

