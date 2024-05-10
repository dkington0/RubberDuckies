#ifndef SHAPE_EDITOR_H
#define SHAPE_EDITOR_H

#include <QDialog>
#include <QButtonGroup>
#include <QPushButton>
#include <QHBoxLayout>
#include "canvas.h"


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

    void uiSetup()
    {
        win = new QWidget;
        QPushButton* lineButton = new QPushButton("Line");
        QPushButton* polylineButton = new QPushButton("Polyline");
        QPushButton* polygoneButton = new QPushButton("Polygon");
        QPushButton* rectangleButton = new QPushButton("Rectangle");
        QPushButton* squareButton = new QPushButton("Square");
        QPushButton* ellipseButton = new QPushButton("Ellipse");
        QPushButton* circleButton = new QPushButton("Circle");
        QPushButton* textButton = new QPushButton("Text");

        layout = new QHBoxLayout(win);
        layout->addWidget(lineButton);
        layout->addWidget(polylineButton);
        layout->addWidget(polygoneButton);
        layout->addWidget(rectangleButton);
        layout->addWidget(squareButton);
        layout->addWidget(ellipseButton);
        layout->addWidget(circleButton);
        layout->addWidget(textButton);

    }

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
    QWidget* win;
    QHBoxLayout* layout;


    add_Text *text_Editor;
    add_CircElip *AddCircElip;
    add_LinePoly *AddLinePoly;
    add_Polygon *AddPolygon;
    add_SquRec *AddSquRec;
};

#endif // SHAPE_EDITOR_H
