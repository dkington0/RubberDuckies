#include "shape.h"
#include "./ui_shape.h"

int Shape::num_shapes = 0;

Shape::Shape(QWidget *parent)
    : MainWindow(parent)
    , ui(new Ui::Shape)
{
    ui->setupUi(this);
    num_shapes++;
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

/*void Shape::drawShape(QPainter &painter)
{
    painter.setPen(pen);
    painter.setBrush(brush);
}*/
