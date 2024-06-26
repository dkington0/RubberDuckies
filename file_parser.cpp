#include "file_parser.h"
#include "vector.h"
#include <QFont>
#include "line.h"
#include "polyline.h"
#include "polygon.h"
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "circle.h"
#include "Text.h"

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

struct TestPolygon {
    int id {};
    myStd::vector<int> dimensions;
    Qt::GlobalColor penColor {};
    int penWidth {};
    Qt::PenStyle penStyle {};
    Qt::PenCapStyle penCapStyle {};
    Qt::PenJoinStyle penJoinStyle {};
    Qt::GlobalColor brushColor {};
    Qt::BrushStyle brushStyle {};

    TestPolygon();
    TestPolygon(int i, myStd::vector<int> d, Qt::GlobalColor color, int penW, Qt::PenStyle penSty, Qt::PenCapStyle penCapSty, Qt::PenJoinStyle penJoinSty, Qt::GlobalColor brushCol, Qt::BrushStyle brushSty)
        : id{i}, dimensions{d}, penColor{color}, penWidth{penW}, penStyle{penSty}, penCapStyle{penCapSty}, penJoinStyle{penJoinSty}, brushColor{brushCol}, brushStyle{brushSty} {}
};

struct TestRectangle {
    int id {};
    myStd::vector<int> dimensions;
    Qt::GlobalColor penColor {};
    int penWidth {};
    Qt::PenStyle penStyle {};
    Qt::PenCapStyle penCapStyle {};
    Qt::PenJoinStyle penJoinStyle {};
    Qt::GlobalColor brushColor {};
    Qt::BrushStyle brushStyle {};

    TestRectangle();
    TestRectangle(int i, myStd::vector<int> d, Qt::GlobalColor color, int penW, Qt::PenStyle penSty, Qt::PenCapStyle penCapSty, Qt::PenJoinStyle penJoinSty, Qt::GlobalColor brushCol, Qt::BrushStyle brushSty)
        : id{i}, dimensions{d}, penColor{color}, penWidth{penW}, penStyle{penSty}, penCapStyle{penCapSty}, penJoinStyle{penJoinSty}, brushColor{brushCol}, brushStyle{brushSty} {}
};

struct TestEllipse {
    int id {};
    myStd::vector<int> dimensions;
    Qt::GlobalColor penColor {};
    int penWidth {};
    Qt::PenStyle penStyle {};
    Qt::PenCapStyle penCapStyle {};
    Qt::PenJoinStyle penJoinStyle {};
    Qt::GlobalColor brushColor {};
    Qt::BrushStyle brushStyle {};

    TestEllipse();
    TestEllipse(int i, myStd::vector<int> d, Qt::GlobalColor color, int penW, Qt::PenStyle penSty, Qt::PenCapStyle penCapSty, Qt::PenJoinStyle penJoinSty, Qt::GlobalColor brushCol, Qt::BrushStyle brushSty)
        : id{i}, dimensions{d}, penColor{color}, penWidth{penW}, penStyle{penSty}, penCapStyle{penCapSty}, penJoinStyle{penJoinSty}, brushColor{brushCol}, brushStyle{brushSty} {}
};

struct TestText {
    int id {};
    myStd::vector<int> dimensions;

    // text string
    string textString {};
    // text color
    Qt::GlobalColor textColor {};
    // text alignment
    Qt::AlignmentFlag textAlignment {};
    // text point size
    int textPointSize {};
    // text font family
    string textFontFamily {};
    // text font style
    QFont::Style textFontStyle {};
    // text font weight
    QFont::Weight textFontWeight {};

    TestText();
    TestText(int i, myStd::vector<int> d, string textStr, Qt::GlobalColor color, Qt::AlignmentFlag align, int ptSize, string fontFamily, QFont::Style fontStyle, QFont::Weight fontWeight)
        : id{i}, dimensions{d}, textString{textStr}, textColor{color}, textAlignment{align}, textPointSize{ptSize}, textFontFamily{fontFamily}, textFontStyle{fontStyle}, textFontWeight{fontWeight} {}
};

enum ShapeType {
    enumLine,
    enumPolyline,
    enumPolygon,
    enumRectangle,
    enumSquare,
    enumEllipse,
    enumCircle,
    enumText
};

//void parse_file(fstream&);
// change to return Shape objects
void readLine(fstream&, int, myStd::vector<Shape*>& userShapes);
void readPolyLine(fstream&, int, myStd::vector<Shape*>& userShapes);
void readPolygon(fstream&, int, myStd::vector<Shape*>& userShapes);
void readRectangle(fstream&, int, myStd::vector<Shape*>& userShapes);
void readSquare(fstream&, int, myStd::vector<Shape*>& userShapes);
void readEllipse(fstream&, int, myStd::vector<Shape*>& userShapes);
void readCircle(fstream&, int, myStd::vector<Shape*>& userShapes);
void readText(fstream&, int, myStd::vector<Shape*>& userShapes);

