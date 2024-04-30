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
    myline->drawLine(50, 50, 200, 200);

    QEventLoop loop;
    QWidget::connect(myline, SIGNAL(editingFinished()), &loop, SLOT(quit()));

    loop.exec();
    // QLineF line(10.0, 80.0, 90.0, 20.0);

    // QPainter painter(this);

    // painter.drawLine(line);
}
