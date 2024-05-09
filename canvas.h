#ifndef CANVAS_H
#define CANVAS_H
#include "shape.h"
#include <QPainter>
#include "vector.h"

enum ShapeType { Line, PolyLine, Polygon, Rectangle, Square, Ellipse, Circle, Text };

class Canvas:public QWidget {
private:
    myStd::vector<Shape>* passedShape; //vector initialized by pass from main
public:
    Canvas();

    Canvas(myStd::vector<Shape>* passedVector); // copy constructor
/*
    Canvas(myStd::vector<Shape> && passedVector); // move constructor

    ~Canvas(); // default destructor

    Canvas& operator=(Canvas && other); // move assignment operator
*/

    void drawShape(); //draws shape based on passed shape. myStd is a horrible name btw&
};

#endif //CANVAS_H

