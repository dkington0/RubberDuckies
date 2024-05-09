#include "canvas.h"


Canvas::Canvas() {} // default constructor


 //vector initialized by pass from main

    Canvas::Canvas(myStd::vector<Shape>* passedVector ) //initializing
    {
      passedShape = passedVector; //error here. other errors inside file parser are from the test case
    }


    Canvas::Canvas(myStd::vector<Shape> && passedVector) // move constructor
    {
      //  passedShape = std::move(passedVector); // move operation
    }

    Canvas::~Canvas() {} //destructor

    Canvas & Canvas::operator=(Canvas && other) // move assignment
    {
        if(this != &other) // check if already assigned
        {
            passedShape = std::move(other.passedShape); // move assignment
        }
        return *this;
    }

    void Canvas::drawShape() //draws shape based on passed shape. myStd is a horrible name btw
    {

        for (Shape &tempShape : *passedShape )
        {
            tempShape;

        }
    }

