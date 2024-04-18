#include "file_parser.h"
#include "vector.h"


struct TestLine {
    int id {};
    unique_ptr<int[]> dimensions;
    string penColor {};
    int penWidth {};
    string penStyle {};
    string penCapStyle {};
    string penJoinStyle {};

    TestLine(int i, unique_ptr<int[]> d, string color, int penW, string penSty, string penCapSty, string penJoinSty)
        : id{i}, dimensions{std::move(d)}, penColor{color}, penWidth{penW}, penStyle{penSty}, penCapStyle{penCapSty}, penJoinStyle{penJoinSty} {};
};

enum ShapeType {
    Line,
    Polyline,
    Polygon,
    Rectangle,
    Square,
    Ellipse,
    Circle,
    Text
};

void parse_file(fstream&);
// change to return Shape objects
void readLine(fstream&, int);
void readPolyLine(fstream&, int);
void readPolygon(fstream&, int);
void readRectangle(fstream&, int);
void readSquare(fstream&, int);
void readEllipse(fstream&, int);
void readCircle(fstream&, int);
void readText(fstream&, int);

void read_file(const string directory_path) {
    /*
    *   Test code for file parsing
    */

    fstream inData;
    string test_path = directory_path + "/shape_list.txt";
    cout << test_path << endl;
    if (filesystem::exists(test_path)) // tests if the file exists at the designated path
        cout << "file exists" <<endl;
    else {
        inData = fstream(test_path, ios::out);
        if (!inData.is_open())
            return; // TODO: change to throw instead of return
        inData.close();
    }

    inData.open(test_path, ios::in);
    if (inData.is_open())        // another test to see if it's open again
        parse_file(inData);
    else
        cout << "Failed to open file for reading" << endl; // change to a throw later

    return;
}

void parse_file(fstream& inData) {
    int counter {};
    string strArray[10];
    string current;

    while (getline(inData, current)) {
        if (!current.empty()) { // means that a new shape is starting
            cout << current << endl;
            int id {};

            // extract the id from the string
            // getting rid of the "ShapeID: " substring
            if (current.find("ShapeId") != string::npos) { // if it finds the substring "ShapeID"
                current = current.substr(9);
                id = stoi(current);
                cout << id << endl;
            } else {
                // throw
                cout << "Error: failed to find substring ShapeId" << endl;
            }

            ShapeType shapeType;
            if (getline(inData, current)) { //next line is the shape type
                if (current.find("ShapeType") != string::npos) { // if it finds the substring "ShapeType"
                    current = current.substr(11);
                    cout << current << endl;
                    if (current == "Line")
                        shapeType  = Line;
                    else if (current == "Polyline")
                        shapeType = Polyline;
                    else if (current == "Polygon")
                        shapeType = Polygon;
                    else if (current == "Rectangle")
                        shapeType = Rectangle;
                    else if (current == "Square")
                        shapeType = Square;
                    else if (current == "Ellipse")
                        shapeType = Ellipse;
                    else if (current == "Circle")
                        shapeType = Circle;
                    else if (current == "Text")
                        shapeType = Text;
                    else {
                        // throw
                        cout << "ShapeType failed to be identified" << endl;
                    }
                } else {
                    // throw
                    cout << "Error: failed to find substring ShapeType" << endl;
                }
            }

            // At this point, the program should have found the ID and Type of the shape
            // depending on the shape type, we will call different functions to read the next lines from inData.

            cout << current << endl;
            // logic for creating the shape
            // 1st line will always be the ID
            // 2nd line defines the type of the shape
                // -> call the corresponding "read shape" function
            switch (shapeType) { // current holds the shape type
            case Line:
                readLine(inData, id);
                break;
            case Polyline:
                readPolyLine(inData, id);
                break;
            case Polygon:
                readPolygon(inData, id);
                break;
            case Rectangle:
                readRectangle(inData, id);
                break;
            case Square:
                readSquare(inData, id);
                break;
            case Ellipse:
                readEllipse(inData, id);
                break;
            case Circle:
                readCircle(inData, id);
                break;
            case Text:
                readText(inData, id);
                break;
            default:
                // throw
                cout << "Error: switch on unidentified shape type enum" << endl;
            }
        }
    }

    if (inData.peek()!=EOF) // once getlines are done, check if there is still data in the file to be read
        cout << "Error: leftover data in file" << endl; // changed to a throw later

    return;
}

