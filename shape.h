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

class Shape : public MainWindow
{
    Q_OBJECT
    private:
        Ui::Shape *ui;
        QPen pen;
        QBrush brush;

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
         * @param : event
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

        void drawShapes(myStd::vector<Shape>, QPaintEvent*);

        // virtual double getArea() const; // Default implementation for getArea()

        // virtual double getPerimeter() const; // Default implementation for getPerimeter()


        // virtual setShape() = 0; // Needs implementation later

        // virtual void draw() = 0;   // Will draw the shape on the window area

    //virtual void drawShape(QPainter & painter);   // Will draw the shape on the window area

};
#endif // SHAPE_H
