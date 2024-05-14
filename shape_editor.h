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

    void createTypeGroupBox();
    void createHintsGroupBox();
    void createDimeGroupBox();

    QFormLayout* changeDimeBox();

    QRadioButton* createShapeButton(const QString &text);
    QComboBox* createPenComboBox();
    QComboBox* createDimeComboBox();
    QSpinBox* createDimeSpinBox();
    QSpinBox* createPenWidthSpinBox();
    QLineEdit* createDimeLineEdit();

public slots:
    void shape_editor_clicked();
    void updateDimeBox();

    QComboBox* createPenComboBox();
    QSpinBox* createPenWidthSpinBox();
    QComboBox* createDimeComboBox();
    QSpinBox* createDimeSpinBoxBox();
    QLineEdit* createDimeLineEdit();

private:
    Ui::shape_Editor *ui;

    int flag;

    QDialog* dialog;

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
