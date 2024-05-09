#include "add_circelip.h"
#include "ui_add_circelip.h"

add_CircElip::add_CircElip(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_CircElip)
{
    ui->setupUi(this);
}

add_CircElip::~add_CircElip()
{
    delete ui;
}
