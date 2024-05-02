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
    polygon(): points{QPoint(900, 90), QPoint(910, 20), QPoint(970, 40), QPoint(980, 80)} {}
    polygon(myStd::vector<QPoint>& p) : points{ p } {} // Initialize with a number of points
    ~polygon();

    void paintEvent(QPaintEvent *event) override;
    // void SetShape() override;
};

#endif // POLYGON_H
