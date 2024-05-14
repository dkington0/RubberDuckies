#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include "QGroupBox"
#include "contact_us.h"
#include "file_parser.h"
#include "vector.h"
#include "sort.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), login_tracker {false}
{
    ui->setupUi(this);

    ui->pushButton_7->hide();
    ui->shape_editor_Button->hide();
    ui->sortShapes->hide();
    ui->list->hide();
    if (!ui->groupBox->isHidden()) {
        testimonial1 = new QLabel(this);
        testimonial1->setText("Rubber Duckies is the best company ever! ~User230725");
        testimonial1->setGeometry(10,-60,400,200);
        testimonial2 = new QLabel(this);
        testimonial2->setText("Great customization options! Good job Rubber Duckies! ~User493683");
        testimonial2->setGeometry(10,-40,450,200);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //QPainter myText(this);
    //myText.drawText(QPoint(20, 30), "Test text sample");
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

    if (((username == "admin") && (password == "password"))||((username == "user") && (password == "password")))  {
        QMessageBox::information(this,"Login", "validated successfully");
        if ((username == "admin") && (password == "password")) {
            ui->shape_editor_Button->setEnabled(true);
            ui->pushButton_7->setEnabled(true);
        }
        loginSet(true);
        ui->groupBox->close();
        setValue(true);

        ui->pushButton_7->show();
        ui->shape_editor_Button->show();
        ui->sortShapes->show();
        ui->list->show();

        testimonial1->close();
        testimonial2->close();

    }
    /*
    else if (username == "user" && password == "password"){
        QMessageBox::information(this,"Login", "validated successfully");
        loginSet(true);
        ui->groupBox->close();
        setValue(true);
    }
    */
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
    Shape_Editor->shape_editor_clicked();
}



void MainWindow::on_sortShapes_clicked()
{
    QString directory_path = QApplication::applicationDirPath();
    myStd::vector<Shape*> shapes; // create vector

    read_file(directory_path.toStdString(), shapes);

    // Sort by ID and write to file
    sort::sortID(shapes);
    sort::write(shapes, (directory_path + "/sorted_shapes_id.txt").toStdString());

    // Sort by Area and write to file
    sort::sortArea(shapes);
    sort::write(shapes, (directory_path + "/sorted_shapes_area.txt").toStdString());

    // Sort by Perimeter and write to file
    sort::sortPerimeter(shapes);
    sort::write(shapes, (directory_path + "/sorted_shapes_perimeter.txt").toStdString());

    // Clear the text box before displaying new content
    ui->list->clear();

    // Display each sorted list
    displayText(directory_path + "/sorted_shapes_id.txt", "Sorted by ID:");
    displayText(directory_path + "/sorted_shapes_area.txt", "Sorted by Area:");
    displayText(directory_path + "/sorted_shapes_perimeter.txt", "Sorted by Perimeter:");
}



void MainWindow::displayText(const QString &filename, const QString &title)
{
    QFile file(filename); // open file
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open file: " + filename); // check to open file
        return;
    }
    QTextStream in(&file); // create text stream object
    QString content = in.readAll(); // read whole file

    // output
    ui->list->appendPlainText(title + "\n" + content + "\n");
    ui->list->setReadOnly(true);
}

