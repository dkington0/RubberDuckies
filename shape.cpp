#include "shape.h"
#include "./ui_shape.h"

Shape::Shape(QWidget *parent)
    : MainWindow(parent)
    , ui(new Ui::Shape)
{
    ui->setupUi(this);
}

Shape::~Shape()
{
    delete ui;
}

void Shape::setPen(const QColor &color, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join)
{
    pen.setColor(color);
    pen.setStyle(style);
    pen.setCapStyle(cap);
    pen.setJoinStyle(join);
}
// virtual void setPen()
// {

// }

void Shape::setBrush(const QColor &color, Qt::BrushStyle style)
{
    brush.setColor(color);
    brush.setStyle(style);
}

QPen& Shape::getPen()
{
    return pen;
}
