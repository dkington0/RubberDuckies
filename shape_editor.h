#ifndef SHAPE_EDITOR_H
#define SHAPE_EDITOR_H

#include <QDialog>
#include "add_Text.h"
#include "add_circelip.h"
#include "add_linepoly.h"
#include "add_polygon.h"
#include "add_squrec.h"

namespace Ui {
class shape_Editor;
}

class shape_Editor : public QDialog
{
    Q_OBJECT

public:
    explicit shape_Editor(QWidget *parent = nullptr);
    ~shape_Editor();

private slots:
    void on_push_Text_Button_clicked(); //Text Editor


    void on_push_Polygon_Button_clicked();

    void on_push_Elipse_Button_clicked();

    void on_push_Circ_Button_clicked();

    void on_push_Rec_Button_clicked();

    void on_push_Squ_Button_clicked();

    void on_push_Polyline_Button_clicked();

    void on_push_Line_Button_clicked();

private:
    Ui::shape_Editor *ui;
    add_Text *text_Editor;
    add_CircElip *AddCircElip;
    add_LinePoly *AddLinePoly;
    add_Polygon *AddPolygon;
    add_SquRec *AddSquRec;
};

#endif // SHAPE_EDITOR_H
