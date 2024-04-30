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
    QPainter *myline = new QPainter(this);
    //QPainter myline(this);
    QPen linePen(Qt::green);

    linePen.setWidth(10);
    myline->setPen(linePen);

    QEventLoop loop;
    connect(myline, SIGNAL(shapeValue()), &loop, SLOT(quit()), Qt::QueuedConnection);

    loop.exec();

    QLineF line(10.0, 80.0, 90.0, 20.0);
    myline->drawLine(50, 50, 200, 200);

    // QPainter painter(this);

    // painter.drawLine(line);


}
void MainWindow::setValue(int value)
{
    if(value !=m_value){
        m_value = value;
        emit valueChanged(value);
    }
}
