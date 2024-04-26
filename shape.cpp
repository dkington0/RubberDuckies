#include "shape.h"
#include "./ui_shape.h"

Shape::Shape(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Shape)
{
    ui->setupUi(this);
}

Shape::~Shape()
{
    delete ui;
}

