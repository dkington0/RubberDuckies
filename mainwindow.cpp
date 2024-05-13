#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include "QGroupBox"
#include "contact_us.h"
#include "vector.h"
#include "sort.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), login_tracker {false}
{
    ui->setupUi(this);

    QLabel *testimonial1 = new QLabel(this);
    testimonial1->setText("Rubber Duckies is the best company ever! ~User230725");
    testimonial1->setGeometry(1300,100,400,200);
    QLabel *testimonial2 = new QLabel(this);
    testimonial2->setText("Great customization options! Good job Rubber Duckies! ~User493683");
    testimonial2->setGeometry(1300,125,450,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter myText(this);
    myText.drawText(QPoint(20, 30), "Test text sample");
    // myText.set = "";

}

void MainWindow::loginSet(bool l)
{
    login_tracker = l;
}

void MainWindow::on_login_clicked()
{
    QString username = ui->lineEdit_user->text();
    QString password = ui->lineEdit_pass->text();

    if (username == "admin" && password == "password"){
        QMessageBox::information(this,"Login", "validated successfully");
        loginSet(true);
        ui->groupBox->close();
        setValue(true);
    }
    else
    {
        loginSet(false);
        setValue(false);
        //QMessageBox::warning(this, "Login", "Username and password incorrect");
        //return false;
    }
}

bool MainWindow::loginGet()
{
    return login_tracker;
}

void MainWindow::setValue(int value)
{
    if(value !=m_value){
        m_value = value;
        emit valueChanged(value);
    }
}



void MainWindow::on_contactUsButton_clicked()
{
    (new ContactUs(this))->show();
}


void MainWindow::on_shape_editor_Button_clicked()
{
    Shape_Editor = new shape_Editor(this);
    Shape_Editor->show();

}



void MainWindow::on_sortShapes_clicked()
{
    myStd::vector<Shape*> shapes; // create vector
    sort::sortID(shapes); // sort id
    sort::sortArea(shapes); // sort area
    sort::sortPerimeter(shapes); // sort perimeter

    QString filename = "sorted_shapes.txt"; // assign QString file name

    sort::write(shapes, "sorted_shapes.txt"); // write to file

    displayText(filename); // call displayText with file
}


void MainWindow::displayText(const QString &filename)
{
    QFile file(filename); // open file
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open file: " + filename); // check to open file
        return;
    }
    QTextStream in(&file); // create text stream object

    ui->list->setPlainText(in.readAll()); // read in entire file

    ui->list->setReadOnly(true); // prevent user from typing
    file.close();
}

