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
#include <QTimer>
//#include "canvas.h"


namespace Ui {
class shape_Editor;
}

class shape_Editor : public QDialog
{
    Q_OBJECT

public:
    explicit shape_Editor(QWidget *parent = nullptr);
    ~shape_Editor();

    enum shapeType{ LineType, PolylineType, PolygonType, RectangleType, SquareType, EllipseType, CircleType, TextType };

    void createTypeGroupBox(QDialog* dia);
    void createHintsGroupBox(QDialog* dia);
    void createDimeGroupBox(QDialog* dia);

    QRadioButton* createRadioButton(const QString &text);
    QComboBox* createComboBox(QGroupBox* box);

    void signalCheck();

public slots:
    void shape_editor_clicked();

private:
    Ui::shape_Editor *ui;

    int flag;

    QGroupBox* typeGroupBox;
    QGroupBox* hintsGroupBox;
    QGroupBox* dimeGroupBox;

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
};

#endif // SHAPE_EDITOR_H
