#include "polygon.h"

polygon::~polygon() {}


void polygon::paintEvent(QPaintEvent *event)
{
    QPainter *myPolygon = new QPainter(this); //

    // Set the pen parameters
    setPen(QPen());
    myPolygon->setPen(getPen());

    //Hardcoded Coordinates for a square
    points[0] = QPoint(10,10);
    points[1] = QPoint(10,20);
    points[2] = QPoint(20,10);
    points[3] = QPoint(20,20);

    // Converts the points vector into a static array so
    // drawPolygon accepts it as an argument.
    QPoint pointsStatic[points.size()];
    for (int i = 0; i <= points.size(); i++)
    {
        pointsStatic[i].setX(points[i].x());
        pointsStatic[i].setY(points[i].y());
    }

    // Draw the polygon in the window
    myPolygon->drawPolygon(pointsStatic, points.size());

    //QPainter painter(this);
    show();

    // Free up memory used to create instance of the shape
    delete myPolygon;
}
