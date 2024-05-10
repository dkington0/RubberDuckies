#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "shape_editor.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow widget constructor, for use with the parent QWidget
     * @param parent QWidget which calls this constructor
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief MainWindow default destructor
     */
    ~MainWindow();

    /**
     * @brief loginGet returns the status of the login_tracker member
     * @return boolean value of login_tracker member
     */
    bool loginGet();

    /**
     * @brief loginSet sets the status of the login_tracker member
     * @param l : boolean value true (valid login) or false (not valid login)
     */
    void loginSet(bool l);

    /**
     * @brief shapeValue gets the integer value stored at m_value
     * @return integer value stored at m_value
     */
    int shapeValue() const { return m_value; }

private slots:

    /**
     * @brief on_login_clicked will check the username and password, and if valid will close the login window. otherwise, the user will need to re-enter their credentials
     */
    void on_login_clicked();

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    virtual void paintEvent(QPaintEvent *event);

    /**
     * @brief on_contactUsButton_clicked will open a window which contains the information of the RubberDuckies development group.
     */
    void on_contactUsButton_clicked();

    void on_shape_editor_Button_clicked();



public slots:
    /**
     * @brief setValue sets the value stored at m_value to the given integer
     * @param value interger passed to be stored at m_value
     */
    void setValue(int value);

signals:
    /**
     * @brief valueChanged
     * @param newValue
     */
    void valueChanged(int newValue);

private:
    Ui::MainWindow *ui;
    /**
     * @brief login_tracker : boolean of whether or not the user has entered valid login credentials
     */
    bool login_tracker;

    /**
     * @brief m_value : an emitter to login, m_value tracks whether the the login is pressed
     */
    int m_value;
    shape_Editor *Shape_Editor;

};


#endif // MAINWINDOW_H


