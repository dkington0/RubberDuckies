#include "serializer.h"
#include <QFile>
#include <QString>
#include <iostream>
#include "line.h"

void serialize(QString filepath, myStd::vector<Shape*> userShapes) {
    filepath.append("/shape_list.txt");
    QFile outFile(filepath);

    // open file
    if (outFile.exists()) // if the file exists, remove it to be overwritten.
        outFile.remove();

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
    else {
        colorStr = "black"; // defaults to a black color if the given pen color is invalid
        std::cout << "Error during writeLine: invalid pen color" << std::endl;
    }

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
    else {
        penStyleStr = "SolidLine"; // defaults to a solid line pen style if pen style is invalid
        std::cout << "Error during writeLine: invalid pen style" << std::endl;
    }

    QString penCapStyleStr;
    if (outLine->getPen().capStyle() == Qt::FlatCap)
        penCapStyleStr = "FlatCap";
    else if (outLine->getPen().capStyle() == Qt::SquareCap)
        penCapStyleStr = "SquareCap";
    else if (outLine->getPen().capStyle() == Qt::RoundCap)
        penCapStyleStr = "RoundCap";
    else {
        penCapStyleStr = "FlatCap"; // defaults to a flat cap pen cap style if cap style is invalid
        std::cout << "Error during writeLine: invalid pen cap style" << std::endl;
    }

    QString penJoinStyleStr;
    if (outLine->getPen().joinStyle() == Qt::MiterJoin)
        penJoinStyleStr = "MiterJoin";
    else if (outLine->getPen().joinStyle() == Qt::BevelJoin)
        penJoinStyleStr = "BevelJoin";
    else if (outLine->getPen().joinStyle() == Qt::RoundJoin)
        penJoinStyleStr = "RoundJoin";
    else {
        penJoinStyleStr = "MiterJoin"; // defaults to miter join style if join style is invalid
        std::cout << "Error during writeLine: invalid pen join style" << std::endl;
    }

    outStream << "ShapeId: " << outLine->getId() << '\n'
              << "ShapeType: " << "Line" << '\n'
              << "ShapeDimensions: " << outLine->getLine().p1().x() << ", " << outLine->getLine().p1().y() << ", " << outLine->getLine().p2().x()  << ", " << outLine->getLine().p2().y() << '\n'
              << "PenColor: " << colorStr << '\n'
              << "PenWidth: " << outLine->getPen().width() << '\n'
              << "PenStyle: " << penStyleStr << '\n'
              << "PenCapStyle: " << penCapStyleStr << '\n'
              << "PenJoinStyle: " << penJoinStyleStr << '\n';

    return;
}

