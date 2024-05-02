#ifndef POLYGON_H
#define POLYGON_H
// #include "vector.h"
#include "shape.h"

class polygon : public Shape
{
private:
    QPointF points[4];

public:
    polygon(): points{QPointF(900, 90), QPointF(910, 20), QPointF(970, 40), QPointF(980, 80)} {}
    polygon(QPointF p1, QPointF p2, QPointF p3, QPointF p4) : points{p1, p2, p3, p4} {} // Initialize with a number of points
    ~polygon();

    // void DrawShape() override;
    // void SetShape() override;
};

#endif // POLYGON_H
