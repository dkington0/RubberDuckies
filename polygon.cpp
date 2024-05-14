#include "polygon.h"

polygon::~polygon() {}


void polygon::draw(QPainter *event)
{
   // QPainter myPolygon(this); //

    // Set the pen parameters
    setPen(getPen());

    // Converts the points vector into a static array so
    // drawPolygon accepts it as an argument.
    QPoint pointsStatic[points.size()];
    for (int i = 0; i < points.size(); i++)
    {
        pointsStatic[i].setX(points[i].x());
        pointsStatic[i].setY(points[i].y());
    }

    // Draw the polygon in the window
    event->drawPolygon(pointsStatic, points.size());

    //QPainter painter(this);
    // show();

    // Free up memory used to create instance of the shape
    // delete myPolygon;
}
