#include "mainwindow.h"
#include "file_parser.h"
#include <QApplication>
#include "line.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QString directory_path = a.applicationDirPath();
    read_file(directory_path.toStdString());

    MainWindow w;
    w.show();

    Line line;
    line.show();

    return a.exec();
}
