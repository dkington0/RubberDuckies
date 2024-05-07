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
    QPainter myline(this); // in render return this pointer
    //setPen(Qt::green, 10, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin); // setPen in Canvas
    myline.setPen(getPen());

    myline.drawLine(line);  // Initialize line in Canvas

    show();
}
// void MainWindow::setValue(int value)
// {
//     if(value !=m_value){
//         m_value = value;
//         emit valueChanged(value);
//     }
// }
