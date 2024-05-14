#include "polyline.h"

polyline::~polyline() {}

void polyline::draw(QPainter *event)
{
   // QPainter myPolyline(this); //

    // Set the pen parameters
    setPen(getPen());

    //Hardcoded Coordinates for a polyline

    // Converts the points vector into a static array so
    // drawPolygon accepts it as an argument.
    QPoint pointsStatic[points.size()];
    for (int i = 0; i < points.size(); i++)
    {
        pointsStatic[i].setX(points[i].x());
        pointsStatic[i].setY(points[i].y());
    }

    // Draw the polygon in the window
    event->drawPolyline(pointsStatic, points.size());

    // Free up memory used to create instance of the shape
    // delete myPolyline;
}
