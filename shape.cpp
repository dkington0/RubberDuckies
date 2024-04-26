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

virtual void setPen()
{

}

virtual void setBrush()
{

}
