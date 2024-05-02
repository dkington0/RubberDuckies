#ifndef polyline_H
#define polyline_H
// #include "vector.h"
#include "shape.h"

class polyline : public Shape
{
private:
    QPointF points[4];

public:
    polyline() : points{QPointF(460, 90), QPointF(470, 20), QPointF(530, 40), QPointF(540, 80)} {}
     polyline(QPointF p1, QPointF p2, QPointF p3, QPointF p4) : points{p1, p2, p3, p4} {} // Number of points
     ~polyline();

    // void DrawShape() override;
    // void SetShape() override;
};

// const QPointF polyline::points[3] = { QPointF(10.0, 80.0), QPointF(20.0, 10.0), QPointF(80.0, 30.0) };

#endif // polyline_H
