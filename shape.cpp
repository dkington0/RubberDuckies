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

void Shape::setPen(const QColor &color, qreal width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join)
{
    pen.setColor(color);
    pen.setWidth(width);
    pen.setStyle(style);
    pen.setCapStyle(cap);
    pen.setJoinStyle(join);
}

void Shape::setBrush(QBrush b)
{
    brush = b;
}

QPen& Shape::getPen()
{
    return pen;
}

QBrush& Shape::getBrush()
{
    return brush;
}
