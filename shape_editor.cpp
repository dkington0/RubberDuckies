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
    QDialog* dialog = new QDialog();
    dialog->setMinimumWidth(680);
    dialog->setMinimumHeight(290);
    dialog->setMaximumWidth(680);
    dialog->setMaximumHeight(290);

    dialog->setWindowTitle("Shape Editor");

    createTypeGroupBox(dialog);
    createHintsGroupBox(dialog);
    createDimeGroupBox(dialog);

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

    QTimer *timer = new QTimer(typeGroupBox);
    // connect(timer, &QTimer::timeout, typeGroupBox, QOverload<>::of(&flagCheck()));
    timer->start(1000);
}

void shape_Editor::createHintsGroupBox(QDialog* dia)
{
    hintsGroupBox = new QGroupBox(dia);
    hintsGroupBox->setTitle("Shape Hints");
    hintsGroupBox->move(220, 0);
    hintsGroupBox->setMinimumHeight(250);
    hintsGroupBox->setMinimumWidth(220);
    hintsGroupBox->setMaximumWidth(220);
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

    // layout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    // layout->setAlignment(Qt::Align);
    //layout->addWidget(penColorBox);
    // layout->setFormAlignment(Qt::AlignLeft);

    hintsGroupBox->setLayout(layout);
}

void shape_Editor::createDimeGroupBox(QDialog* dia)
{
    dimeGroupBox = new QGroupBox(dia);
    dimeGroupBox->setTitle("Shape Dimensions");
    dimeGroupBox->move(450, 0);
    dimeGroupBox->setMinimumHeight(250);
    dimeGroupBox->setMinimumWidth(200);
    dimeGroupBox->setMaximumWidth(200);
    dimeGroupBox->setMaximumHeight(250);
    dimeGroupBox->setAlignment(Qt::AlignLeft);

    QFormLayout *layout = new QFormLayout(dimeGroupBox);

    if (LineType == flag)
    {
        QSpinBox* posX1 = new QSpinBox(dia);
        QSpinBox* posY1 = new QSpinBox(dia);
        QSpinBox* posX2 = new QSpinBox(dia);
        QSpinBox* posY2 = new QSpinBox(dia);

        layout->addRow(new QLabel(tr("Position X1:")), posX1);
        layout->addRow(new QLabel(tr("Position Y1:")), posY1);
        layout->addRow(new QLabel(tr("Position X2:")), posX2);
        layout->addRow(new QLabel(tr("Position Y2:")), posY2);

    }
    else if (PolylineType == flag)
    {
        QSpinBox* numPoints = new QSpinBox(dia);

        layout->addRow(new QLabel(tr("Number of Points:")), numPoints);

    }
    else if (PolygonType == flag)
    {

    }
    else if (RectangleType == flag)
    {

    }
    else if (SquareType == flag)
    {

    }
    else if (EllipseType == flag)
    {

    }
    else if (CircleType == flag)
    {

    }
    else if (TextType == flag)
    {

    }

    layout->setAlignment(Qt::AlignLeft);
    dimeGroupBox->setLayout(layout);
}

QComboBox* shape_Editor::createComboBox(QGroupBox* box)
{
    QComboBox *comboBox = new QComboBox(box);
    // connect(checkBox, &QGroupBox::clicked, this);
    return comboBox;
}

void shape_Editor::signalCheck()
{
    if (lineButton->isChecked())
        flag = LineType;
    else if (polylineButton->isChecked())
        flag = PolylineType;
    else if (polygonButton->isChecked())
        flag = PolygonType;
    else if (rectangleButton->isChecked())
        flag = RectangleType;
    else if (squareButton->isChecked())
        flag = SquareType;
    else if (ellipseButton->isChecked())
        flag = EllipseType;
    else if (circleButton->isChecked())
        flag = CircleType;
    else if (textButton->isChecked())
        flag = TextType;

    // emit flag;
}
