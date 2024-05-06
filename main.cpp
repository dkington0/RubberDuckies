#include "mainwindow.h"
#include "file_parser.h"
#include <QApplication>
// #include "line.h"
#include "vector.h"
#include "shape.h"

//template <class Type>
int main(int argc, char *argv[])
{
    myStd::vector<Shape*> container;
    QApplication a(argc, argv);
    QString directory_path = a.applicationDirPath();
    read_file(directory_path.toStdString(), container);

    MainWindow w;
    w.show();
    // Line* line = ;
    // Line fakeLine;
    // QObject::connect(&line, SIGNAL(w.shapeValue()), SLOT(w.setValue()));



    return a.exec();
}
