#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "shape_editor.h"
#include "text_editor.h"

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

    void on_contactUsButton_clicked();

    void on_shape_editor_Button_clicked();

    void on_text_editor_Button_clicked();

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    Ui::MainWindow *ui;
    bool login_tracker;
    int m_value;
    shape_Editor *Shape_Editor;
    Text_Editor *text_Editor;
};


#endif // MAINWINDOW_H


