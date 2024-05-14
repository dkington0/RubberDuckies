#ifndef SORT_H
#define SORT_H

#include "vector.h"
#include "shape.h"
#include <iostream>
#include <fstream>

/**
 * @brief sort class
 * @details contains sorting algortihms to be used with a vector of shape pointers, allowing the program to sort based on shape ID, area, and perimeter.
 */
class sort
{
public:
    /**
     * @brief sortID sorts the given vector of Shapes based on their ID's
     * @param shapes : the vector of Shape objects to sort
     */
    static void sortID(myStd::vector<Shape*> & shapes); // sort ID

    /**
     * @brief sortArea sorts the given vector of Shapes by area, excluding Shapes which do not have an area
     * @param shapes : the vector of Shape objects to sort
     */
    static void sortArea(myStd::vector<Shape*>& shapes); // sort Area

    /**
     * @brief sortPerimeter sorts the given vector of Shapes by perimeter, excluding Shapes which do not have a perimeter
     * @param shapes
     */
    static void sortPerimeter(myStd::vector<Shape*> & shapes); // sort Perimeter

    /**
     * @brief write writes the Shapes to a report which will be output into an external file
     * @param shapes : the vector of Shape objects to be written to a report file
     * @param filename : the filepath of the external file to be output
     */
    static void write(const myStd::vector<Shape*> & shapes, const std::string & filename); // write to file

    // void customSwap(Shape *& shape, Shape *& other);

};

struct sortPerimeter
{
    bool operator()(const Shape * shape, const Shape * other)
    {
        return shape->calculatePerimeter() < other->calculatePerimeter();
    }
};

struct sortArea
{
    bool operator()(const Shape * shape, const Shape * other)
    {
        return shape->calculateArea() < other->calculateArea();
    }
};

struct sortId
{
    bool operator()(const Shape * shape, const Shape * other)
    {
        return shape->getId() < other->getId();
    }
};




#endif // SORT_H