void writePolyline(QTextStream& outStream, polyline* outPolyline) {
    QString colorStr;
    if (outPolyline->getPen().color() == Qt::white)
        colorStr = "white";
    else if (outPolyline->getPen().color() == Qt::black)
        colorStr = "black";
    else if (outPolyline->getPen().color() == Qt::red)
        colorStr = "red";
    else if (outPolyline->getPen().color() == Qt::green)
        colorStr = "green";
    else if (outPolyline->getPen().color() == Qt::blue)
        colorStr = "blue";
    else if (outPolyline->getPen().color() == Qt::cyan)
        colorStr = "cyan";
    else if (outPolyline->getPen().color() == Qt::magenta)
        colorStr = "magenta";
    else if (outPolyline->getPen().color() == Qt::yellow)
        colorStr = "yellow";
    else if (outPolyline->getPen().color() == Qt::gray)
        colorStr = "gray";
    else {
        colorStr = "black"; // defaults to a black color if the given pen color is invalid
        std::cout << "Error during writePolyline: invalid pen color" << std::endl;
    }

    QString penStyleStr;
    if (outPolyline->getPen().style() == Qt::NoPen)
        penStyleStr = "NoPen";
    else if (outPolyline->getPen().style() == Qt::SolidLine)
        penStyleStr = "SolidLine";
    else if (outPolyline->getPen().style() == Qt::DashLine)
        penStyleStr = "DashLine";
    else if (outPolyline->getPen().style() == Qt::DotLine)
        penStyleStr = "DotLine";
    else if (outPolyline->getPen().style() == Qt::DashDotLine)
        penStyleStr = "DashDotLine";
    else if (outPolyline->getPen().style() == Qt::DashDotDotLine)
        penStyleStr = "DashDotDotLine";
    else {
        penStyleStr = "SolidLine"; // defaults to a solid line pen style if pen style is invalid
        std::cout << "Error during writePolyline: invalid pen style" << std::endl;
    }

    QString penCapStyleStr;
    if (outPolyline->getPen().capStyle() == Qt::FlatCap)
        penCapStyleStr = "FlatCap";
    else if (outPolyline->getPen().capStyle() == Qt::SquareCap)
        penCapStyleStr = "SquareCap";
    else if (outPolyline->getPen().capStyle() == Qt::RoundCap)
        penCapStyleStr = "RoundCap";
    else {
        penCapStyleStr = "FlatCap"; // defaults to a flat cap pen cap style if cap style is invalid
        std::cout << "Error during writePolyline: invalid pen cap style" << std::endl;
    }

    QString penJoinStyleStr;
    if (outPolyline->getPen().joinStyle() == Qt::MiterJoin)
        penJoinStyleStr = "MiterJoin";
    else if (outPolyline->getPen().joinStyle() == Qt::BevelJoin)
        penJoinStyleStr = "BevelJoin";
    else if (outPolyline->getPen().joinStyle() == Qt::RoundJoin)
        penJoinStyleStr = "RoundJoin";
    else {
        penJoinStyleStr = "MiterJoin"; // defaults to miter join style if join style is invalid
        std::cout << "Error during writePolyline: invalid pen join style" << std::endl;
    }

    outStream << "ShapeId: " << outPolyline->getId() << '\n'
              << "ShapeType: " << "Polyline" << '\n'
              << "ShapeDimensions: ";

    myStd::vector<QPoint> points(outPolyline->getPoints());
    for (size_t i {}; i < points.size(); i++) {
        outStream << points[i].x() << ", " << points[i].y();
        if ((i+1) < points.size()) // if the next iteration is not the last
            outStream << ", ";
    }
    outStream << '\n';

    outStream << "PenColor: " << colorStr << '\n'
              << "PenWidth: " << outPolyline->getPen().width() << '\n'
              << "PenStyle: " << penStyleStr << '\n'
              << "PenCapStyle: " << penCapStyleStr << '\n'
              << "PenJoinStyle: " << penJoinStyleStr << '\n';

    return;
}

