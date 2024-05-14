#include "canvas.h"


Canvas::Canvas() {} // default constructor


 //vector initialized by pass from main

    Canvas::Canvas(myStd::vector<Shape*> passedVector ) //initializing
    {
      passedShapes = passedVector; //error here. other errors inside file parser are from the test case
    }

    void Canvas::configureShape()
    {

    }

    Canvas::Canvas(myStd::vector<Shape> && passedVector) // move constructor
    {
        //passedShape = std::move(passedVector); // move operation
    }

    void Canvas::drawShape(QPaintEvent* eventThing) //draws shape based on passed shape.
    {    // Iterates through the container calling the paint
        // event for each shape.

        for (int i = 0; i < passedShapes.size(); i++)
        {
            passedShapes[i]->paintEvent(eventThing);
        }

    }
    //destructor

/*    Canvas & Canvas::operator=(Canvas && other) // move assignment
    {
        if(this != &other) // check if already assigned
        {
            passedShape = std::move(other.passedShape); // move assignment
        }
        return *this;
    }
*/
