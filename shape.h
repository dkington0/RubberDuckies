#ifndef SHAPE_H
#define SHAPE_H

#include "MainWindow.h"
#include "vector.h"
#include <QPainter>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui {
class Shape;
}
QT_END_NAMESPACE

/**
 * @brief Shape class
 * @details the base class for the main Shape objects, this abstract class holds the information all shapes should be able to implement, such as its UI, a QPen, and a QBrush.
 *          Provides overloaded comparison operators as well as some virtual functions for the derived classes.
 */
class Shape : public MainWindow
{
    public:
        /**
         * @brief ShapeType enum holds the shape's type, used when determining the shape from the main vector of Shape pointers
         */
        enum ShapeType {
            LineType,
            PolylineType,
            PolygonType,
            RectangleType,
            SquareType,
            EllipseType,
            CircleType,
            TextType
        };

    Q_OBJECT
    private:
        Ui::Shape *ui;
        /**
         * @brief pen : QPen object which holds the data for parameters such as color, pen style, etc.
         */
        QPen pen;

        /**
         * @brief brush : QBrush object which holds the data for parameters such as brush style.
         */
        QBrush brush;

        /**
         * @brief shapeTypeFlag holds one of the values from the ShapeType enum, to be used when determing which shape type the object is.
         */
        ShapeType shapeTypeFlag;

        /**
         * @brief ID is the unique integer assigned to each instance of a Shape object.
         */
        int id;

    public:
        /**
         * @brief num_shapes : counter for the number of shapes created, used for setting ID upon shape creation
         */
        static int num_shapes;

        /**
         * @brief : Shape constructor for parent widget
         * @param parent : parent QWidget being used for rendering
         */
        Shape(QWidget *parent = nullptr);

        /**
         * @brief   Virtual destructor for abstract Shape
         */
        virtual ~Shape();

        /**
         * @brief : paintEvent to be called upon a QPaintEvent, such as update()
         * @param : QPaintEvent being called
         */
        virtual void paintEvent(QPaintEvent* event)=0;

        /**
         * @brief : Shape copy constructor, disabled and marked for deletion
         */
        Shape(const Shape&) = delete; // disable copy constructor

        /**
         * @brief : operator= overloaded copy assignment, disabled and marked for deletion
         */
        Shape& operator=(const Shape&) = delete; // disable assignment operator

        /**
         * @brief operator== : overloaded equality operator
         * @param other : right-hand side Shape object for invoking object to compare against
         * @return : returns true if the same Shape
         */
        bool operator==(const Shape& other) const; // overloaded equality operator

        /**
         * @brief operator< : overloaded less-than operator
         * @param other : right-hand side Shape object for invoking object to compare against
         * @return : returns true if less than the other Shape
         */
        bool operator<(const Shape& other) const; // overloaded less than operator

        /**
         * @brief setPen : sets the Shape pen member to the incoming QPen object
         * @param p : QPen object to be stored
         */
        void setPen(QPen p);

        /**
         * @brief getFont : retrieves the Shape's QFont
         * @return : QFont object
         */
        QFont& getFont();
        //void setPen(); //Dropdown to select different pen options

        /**
         * @brief getPen : retrieves the data stored in Shape's pen member
         * @return : QPen object stored in pen member
         */
        QPen& getPen();

        /**
         * @brief setShapeTypeFlag sets the type of the shape object with a value from the ShapeType enum
         * @param flag : a value from the Shape class' ShapeType enum
         */
        void setShapeTypeFlag(ShapeType flag);

        /**
         * @brief getShapeTypeFlag gets the type of Shape from the ShapeType member
         * @return : returns the ShapeType for the object
         */
        ShapeType getShapeTypeFlag() const;

        void drawShapes(myStd::vector<Shape*>, QPaintEvent*);

        virtual double getArea() const; // Default implementation for getArea()

        virtual double getPerimeter() const; // Default implementation for getPerimeter()

        int getId() const; // get id

        void setId(int i);


        // virtual setShape() = 0; // Needs implementation later

        // virtual void draw() = 0;   // Will draw the shape on the window area

    //virtual void drawShape(QPainter & painter);   // Will draw the shape on the window area

};
#endif // SHAPE_H