void read_file(const string directory_path, myStd::vector<Shape*>& userShapes) {
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
    if (inData.is_open()) {       // another test to see if it's open again
        parse_file(inData, userShapes);
        //for (int i {}; i < userShapes.size(); i++)
        //    cout << userShapes[i]->getPen().color().isValid() << endl;
        inData.close();
        cout << "File parse completed" << endl;
    }
    else
        cout << "Failed to open file for reading" << endl; // change to a throw later
    return;
}

void parse_file(fstream& inData, myStd::vector<Shape*>& userShapes) {
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
                        shapeType  = enumLine;
                    else if (current == "Polyline")
                        shapeType = enumPolyline;
                    else if (current == "Polygon")
                        shapeType = enumPolygon;
                    else if (current == "Rectangle")
                        shapeType = enumRectangle;
                    else if (current == "Square")
                        shapeType = enumSquare;
                    else if (current == "Ellipse")
                        shapeType = enumEllipse;
                    else if (current == "Circle")
                        shapeType = enumCircle;
                    else if (current == "Text")
                        shapeType = enumText;
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
            case enumLine:
                readLine(inData, id, userShapes);
                break;
            case enumPolyline:
                readPolyLine(inData, id, userShapes);
                break;
            case enumPolygon:
                readPolygon(inData, id, userShapes);
                break;
            case enumRectangle:
                readRectangle(inData, id, userShapes);
                break;
            case enumSquare:
                readSquare(inData, id, userShapes);
                break;
            case enumEllipse:
                readEllipse(inData, id, userShapes);
                break;
            case enumCircle:
                readCircle(inData, id, userShapes);
                break;
            case enumText:
                readText(inData, id, userShapes);
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

void readLine(fstream& inData, int id, myStd::vector<Shape*>& userShapes) {
    string current {};

    myStd::vector<int> dimensions; //shape dimensions
    Qt::GlobalColor penColor; // shape pen color
    int penWidth;   //shape pen width
    Qt::PenStyle penStyle;  // shape pen style
    Qt::PenCapStyle penCapStyle;    // shape pen cap style
    Qt::PenJoinStyle penJoinStyle;  // shape pen join style
    myStd::vector<QPoint> points;

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
                bool isXCoord {false}; // determines if the given int is an x coordinate or not.
                int xCoord {};
                int yCoord {};

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
                        if (isXCoord) {  // if isXCoord is true, then the dimension should be stored as the x coordinate of a QPoint
                            xCoord = stoi(newDimensionStr);
                            isXCoord = false;   // if this is an x coordinate, the next dimension will be a y coordinate.
                        } else {    // if XCoord is false, the dimension should be stored as the y coordinate of a QPoint..
                            yCoord = stoi(newDimensionStr);
                            isXCoord = true; // if this is a y coordinate, the next dimension will be an x coordinate.
                            points.push_back(QPoint(xCoord, yCoord)); // if a Y coordinate is being stored, then an X coordinate has already been stored.
                                                                           // then we are able to make a QPoint, which is added to the points array.
                        }
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
                cout << "Pen Color String: " << colorSubStr << endl;
                if (colorSubStr == "white")
                    penColor = Qt::white;
                else if (colorSubStr == "black")
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

    QPen pen;
    pen.setColor(penColor);
    pen.setWidth(penWidth);
    pen.setStyle(penStyle);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);

    Line* newLine = new Line(QLine(points[0].x(), points[0].y(), points[1].x(), points[1].y()));
    newLine->setPen(pen);

    //cout << "line shape pen issolid: " << newLine->getPen().isSolid() << endl;
    userShapes.push_back(newLine);

    return;
}

void readPolyLine(fstream& inData, int id, myStd::vector<Shape*>& userShapes) {
    string current {};

    myStd::vector<int> dimensions; //shape dimensions
    Qt::GlobalColor penColor; // shape pen color
    int penWidth;   //shape pen width
    Qt::PenStyle penStyle;  // shape pen style
    Qt::PenCapStyle penCapStyle;    // shape pen cap style
    Qt::PenJoinStyle penJoinStyle;  // shape pen join style
    myStd::vector<QPoint> points;

    cout << "Start of Read Polyline fcn" << endl;
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
                bool isXCoord {false}; // determines if the given int is an x coordinate or not.
                int xCoord {};
                int yCoord {};

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
                        if (isXCoord) {  // if isXCoord is true, then the dimension should be stored as the x coordinate of a QPoint
                            xCoord = stoi(newDimensionStr);
                            isXCoord = false;   // if this is an x coordinate, the next dimension will be a y coordinate.
                        } else {    // if XCoord is false, the dimension should be stored as the y coordinate of a QPoint..
                            yCoord = stoi(newDimensionStr);
                            isXCoord = true; // if this is a y coordinate, the next dimension will be an x coordinate.
                            points.push_back(QPoint(xCoord, yCoord)); // if a Y coordinate is being stored, then an X coordinate has already been stored.
                                                                      // then we are able to make a QPoint, which is added to the points array.
                        }
                        if (dimensionsSubStr.at(rBoundPosition) == dimensionsSubStr.back())
                            hasMoreDimensions = false;
                        else
                            dimensionsSubStr = dimensionsSubStr.substr(rBoundPosition + 1);
                    } else {
                        cout << "Error in Read Polyline fcn: whitespace for next dimension not found." << endl;
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
                cout << "Pen Color String: " << colorSubStr <<endl;
                if (colorSubStr == "white")
                    penColor = Qt::white;
                else if (colorSubStr == "black")
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
                cout << "Error During Read Polyline Function: Unidentified parameter string" << endl;
                return;
            }
        } else {
            cout << "Error During Read Polyline Function: failed to find \":\" in current string" << endl;
            return;
        }
    }

    QPen pen;
    pen.setColor(penColor);
    pen.setWidth(penWidth);
    pen.setStyle(penStyle);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);

    polyline* newPolyline = new polyline(points);
    newPolyline->setPen(pen);

    userShapes.push_back(newPolyline);

    cout << "End of Read Polyline fcn" << endl;

    return;
}

