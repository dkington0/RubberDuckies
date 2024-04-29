#include "line.h"

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
    QPainter myline(this);
    QPen linePen(Qt::green);

    linePen.setWidth(10);
    myline.setPen(linePen);
    myline.drawLine(50, 50, 200, 200);
    // QLineF line(10.0, 80.0, 90.0, 20.0);

    // QPainter painter(this);

    // painter.drawLine(line);
}
