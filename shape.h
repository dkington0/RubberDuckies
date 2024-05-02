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

        // virtual void paintEvent(QPaintEvent* event)=0;
        void setPen(const QColor &color, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);
        void setBrush(const QColor &color, Qt::BrushStyle style);
        QPen& getPen();
        // virtual void draw() = 0;   // Will draw the shape on the window area

};
#endif // SHAPE_H
