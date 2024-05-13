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

void shape_Editor::shape_editor_clicked()
{
    // const QSize btnSize = QSize(50, 50);

    QDialog* dialog = new QDialog();
    dialog->setMinimumWidth(650);
    dialog->setMinimumHeight(290);
    dialog->setMaximumWidth(650);
    dialog->setMaximumHeight(290);

    dialog->setWindowTitle("Shape Editor");

    createTypeGroupBox(dialog);
    createHintsGroupBox(dialog);

    utilityButton = new QDialogButtonBox(QDialogButtonBox::Apply | QDialogButtonBox::Discard | QDialogButtonBox::Cancel);

    connect(utilityButton, SIGNAL(accepted()), dialog, SLOT(accept()));
    connect(utilityButton, SIGNAL(rejected()), dialog, SLOT(reject()));

    utilityButton->setParent(dialog);

    QHBoxLayout *bottomLayout = new QHBoxLayout(dialog);
    bottomLayout->addStretch();
    bottomLayout->setAlignment(Qt::AlignBottom);
    bottomLayout->addWidget(utilityButton);

    QHBoxLayout *mainLayout = new QHBoxLayout(dialog);
    mainLayout->addWidget(typeGroupBox);
    mainLayout->addWidget(hintsGroupBox);
    mainLayout->addLayout(bottomLayout);
    dialog->setLayout(mainLayout);

    typeGroupBox->show();

    dialog->exec();
}

QRadioButton* shape_Editor::createRadioButton(const QString &text)
{
    QRadioButton *button = new QRadioButton(text);

    return button;
}

void shape_Editor::createTypeGroupBox(QDialog* dia)
{
    typeGroupBox = new QGroupBox(dia);
    typeGroupBox->setTitle("Shape Type");
    typeGroupBox->move(30,0);
    typeGroupBox->setMinimumHeight(250);
    typeGroupBox->setMinimumWidth(180);
    typeGroupBox->setMaximumWidth(180);
    typeGroupBox->setMaximumHeight(250);
    typeGroupBox->setAlignment(Qt::AlignLeft);

    lineButton = createRadioButton("Line");
    polylineButton = createRadioButton(tr("Polyline"));
    polygonButton = createRadioButton(tr("Polygon"));
    rectangleButton = createRadioButton(tr("Rectangle"));
    squareButton = createRadioButton(tr("Square"));
    ellipseButton = createRadioButton(tr("Ellipse"));
    circleButton = createRadioButton(tr("Circle"));
    textButton = createRadioButton(tr("Text"));
    lineButton->setChecked(true);

    QGridLayout *layout = new QGridLayout(dia);
    layout->addWidget(lineButton, 0, 0);
    layout->addWidget(polylineButton, 1, 0);
    layout->addWidget(polygonButton, 2, 0);
    layout->addWidget(rectangleButton, 3, 0);
    layout->addWidget(squareButton, 0, 1);
    layout->addWidget(ellipseButton, 1, 1);
    layout->addWidget(circleButton, 2, 1);
    layout->addWidget(textButton, 3, 1);
    typeGroupBox->setLayout(layout);
}

