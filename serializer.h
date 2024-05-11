#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "vector.h"
#include "shape.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "rectangle.h"
#include "polyline.h"
#include "square.h"
#include "Text.h"
#include "circle.h"

/**
 * @brief serialize will save the shapes within the main container into the shape_list.txt file created upon program launch.
 * @param filepath : the file path of the shape_list.txt file
 * @param userShapes : main container of Shape pointers
 */
void serialize(QString filepath, myStd::vector<Shape*> userShapes);

void writeLine(QTextStream&, Line*);
void writePolyline(QTextStream&, polyline*);
void writePolygon(QTextStream&, polygon*);
void writeRectangle(QTextStream&, rectangle*);
void writeSquare(QTextStream&, square*);
void writeEllipse(QTextStream&, ellipse*);
void writeCircle(QTextStream&, circle*);
void writeText(QTextStream&, text*);

#endif // SERIALIZER_H
