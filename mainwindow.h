#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool loginGet();

    void loginSet(bool l);

private slots:
    void on_login_clicked();
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    bool login_tracker;
};


#endif // MAINWINDOW_H


