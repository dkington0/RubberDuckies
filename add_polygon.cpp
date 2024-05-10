#include "add_polygon.h"
#include "ui_add_polygon.h"

add_Polygon::add_Polygon(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_Polygon)
{
    ui->setupUi(this);
}

add_Polygon::~add_Polygon()
{
    delete ui;
}
