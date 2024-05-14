#include "sort.h"
void sort::sortID(myStd::vector<Shape*> & shapes)
{
    int n = shapes.size();
    for(int i = 0; i < n -1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(shapes[j]->getId() > shapes[j + 1]->getId())
            {
                std::swap(shapes[j], shapes[j+1]);
            }
        }
    }
}



void sort::sortArea(myStd::vector<Shape*> & shapes)
{
    int n = shapes.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (shapes[j]->calculateArea() > shapes[j + 1]->calculateArea())
            {
                std::swap(shapes[j], shapes[j + 1]);
            }
        }
    }
}



void sort::sortPerimeter(myStd::vector<Shape*> & shapes)
{
    int n = shapes.size();
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(shapes[j]->calculatePerimeter() > shapes[j + 1]->calculatePerimeter())
            {
                std::swap(shapes[j], shapes[j+1]);
            }
        }
    }
}

// void sort::customSwap(Shape *& shape, Shape *& other)
// {
//     Shape * temp = shape;
//     shape = other;
//     other = temp;
// }


void sort::write(const myStd::vector<Shape*> & shapes, const std::string & filename)
{
    std::ofstream outFile(filename);
    if(!outFile.is_open())
    {
        std::cout << "Error unable to open " << filename << std::endl;
        exit(1);
    }

    for(const auto& shape : shapes)
    {
        if(shape->validArea() && shape->validPerimeter())
        {
        outFile << "Shape Type: " << shape->shapeType(shape->getShapeTypeFlag()) << std::endl;
        outFile << "ID: " << shape->getId() << std::endl;
        outFile << "Area: " << shape->calculateArea() << std::endl;
        outFile << "Perimeter: " << shape->calculatePerimeter() << std::endl;
        outFile << std::endl;
        }
        else
        {
            outFile << "Shape Type: " << shape->shapeType(shape->getShapeTypeFlag()) << std::endl;
            outFile << "ID: " << shape->getId() << std::endl;
            outFile << "No valid area or perimter" << std::endl;
            outFile << std::endl;

        }
    }
    outFile.close();
}