void readLine(fstream& inData, int id) {
    string current {};

    myStd::vector<int> dimensions;

    cout << "Start of Read Line fcn" << endl;
    while (getline(inData, current) && (!current.empty())) { // program is still reading from shape if the string is not empty
        string paramSubStr {};
        if (current.find(":") != string::npos) {
            paramSubStr = current.substr(0, current.find(":")); // splices beginning of string up until the colon
            cout << "Param SubStr: " << paramSubStr << endl;
            if (paramSubStr == "ShapeDimensions") {

                string dimensionsSubStr = current.substr(current.find(':')+1); // splices the string so only the chracters after ':' remain
                cout << "Dimension Sub String:" << dimensionsSubStr << endl;
                bool hasMoreDimensions {dimensionsSubStr.find(' ', 0) != string::npos}; // flag to determine when the while loop needs to stop

                while (hasMoreDimensions) {
                    size_t rBoundPosition {};
                    string newDimensionStr {};

                    //size_t lBoundPosition {};
                    // check first character
                    if (dimensionsSubStr.at(0) == ' ') {// if the first character is a space, we know there is a dimension
                        if (dimensionsSubStr.find(',', 1) != string::npos) {
                            rBoundPosition = dimensionsSubStr.find(',', 1);

                        } else {
                            rBoundPosition = dimensionsSubStr.length()-1;
                            //throw
                            //cout << "Neither \',\' or \' \' found in string" << endl;
                            //break;
                        }
                        newDimensionStr = dimensionsSubStr.substr(1, rBoundPosition);
                        dimensions.push_back(stoi(newDimensionStr));

                        if (dimensionsSubStr.at(rBoundPosition) == dimensionsSubStr.back())
                            hasMoreDimensions = false;
                        else
                            dimensionsSubStr = dimensionsSubStr.substr(rBoundPosition + 1);
                    } else {
                        //throw
                        cout << "Error in Read Line fcn: whitespace for next dimension not found." << endl;
                    }
                }
                /*
                for (int i {}; i < dimensions.size(); i++)
                    cout << dimensions[i] << " ";
                cout << endl;
                */
            }
            else if (paramSubStr == "PenColor") {
                cout << "Pen Color line" << endl;
            }
            else if (paramSubStr == "PenWidth") {
                cout << "Pen Width line" << endl;
            }
            else if (paramSubStr == "PenStyle") {
                cout << "Pen Style Line" << endl;
            }
            else if (paramSubStr == "PenCapStyle") {
                cout << "Pen Cap Style" << endl;
            }
            else if (paramSubStr == "PenJoinStyle") {
                cout << "Pen Join Style" << endl;
            }
            else {
                // throw
                cout << "Error During Read Line Function: Unidentified parameter string" << endl;
                return;
            }
        } else {
            cout << "Error During Read Line Function: failed to find \":\" in current string" << endl;
            return;
        }




        // Shape Dimension
        // splice off "ShapeDimensions:"

// There is no comma at the end - a shape with 3 commas would have 4 dimensions

        //cout << "Number of Commas in SHape index: " << numCommas << endl;
        // Pen Color

        // Pen Width

        // Pen Style

        // Pen Cap Style

        // Pen Join Style

    }
    //unique_ptr<int[]> paramShapeDimensions(std::move(dimensions));
    cout << "End of Read Line fcn" << endl;

    return;
}

void readPolyLine(fstream&, int) {
    return;
}
void readPolygon(fstream&, int) {
    return;
}
void readRectangle(fstream&, int) {
    return;
}
void readSquare(fstream&, int) {
    return;
}
void readEllipse(fstream&, int) {
    return;
}
void readCircle(fstream&, int) {
    return;
}
void readText(fstream&, int) {
    return;
}
