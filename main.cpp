#include "mainwindow.h"
#include "file_parser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    
    // Test code for file parsing
    read_file();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
