#include "add_linepoly.h"
#include "ui_add_linepoly.h"

add_LinePoly::add_LinePoly(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_LinePoly)
{
    ui->setupUi(this);
}

add_LinePoly::~add_LinePoly()
{
    delete ui;
}
