#ifndef CANVAS_H
#define CANVAS_H
#include "shape.h"
#include <QPainter>
#include "vector.h"



class Canvas:public Shape {
private:
    myStd::vector<Shape> passedShape; //vector initialized by pass from main
public:
    Canvas();
    Canvas(myStd::vector<Shape> const & passedVector);
    ~Canvas();
    void drawShape(); //draws shape based on passed shape. myStd is a horrible name btw


};

#endif //CANVAS_H

