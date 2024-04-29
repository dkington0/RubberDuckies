#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
#include "QGroupBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), login_tracker {false}
{
    ui->setupUi(this);
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
        ui->groupBox->hide();
    }
    else
        loginSet(false);
        //QMessageBox::warning(this, "Login", "Username and password incorrect");
        //return false;
}
bool MainWindow::loginGet()
{
    return login_tracker;
}

