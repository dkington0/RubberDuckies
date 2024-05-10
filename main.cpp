#include "ellipse.h"
#include "mainwindow.h"
#include "file_parser.h"
#include <QApplication>
#include <QPaintEvent>
// #include "line.h"
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
// #include "canvas.h"

//template <class Type>
int main(int argc, char *argv[])
{
    //Line l;

    myStd::vector<Shape*> container;
    QApplication a(argc, argv);
    QString directory_path = a.applicationDirPath();
    read_file(directory_path.toStdString(), container);
    //container[0] = new circle;



    MainWindow w;
    w.show();

    // // Trying to draw shapes
    // QRect widgetRegion {0, 0, 1000, 1000};
    // QPaintEvent *paintTest = new QPaintEvent{widgetRegion};

    // //QPaintEvent paint;
    // container[0]->drawShapes(container, paintTest);
    QPoint point(460, 90);
    QPoint point1(470, 20);
    QPoint point2(530, 40);
    QPoint point3(540, 80);

    myStd::vector<QPoint> pline(4);
    pline[0] = point;
    pline[1] = point1;
    pline[2] = point2;
    pline[3] = point3;

    QPoint point4(900, 90);
    QPoint point5(910, 20);
    QPoint point6(970, 40);
    QPoint point7(980, 80);

    myStd::vector<QPoint> pgone(4);
    pgone[0] = point4;
    pgone[1] = point5;
    pgone[2] = point6;
    pgone[3] = point7;

    QString str = "Nothing Here";

    Line* line = new Line(1, QLine(20, 90, 100, 20));
    polyline* Polyline = new polyline(2, pline);
    polygon* Polygon = new polygon(3, pgone);
    rectangle* Rectangle = new rectangle(4, QRect(20, 200, 170, 100));
    square* Square = new square(5, 750, 150, 200);
    ellipse* Ellipse = new ellipse(6, QRect(520, 200, 170, 100));
    circle* Circle = new circle(7, 250, 150, 200);
    text* Text = new text(8, QRect(250, 425, 500, 50), Qt::AlignCenter, str, QFont(str, -1, -1, false));

    container.push_back(line);
    container.push_back(Polyline);
    container.push_back(Polygon);
    container.push_back(Rectangle);
    container.push_back(Square);
    container.push_back(Ellipse);
    container.push_back(Circle);
    container.push_back(Text);

    // Canvas canvas(container);

    // MainWindow w;
    // w.show();


    // Line* line = ;
    // Line fakeLine;
    // QObject::connect(&line, SIGNAL(w.shapeValue()), SLOT(w.setValue()));



    return a.exec();
}
