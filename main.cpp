#include "mainwindow.h"
#include "file_parser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    *   Test code for file parsing
    */
    fstream save_file;
    try {
        // QString object to store the file path for the shape save file
        // Shape save file MUST be in the same folder as the binary executable for the project
        // for example, my executable is stored RubberDuckies\build\Desktop_Qt_6_7_0_MinGW_64_bit-Debug
        //      your Debug folder will most likely be different, depending on your OS and compiler
        // Down the line we can add functionality to check if a file exists
        //      -> if it exists, read from it
        //      -> if it does not exist, create it
        QString save_file_path = a.applicationDirPath() + "/shape_list.txt";
        cout << save_file_path.toStdString() << endl;
        // opens the save file for reading
        save_file.open(save_file_path.toStdString());
        // Checks if the filed opened sucessfully
        if (save_file.is_open())
            read_file(save_file); // if opened successfully, read from file
        else {
            string err("Error: file failed to open successfully");
            throw err;
        }
    }
    catch (string err) {
        cout << err << endl;
    }
    catch (...) {
        cout << "Unexpected error during file read." << endl;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
