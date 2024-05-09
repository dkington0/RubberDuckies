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

bool Shape::operator==(const Shape& other) const // overloaded equality operator
{
    return (this == &other); // compare values
}


bool Shape::operator<(const Shape& other) const // overloaded less than operator
{
    return (this < &other); // compare values
}


void Shape::setPen(QPen p)
{
    /*
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::green);
    pen.setWidth(3);
    pen.setCapStyle(Qt::SquareCap);
    pen.setJoinStyle(Qt::BevelJoin);
    */

    pen = p;
    update();
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


// double Shape::getArea() const
// {
//     return 0; // Default implementation: 0 area for all shapes
// }

// double Shape::getPerimeter() const
// {
//     return 0; // Default implementation: 0 perimeter for all shapes
// }