void readPolygon(fstream& inData, int id, myStd::vector<Shape*>& userShapes) {
    string current {};

    myStd::vector<int> dimensions; //shape dimensions
    Qt::GlobalColor penColor; // shape pen color
    int penWidth;   //shape pen width
    Qt::PenStyle penStyle;  // shape pen style
    Qt::PenCapStyle penCapStyle;    // shape pen cap style
    Qt::PenJoinStyle penJoinStyle;  // shape pen join style
    Qt::GlobalColor brushColor; // brush color
    Qt::BrushStyle brushStyle;  // brush style
    myStd::vector<QPoint> points;

    cout << "Start of Read Polygon fcn" << endl;
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
                bool isXCoord {false}; // determines if the given int is an x coordinate or not.
                int xCoord {};
                int yCoord {};

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
                        if (isXCoord) {  // if isXCoord is true, then the dimension should be stored as the x coordinate of a QPoint
                            xCoord = stoi(newDimensionStr);
                            isXCoord = false;   // if this is an x coordinate, the next dimension will be a y coordinate.
                        } else {    // if XCoord is false, the dimension should be stored as the y coordinate of a QPoint..
                            yCoord = stoi(newDimensionStr);
                            isXCoord = true; // if this is a y coordinate, the next dimension will be an x coordinate.
                            points.push_back(QPoint(xCoord, yCoord)); // if a Y coordinate is being stored, then an X coordinate has already been stored.
                                // then we are able to make a QPoint, which is added to the points array.
                        }

                        if (dimensionsSubStr.at(rBoundPosition) == dimensionsSubStr.back())
                            hasMoreDimensions = false;
                        else
                            dimensionsSubStr = dimensionsSubStr.substr(rBoundPosition + 1);
                    } else {
                        cout << "Error in Read Polygon fcn: whitespace for next dimension not found." << endl;
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
                cout << "Pen Color String: " << colorSubStr << endl;
                if (colorSubStr == "white")
                    penColor = Qt::white;
                else if (colorSubStr == "black")
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
            else if (paramSubStr == "BrushColor") {

                string brushColorSubStr = current.substr(current.find(':')+2);
                cout << "Brush Color String: " << brushColorSubStr << endl;
                if (brushColorSubStr == "white")
                    brushColor = Qt::white;
                else if (brushColorSubStr == "black")
                    brushColor = Qt::black;
                else if (brushColorSubStr == "red")
                    brushColor = Qt::red;
                else if (brushColorSubStr == "green")
                    brushColor = Qt::green;
                else if (brushColorSubStr == "blue")
                    brushColor = Qt::blue;
                else if (brushColorSubStr == "cyan")
                    brushColor = Qt::cyan;
                else if (brushColorSubStr == "magenta")
                    brushColor = Qt::magenta;
                else if (brushColorSubStr == "yellow")
                    brushColor = Qt::yellow;
                else if (brushColorSubStr == "gray")
                    brushColor = Qt::gray;
                else {
                    cout << "Brush color not found" << endl;
                }

            }
            else if (paramSubStr == "BrushStyle") {

                string brushStyleSubStr = current.substr(current.find(':')+2);
                cout << "Brush Style String: " << brushStyleSubStr << endl;
                if (brushStyleSubStr == "SolidPattern")
                    brushStyle = Qt::SolidPattern;
                else if (brushStyleSubStr == "HorPattern")
                    brushStyle = Qt::HorPattern;
                else if (brushStyleSubStr == "VerPattern")
                    brushStyle = Qt::VerPattern;
                else if (brushStyleSubStr == "NoBrush")
                    brushStyle = Qt::NoBrush;
                else
                    cout << "Error: Brush Style not found" << endl;

            }
            else {
                // throw
                cout << "Error During Read Polygon Function: Unidentified parameter string" << endl;
                return;
            }
        } else {
            cout << "Error During Read Polygon Function: failed to find \":\" in current string" << endl;
            return;
        }
    }

    QPen pen;
    pen.setColor(penColor);
    pen.setWidth(penWidth);
    pen.setStyle(penStyle);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);

    QBrush brush;
    brush.setColor(brushColor);
    brush.setStyle(brushStyle);

    pen.setBrush(brush);

    polygon* newPolygon = new polygon(points);
    newPolygon->setPen(pen);

    userShapes.push_back(newPolygon);

    cout << "End of Read Polygon fcn" << endl;
    return;
}

