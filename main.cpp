#include "mainwindow.h"
#include "file_parser.h"
#include <QApplication>
#include "line.h"
#include "vector.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QString directory_path = a.applicationDirPath();
    myStd::vector<Shape*> userShapes;
    read_file(directory_path.toStdString(), userShapes);

    MainWindow w;
    w.show();
    // Line* line = ;
    // Line fakeLine;
    // QObject::connect(&line, SIGNAL(w.shapeValue()), SLOT(w.setValue()));



    return a.exec();
}