void writePolygon(QTextStream& outStream, polygon* outPolygon) {
    QString colorStr;
    if (outPolygon->getPen().color() == Qt::white)
        colorStr = "white";
    else if (outPolygon->getPen().color() == Qt::black)
        colorStr = "black";
    else if (outPolygon->getPen().color() == Qt::red)
        colorStr = "red";
    else if (outPolygon->getPen().color() == Qt::green)
        colorStr = "green";
    else if (outPolygon->getPen().color() == Qt::blue)
        colorStr = "blue";
    else if (outPolygon->getPen().color() == Qt::cyan)
        colorStr = "cyan";
    else if (outPolygon->getPen().color() == Qt::magenta)
        colorStr = "magenta";
    else if (outPolygon->getPen().color() == Qt::yellow)
        colorStr = "yellow";
    else if (outPolygon->getPen().color() == Qt::gray)
        colorStr = "gray";
    else {
        colorStr = "black"; // defaults to a black color if the given pen color is invalid
        std::cout << "Error during writePolygon: invalid pen color" << std::endl;
    }

    QString penStyleStr;
    if (outPolygon->getPen().style() == Qt::NoPen)
        penStyleStr = "NoPen";
    else if (outPolygon->getPen().style() == Qt::SolidLine)
        penStyleStr = "SolidLine";
    else if (outPolygon->getPen().style() == Qt::DashLine)
        penStyleStr = "DashLine";
    else if (outPolygon->getPen().style() == Qt::DotLine)
        penStyleStr = "DotLine";
    else if (outPolygon->getPen().style() == Qt::DashDotLine)
        penStyleStr = "DashDotLine";
    else if (outPolygon->getPen().style() == Qt::DashDotDotLine)
        penStyleStr = "DashDotDotLine";
    else {
        penStyleStr = "SolidLine"; // defaults to a solid line pen style if pen style is invalid
        std::cout << "Error during writePolygon: invalid pen style" << std::endl;
    }

    QString penCapStyleStr;
    if (outPolygon->getPen().capStyle() == Qt::FlatCap)
        penCapStyleStr = "FlatCap";
    else if (outPolygon->getPen().capStyle() == Qt::SquareCap)
        penCapStyleStr = "SquareCap";
    else if (outPolygon->getPen().capStyle() == Qt::RoundCap)
        penCapStyleStr = "RoundCap";
    else {
        penCapStyleStr = "FlatCap"; // defaults to a flat cap pen cap style if cap style is invalid
        std::cout << "Error during writePolygon: invalid pen cap style" << std::endl;
    }

    QString penJoinStyleStr;
    if (outPolygon->getPen().joinStyle() == Qt::MiterJoin)
        penJoinStyleStr = "MiterJoin";
    else if (outPolygon->getPen().joinStyle() == Qt::BevelJoin)
        penJoinStyleStr = "BevelJoin";
    else if (outPolygon->getPen().joinStyle() == Qt::RoundJoin)
        penJoinStyleStr = "RoundJoin";
    else {
        penJoinStyleStr = "MiterJoin"; // defaults to miter join style if join style is invalid
        std::cout << "Error during writePolygon: invalid pen join style" << std::endl;
    }

    QString brushColorStr;
    if (outPolygon->getPen().brush().color() == Qt::white)
        brushColorStr = "white";
    else if (outPolygon->getPen().brush().color() == Qt::black)
        brushColorStr = "black";
    else if (outPolygon->getPen().brush().color() == Qt::red)
        brushColorStr = "red";
    else if (outPolygon->getPen().brush().color() == Qt::green)
        brushColorStr = "green";
    else if (outPolygon->getPen().brush().color() == Qt::blue)
        brushColorStr = "blue";
    else if (outPolygon->getPen().brush().color() == Qt::cyan)
        brushColorStr = "cyan";
    else if (outPolygon->getPen().brush().color() == Qt::magenta)
        brushColorStr = "magenta";
    else if (outPolygon->getPen().brush().color() == Qt::yellow)
        brushColorStr = "yellow";
    else if (outPolygon->getPen().brush().color() == Qt::gray)
        brushColorStr = "gray";
    else {
        brushColorStr = "black"; // defaults to black if brush color is invalid
        std::cout << "Error during writePolygon: invalid brush color" << std::endl;
    }

    QString brushStyleStr;
    if (outPolygon->getPen().brush().style() == Qt::SolidPattern)
        brushStyleStr = "SolidPattern";
    else if (outPolygon->getPen().brush().style() == Qt::HorPattern)
        brushStyleStr = "HorPattern";
    else if (outPolygon->getPen().brush().style() == Qt::VerPattern)
        brushStyleStr = "VerPattern";
    else if (outPolygon->getPen().brush().style() == Qt::NoBrush)
        brushStyleStr = "NoBrush";
    else {
        brushStyleStr = "SolidPattern"; //defaults to a solid pattern if brush style is invalid
        std::cout << "Error during writePolygon: invalid brush style" << std::endl;
    }

    outStream << "ShapeId: " << outPolygon->getId() << '\n'
              << "ShapeType: " << "Polygon" << '\n'
              << "ShapeDimensions: ";

    myStd::vector<QPoint> points(outPolygon->getPoints());
    for (size_t i {}; i < points.size(); i++) {
        outStream << points[i].x() << ", " << points[i].y();
        if ((i+1) < points.size()) // if the next iteration is not the last
            outStream << ", ";
    }
    outStream << '\n';

    outStream << "PenColor: " << colorStr << '\n'
              << "PenWidth: " << outPolygon->getPen().width() << '\n'
              << "PenStyle: " << penStyleStr << '\n'
              << "PenCapStyle: " << penCapStyleStr << '\n'
              << "PenJoinStyle: " << penJoinStyleStr << '\n'
              << "BrushColor: " << brushColorStr << '\n'
              << "BrushStyle: " << brushStyleStr << '\n';

    return;
}