void readRectangle(fstream& inData, int id, myStd::vector<Shape*>& userShapes) {
    string current {};

    myStd::vector<int> dimensions; //shape dimensions
    Qt::GlobalColor penColor; // shape pen color
    int penWidth;   //shape pen width
    Qt::PenStyle penStyle;  // shape pen style
    Qt::PenCapStyle penCapStyle;    // shape pen cap style
    Qt::PenJoinStyle penJoinStyle;  // shape pen join style
    Qt::GlobalColor brushColor; // brush color
    Qt::BrushStyle brushStyle;  // brush style
    myStd::vector<QPoint> points;

    cout << "Start of Read Rectangle fcn" << endl;
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
                bool isXCoord {false}; // determines if the given int is an x coordinate or not.
                int xCoord {};
                int yCoord {};

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
                        if (isXCoord) {  // if isXCoord is true, then the dimension should be stored as the x coordinate of a QPoint
                            xCoord = stoi(newDimensionStr);
                            isXCoord = false;   // if this is an x coordinate, the next dimension will be a y coordinate.
                        } else {    // if XCoord is false, the dimension should be stored as the y coordinate of a QPoint..
                            yCoord = stoi(newDimensionStr);
                            isXCoord = true; // if this is a y coordinate, the next dimension will be an x coordinate.
                            points.push_back(QPoint(xCoord, yCoord)); // if a Y coordinate is being stored, then an X coordinate has already been stored.
                                // then we are able to make a QPoint, which is added to the points array.
                        }

                        if (dimensionsSubStr.at(rBoundPosition) == dimensionsSubStr.back())
                            hasMoreDimensions = false;
                        else
                            dimensionsSubStr = dimensionsSubStr.substr(rBoundPosition + 1);
                    } else {
                        cout << "Error in Read Rectangle fcn: whitespace for next dimension not found." << endl;
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
                cout << "Pen Color String: " << colorSubStr << endl;
                if (colorSubStr == "white")
                    penColor = Qt::white;
                else if (colorSubStr == "black")
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
            else if (paramSubStr == "BrushColor") {

                string brushColorSubStr = current.substr(current.find(':')+2);
                cout << "Brush Color String: " << brushColorSubStr << endl;
                if (brushColorSubStr == "white")
                    brushColor = Qt::white;
                else if (brushColorSubStr == "black")
                    brushColor = Qt::black;
                else if (brushColorSubStr == "red")
                    brushColor = Qt::red;
                else if (brushColorSubStr == "green")
                    brushColor = Qt::green;
                else if (brushColorSubStr == "blue")
                    brushColor = Qt::blue;
                else if (brushColorSubStr == "cyan")
                    brushColor = Qt::cyan;
                else if (brushColorSubStr == "magenta")
                    brushColor = Qt::magenta;
                else if (brushColorSubStr == "yellow")
                    brushColor = Qt::yellow;
                else if (brushColorSubStr == "gray")
                    brushColor = Qt::gray;
                else {
                    cout << "Brush color not found" << endl;
                }

            }
            else if (paramSubStr == "BrushStyle") {

                string brushStyleSubStr = current.substr(current.find(':')+2);
                cout << "Brush Style String: " << brushStyleSubStr << endl;
                if (brushStyleSubStr == "SolidPattern")
                    brushStyle = Qt::SolidPattern;
                else if (brushStyleSubStr == "HorPattern")
                    brushStyle = Qt::HorPattern;
                else if (brushStyleSubStr == "VerPattern")
                    brushStyle = Qt::VerPattern;
                else if (brushStyleSubStr == "NoBrush")
                    brushStyle = Qt::NoBrush;
                else
                    cout << "Error: Brush Style not found" << endl;

            }
            else {
                // throw
                cout << "Error During Read Rectangle Function: Unidentified parameter string" << endl;
                return;
            }
        } else {
            cout << "Error During Read Rectangle Function: failed to find \":\" in current string" << endl;
            return;
        }
    }

    QPen pen;
    pen.setColor(penColor);
    pen.setWidth(penWidth);
    pen.setStyle(penStyle);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);

    QBrush brush;
    brush.setColor(brushColor);
    brush.setStyle(brushStyle);

    // width and height of the rectangle come from the x and y coordinates of the second QPoint
    int width = points[1].x();
    int height = points[1].y();

    QRect boundRect(points[0].x(), points[0].y(), width, height);
    rectangle* newRectangle = new rectangle(boundRect);

    pen.setBrush(brush);
    newRectangle->setPen(pen);

    userShapes.push_back(newRectangle);

    cout << "End of Read Rectangle fcn" << endl;
    return;
}

