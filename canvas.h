#ifndef CANVAS_H
#define CANVAS_H
#include "shape.h"
#include <QPainter>
#include "vector.h"

// enum ShapeType { line, PolyLine, Polygon, Rectangle, Square, Ellipse, Circle, Text };
QT_BEGIN_NAMESPACE
namespace Ui {
class Canvas;
}
QT_END_NAMESPACE
/**
 * @brief Canvas class
 * @details Canvas is where the user is taken after the main window is closed upon login. in canvas the user can create tools to create and edit shapes.
 */
class Canvas: public MainWindow
{
private:
    Ui::Canvas *ui;
    myStd::vector<Shape*> passedShapes; //vector initialized by pass from main

public:
    /**
     * @brief : Default constructor
     * @param src : Default object
     */
    Canvas(){};

    /**
     * @brief : Copy constructor
     * @param src : Vector holding shape and vector to copy to
     * @return returns copied vector
     */
    Canvas(myStd::vector<Shape*> passedVector); // copy constructor

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
    ~Canvas(){}; // default destructor

    /**
     * @brief : overloaded assignment operation
     * @param src : Canvas object to move into "other"
     * @return returns moved object
     */
    Canvas& operator=(Canvas && other); // move assignment operator

    /**
     * @brief : Function to draw shapes on canvas
     */
    void drawShape(QPaintEvent* t); //draws shape based on passed shape. myStd is a horrible name btw&

    void configureShape();
};

#endif //CANVAS_H

