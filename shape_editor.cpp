#include "shape_editor.h"
#include "ui_shape_editor.h"

shape_Editor::shape_Editor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::shape_Editor)
{
    ui->setupUi(this);
}

shape_Editor::~shape_Editor()
{
    delete ui;
}

void shape_Editor::on_push_Text_Button_clicked()//open text adder
{
    text_Editor = new add_Text(this);
    text_Editor->show();
}


void shape_Editor::on_push_Polygon_Button_clicked()
{
    AddPolygon = new add_Polygon(this);
    AddPolygon->show();
}


void shape_Editor::on_push_Elipse_Button_clicked()
{
    AddCircElip = new add_CircElip(this);
    AddCircElip->show();
}




void shape_Editor::on_push_Circ_Button_clicked()
{
    AddCircElip = new add_CircElip(this);
    AddCircElip->show();
}


void shape_Editor::on_push_Rec_Button_clicked()
{
    AddSquRec = new add_SquRec(this);
    AddSquRec->show();
}


void shape_Editor::on_push_Squ_Button_clicked()
{
    AddSquRec = new add_SquRec(this);
    AddSquRec->show();
}


void shape_Editor::on_push_Polyline_Button_clicked()
{
    AddLinePoly = new add_LinePoly(this);
    AddLinePoly->show();
}


void shape_Editor::on_push_Line_Button_clicked()
{
    AddLinePoly = new add_LinePoly(this);
    AddLinePoly->show();
}