void readSquare(fstream& inData, int id, myStd::vector<Shape*>& userShapes) {
    string current {};

    myStd::vector<int> dimensions; //shape dimensions
    Qt::GlobalColor penColor; // shape pen color
    int penWidth;   //shape pen width
    Qt::PenStyle penStyle;  // shape pen style
    Qt::PenCapStyle penCapStyle;    // shape pen cap style
    Qt::PenJoinStyle penJoinStyle;  // shape pen join style
    Qt::GlobalColor brushColor; // brush color
    Qt::BrushStyle brushStyle;  // brush style
    myStd::vector<QPoint> points;

    cout << "Start of Read Square fcn" << endl;
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
                bool isXCoord {false}; // determines if the given int is an x coordinate or not.
                int xCoord {};
                int yCoord {};

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
                        if (isXCoord) {  // if isXCoord is true, then the dimension should be stored as the x coordinate of a QPoint
                            xCoord = stoi(newDimensionStr);
                            isXCoord = false;   // if this is an x coordinate, the next dimension will be a y coordinate.
                        } else {    // if XCoord is false, the dimension should be stored as the y coordinate of a QPoint..
                            yCoord = stoi(newDimensionStr);
                            isXCoord = true; // if this is a y coordinate, the next dimension will be an x coordinate.
                            points.push_back(QPoint(xCoord, yCoord)); // if a Y coordinate is being stored, then an X coordinate has already been stored.
                                // then we are able to make a QPoint, which is added to the points array.
                        }

                        if (dimensionsSubStr.at(rBoundPosition) == dimensionsSubStr.back())
                            hasMoreDimensions = false;
                        else
                            dimensionsSubStr = dimensionsSubStr.substr(rBoundPosition + 1);
                    } else {
                        cout << "Error in Read Polygon fcn: whitespace for next dimension not found." << endl;
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
                cout << "Pen Color String: " << colorSubStr << endl;
                if (colorSubStr == "white")
                    penColor = Qt::white;
                else if (colorSubStr == "black")
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
            else if (paramSubStr == "BrushColor") {

                string brushColorSubStr = current.substr(current.find(':')+2);
                cout << "Brush Color String: " << brushColorSubStr << endl;
                if (brushColorSubStr == "white")
                    brushColor = Qt::white;
                else if (brushColorSubStr == "black")
                    brushColor = Qt::black;
                else if (brushColorSubStr == "red")
                    brushColor = Qt::red;
                else if (brushColorSubStr == "green")
                    brushColor = Qt::green;
                else if (brushColorSubStr == "blue")
                    brushColor = Qt::blue;
                else if (brushColorSubStr == "cyan")
                    brushColor = Qt::cyan;
                else if (brushColorSubStr == "magenta")
                    brushColor = Qt::magenta;
                else if (brushColorSubStr == "yellow")
                    brushColor = Qt::yellow;
                else if (brushColorSubStr == "gray")
                    brushColor = Qt::gray;
                else {
                    cout << "Brush color not found" << endl;
                }

            }
            else if (paramSubStr == "BrushStyle") {

                string brushStyleSubStr = current.substr(current.find(':')+2);
                cout << "Brush Style String: " << brushStyleSubStr << endl;
                if (brushStyleSubStr == "SolidPattern")
                    brushStyle = Qt::SolidPattern;
                else if (brushStyleSubStr == "HorPattern")
                    brushStyle = Qt::HorPattern;
                else if (brushStyleSubStr == "VerPattern")
                    brushStyle = Qt::VerPattern;
                else if (brushStyleSubStr == "NoBrush")
                    brushStyle = Qt::NoBrush;
                else
                    cout << "Error: Brush Style not found" << endl;

            }
            else {
                // throw
                cout << "Error During Read Square Function: Unidentified parameter string" << endl;
                return;
            }
        } else {
            cout << "Error During Read Square Function: failed to find \":\" in current string" << endl;
            return;
        }
    }

    QPen pen;
    pen.setColor(penColor);
    pen.setWidth(penWidth);
    pen.setStyle(penStyle);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);

    QBrush brush;
    brush.setColor(brushColor);
    brush.setStyle(brushStyle);

    int sides = points[1].x();
    //QRect boundingRect(points[0].x(), points[0].y(), sides, sides);
    //square* newSquare = new square(boundingRect);
    square* newSquare = new square(points[0].x(), points[0].y(), sides);

    pen.setBrush(brush);
    newSquare->setPen(pen);

    userShapes.push_back(newSquare);

    cout << "End of Read Square fcn" << endl;
    return;
}

