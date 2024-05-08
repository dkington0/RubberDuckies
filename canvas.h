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

    Canvas(const myStd::vector<Shape> & passedVector); // copy constructor

    Canvas(myStd::vector<Shape> && passedVector); // move constructor

    ~Canvas(); // default destructor

    Canvas& operator=(Canvas && other); // move assignment operator

    void drawShape(); //draws shape based on passed shape. myStd is a horrible name btw


};

#endif //CANVAS_H

