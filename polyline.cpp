#include "polyline.h"

polyline::~polyline() {}

void polyline::paintEvent(QPaintEvent *event)
{
    QPainter *myPolyline = new QPainter(this); //

    // Set the pen parameters
    setPen(QPen());
    myPolyline->setPen(getPen());

    //Hardcoded Coordinates for a polyline
    points[0] = QPoint(40,10);
    points[1] = QPoint(50,20);
    points[2] = QPoint(60,10);

    // Converts the points vector into a static array so
    // drawPolygon accepts it as an argument.
    QPoint pointsStatic[points.size()];
    for (int i = 0; i <= points.size(); i++)
    {
        pointsStatic[i].setX(points[i].x());
        pointsStatic[i].setY(points[i].y());
    }

    // Draw the polygon in the window
    myPolyline->drawPolyline(pointsStatic, points.size());

    //QPainter painter(this);
    show();

    // Free up memory used to create instance of the shape
    delete myPolyline;
}
