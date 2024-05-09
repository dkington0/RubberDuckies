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
    polyline() : points{} { id = num_shapes++ + 1; }
    polyline(myStd::vector<QPoint>& p) : points{p} { id = num_shapes++ + 1; } // Number of points
    polyline(int i, myStd::vector<QPoint>& p) : points{p}, id{i} { }
    ~polyline();

    void paintEvent(QPaintEvent* event) override {};

    // void DrawShape() override;
    // void SetShape() override;
};

// const QPointF polyline::points[3] = { QPointF(10.0, 80.0), QPointF(20.0, 10.0), QPointF(80.0, 30.0) };

#endif // polyline_H
