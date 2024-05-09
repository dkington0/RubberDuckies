#ifndef SORT_H
#define SORT_H

#include "vector.h"
#include "shape.h"
#include <iostream>
#include <fstream>

class sort
{
public:
    static void sortID(myStd::vector<Shape> & shapes); // sort ID

    static void sortArea(myStd::vector<Shape>& shapes); // sort Area

    static void sortPerimeter(myStd::vector<Shape> & shapes); // sort Perimeter

    static void write(const myStd::vector<Shape> & shapes, const std::string & filename); // write to file
};

#endif // SORT_H
