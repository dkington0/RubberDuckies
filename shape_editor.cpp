#include "shape_editor.h"
#include "qlineedit.h"
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
    dialog = new QDialog(this);
    dialog->setMinimumWidth(700);
    dialog->setMinimumHeight(330);
    dialog->setMaximumWidth(700);
    dialog->setMaximumHeight(330);

    dialog->setWindowTitle("Shape Editor");

    createTypeGroupBox();
    createHintsGroupBox();
    createDimeGroupBox();

    utilityButton = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Apply
    | QDialogButtonBox::Discard | QDialogButtonBox::Cancel);

    utilityButton->addButton("Add Shape", QDialogButtonBox::AcceptRole);

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

    connect(button, &QRadioButton::clicked, this, &shape_Editor::updateDimeBox);

    return button;
}

void shape_Editor::createTypeGroupBox()
{
    typeGroupBox = new QGroupBox(dialog);
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

    QGridLayout *layout = new QGridLayout(dialog);
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

void shape_Editor::createHintsGroupBox()
{
    hintsGroupBox = new QGroupBox(dialog);
    hintsGroupBox->setTitle("Shape Hints");
    hintsGroupBox->move(220, 0);
    hintsGroupBox->setMinimumHeight(250);
    hintsGroupBox->setMinimumWidth(220);
    hintsGroupBox->setMaximumWidth(220);
    hintsGroupBox->setMaximumHeight(250);
    hintsGroupBox->setAlignment(Qt::AlignLeft);

    penColorBox = createComboBox();
    penStyleBox = createComboBox();
    penCapStyleBox = createComboBox();
    penJointStyleBox = createComboBox();
    brushColorBox = createComboBox();
    brushStyleBox = createComboBox();
    penWidthBox = new QSpinBox();

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

    QFormLayout *layout = new QFormLayout(dialog);

    layout->addRow(new QLabel(tr("Pen Color:")), penColorBox);
    layout->addRow(new QLabel(tr("Pen Style:")), penStyleBox);
    layout->addRow(new QLabel(tr("Pen Cap Style:")), penCapStyleBox);
    layout->addRow(new QLabel(tr("Pen Joint Style:")), penJointStyleBox);
    layout->addRow(new QLabel(tr("Brush Color:")), brushColorBox);
    layout->addRow(new QLabel(tr("Brush Style:")), brushStyleBox);
    layout->addRow(new QLabel(tr("Pen Width:")), penWidthBox);
    // layout->setHorizontalSpacing(5);

    // layout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    // layout->setAlignment(Qt::Align);
    //layout->addWidget(penColorBox);
    // layout->setFormAlignment(Qt::AlignLeft);

    hintsGroupBox->setLayout(layout);
}

void shape_Editor::createDimeGroupBox()
{
    dimeGroupBox = new QGroupBox(dialog);
    dimeGroupBox->setTitle("Shape Dimensions");
    dimeGroupBox->move(450, 0);
    dimeGroupBox->setMinimumHeight(280);
    dimeGroupBox->setMinimumWidth(220);
    dimeGroupBox->setMaximumWidth(220);
    dimeGroupBox->setMaximumHeight(280);
    dimeGroupBox->setAlignment(Qt::AlignLeft);

    QFormLayout* layout = changeDimeBox();
    dimeGroupBox->setLayout(layout);
}

QFormLayout* shape_Editor::changeDimeBox()
{
    if (LineType == flag)
    {
        QSpinBox* posX1 = new QSpinBox(dialog);
        QSpinBox* posY1 = new QSpinBox(dialog);
        QSpinBox* posX2 = new QSpinBox(dialog);
        QSpinBox* posY2 = new QSpinBox(dialog);

        QFormLayout* layout = new QFormLayout(dimeGroupBox);

        layout->addRow(new QLabel(tr("Position X1:")), posX1);
        layout->addRow(new QLabel(tr("Position Y1:")), posY1);
        layout->addRow(new QLabel(tr("Position X2:")), posX2);
        layout->addRow(new QLabel(tr("Position Y2:")), posY2);

        return layout;
    }
    else if (PolylineType == flag)
    {
        QSpinBox* pointX1 = new QSpinBox(dialog);
        QSpinBox* pointY1 = new QSpinBox(dialog);
        QSpinBox* pointX2 = new QSpinBox(dialog);
        QSpinBox* pointY2 = new QSpinBox(dialog);
        QSpinBox* pointX3 = new QSpinBox(dialog);
        QSpinBox* pointY3 = new QSpinBox(dialog);
        QSpinBox* pointX4 = new QSpinBox(dialog);
        QSpinBox* pointY4 = new QSpinBox(dialog);

        QFormLayout* layout = new QFormLayout(dimeGroupBox);

        layout->addRow(new QLabel(tr("X1:")), pointX1);
        layout->addRow(new QLabel(tr("Y1:")), pointY1);
        layout->addRow(new QLabel(tr("X2:")), pointX2);
        layout->addRow(new QLabel(tr("Y2:")), pointY2);
        layout->addRow(new QLabel(tr("X3:")), pointX3);
        layout->addRow(new QLabel(tr("Y3:")), pointY3);
        layout->addRow(new QLabel(tr("X4:")), pointX4);
        layout->addRow(new QLabel(tr("Y4:")), pointY4);

        return layout;
    }
    else if (PolygonType == flag)
    {
        QSpinBox* pointX1 = new QSpinBox(dialog);
        QSpinBox* pointY1 = new QSpinBox(dialog);
        QSpinBox* pointX2 = new QSpinBox(dialog);
        QSpinBox* pointY2 = new QSpinBox(dialog);
        QSpinBox* pointX3 = new QSpinBox(dialog);
        QSpinBox* pointY3 = new QSpinBox(dialog);
        QSpinBox* pointX4 = new QSpinBox(dialog);
        QSpinBox* pointY4 = new QSpinBox(dialog);

        QFormLayout* layout = new QFormLayout(dimeGroupBox);

        layout->addRow(new QLabel(tr("X1:")), pointX1);
        layout->addRow(new QLabel(tr("Y1:")), pointY1);
        layout->addRow(new QLabel(tr("X2:")), pointX2);
        layout->addRow(new QLabel(tr("Y2:")), pointY2);
        layout->addRow(new QLabel(tr("X3:")), pointX3);
        layout->addRow(new QLabel(tr("Y3:")), pointY3);
        layout->addRow(new QLabel(tr("X4:")), pointX4);
        layout->addRow(new QLabel(tr("Y4:")), pointY4);

        return layout;
    }
    else if (RectangleType == flag)
    {
        QSpinBox* x = new QSpinBox(dialog);
        QSpinBox* y = new QSpinBox(dialog);
        QSpinBox* width = new QSpinBox(dialog);
        QSpinBox* height = new QSpinBox(dialog);

        QFormLayout* layout = new QFormLayout(dimeGroupBox);

        layout->addRow(new QLabel(tr("X:")), x);
        layout->addRow(new QLabel(tr("Y:")), y);
        layout->addRow(new QLabel(tr("Width:")), width);
        layout->addRow(new QLabel(tr("Height:")), height);

        return layout;
    }
    else if (SquareType == flag)
    {
        QSpinBox* x = new QSpinBox(dialog);
        QSpinBox* y = new QSpinBox(dialog);
        QSpinBox* sides = new QSpinBox(dialog);

        QFormLayout* layout = new QFormLayout(dimeGroupBox);

        layout->addRow(new QLabel(tr("X:")), x);
        layout->addRow(new QLabel(tr("Y:")), y);
        layout->addRow(new QLabel(tr("Sides:")), sides);

        return layout;
    }
    else if (EllipseType == flag)
    {
        QSpinBox* x = new QSpinBox(dialog);
        QSpinBox* y = new QSpinBox(dialog);
        QSpinBox* width = new QSpinBox(dialog);
        QSpinBox* height = new QSpinBox(dialog);

        QFormLayout* layout = new QFormLayout(dimeGroupBox);

        layout->addRow(new QLabel(tr("X:")), x);
        layout->addRow(new QLabel(tr("Y:")), y);
        layout->addRow(new QLabel(tr("Width:")), width);
        layout->addRow(new QLabel(tr("Height:")), height);

        return layout;
    }
    else if (CircleType == flag)
    {
        QSpinBox* x = new QSpinBox(dialog);
        QSpinBox* y = new QSpinBox(dialog);
        QSpinBox* sides = new QSpinBox(dialog);

        QFormLayout* layout = new QFormLayout(dimeGroupBox);

        layout->addRow(new QLabel(tr("X:")), x);
        layout->addRow(new QLabel(tr("Y:")), y);
        layout->addRow(new QLabel(tr("Sides:")), sides);

        return layout;
    }
    else if (TextType == flag)
    {
        QSpinBox* x = new QSpinBox(dialog);
        QSpinBox* y = new QSpinBox(dialog);
        QSpinBox* width = new QSpinBox(dialog);
        QSpinBox* height = new QSpinBox(dialog);
        QLineEdit* text = new QLineEdit(dialog);
        QComboBox* textColor = new QComboBox(dialog);
        QComboBox* alignment = new QComboBox(dialog);
        QSpinBox* pointSize = new QSpinBox(dialog);
        QComboBox* font = new QComboBox(dialog);
        QComboBox* fontStyle = new QComboBox(dialog);
        QComboBox* fontWeight = new QComboBox(dialog);

        textColor->addItem("White");
        textColor->addItem("Black");
        textColor->addItem("Red");
        textColor->addItem("Green");
        textColor->addItem("Blue");
        textColor->addItem("Cyan");
        textColor->addItem("Magenta");
        textColor->addItem("Yellow");
        textColor->addItem("Gray");

        alignment->addItem("Align Center");
        alignment->addItem("Align Top");
        alignment->addItem("Align Bottom");
        alignment->addItem("Align Left");
        alignment->addItem("Align Right");

        font->addItem("Sans Serif");
        font->addItem("Helvetica");
        font->addItem("Serif");
        font->addItem("Times New Roman");
        font->addItem("Courier");
        font->addItem("Decorative");
        font->addItem("Monospace");
        font->addItem("Fantasy");
        font->addItem("Cursive");
        font->addItem("System Default");

        fontStyle->addItem("Normal");
        fontStyle->addItem("Italic");
        fontStyle->addItem("Oblique");

        fontWeight->addItem("Thin");
        fontWeight->addItem("Light");
        fontWeight->addItem("Normal");
        fontWeight->addItem("Medium");
        fontWeight->addItem("Demi Bold");
        fontWeight->addItem("Bold");

        QFormLayout* layout = new QFormLayout(dimeGroupBox);

        layout->addRow(new QLabel(tr("X:")), x);
        layout->addRow(new QLabel(tr("Y:")), y);
        layout->addRow(new QLabel(tr("Width:")), width);
        layout->addRow(new QLabel(tr("Height:")), height);
        layout->addRow(new QLabel(tr("Text:")), text);
        layout->addRow(new QLabel(tr("Text Color:")), textColor);
        layout->addRow(new QLabel(tr("Text Alignment:")), alignment);
        layout->addRow(new QLabel(tr("Point Size:")), pointSize);
        layout->addRow(new QLabel(tr("Font:")), font);
        layout->addRow(new QLabel(tr("Font Style:")), fontStyle);
        layout->addRow(new QLabel(tr("Font Weight:")), fontWeight);

        return layout;
    }

    return nullptr;
}

QComboBox* shape_Editor::createComboBox()
{
    QComboBox *comboBox = new QComboBox(hintsGroupBox);
    // connect(comboBox, &QComboBox::clicked, hintsGroupBox, &shape_Editor::updateDimeBox);
    return comboBox;
}

// Selecting the shape on the left updates the boxes on the right to
// the correct parameters
void shape_Editor::updateDimeBox()
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

    qDeleteAll(dimeGroupBox->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    delete dimeGroupBox->layout();

    QFormLayout* layout = changeDimeBox();
    dimeGroupBox->setLayout(layout);
}
