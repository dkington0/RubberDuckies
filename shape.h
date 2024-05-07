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
        static int num_shapes;

        Shape(QWidget *parent = nullptr);
        virtual ~Shape();

        // virtual void paintEvent(QPaintEvent* event)=0;
        void setPen(QPen p);
        QFont& getFont();
        QPen& getPen();
        // virtual setShape() = 0; // Needs implementation later
};
#endif // SHAPE_H
