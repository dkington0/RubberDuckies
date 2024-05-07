#include "canvas.h"


Canvas::Canvas() {}


 //vector initialized by pass from main
    Canvas::Canvas(const myStd::vector<Shape> &shapeThing ) //initializing
    {
      passedShape = shapeThing; //error here. other errors inside file parser are from the test case
    }
    void Canvas::drawShape() //draws shape based on passed shape. myStd is a horrible name btw
    {

        for (Shape &tempShape : passedShape )
        {
            tempShape;

        }
    }