void shape_Editor::createHintsGroupBox(QDialog* dia)
{
    hintsGroupBox = new QGroupBox(dia);
    hintsGroupBox->setTitle("Shape Hints");
    hintsGroupBox->move(220, 0);
    hintsGroupBox->setMinimumHeight(250);
    hintsGroupBox->setMinimumWidth(420);
    hintsGroupBox->setMaximumWidth(420);
    hintsGroupBox->setMaximumHeight(250);
    hintsGroupBox->setAlignment(Qt::AlignLeft);

    penColorBox = createComboBox(hintsGroupBox);
    penStyleBox = createComboBox(hintsGroupBox);
    penCapStyleBox = createComboBox(hintsGroupBox);
    penJointStyleBox = createComboBox(hintsGroupBox);
    brushColorBox = createComboBox(hintsGroupBox);
    brushStyleBox = createComboBox(hintsGroupBox);
    penWidthBox = new QSpinBox(hintsGroupBox);

    // QLabel* penColorLabel = new QLabel(penColorBox);
    // penColorLabel->setBuddy(penColorBox);

    penColorBox->addItem("White");
    penColorBox->addItem("Black");
    penColorBox->addItem("Red");
    penColorBox->addItem("Green");
    penColorBox->addItem("Blue");
    penColorBox->addItem("Cyan");
    penColorBox->addItem("Magenta");
    penColorBox->addItem("Yellow");
    penColorBox->addItem("Gray");

    penStyleBox->addItem("Solid Line");
    penStyleBox->addItem("Dash Line");
    penStyleBox->addItem("Dot Line");
    penStyleBox->addItem("Dot Dash Line");

    penCapStyleBox->addItem("Flat Cap");
    penStyleBox->addItem("Square Cap");
    penStyleBox->addItem("Round Cap");

    penJointStyleBox->addItem("Miter Joint");
    penJointStyleBox->addItem("Bevel Joint");
    penJointStyleBox->addItem("Round Joint");

    brushColorBox->addItem("White");
    brushColorBox->addItem("Black");
    brushColorBox->addItem("Red");
    brushColorBox->addItem("Green");
    brushColorBox->addItem("Blue");
    brushColorBox->addItem("Cyan");
    brushColorBox->addItem("Magenta");
    brushColorBox->addItem("Yellow");
    brushColorBox->addItem("Gray");

    brushStyleBox->addItem("Solid Pattern");
    brushStyleBox->addItem("Horizontal Pattern");
    brushStyleBox->addItem("Vertical Pattern");

    QFormLayout *layout = new QFormLayout(dia);

    layout->addRow(new QLabel(tr("Pen Color:")), penColorBox);
    layout->addRow(new QLabel(tr("Pen Style:")), penStyleBox);
    layout->addRow(new QLabel(tr("Pen Cap Style:")), penCapStyleBox);
    layout->addRow(new QLabel(tr("Pen Joint Style:")), penJointStyleBox);
    layout->addRow(new QLabel(tr("Brush Color:")), brushColorBox);
    layout->addRow(new QLabel(tr("Brush Style:")), brushStyleBox);
    layout->addRow(new QLabel(tr("Pen Width:")), penWidthBox);
    layout->setHorizontalSpacing(10);
    layout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

    hintsGroupBox->setLayout(layout);
}

void shape_Editor::createShapeBox(QGroupBox* box)
{
    QGroupBox* innerBox = new QGroupBox(box);
    hintsGroupBox->setTitle("Shape Dimensions");
    hintsGroupBox->move(420, 0);
    hintsGroupBox->setMinimumHeight(100);
    hintsGroupBox->setMinimumWidth(100);
    hintsGroupBox->setMaximumWidth(100);
    hintsGroupBox->setMaximumHeight(100);
    hintsGroupBox->setAlignment(Qt::AlignRight);

    if (lineButton->isChecked())
    {
        QSpinBox* posX1 = new QSpinBox(box);
        QSpinBox* posY1 = new QSpinBox(box);
        QSpinBox* posX2 = new QSpinBox(box);
        QSpinBox* posY2 = new QSpinBox(box);

        QVBoxLayout *bottomLayout = new QVBoxLayout(box);
        bottomLayout->addWidget(posX1);
        bottomLayout->addWidget(posY1);
        bottomLayout->addWidget(posX2);
        bottomLayout->addWidget(posY2);
        bottomLayout->setAlignment(Qt::AlignRight);
        innerBox->setLayout(bottomLayout);
    }
    else if (polylineButton->isChecked())
    {

    }
    else if (polygonButton->isChecked())
    {

    }
    else if (rectangleButton->isChecked())
    {

    }
    else if (squareButton->isChecked())
    {

    }
    else if (ellipseButton->isChecked())
    {

    }
    else if (circleButton->isChecked())
    {

    }
    else if (textButton->isChecked())
    {

    }

}

QComboBox* shape_Editor::createComboBox(QGroupBox* box)
{
    QComboBox *comboBox = new QComboBox(box);
    // connect(checkBox, &QGroupBox::clicked, this);
    return comboBox;
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

