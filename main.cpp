#include "mainwindow.h"
#include "file_parser.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QString directory_path = a.applicationDirPath();
    read_file(directory_path.toStdString());

    MainWindow w;
    w.show();

    if(w.on_login_clicked())
        w.hide();

    return a.exec();
}
