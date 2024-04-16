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

    private:
        Ui::Shape *ui;




    public:
        Shape(QWidget *parent = nullptr);
        ~Shape();


        virtual void DrawShape()=0;   // Will draw the shape on the window area
        virtual void SetShape()=0;    // Set the values of the shape




};
#endif // SHAPE_H