void readEllipse(fstream& inData, int id, myStd::vector<Shape*>& userShapes) {
    string current {};

    myStd::vector<int> dimensions; //shape dimensions
    Qt::GlobalColor penColor; // shape pen color
    int penWidth;   //shape pen width
    Qt::PenStyle penStyle;  // shape pen style
    Qt::PenCapStyle penCapStyle;    // shape pen cap style
    Qt::PenJoinStyle penJoinStyle;  // shape pen join style
    Qt::GlobalColor brushColor; // brush color
    Qt::BrushStyle brushStyle;  // brush style
    myStd::vector<QPoint> points;

    cout << "Start of Read Ellipse fcn" << endl;
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
                bool isXCoord {false}; // determines if the given int is an x coordinate or not.
                int xCoord {};
                int yCoord {};

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
                        if (isXCoord) {  // if isXCoord is true, then the dimension should be stored as the x coordinate of a QPoint
                            xCoord = stoi(newDimensionStr);
                            isXCoord = false;   // if this is an x coordinate, the next dimension will be a y coordinate.
                        } else {    // if XCoord is false, the dimension should be stored as the y coordinate of a QPoint..
                            yCoord = stoi(newDimensionStr);
                            isXCoord = true; // if this is a y coordinate, the next dimension will be an x coordinate.
                            points.push_back(QPoint(xCoord, yCoord)); // if a Y coordinate is being stored, then an X coordinate has already been stored.
                                // then we are able to make a QPoint, which is added to the points array.
                        }

                        if (dimensionsSubStr.at(rBoundPosition) == dimensionsSubStr.back())
                            hasMoreDimensions = false;
                        else
                            dimensionsSubStr = dimensionsSubStr.substr(rBoundPosition + 1);
                    } else {
                        cout << "Error in Read Ellipse fcn: whitespace for next dimension not found." << endl;
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
                cout << "Pen Color String: " << colorSubStr << endl;
                if (colorSubStr == "white")
                    penColor = Qt::white;
                else if (colorSubStr == "black")
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
            else if (paramSubStr == "BrushColor") {

                string brushColorSubStr = current.substr(current.find(':')+2);
                cout << "Brush Color String: " << brushColorSubStr << endl;
                if (brushColorSubStr == "white")
                    brushColor = Qt::white;
                else if (brushColorSubStr == "black")
                    brushColor = Qt::black;
                else if (brushColorSubStr == "red")
                    brushColor = Qt::red;
                else if (brushColorSubStr == "green")
                    brushColor = Qt::green;
                else if (brushColorSubStr == "blue")
                    brushColor = Qt::blue;
                else if (brushColorSubStr == "cyan")
                    brushColor = Qt::cyan;
                else if (brushColorSubStr == "magenta")
                    brushColor = Qt::magenta;
                else if (brushColorSubStr == "yellow")
                    brushColor = Qt::yellow;
                else if (brushColorSubStr == "gray")
                    brushColor = Qt::gray;
                else {
                    cout << "Brush color not found" << endl;
                }

            }
            else if (paramSubStr == "BrushStyle") {

                string brushStyleSubStr = current.substr(current.find(':')+2);
                cout << "Brush Style String: " << brushStyleSubStr << endl;
                if (brushStyleSubStr == "SolidPattern")
                    brushStyle = Qt::SolidPattern;
                else if (brushStyleSubStr == "HorPattern")
                    brushStyle = Qt::HorPattern;
                else if (brushStyleSubStr == "VerPattern")
                    brushStyle = Qt::VerPattern;
                else if (brushStyleSubStr == "NoBrush")
                    brushStyle = Qt::NoBrush;
                else
                    cout << "Error: Brush Style not found" << endl;

            }
            else {
                // throw
                cout << "Error During Read Ellipse Function: Unidentified parameter string" << endl;
                return;
            }
        } else {
            cout << "Error During Read Ellipse Function: failed to find \":\" in current string" << endl;
            return;
        }
    }

    QPen pen;
    pen.setColor(penColor);
    pen.setWidth(penWidth);
    pen.setStyle(penStyle);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);

    QBrush brush;
    brush.setColor(brushColor);
    brush.setStyle(brushStyle);

    int width = points[1].x();
    int height = points[1].y();
    QRect boundingRect(points[0].x(), points[0].y(), width, height);

    ellipse* newEllipse = new ellipse(boundingRect);

    pen.setBrush(brush);
    newEllipse->setPen(pen);

    userShapes.push_back(newEllipse);

    cout << "End of Read Ellipse fcn" << endl;
    return;
}

