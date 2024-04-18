#ifndef SHAPE_H
#define SHAPE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Shape;
}
QT_END_NAMESPACE

class Shape : public QMainWindow
{
    Q_OBJECT

public:
    Shape(QWidget *parent = nullptr);
    ~Shape();

private:
    Ui::Shape *ui;
};
#endif // SHAPE_H
