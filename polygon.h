#ifndef POLYGON_H
#define POLYGON_H
// #include "vector.h"
#include "shape.h"
#include "vector.h"


class polygon : public Shape
{
private:
    myStd::vector<QPoint> points;

public:
    polygon(): points{myStd::vector<QPoint>()} {}
    polygon(myStd::vector<QPoint>& p) : points{ p } {} // Initialize with a number of points
    ~polygon();

    void paintEvent(QPaintEvent *event) override;
    // void SetShape() override;
};

#endif // POLYGON_H
