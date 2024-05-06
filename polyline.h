#ifndef polyline_H
#define polyline_H
// #include "vector.h"
#include "shape.h"
#include "vector.h"

class polyline : public Shape
{
private:
    myStd::vector<QPoint> points;

public:
    polyline() : points{} {}
    polyline(myStd::vector<QPoint>& p) : points{p} {} // Number of points
    ~polyline();

    // void DrawShape() override;
    // void SetShape() override;
};

// const QPointF polyline::points[3] = { QPointF(10.0, 80.0), QPointF(20.0, 10.0), QPointF(80.0, 30.0) };

#endif // polyline_H
