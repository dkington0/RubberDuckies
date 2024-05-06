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

void Shape::setPen(QPen p)
{
    pen = p;
}

QPen& Shape::getPen()
{
    return pen;
}
void Shape::drawShape(QPainter &painter)
{
    painter.setPen(pen);
    painter.setBrush(brush);
}
