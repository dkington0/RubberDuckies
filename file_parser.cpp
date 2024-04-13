#include "file_parser.h"

void read_file() {
    ifstream inData;
    inData.open("shape_list.txt");

    string shapeArray[5] {};
    if (inData.eof()) {
        cout << "reached end of file" << endl;
    } else {
        getline(inData, shapeArray[0]);
        cout << shapeArray[0];
    }


	return;
}
