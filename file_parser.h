#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <iostream>
#include <QString>
#include <QFile>
#include <memory>
#include <fstream>

using namespace std;

/**
 * @brief   Read File
 *          Creates a filestream object for parsing
 *
 * @param filename  a string which consists of the filepath for the save file
 *
 */
void read_file(const string filename);

/**
 * @brief   Parse File
 *          Reads the shape save data line by line into the widget's shape objects
 *
 * @param inData    a filestream object which contains the saved shape data
 *
 */
void parse_file(fstream& inData);

#endif