void readCircle(fstream& inData, int id, myStd::vector<Shape*>& userShapes) {
    string current {};

    myStd::vector<int> dimensions; //shape dimensions
    Qt::GlobalColor penColor; // shape pen color
    int penWidth;   //shape pen width
    Qt::PenStyle penStyle;  // shape pen style
    Qt::PenCapStyle penCapStyle;    // shape pen cap style
    Qt::PenJoinStyle penJoinStyle;  // shape pen join style
    Qt::GlobalColor brushColor; // brush color
    Qt::BrushStyle brushStyle;  // brush style
    myStd::vector<QPoint> points;

    cout << "Start of Read Circle fcn" << endl;
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
                bool isXCoord {false}; // determines if the given int is an x coordinate or not.
                int xCoord {};
                int yCoord {};

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
                        if (isXCoord) {  // if isXCoord is true, then the dimension should be stored as the x coordinate of a QPoint
                            xCoord = stoi(newDimensionStr);
                            isXCoord = false;   // if this is an x coordinate, the next dimension will be a y coordinate.
                        } else {    // if XCoord is false, the dimension should be stored as the y coordinate of a QPoint..
                            yCoord = stoi(newDimensionStr);
                            isXCoord = true; // if this is a y coordinate, the next dimension will be an x coordinate.
                            points.push_back(QPoint(xCoord, yCoord)); // if a Y coordinate is being stored, then an X coordinate has already been stored.
                                // then we are able to make a QPoint, which is added to the points array.
                        }

                        if (dimensionsSubStr.at(rBoundPosition) == dimensionsSubStr.back())
                            hasMoreDimensions = false;
                        else
                            dimensionsSubStr = dimensionsSubStr.substr(rBoundPosition + 1);
                    } else {
                        cout << "Error in Read Circle fcn: whitespace for next dimension not found." << endl;
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
                cout << "Pen Color String: " << colorSubStr << endl;
                if (colorSubStr == "white")
                    penColor = Qt::white;
                else if (colorSubStr == "black")
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
            else if (paramSubStr == "BrushColor") {

                string brushColorSubStr = current.substr(current.find(':')+2);
                cout << "Brush Color String: " << brushColorSubStr << endl;
                if (brushColorSubStr == "white")
                    brushColor = Qt::white;
                else if (brushColorSubStr == "black")
                    brushColor = Qt::black;
                else if (brushColorSubStr == "red")
                    brushColor = Qt::red;
                else if (brushColorSubStr == "green")
                    brushColor = Qt::green;
                else if (brushColorSubStr == "blue")
                    brushColor = Qt::blue;
                else if (brushColorSubStr == "cyan")
                    brushColor = Qt::cyan;
                else if (brushColorSubStr == "magenta")
                    brushColor = Qt::magenta;
                else if (brushColorSubStr == "yellow")
                    brushColor = Qt::yellow;
                else if (brushColorSubStr == "gray")
                    brushColor = Qt::gray;
                else {
                    cout << "Brush color not found" << endl;
                }

            }
            else if (paramSubStr == "BrushStyle") {

                string brushStyleSubStr = current.substr(current.find(':')+2);
                cout << "Brush Style String: " << brushStyleSubStr << endl;
                if (brushStyleSubStr == "SolidPattern")
                    brushStyle = Qt::SolidPattern;
                else if (brushStyleSubStr == "HorPattern")
                    brushStyle = Qt::HorPattern;
                else if (brushStyleSubStr == "VerPattern")
                    brushStyle = Qt::VerPattern;
                else if (brushStyleSubStr == "NoBrush")
                    brushStyle = Qt::NoBrush;
                else
                    cout << "Error: Brush Style not found" << endl;

            }
            else {
                // throw
                cout << "Error During Read Circle Function: Unidentified parameter string" << endl;
                return;
            }
        } else {
            cout << "Error During Read Circle Function: failed to find \":\" in current string" << endl;
            return;
        }
    }

    QPen pen;
    pen.setColor(penColor);
    pen.setWidth(penWidth);
    pen.setStyle(penStyle);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJoinStyle);

    QBrush brush;
    brush.setColor(brushColor);
    brush.setStyle(brushStyle);

    int sides = points[1].x();
    //QRect boundingRect(points[0].x(), points[0].y(), sides, sides);
    //circle* newCircle = new circle(boundingRect);
    circle* newCircle = new circle(points[0].x(), points[0].y(), sides);

    pen.setBrush(brush);
    newCircle->setPen(pen);

    userShapes.push_back(newCircle);

    cout << "End of Read Circle fcn" << endl;
    return;
}

