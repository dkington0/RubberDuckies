#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <iostream>
#include <QString>
#include <QFile>
#include <memory>
#include <fstream>
#include "vector.h"
#include "shape.h"

using namespace std;

/**
 * @brief Read File : Creates a filestream object for parsing
 * @param filename : a string which consists of the filepath for the save file
 * @param shapes : the vector of Shape pointers to be used by the main application
 */
void read_file(const string filename, myStd::vector<Shape*>& shapes);

/**
 * @brief Parse File : Reads the shape save data line by line into the widget's shape objects
 * @param inData : a filestream object which contains the saved shape data
 * @param shapes : the vector of Shape pointers to be used by the main application
 */
void parse_file(fstream& inData, myStd::vector<Shape*>& shapes);

#endif
