#include "serializer.h"
#include <QFile>
#include <QString>
#include <iostream>
#include "line.h"

void serialize(QString filepath, myStd::vector<Shape*> userShapes) {
    filepath.append("/shape_list.txt");
    QFile outFile(filepath);

    // open file

    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        std::cout << "Serialize error: file failed to open." << std::endl;
        return;
    }

    QTextStream outStream(&outFile);
    outStream << "This is a serializer test";

    // move through vector
    for (Shape* shape : userShapes) {
        // for each item, switch on ShapeType
        // call corresponding shape save fcn
        switch (shape->getShapeTypeFlag()) {
            case Shape::LineType:
            writeLine(outStream, dynamic_cast<Line*>(shape));
                break;
            case Shape::PolylineType:
                writePolyline(outStream, dynamic_cast<polyline*>(shape));
                break;
            case Shape::PolygonType:
                writePolygon(outStream, dynamic_cast<polygon*>(shape));
                break;
            case Shape::RectangleType:
                writeRectangle(outStream, dynamic_cast<rectangle*>(shape));
                break;
            case Shape::SquareType:
                writeSquare(outStream, dynamic_cast<square*>(shape));
                break;
            case Shape::EllipseType:
                writeEllipse(outStream, dynamic_cast<ellipse*>(shape));
                break;
            case Shape::CircleType:
                writeCircle(outStream, dynamic_cast<circle*>(shape));
                break;
            case Shape::TextType:
                writeText(outStream, dynamic_cast<text*>(shape));
                break;
            default:
                std::cout << "Error during serialize: no known ShapeType during switch" << std::endl;
                break;
        }
        // add empty line before end of loop iteration to signal new shape
        outStream << '\n';
    }

    // close file
    outFile.close();
    return;
}

void writeLine(QTextStream& outStream, Line* outLine) {
    outStream << "ShapeId: ";
    outStream << "ShapeType: Line" << '\n';
    return;
}

void writePolyline(QTextStream& outStream, polyline* outPolyline) {
    outStream << "ShapeType: Polyline" << '\n';
    return;
}

void writePolygon(QTextStream& outStream, polygon* outPolygon) {
    outStream << "ShapeType: Polygon" << '\n';
    return;
}

void writeRectangle(QTextStream& outStream, rectangle* outRectangle) {
    return;
}

void writeSquare(QTextStream& outStream, square* outSquare) {
    return;
}

void writeEllipse(QTextStream& outStream, ellipse* outEllipse) {
    return;
}

void writeCircle(QTextStream& outStream, circle* outCircle) {
    return;
}

void writeText(QTextStream& outStream, text* outText) {
    return;
}
