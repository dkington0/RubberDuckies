#ifndef polyline_H
#define polyline_H
#include "vector.h"
#include "Shape.h"

class polyline : public Shape
{
private:
    myStd::vector<QPoint> points;
    Shape* shape;

public:
    polyline();
    polyline(int);  // Number of points
    ~polyline();

    // void DrawShape() override;
    // void SetShape() override;
};

#endif // polyline_H
