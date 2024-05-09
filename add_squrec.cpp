#include "add_squrec.h"
#include "ui_add_squrec.h"

add_SquRec::add_SquRec(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_SquRec)
{
    ui->setupUi(this);
}

add_SquRec::~add_SquRec()
{
    delete ui;
}
