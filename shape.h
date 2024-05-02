#ifndef SHAPE_H
#define SHAPE_H

#include "MainWindow.h"
#include <QPainter>

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
        QPainter brush;

    public:
        Shape(QWidget *parent = nullptr);
        ~Shape();

        virtual void paintEvent(QPaintEvent* event)=0;
        virtual void setPen();
        virtual void setBrush();
        // virtual void draw() = 0;   // Will draw the shape on the window area

};
#endif // SHAPE_H
