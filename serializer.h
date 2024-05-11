#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "vector.h"
#include "shape.h"

/**
 * @brief serialize will save the shapes within the main container into the shape_list.txt file created upon program launch.
 * @param filepath : the file path of the shape_list.txt file
 * @param userShapes : main container of Shape pointers
 */
void serialize(QString filepath, myStd::vector<Shape*> userShapes);

#endif // SERIALIZER_H
