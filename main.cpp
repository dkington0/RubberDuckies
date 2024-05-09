#include "mainwindow.h"
#include "file_parser.h"
#include <QApplication>
#include <QPaintEvent>
// #include "line.h"
#include "vector.h"
#include "shape.h"
#include "circle.h"
#include "ellipse.h"
#include "rectangle.h"
#include "square.h"
#include "polygon.h"
#include "polyline.h"
#include "Text.h"

//template <class Type>
int main(int argc, char *argv[])
{
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


    // Line* line = ;
    // Line fakeLine;
    // QObject::connect(&line, SIGNAL(w.shapeValue()), SLOT(w.setValue()));



    return a.exec();
}
