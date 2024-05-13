#ifndef SHAPE_EDITOR_H
#define SHAPE_EDITOR_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QPalette>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QGroupBox>
#include <QComboBox>
#include <QFormLayout>
#include <QSpinBox>
//#include "canvas.h"


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

    void createTypeGroupBox(QDialog* dia);
    void createHintsGroupBox(QDialog* dia);
    void flagCheck();
    QRadioButton* createRadioButton(const QString &text);
    QComboBox* createComboBox(QGroupBox* box);
    void createShapeBox(QGroupBox* box);

    void uiSetup(QDialog *Menu)
    {
        // Menu = new
        // win = new QWidget;
        QDialogButtonBox* box = new QDialogButtonBox();
        box->addButton("Line", QDialogButtonBox::AcceptRole);
        box->addButton("Polyline", QDialogButtonBox::AcceptRole);
        box->addButton("Polygon", QDialogButtonBox::AcceptRole);
        box->addButton("Rectangle", QDialogButtonBox::AcceptRole);
        box->addButton("Squaree", QDialogButtonBox::AcceptRole);
        box->addButton("Ellipse", QDialogButtonBox::AcceptRole);
        box->addButton("Circle", QDialogButtonBox::AcceptRole);
        box->addButton("Text", QDialogButtonBox::AcceptRole);
        // QPushButton* QDialogButtonBox::addButton("Line", QDialogButtonBox::AcceptRole);
        // QDialogButtonBox* polylineButton = new QPushButton("Polyline");
        // QDialogButtonBox* polygoneButton = new QPushButton("Polygon");
        // QDialogButtonBox* rectangleButton = new QPushButton("Rectangle");
        // QDialogButtonBox* squareButton = new QPushButton("Square");
        // QDialogButtonBox* ellipseButton = new QPushButton("Ellipse");
        // QDialogButtonBox* circleButton = new QPushButton("Circle");
        // QDialogButtonBox* textButton = new QPushButton("Text");

        // layout = new QHBoxLayout(win);
        // layout->addWidget(lineButton);
        // layout->addWidget(polylineButton);
        // layout->addWidget(polygoneButton);
        // layout->addWidget(rectangleButton);
        // layout->addWidget(squareButton);
        // layout->addWidget(ellipseButton);
        // layout->addWidget(circleButton);
        // layout->addWidget(textButton);

    }

public slots:
    void shape_editor_clicked();

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

    QGroupBox *typeGroupBox;
    QGroupBox *hintsGroupBox;
    QDialogButtonBox* utilityButton;
    QComboBox* penColorBox;
    QComboBox* penStyleBox;
    QComboBox* penCapStyleBox;
    QComboBox* penJointStyleBox;
    QComboBox* brushColorBox;
    QComboBox* brushStyleBox;
    QSpinBox* penWidthBox;

    QRadioButton *lineButton;
    QRadioButton *polylineButton;
    QRadioButton *polygonButton;
    QRadioButton *rectangleButton;
    QRadioButton *squareButton;
    QRadioButton *ellipseButton;
    QRadioButton *circleButton;
    QRadioButton *textButton;

    add_Text *text_Editor;
    add_CircElip *AddCircElip;
    add_LinePoly *AddLinePoly;
    add_Polygon *AddPolygon;
    add_SquRec *AddSquRec;
};

#endif // SHAPE_EDITOR_H
