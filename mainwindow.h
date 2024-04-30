#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "QPushButton"

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
    int shapeValue() const { return m_value; }

private slots:
    void on_login_clicked();
    virtual void paintEvent(QPaintEvent *event);

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    Ui::MainWindow *ui;
    bool login_tracker;
    int m_value;
};


#endif // MAINWINDOW_H


