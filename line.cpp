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

void Line::draw(QPainter *event)
{
    //QPainter* myline = new QPainter(event); // in render return this pointer

    setPen(getPen());    // Will be set in Canvas

    event->drawLine(line);  // Initialize line in Canvas

    show();
}
// void MainWindow::setValue(int value)
// {
//     if(value !=m_value){
//         m_value = value;
//         emit valueChanged(value);
//     }
// }