void writeRectangle(QTextStream& outStream, rectangle* outRectangle) {
    QString colorStr;
    if (outRectangle->getPen().color() == Qt::white)
        colorStr = "white";
    else if (outRectangle->getPen().color() == Qt::black)
        colorStr = "black";
    else if (outRectangle->getPen().color() == Qt::red)
        colorStr = "red";
    else if (outRectangle->getPen().color() == Qt::green)
        colorStr = "green";
    else if (outRectangle->getPen().color() == Qt::blue)
        colorStr = "blue";
    else if (outRectangle->getPen().color() == Qt::cyan)
        colorStr = "cyan";
    else if (outRectangle->getPen().color() == Qt::magenta)
        colorStr = "magenta";
    else if (outRectangle->getPen().color() == Qt::yellow)
        colorStr = "yellow";
    else if (outRectangle->getPen().color() == Qt::gray)
        colorStr = "gray";
    else {
        colorStr = "black"; // defaults to a black color if the given pen color is invalid
        std::cout << "Error during writeRectangle: invalid pen color" << std::endl;
    }

    QString penStyleStr;
    if (outRectangle->getPen().style() == Qt::NoPen)
        penStyleStr = "NoPen";
    else if (outRectangle->getPen().style() == Qt::SolidLine)
        penStyleStr = "SolidLine";
    else if (outRectangle->getPen().style() == Qt::DashLine)
        penStyleStr = "DashLine";
    else if (outRectangle->getPen().style() == Qt::DotLine)
        penStyleStr = "DotLine";
    else if (outRectangle->getPen().style() == Qt::DashDotLine)
        penStyleStr = "DashDotLine";
    else if (outRectangle->getPen().style() == Qt::DashDotDotLine)
        penStyleStr = "DashDotDotLine";
    else {
        penStyleStr = "SolidLine"; // defaults to a solid line pen style if pen style is invalid
        std::cout << "Error during writeRectangle: invalid pen style" << std::endl;
    }

    QString penCapStyleStr;
    if (outRectangle->getPen().capStyle() == Qt::FlatCap)
        penCapStyleStr = "FlatCap";
    else if (outRectangle->getPen().capStyle() == Qt::SquareCap)
        penCapStyleStr = "SquareCap";
    else if (outRectangle->getPen().capStyle() == Qt::RoundCap)
        penCapStyleStr = "RoundCap";
    else {
        penCapStyleStr = "FlatCap"; // defaults to a flat cap pen cap style if cap style is invalid
        std::cout << "Error during writeRectangle: invalid pen cap style" << std::endl;
    }

    QString penJoinStyleStr;
    if (outRectangle->getPen().joinStyle() == Qt::MiterJoin)
        penJoinStyleStr = "MiterJoin";
    else if (outRectangle->getPen().joinStyle() == Qt::BevelJoin)
        penJoinStyleStr = "BevelJoin";
    else if (outRectangle->getPen().joinStyle() == Qt::RoundJoin)
        penJoinStyleStr = "RoundJoin";
    else {
        penJoinStyleStr = "MiterJoin"; // defaults to miter join style if join style is invalid
        std::cout << "Error during writeRectangle: invalid pen join style" << std::endl;
    }

    QString brushColorStr;
    if (outRectangle->getPen().brush().color() == Qt::white)
        brushColorStr = "white";
    else if (outRectangle->getPen().brush().color() == Qt::black)
        brushColorStr = "black";
    else if (outRectangle->getPen().brush().color() == Qt::red)
        brushColorStr = "red";
    else if (outRectangle->getPen().brush().color() == Qt::green)
        brushColorStr = "green";
    else if (outRectangle->getPen().brush().color() == Qt::blue)
        brushColorStr = "blue";
    else if (outRectangle->getPen().brush().color() == Qt::cyan)
        brushColorStr = "cyan";
    else if (outRectangle->getPen().brush().color() == Qt::magenta)
        brushColorStr = "magenta";
    else if (outRectangle->getPen().brush().color() == Qt::yellow)
        brushColorStr = "yellow";
    else if (outRectangle->getPen().brush().color() == Qt::gray)
        brushColorStr = "gray";
    else {
        brushColorStr = "black"; // defaults to black if brush color is invalid
        std::cout << "Error during writeRectangle: invalid brush color" << std::endl;
    }

    QString brushStyleStr;
    if (outRectangle->getPen().brush().style() == Qt::SolidPattern)
        brushStyleStr = "SolidPattern";
    else if (outRectangle->getPen().brush().style() == Qt::HorPattern)
        brushStyleStr = "HorPattern";
    else if (outRectangle->getPen().brush().style() == Qt::VerPattern)
        brushStyleStr = "VerPattern";
    else if (outRectangle->getPen().brush().style() == Qt::NoBrush)
        brushStyleStr = "NoBrush";
    else {
        brushStyleStr = "SolidPattern"; //defaults to a solid pattern if brush style is invalid
        std::cout << "Error during writeRectangle: invalid brush style" << std::endl;
    }

    outStream << "ShapeId: " << outRectangle->getId() << '\n'
              << "ShapeType: " << "Rectangle" << '\n'
              << "ShapeDimensions: " << outRectangle->getRect().topLeft().x() << ", " << outRectangle->getRect().topLeft().y() << ", " << outRectangle->getRect().height() << ", " << outRectangle->getRect().width() << '\n'
              << "PenColor: " << colorStr << '\n'
              << "PenWidth: " << outRectangle->getPen().width() << '\n'
              << "PenStyle: " << penStyleStr << '\n'
              << "PenCapStyle: " << penCapStyleStr << '\n'
              << "PenJoinStyle: " << penJoinStyleStr << '\n'
              << "BrushColor: " << brushColorStr << '\n'
              << "BrushStyle: " << brushStyleStr << '\n';
    return;
}

