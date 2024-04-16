#ifndef POLYLINE_H
#define POLYLINE_H
#include "vector.h"
#include "Shape.h"

class Polyline : public Shape
{
private:
    myStd::vector<QPoint> points;

public:
    Polyline();
    ~Polyline();

    void DrawShape() override;
    void SetShape() override;
};

#endif // POLYLINE_H
