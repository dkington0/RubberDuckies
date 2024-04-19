#include "file_parser.h"
#include "vector.h"


struct TestLine {
    int id {};
    myStd::vector<int> dimensions;
    Qt::GlobalColor penColor {};
    int penWidth {};
    Qt::PenStyle penStyle {};
    Qt::PenCapStyle penCapStyle {};
    Qt::PenJoinStyle penJoinStyle {};

    TestLine();
    TestLine(int i, myStd::vector<int> d, Qt::GlobalColor color, int penW, Qt::PenStyle penSty, Qt::PenCapStyle penCapSty, Qt::PenJoinStyle penJoinSty)
        : id{i}, dimensions{d}, penColor{color}, penWidth{penW}, penStyle{penSty}, penCapStyle{penCapSty}, penJoinStyle{penJoinSty} {}
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
    Qt::GlobalColor penColor;
    int penWidth;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle penCapStyle;
    Qt::PenJoinStyle penJoinStyle;

    cout << "Start of Read Line fcn" << endl;
    while (getline(inData, current) && (!current.empty())) { // program is still reading from shape if the string is not empty
        string paramSubStr {};
        if (current.find(":") != string::npos) {
            paramSubStr = current.substr(0, current.find(":")); // splices beginning of string up until the colon
            cout << "Param SubStr: " << paramSubStr << endl;

            // Reading Shape Dimension
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
                        }
                        newDimensionStr = dimensionsSubStr.substr(1, rBoundPosition);
                        dimensions.push_back(stoi(newDimensionStr));

                        if (dimensionsSubStr.at(rBoundPosition) == dimensionsSubStr.back())
                            hasMoreDimensions = false;
                        else
                            dimensionsSubStr = dimensionsSubStr.substr(rBoundPosition + 1);
                    } else {
                        cout << "Error in Read Line fcn: whitespace for next dimension not found." << endl;
                    }
                }

                for (int i {}; i < dimensions.size(); i++)
                    cout << dimensions[i] << " ";
                cout << endl;
            }

            // Reading Pen Color
            else if (paramSubStr == "PenColor") {
                //cout << "Pen Color line" << endl;
                string colorSubStr = current.substr(current.find(':')+2);
                cout << "Pen Color String: " << colorSubStr;
                if (colorSubStr == "white")
                    penColor = Qt::white;
                if (colorSubStr == "black")
                    penColor = Qt::black;
                else if (colorSubStr == "red")
                    penColor = Qt::red;
                else if (colorSubStr == "green")
                    penColor = Qt::green;
                else if (colorSubStr == "blue")
                    penColor = Qt::blue;
                else if (colorSubStr == "cyan")
                    penColor = Qt::cyan;
                else if (colorSubStr == "magenta")
                    penColor = Qt::magenta;
                else if (colorSubStr == "yellow")
                    penColor = Qt::yellow;
                else if (colorSubStr == "gray")
                    penColor = Qt::gray;
                else {
                    cout << "Pen color not found" << endl;
                }
            }
            else if (paramSubStr == "PenWidth") {
                string widthSubStr = current.substr(current.find(':')+2);
                cout << "Pen Width String:" << widthSubStr << endl;
                penWidth = stoi(widthSubStr);
            }
            else if (paramSubStr == "PenStyle") {

                string penSubStr = current.substr(current.find(':')+2);
                cout << "Pen Style String: " << penSubStr << endl;
                if (penSubStr == "NoPen")
                    penStyle = Qt::NoPen;
                else if (penSubStr == "SolidLine")
                    penStyle = Qt::SolidLine;
                else if (penSubStr == "DashLine")
                    penStyle = Qt::DashLine;
                else if (penSubStr == "DotLine")
                    penStyle = Qt::DotLine;
                else if (penSubStr == "DashDotLine")
                    penStyle = Qt::DashDotLine;
                else if (penSubStr == "DashDotDotLine")
                    penStyle = Qt::DashDotDotLine;
                else {
                    cout << "Error: Pen Style not found" << endl;
                }
            }
            else if (paramSubStr == "PenCapStyle") {

                string penCapSubStr = current.substr(current.find(':')+2);
                cout << "Pen Cap String: " << penCapSubStr << endl;
                if (penCapSubStr == "FlatCap")
                    penCapStyle = Qt::FlatCap;
                else if (penCapSubStr == "SquareCap")
                    penCapStyle = Qt::SquareCap;
                else if (penCapSubStr == "RoundCap")
                    penCapStyle = Qt::RoundCap;
                else
                    cout << "Error: Pen Cap Style Not Found" << endl;

            }
            else if (paramSubStr == "PenJoinStyle") {

                string penJoinSubStr = current.substr(current.find(':')+2);
                cout << "Pen Join String: " << penJoinSubStr << endl;
                if (penJoinSubStr == "MiterJoin")
                    penJoinStyle = Qt::MiterJoin;
                else if (penJoinSubStr == "BevelJoin")
                    penJoinStyle = Qt::BevelJoin;
                else if (penJoinSubStr == "RoundJoin")
                    penJoinStyle = Qt::RoundJoin;
                else
                    cout << "Error: Pen Join Style not found" << endl;

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



    }
    //unique_ptr<int[]> paramShapeDimensions(std::move(dimensions));
    cout << "End of Read Line fcn" << endl;
    TestLine outShape(id, dimensions, penColor, penWidth, penStyle, penCapStyle, penJoinStyle);
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
