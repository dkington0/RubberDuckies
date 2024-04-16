#ifndef POLYGON_H
#define POLYGON_H
#include "vector.h"
#include "Shape.h"

class polygon : public Shape
{
private:
    myStd::vector<QPoint> points;

public:
    polygon();
    polygon(int); // Initialize with a number of points
    ~polygon();

    void DrawShape() override;
    void SetShape() override;
};

#endif // POLYGON_H
