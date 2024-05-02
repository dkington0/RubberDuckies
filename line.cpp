#include "line.h"
#include "QEventLoop"

// Line::Line()
// {

// }

Line::~Line() {}
// void setPen()
// {
//     // pen(Qt::green);

// }
// void setBrush()
// {

// }

void Line::paintEvent(QPaintEvent *event)
{
    QPainter *myline = new QPainter(this); // in render return this pointer
    setPen(Qt::green, 10, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin);
    myline->setPen(getPen());

    // QEventLoop loop;
    // QObject::connect(myline, SIGNAL(shapeValue()), &loop, SLOT(quit()));

    // loop.exec();
    qreal l;
    // QLineF line(10.0, 80.0, 90.0, 20.0);
    myline->drawLine(50, 50, 200, 200);

    // QPainter painter(this);

    // painter.drawLine(line);
    show();

}
// void MainWindow::setValue(int value)
// {
//     if(value !=m_value){
//         m_value = value;
//         emit valueChanged(value);
//     }
// }