void writeSquare(QTextStream& outStream, square* outSquare) {
    QString colorStr;
    if (outSquare->getPen().color() == Qt::white)
        colorStr = "white";
    else if (outSquare->getPen().color() == Qt::black)
        colorStr = "black";
    else if (outSquare->getPen().color() == Qt::red)
        colorStr = "red";
    else if (outSquare->getPen().color() == Qt::green)
        colorStr = "green";
    else if (outSquare->getPen().color() == Qt::blue)
        colorStr = "blue";
    else if (outSquare->getPen().color() == Qt::cyan)
        colorStr = "cyan";
    else if (outSquare->getPen().color() == Qt::magenta)
        colorStr = "magenta";
    else if (outSquare->getPen().color() == Qt::yellow)
        colorStr = "yellow";
    else if (outSquare->getPen().color() == Qt::gray)
        colorStr = "gray";
    else {
        colorStr = "black"; // defaults to a black color if the given pen color is invalid
        std::cout << "Error during writeSquare: invalid pen color" << std::endl;
    }

    QString penStyleStr;
    if (outSquare->getPen().style() == Qt::NoPen)
        penStyleStr = "NoPen";
    else if (outSquare->getPen().style() == Qt::SolidLine)
        penStyleStr = "SolidLine";
    else if (outSquare->getPen().style() == Qt::DashLine)
        penStyleStr = "DashLine";
    else if (outSquare->getPen().style() == Qt::DotLine)
        penStyleStr = "DotLine";
    else if (outSquare->getPen().style() == Qt::DashDotLine)
        penStyleStr = "DashDotLine";
    else if (outSquare->getPen().style() == Qt::DashDotDotLine)
        penStyleStr = "DashDotDotLine";
    else {
        penStyleStr = "SolidLine"; // defaults to a solid line pen style if pen style is invalid
        std::cout << "Error during writeSquare: invalid pen style" << std::endl;
    }

    QString penCapStyleStr;
    if (outSquare->getPen().capStyle() == Qt::FlatCap)
        penCapStyleStr = "FlatCap";
    else if (outSquare->getPen().capStyle() == Qt::SquareCap)
        penCapStyleStr = "SquareCap";
    else if (outSquare->getPen().capStyle() == Qt::RoundCap)
        penCapStyleStr = "RoundCap";
    else {
        penCapStyleStr = "FlatCap"; // defaults to a flat cap pen cap style if cap style is invalid
        std::cout << "Error during writeSquare: invalid pen cap style" << std::endl;
    }

    QString penJoinStyleStr;
    if (outSquare->getPen().joinStyle() == Qt::MiterJoin)
        penJoinStyleStr = "MiterJoin";
    else if (outSquare->getPen().joinStyle() == Qt::BevelJoin)
        penJoinStyleStr = "BevelJoin";
    else if (outSquare->getPen().joinStyle() == Qt::RoundJoin)
        penJoinStyleStr = "RoundJoin";
    else {
        penJoinStyleStr = "MiterJoin"; // defaults to miter join style if join style is invalid
        std::cout << "Error during writeSquare: invalid pen join style" << std::endl;
    }

    QString brushColorStr;
    if (outSquare->getPen().brush().color() == Qt::white)
        brushColorStr = "white";
    else if (outSquare->getPen().brush().color() == Qt::black)
        brushColorStr = "black";
    else if (outSquare->getPen().brush().color() == Qt::red)
        brushColorStr = "red";
    else if (outSquare->getPen().brush().color() == Qt::green)
        brushColorStr = "green";
    else if (outSquare->getPen().brush().color() == Qt::blue)
        brushColorStr = "blue";
    else if (outSquare->getPen().brush().color() == Qt::cyan)
        brushColorStr = "cyan";
    else if (outSquare->getPen().brush().color() == Qt::magenta)
        brushColorStr = "magenta";
    else if (outSquare->getPen().brush().color() == Qt::yellow)
        brushColorStr = "yellow";
    else if (outSquare->getPen().brush().color() == Qt::gray)
        brushColorStr = "gray";
    else {
        brushColorStr = "black"; // defaults to black if brush color is invalid
        std::cout << "Error during writeSquare: invalid brush color" << std::endl;
    }

    QString brushStyleStr;
    if (outSquare->getPen().brush().style() == Qt::SolidPattern)
        brushStyleStr = "SolidPattern";
    else if (outSquare->getPen().brush().style() == Qt::HorPattern)
        brushStyleStr = "HorPattern";
    else if (outSquare->getPen().brush().style() == Qt::VerPattern)
        brushStyleStr = "VerPattern";
    else if (outSquare->getPen().brush().style() == Qt::NoBrush)
        brushStyleStr = "NoBrush";
    else {
        brushStyleStr = "SolidPattern"; //defaults to a solid pattern if brush style is invalid
        std::cout << "Error during writeSquare: invalid brush style" << std::endl;
    }

    outStream << "ShapeId: " << outSquare->getId() << '\n'
              << "ShapeType: " << "Square" << '\n'
              << "ShapeDimensions: " << outSquare->getRect().topLeft().x() << ", " << outSquare->getRect().topLeft().y() << ", " << outSquare->getRect().width() << '\n'
              << "PenColor: " << colorStr << '\n'
              << "PenWidth: " << outSquare->getPen().width() << '\n'
              << "PenStyle: " << penStyleStr << '\n'
              << "PenCapStyle: " << penCapStyleStr << '\n'
              << "PenJoinStyle: " << penJoinStyleStr << '\n'
              << "BrushColor: " << brushColorStr << '\n'
              << "BrushStyle: " << brushStyleStr << '\n';
    return;
}

