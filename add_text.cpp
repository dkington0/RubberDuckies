#include "add_text.h"
#include "ui_add_text.h"

add_Text::add_Text(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_Text)
{
    ui->setupUi(this);
}

add_Text::~add_Text()
{
    delete ui;
}
