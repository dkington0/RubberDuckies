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

void Shape::setPen()
{
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::green);
    pen.setWidth(3);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::BevelJoin);

    this->setJoinStyle(Qt::BevelJoin;)
    update();

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
