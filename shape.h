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
        QBrush brush;

    public:
        Shape(QWidget *parent = nullptr);
        virtual ~Shape();

        virtual void paintEvent(QPaintEvent* event)=0;
        void setPen(QPen p); //Dropdown to select different pen options
        QPen& getPen();
        // virtual void draw() = 0;   // Will draw the shape on the window area

    virtual void drawShape(QPainter & painter);   // Will draw the shape on the window area
};
#endif // SHAPE_H
