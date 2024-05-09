#ifndef SHAPE_H
#define SHAPE_H

#include "MainWindow.h"
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
        static int num_shapes;

        Shape(QWidget *parent = nullptr);

        virtual ~Shape();

        virtual void paintEvent(QPaintEvent* event)=0;

        Shape(const Shape&) = delete; // disable copy constructor

        Shape& operator=(const Shape&) = delete; // disable assignment operator

        bool operator==(const Shape& other) const; // overloaded equality operator

        bool operator<(const Shape& other) const; // overloaded less than operator

        void setPen(QPen p);

        QFont& getFont();
        //void setPen(); //Dropdown to select different pen options

        QPen& getPen();

        virtual double getArea() const; // Default implementation for getArea()

        virtual double getPerimeter() const; // Default implementation for getPerimeter()


        // virtual setShape() = 0; // Needs implementation later

        // virtual void draw() = 0;   // Will draw the shape on the window area

    //virtual void drawShape(QPainter & painter);   // Will draw the shape on the window area

};
#endif // SHAPE_H
