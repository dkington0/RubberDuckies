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
void Shape::setValue(int value)
{
    if(value !=m_value){
        m_value = value;
        emit valueChanged(value);
    }
}
// virtual void setPen()
// {

// }

// virtual void setBrush()
// {

// }
