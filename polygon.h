#ifndef POLYGON_H
#define POLYGON_H
// #include "vector.h"
#include "shape.h"
#include "vector.h"


class polygon : public Shape
{
private:
    myStd::vector<QPoint> points{4};
    int id;
    //QPoint points [4] {};

public:
    polygon(): points{myStd::vector<QPoint>()} { id = num_shapes++ + 1; }
    polygon(myStd::vector<QPoint>& p) : points{ p } { id = num_shapes++ + 1; }
    polygon(int i, myStd::vector<QPoint>& p) : points{ p } { id = num_shapes++ + 1; }// Initialize with a number of points
    ~polygon();

    void paintEvent(QPaintEvent *event) override;
    // void SetShape() override;
};

#endif // POLYGON_H

//explicit vector(int s) : size_v{s}, elem{new T[s]}, space{s} // alternate constructor
