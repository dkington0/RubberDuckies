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
        int m_value;
    public:
        Shape(QWidget *parent = nullptr);
        ~Shape();
        int shapeValue() const { return m_value; }
        virtual void paintEvent(QPaintEvent* event
            )=0;
       // virtual void setPen()=0;
       // virtual void setBrush()=0;
       // virtual void DrawShape()=0;   // Will draw the shape on the window area
       // virtual void SetShape()=0;    // Set the values of the shape
    public slots:
        void setValue(int value);
    signals:
        void valueChanged(int newValue);



};
#endif // SHAPE_H
