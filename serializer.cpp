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
    QString colorStr;
    if (outLine->getPen().color() == Qt::white)
        colorStr = "white";
    else if (outLine->getPen().color() == Qt::black)
        colorStr = "black";
    else if (outLine->getPen().color() == Qt::red)
        colorStr = "red";
    else if (outLine->getPen().color() == Qt::green)
        colorStr = "green";
    else if (outLine->getPen().color() == Qt::blue)
        colorStr = "blue";
    else if (outLine->getPen().color() == Qt::cyan)
        colorStr = "cyan";
    else if (outLine->getPen().color() == Qt::magenta)
        colorStr = "magenta";
    else if (outLine->getPen().color() == Qt::yellow)
        colorStr = "yellow";
    else if (outLine->getPen().color() == Qt::gray)
        colorStr = "gray";
    else
        colorStr = "black"; // defaults to a black color if the given pen color is invalid

    QString penStyleStr;
    if (outLine->getPen().style() == Qt::NoPen)
        penStyleStr = "NoPen";
    else if (outLine->getPen().style() == Qt::SolidLine)
        penStyleStr = "SolidLine";
    else if (outLine->getPen().style() == Qt::DashLine)
        penStyleStr = "DashLine";
    else if (outLine->getPen().style() == Qt::DotLine)
        penStyleStr = "DotLine";
    else if (outLine->getPen().style() == Qt::DashDotLine)
        penStyleStr = "DashDotLine";
    else if (outLine->getPen().style() == Qt::DashDotDotLine)
        penStyleStr = "DashDotDotLine";
    else
        penStyleStr = "SolidLine"; // defaults to a solid line pen style if pen style is invalid

    QString penCapStyleStr;
    if (outLine->getPen().capStyle() == Qt::FlatCap)
        penCapStyleStr = "FlatCap";
    else if (outLine->getPen().capStyle() == Qt::SquareCap)
        penCapStyleStr = "SquareCap";
    else if (outLine->getPen().capStyle() == Qt::RoundCap)
        penCapStyleStr = "RoundCap";
    else
        penCapStyleStr = "FlatCap"; // defaults to a flat cap pen cap style if cap style is invalid

    QString penJoinStyleStr;
    if (outLine->getPen().joinStyle() == Qt::MiterJoin)
        penJoinStyleStr = "MiterJoin";
    else if (outLine->getPen().joinStyle() == Qt::BevelJoin)
        penJoinStyleStr = "BevelJoin";
    else if (outLine->getPen().joinStyle() == Qt::RoundJoin)
        penJoinStyleStr = "RoundJoin";
    else
        penJoinStyleStr = "MiterJoin"; // defaults to miter join style if join style is invalid

    outStream << "ShapeId: " << outLine->getId() << '\n'
              << "ShapeType: " << "Line" << '\n'
              << "ShapeDimensions: " << outLine->getRect().topLeft().x() << ", " << outLine->getRect().topLeft().y() << ", " << outLine->getRect().width() << '\n'
              << "PenColor: " << colorStr << '\n'
              << "PenWidth: " << outLine->getPen().width() << '\n'
              << "PenStyle: " << penStyleStr << '\n'
              << "PenCapStyle: " << penCapStyleStr << '\n'
              << "PenJoinStyle: " << penJoinStyleStr << '\n'
              << "BrushColor: " << brushColorStr << '\n'
              << "BrushStyle: " << brushStyleStr << '\n';
    return;

    //outLine->get;
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

    QString colorStr;
    if (outCircle->getPen().color() == Qt::white)
        colorStr = "white";
    else if (outCircle->getPen().color() == Qt::black)
        colorStr = "black";
    else if (outCircle->getPen().color() == Qt::red)
        colorStr = "red";
    else if (outCircle->getPen().color() == Qt::green)
        colorStr = "green";
    else if (outCircle->getPen().color() == Qt::blue)
        colorStr = "blue";
    else if (outCircle->getPen().color() == Qt::cyan)
        colorStr = "cyan";
    else if (outCircle->getPen().color() == Qt::magenta)
        colorStr = "magenta";
    else if (outCircle->getPen().color() == Qt::yellow)
        colorStr = "yellow";
    else if (outCircle->getPen().color() == Qt::gray)
        colorStr = "gray";
    else
        colorStr = "black"; // defaults to a black color if the given pen color is invalid

    QString penStyleStr;
    if (outCircle->getPen().style() == Qt::NoPen)
        penStyleStr = "NoPen";
    else if (outCircle->getPen().style() == Qt::SolidLine)
        penStyleStr = "SolidLine";
    else if (outCircle->getPen().style() == Qt::DashLine)
        penStyleStr = "DashLine";
    else if (outCircle->getPen().style() == Qt::DotLine)
        penStyleStr = "DotLine";
    else if (outCircle->getPen().style() == Qt::DashDotLine)
        penStyleStr = "DashDotLine";
    else if (outCircle->getPen().style() == Qt::DashDotDotLine)
        penStyleStr = "DashDotDotLine";
    else
        penStyleStr = "SolidLine"; // defaults to a solid line pen style if pen style is invalid

    QString penCapStyleStr;
    if (outCircle->getPen().capStyle() == Qt::FlatCap)
        penCapStyleStr = "FlatCap";
    else if (outCircle->getPen().capStyle() == Qt::SquareCap)
        penCapStyleStr = "SquareCap";
    else if (outCircle->getPen().capStyle() == Qt::RoundCap)
        penCapStyleStr = "RoundCap";
    else
        penCapStyleStr = "FlatCap"; // defaults to a flat cap pen cap style if cap style is invalid

    QString penJoinStyleStr;
    if (outCircle->getPen().joinStyle() == Qt::MiterJoin)
        penJoinStyleStr = "MiterJoin";
    else if (outCircle->getPen().joinStyle() == Qt::BevelJoin)
        penJoinStyleStr = "BevelJoin";
    else if (outCircle->getPen().joinStyle() == Qt::RoundJoin)
        penJoinStyleStr = "RoundJoin";
    else
        penJoinStyleStr = "MiterJoin"; // defaults to miter join style if join style is invalid

    QString brushColorStr;
    if (outCircle->getPen().brush().color() == Qt::white)
        brushColorStr = "white";
    else if (outCircle->getPen().brush().color() == Qt::black)
        brushColorStr = "black";
    else if (outCircle->getPen().brush().color() == Qt::red)
        brushColorStr = "red";
    else if (outCircle->getPen().brush().color() == Qt::green)
        brushColorStr = "green";
    else if (outCircle->getPen().brush().color() == Qt::blue)
        brushColorStr = "blue";
    else if (outCircle->getPen().brush().color() == Qt::cyan)
        brushColorStr = "cyan";
    else if (outCircle->getPen().brush().color() == Qt::magenta)
        brushColorStr = "magenta";
    else if (outCircle->getPen().brush().color() == Qt::yellow)
        brushColorStr = "yellow";
    else if (outCircle->getPen().brush().color() == Qt::gray)
        brushColorStr = "gray";
    else {
        brushColorStr = "black"; // defaults to black if brush color is invalid
    }

    QString brushStyleStr;
    if (outCircle->getPen().brush().style() == Qt::SolidPattern)
        brushStyleStr = "SolidPattern";
    else if (outCircle->getPen().brush().style() == Qt::HorPattern)
        brushStyleStr = "HorPattern";
    else if (outCircle->getPen().brush().style() == Qt::VerPattern)
        brushStyleStr = "VerPattern";
    else if (outCircle->getPen().brush().style() == Qt::NoBrush)
        brushStyleStr = "NoBrush";
    else
        brushStyleStr = "SolidPattern"; //defaults to a solid pattern if brush style is invalid

    outStream << "ShapeId: " << outCircle->getId() << '\n'
              << "ShapeType: " << "Circle" << '\n'
              << "ShapeDimensions: " << outCircle->getRect().topLeft().x() << ", " << outCircle->getRect().topLeft().y() << ", " << outCircle->getRect().width() << '\n'
              << "PenColor: " << colorStr << '\n'
              << "PenWidth: " << outCircle->getPen().width() << '\n'
              << "PenStyle: " << penStyleStr << '\n'
              << "PenCapStyle: " << penCapStyleStr << '\n'
              << "PenJoinStyle: " << penJoinStyleStr << '\n'
              << "BrushColor: " << brushColorStr << '\n'
              << "BrushStyle: " << brushStyleStr << '\n';
    return;
}

void writeText(QTextStream& outStream, text* outText) {
    return;
}