void readText(fstream& inData, int id, myStd::vector<Shape*>& userShapes) {

    myStd::vector<int> dimensions;
    // text string
    string textString {};
    // text color
    Qt::GlobalColor textColor {};
    // text alignment
    Qt::AlignmentFlag textAlignment {};
    // text point size
    int textPointSize {};
    // text font family
    string textFontFamily {};
    // text font style
    QFont::Style textFontStyle {};
    // text font weight
    QFont::Weight textFontWeight {};
    string current {};
    myStd::vector<QPoint> points;

    cout << "Start of Read Text fcn" << endl;
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
                bool isXCoord {false}; // determines if the given int is an x coordinate or not.
                int xCoord {};
                int yCoord {};

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
                        if (isXCoord) {  // if isXCoord is true, then the dimension should be stored as the x coordinate of a QPoint
                            xCoord = stoi(newDimensionStr);
                            isXCoord = false;   // if this is an x coordinate, the next dimension will be a y coordinate.
                        } else {    // if XCoord is false, the dimension should be stored as the y coordinate of a QPoint..
                            yCoord = stoi(newDimensionStr);
                            isXCoord = true; // if this is a y coordinate, the next dimension will be an x coordinate.
                            points.push_back(QPoint(xCoord, yCoord)); // if a Y coordinate is being stored, then an X coordinate has already been stored.
                                // then we are able to make a QPoint, which is added to the points array.
                        }

                        if (dimensionsSubStr.at(rBoundPosition) == dimensionsSubStr.back())
                            hasMoreDimensions = false;
                        else
                            dimensionsSubStr = dimensionsSubStr.substr(rBoundPosition + 1);
                    } else {
                        cout << "Error in Read Text fcn: whitespace for next dimension not found." << endl;
                    }
                }

                for (int i {}; i < dimensions.size(); i++)
                    cout << dimensions[i] << " ";
                cout << endl;
            }

            else if (paramSubStr == "TextString") {
                string textSubStr = current.substr(current.find(':')+2);
                cout << "Text String:" << textSubStr << endl;
                textString = textSubStr;
            }

            else if (paramSubStr == "TextColor") {
                string textColorSubStr = current.substr(current.find(':')+2);
                cout << "Text Color String: " << textColorSubStr << endl;
                if (textColorSubStr == "white")
                    textColor = Qt::white;
                else if (textColorSubStr == "black")
                    textColor = Qt::black;
                else if (textColorSubStr == "red")
                    textColor = Qt::red;
                else if (textColorSubStr == "green")
                    textColor = Qt::green;
                else if (textColorSubStr == "blue")
                    textColor = Qt::blue;
                else if (textColorSubStr == "cyan")
                    textColor = Qt::cyan;
                else if (textColorSubStr == "magenta")
                    textColor = Qt::magenta;
                else if (textColorSubStr == "yellow")
                    textColor = Qt::yellow;
                else if (textColorSubStr == "gray")
                    textColor = Qt::gray;
                else {
                    cout << "Text color not found" << endl;
                }
            }

            else if (paramSubStr == "TextAlignment") {
                string textAlignSubStr = current.substr(current.find(':')+2);
                cout << "Text Alignment Style String: " << textAlignSubStr << endl;
                if (textAlignSubStr == "AlignLeft")
                    textAlignment = Qt::AlignLeft;
                else if (textAlignSubStr == "AlignRight")
                    textAlignment = Qt::AlignRight;
                else if (textAlignSubStr == "AlignTop")
                    textAlignment = Qt::AlignTop;
                else if (textAlignSubStr == "AlignBottom")
                    textAlignment = Qt::AlignBottom;
                else if (textAlignSubStr == "AlignCenter")
                    textAlignment = Qt::AlignCenter;
                else {
                    cout << "Error: Text Alignment Style not found" << endl;
                }
            }

            else if (paramSubStr == "TextPointSize") {
                string textPointSubStr = current.substr(current.find(':')+2);
                cout << "Text Point Size String:" << textPointSubStr << endl;
                textPointSize = stoi(textPointSubStr);
            }

            else if (paramSubStr == "TextFontFamily") {
                string textFontFamilySubStr = current.substr(current.find(':')+2);
                cout << "Text Font Family String: " << textFontFamilySubStr << endl;
                if (textFontFamilySubStr == "Comic Sans MS")
                    textFontFamily = "Comic Sans MS";
                else if (textFontFamilySubStr == "Courier")
                    textFontFamily = "Courier";
                else if (textFontFamilySubStr == "Helvetica")
                    textFontFamily = "Helvetica";
                else if (textFontFamilySubStr == "Times")
                    textFontFamily = "Times";
                else
                    cout << "Error: Text Font Family Not Found" << endl;

            }

            else if (paramSubStr == "TextFontStyle") {
                string textFontStyleSubStr = current.substr(current.find(':')+2);
                cout << "Text Font Style String: " << textFontStyleSubStr << endl;
                if (textFontStyleSubStr == "StyleNormal")
                    textFontStyle = QFont::StyleNormal;
                else if (textFontStyleSubStr == "StyleItalic")
                    textFontStyle = QFont::StyleItalic;
                else if (textFontStyleSubStr == "StyleOblique")
                    textFontStyle = QFont::StyleOblique;
                else
                    cout << "Error: Text Font Style not found" << endl;

            }

            else if (paramSubStr == "TextFontWeight") {
                string textFontWeightSubStr = current.substr(current.find(':')+2);
                cout << "Text Font Weight String: " << textFontWeightSubStr << endl;
                if (textFontWeightSubStr == "Thin")
                    textFontWeight = QFont::Thin;
                else if (textFontWeightSubStr == "Light")
                    textFontWeight = QFont::Light;
                else if (textFontWeightSubStr == "Normal")
                    textFontWeight = QFont::Normal;
                else if (textFontWeightSubStr == "Bold")
                    textFontWeight = QFont::Bold;
                else {
                    cout << "Text Font Weight not found" << endl;
                }

            }
            else {
                // throw
                cout << "Error During Read Text Function: Unidentified parameter string" << endl;
                return;
            }
        } else {
            cout << "Error During Read Text Function: failed to find \":\" in current string" << endl;
            return;
        }
    }
    cout << "End of Read Text fcn" << endl;
    //QFont(const QString &family, int pointSize = -1, int weight = -1, bool italic = false)
    QRect boundingRect(points[0].x(), points[0].y(), points[1].x(), points[1].y());
    QPen newPen(textColor);

    QFont newFont(textFontFamily.c_str(), textPointSize, textFontWeight);
    newFont.setStyle(textFontStyle);

    text* newText = new text(boundingRect, textAlignment, QString(textString.c_str()), newFont);
    newText->setPen(newPen);

    userShapes.push_back(newText);
}
