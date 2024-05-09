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
        Shape& operator=(const Shape&) = delete;
        void setPen(QPen p);
        QFont& getFont();
        //void setPen(); //Dropdown to select different pen options

        QPen& getPen();

        // virtual setShape() = 0; // Needs implementation later

        // virtual void draw() = 0;   // Will draw the shape on the window area

    //virtual void drawShape(QPainter & painter);   // Will draw the shape on the window area

};
#endif // SHAPE_H
