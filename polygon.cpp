#include "polygon.h"

polygon::~polygon() {}


void polygon::paintEvent(QPaintEvent *event)
{
    QPainter *myPolygon = new QPainter(this); //

    //setPen();
    //getPen().setWidth(10);

    //myPolygon->drawPolygon(points, sizeof(points));

    QPainter painter(this);

    delete myPolygon;
}

// void Line::paintEvent(QPaintEvent *event)
// {
//     QPainter *myline = new QPainter(this); // in render return this pointer
//     shape->setPen(Qt::green, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin);
//     shape->getPen().setWidth(10);
//     myline->setPen(shape->getPen());

//     // QEventLoop loop;
//     // QObject::connect(myline, SIGNAL(shapeValue()), &loop, SLOT(quit()));

//     // loop.exec();
//     qreal l;
//     // QLineF line(10.0, 80.0, 90.0, 20.0);
//     myline->drawLine(50, 50, 200, 200);

//     // QPainter painter(this);

//     // painter.drawLine(line)6;
//     show();
// }
