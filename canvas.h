#ifndef CANVAS_H
#define CANVAS_H
#include "shape.h"
#include <QPainter>
#include "vector.h"

/**
     * @brief : Enum to provide shape type
     * @param src : Types of shapes
     */
enum ShapeType { Line, PolyLine, Polygon, Rectangle, Square, Ellipse, Circle, Text };

class Canvas: public QWidget
{
private:
    myStd::vector<Shape>* passedShape; //vector initialized by pass from main
public:
    /**
     * @brief : Default constructor
     * @param src : Default object
     */
    Canvas();

    /**
     * @brief : Copy constructor
     * @param src : Vector holding shape and vector to copy to
     * @return returns copied vector
     */
    Canvas(myStd::vector<Shape>* passedVector); // copy constructor

    /**
     * @brief : Move constructor
     * @param src : Vector holding shape and vector to move to
     * @return returns moved vector
     */
    Canvas(myStd::vector<Shape> && passedVector); // move constructor

    /**
     * @brief : Default destructor
     * @param src : Vector to be destructed
     */
    ~Canvas(); // default destructor

    /**
     * @brief : overloaded assignment operation
     * @param src : Canvas object to move into "other"
     * @return returns moved object
     */
    Canvas& operator=(Canvas && other); // move assignment operator


    /**
     * @brief : Function to draw shapes on canvas
     */
    void drawShape(); //draws shape based on passed shape. myStd is a horrible name btw&
};

#endif //CANVAS_H

