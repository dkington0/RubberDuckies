#include "line.h"

Line::Line() {}

Line::~Line() {}
// void setPen()
// {
//     // pen(Qt::green);

// }
// void setBrush()
// {

// }

void Line::paintEvent(QPaintEvent* event)
{
    QPainter myline(this);
    QPen linePen(Qt::green);

    linePen.setWidth(10);
    myline.setPen(linePen);
    myline.drawLine(50, 50, 200, 200);
}
