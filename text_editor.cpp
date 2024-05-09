#include "text_editor.h"
#include "ui_text_editor.h"

Text_Editor::Text_Editor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Text_Editor)
{
    ui->setupUi(this);
}

Text_Editor::~Text_Editor()
{
    delete ui;
}