void writeEllipse(QTextStream& outStream, ellipse* outEllipse) {
    QString colorStr;
    if (outEllipse->getPen().color() == Qt::white)
        colorStr = "white";
    else if (outEllipse->getPen().color() == Qt::black)
        colorStr = "black";
    else if (outEllipse->getPen().color() == Qt::red)
        colorStr = "red";
    else if (outEllipse->getPen().color() == Qt::green)
        colorStr = "green";
    else if (outEllipse->getPen().color() == Qt::blue)
        colorStr = "blue";
    else if (outEllipse->getPen().color() == Qt::cyan)
        colorStr = "cyan";
    else if (outEllipse->getPen().color() == Qt::magenta)
        colorStr = "magenta";
    else if (outEllipse->getPen().color() == Qt::yellow)
        colorStr = "yellow";
    else if (outEllipse->getPen().color() == Qt::gray)
        colorStr = "gray";
    else {
        colorStr = "black"; // defaults to a black color if the given pen color is invalid
        std::cout << "Error during writeEllipse: invalid pen color" << std::endl;
    }

    QString penStyleStr;
    if (outEllipse->getPen().style() == Qt::NoPen)
        penStyleStr = "NoPen";
    else if (outEllipse->getPen().style() == Qt::SolidLine)
        penStyleStr = "SolidLine";
    else if (outEllipse->getPen().style() == Qt::DashLine)
        penStyleStr = "DashLine";
    else if (outEllipse->getPen().style() == Qt::DotLine)
        penStyleStr = "DotLine";
    else if (outEllipse->getPen().style() == Qt::DashDotLine)
        penStyleStr = "DashDotLine";
    else if (outEllipse->getPen().style() == Qt::DashDotDotLine)
        penStyleStr = "DashDotDotLine";
    else {
        penStyleStr = "SolidLine"; // defaults to a solid line pen style if pen style is invalid
        std::cout << "Error during writeEllipse: invalid pen style" << std::endl;
    }

    QString penCapStyleStr;
    if (outEllipse->getPen().capStyle() == Qt::FlatCap)
        penCapStyleStr = "FlatCap";
    else if (outEllipse->getPen().capStyle() == Qt::SquareCap)
        penCapStyleStr = "SquareCap";
    else if (outEllipse->getPen().capStyle() == Qt::RoundCap)
        penCapStyleStr = "RoundCap";
    else {
        penCapStyleStr = "FlatCap"; // defaults to a flat cap pen cap style if cap style is invalid
        std::cout << "Error during writeEllipse: invalid pen cap style" << std::endl;
    }

    QString penJoinStyleStr;
    if (outEllipse->getPen().joinStyle() == Qt::MiterJoin)
        penJoinStyleStr = "MiterJoin";
    else if (outEllipse->getPen().joinStyle() == Qt::BevelJoin)
        penJoinStyleStr = "BevelJoin";
    else if (outEllipse->getPen().joinStyle() == Qt::RoundJoin)
        penJoinStyleStr = "RoundJoin";
    else {
        penJoinStyleStr = "MiterJoin"; // defaults to miter join style if join style is invalid
        std::cout << "Error during writeEllipse: invalid pen join style" << std::endl;
    }

    QString brushColorStr;
    if (outEllipse->getPen().brush().color() == Qt::white)
        brushColorStr = "white";
    else if (outEllipse->getPen().brush().color() == Qt::black)
        brushColorStr = "black";
    else if (outEllipse->getPen().brush().color() == Qt::red)
        brushColorStr = "red";
    else if (outEllipse->getPen().brush().color() == Qt::green)
        brushColorStr = "green";
    else if (outEllipse->getPen().brush().color() == Qt::blue)
        brushColorStr = "blue";
    else if (outEllipse->getPen().brush().color() == Qt::cyan)
        brushColorStr = "cyan";
    else if (outEllipse->getPen().brush().color() == Qt::magenta)
        brushColorStr = "magenta";
    else if (outEllipse->getPen().brush().color() == Qt::yellow)
        brushColorStr = "yellow";
    else if (outEllipse->getPen().brush().color() == Qt::gray)
        brushColorStr = "gray";
    else {
        brushColorStr = "black"; // defaults to black if brush color is invalid
        std::cout << "Error during writeEllipse: invalid brush color" << std::endl;
    }

    QString brushStyleStr;
    if (outEllipse->getPen().brush().style() == Qt::SolidPattern)
        brushStyleStr = "SolidPattern";
    else if (outEllipse->getPen().brush().style() == Qt::HorPattern)
        brushStyleStr = "HorPattern";
    else if (outEllipse->getPen().brush().style() == Qt::VerPattern)
        brushStyleStr = "VerPattern";
    else if (outEllipse->getPen().brush().style() == Qt::NoBrush)
        brushStyleStr = "NoBrush";
    else {
        brushStyleStr = "SolidPattern"; //defaults to a solid pattern if brush style is invalid
        std::cout << "Error during writeEllipse: invalid brush style" << std::endl;
    }

    outStream << "ShapeId: " << outEllipse->getId() << '\n'
              << "ShapeType: " << "Ellipse" << '\n'
              << "ShapeDimensions: " << outEllipse->getRect().topLeft().x() << ", " << outEllipse->getRect().topLeft().y() << ", " << outEllipse->getRect().height() << ", " << outEllipse->getRect().width() << '\n'
              << "PenColor: " << colorStr << '\n'
              << "PenWidth: " << outEllipse->getPen().width() << '\n'
              << "PenStyle: " << penStyleStr << '\n'
              << "PenCapStyle: " << penCapStyleStr << '\n'
              << "PenJoinStyle: " << penJoinStyleStr << '\n'
              << "BrushColor: " << brushColorStr << '\n'
              << "BrushStyle: " << brushStyleStr << '\n';
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
    else {
        colorStr = "black"; // defaults to a black color if the given pen color is invalid
        std::cout << "Error during writeCircle: invalid pen color" << std::endl;
    }

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
    else {
        penStyleStr = "SolidLine"; // defaults to a solid line pen style if pen style is invalid
        std::cout << "Error during writeCircle: invalid pen style" << std::endl;
    }

    QString penCapStyleStr;
    if (outCircle->getPen().capStyle() == Qt::FlatCap)
        penCapStyleStr = "FlatCap";
    else if (outCircle->getPen().capStyle() == Qt::SquareCap)
        penCapStyleStr = "SquareCap";
    else if (outCircle->getPen().capStyle() == Qt::RoundCap)
        penCapStyleStr = "RoundCap";
    else {
        penCapStyleStr = "FlatCap"; // defaults to a flat cap pen cap style if cap style is invalid
        std::cout << "Error during writeCircle: invalid pen cap style" << std::endl;
    }

    QString penJoinStyleStr;
    if (outCircle->getPen().joinStyle() == Qt::MiterJoin)
        penJoinStyleStr = "MiterJoin";
    else if (outCircle->getPen().joinStyle() == Qt::BevelJoin)
        penJoinStyleStr = "BevelJoin";
    else if (outCircle->getPen().joinStyle() == Qt::RoundJoin)
        penJoinStyleStr = "RoundJoin";
    else {
        penJoinStyleStr = "MiterJoin"; // defaults to miter join style if join style is invalid
        std::cout << "Error during writeCircle: invalid pen join style" << std::endl;
    }

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
        std::cout << "Error during writeCircle: invalid brush color" << std::endl;
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
    else {
        brushStyleStr = "SolidPattern"; //defaults to a solid pattern if brush style is invalid
        std::cout << "Error during writeCircle: invalid brush style" << std::endl;
    }

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
    QString colorStr;
    if (outText->getPen().color() == Qt::white)
        colorStr = "white";
    else if (outText->getPen().color() == Qt::black)
        colorStr = "black";
    else if (outText->getPen().color() == Qt::red)
        colorStr = "red";
    else if (outText->getPen().color() == Qt::green)
        colorStr = "green";
    else if (outText->getPen().color() == Qt::blue)
        colorStr = "blue";
    else if (outText->getPen().color() == Qt::cyan)
        colorStr = "cyan";
    else if (outText->getPen().color() == Qt::magenta)
        colorStr = "magenta";
    else if (outText->getPen().color() == Qt::yellow)
        colorStr = "yellow";
    else if (outText->getPen().color() == Qt::gray)
        colorStr = "gray";
    else {
        colorStr = "black"; // defaults to a black color if the given pen color is invalid
        std::cout << "Error during writeText: invalid text color" << std::endl;
    }

    QString textAlignmentStr;
    if (outText->getFlags() == Qt::AlignLeft)
        textAlignmentStr = "AlignLeft";
    else if (outText->getFlags() == Qt::AlignRight)
        textAlignmentStr = "AlignRight";
    else if (outText->getFlags() == Qt::AlignTop)
        textAlignmentStr = "AlignTop";
    else if (outText->getFlags() == Qt::AlignBottom)
        textAlignmentStr= "AlignBottom";
    else if (outText->getFlags() == Qt::AlignCenter)
        textAlignmentStr = "AlignCenter";
    else {
        textAlignmentStr = "AlignLeft"; // default to align left if alignment flag is invalid
        std::cout << "Error during writeText: invalid text alignment flag" << std::endl;
    }

    QString textWeightStr;
    if (outText->getFont().weight() == QFont::Thin)
        textWeightStr = "Thin";
    else if (outText->getFont().weight() == QFont::Light)
        textWeightStr = "Light";
    else if (outText->getFont().weight() == QFont::Normal)
        textWeightStr = "Normal";
    else if (outText->getFont().weight() == QFont::Bold)
        textWeightStr = "Bold";
    else {
        textWeightStr = "Normal"; // defaults to normal if text weight is invalid
        std::cout << "Error during writeText: invalid text weight" << std::endl;
    }

    QString textFontStyleStr;
    if (outText->getFont().style() == QFont::StyleNormal)
        textFontStyleStr = "StyleNormal";
    else if (outText->getFont().style() == QFont::StyleItalic)
        textFontStyleStr = "StyleItalic";
    else if (outText->getFont().style() == QFont::StyleOblique)
        textFontStyleStr = "StyleOblique";
    else {
        textFontStyleStr = "StyleNormal"; // defaults to normal style if style is invalid
        std::cout << "Error during writeText: invalid text font style" << std::endl;
    }

    outStream << "ShapeId: " << outText->getId() << '\n'
              << "ShapeType: " << "Text" << '\n'
              << "ShapeDimensions: " << outText->getRect().topLeft().x() << ", " << outText->getRect().topLeft().y() << ", " << outText->getRect().height() << ", " << outText->getRect().width() << '\n'
              << "TextString: " << outText->getStrText() << '\n'
              << "TextColor: " << colorStr << '\n'
              << "TextAlignment: " << textAlignmentStr << '\n'
              << "TextPointSize: " << outText->getFont().pointSize() << '\n'
              << "TextFontFamily: " << outText->getFont().family() << '\n'
              << "TextFontStyle: " << textFontStyleStr << '\n'
              << "TextFontWeight: " << textWeightStr << '\n';
    return;
}