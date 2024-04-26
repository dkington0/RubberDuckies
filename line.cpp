#include "line.h"

Line::Line() {}

void setPen()
{
    pen(Qt::green);

}
void setBrush()
{

}

void Line::paintEvent(QPaintEvent* event)
{
    pen myline(this);
    QPen linePen(Qt::green);
    linePen.setWidth(10);
    myline.setPen(linepen);
    myline.draw(50, 50, 200, 200);

}
