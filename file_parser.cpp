#include "file_parser.h"
#include <fstream>

void read_file(const string directory_path) {
    /*
    *   Test code for file parsing
    */
    QString save_file_path = ":/files/shape_list.txt";
    QFile save_file = QString(save_file_path);
    if (save_file.exists())
        cout << "file exists" << endl;

    string test_path = directory_path + "/shape_list.txt";
    cout << test_path << endl;

    fstream inData;
    inData.open(test_path);
    if (inData.is_open())
        cout << "is open" << endl;

    string testline;
    if (getline(inData, testline))
        cout << testline << endl;
    else
        cout << "getline fail" << endl;
    return;
}

void parse_file(fstream& inData) {

    return;
}
