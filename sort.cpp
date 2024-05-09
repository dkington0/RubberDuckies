#include "sort.h"

// void sort::sortID(myStd::vector<Shape> & shapes)
// {
//     int n = shapes.size();
//     for(int i = 0; i < n -1; i++)
//     {
//         for(int j = 0; j < n - i - 1; j++)
//         {
//             if(shapes[j].getID() > shapes[j + 1].getID())
//             {
//                 std::swap(shapes[j], shapes[j+1]);
//             }
//         }
//     }
// }



void sort::sortArea(myStd::vector<Shape> & shapes)
{
    int n = shapes.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (shapes[j].getArea() > shapes[j + 1].getArea())
            {
                std::swap(shapes[j], shapes[j + 1]);
            }
        }
    }
}



void sort::sortPerimeter(myStd::vector<Shape> & shapes)
{
    int n = shapes.size();
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(shapes[j].getPerimeter() > shapes[j + 1].getPerimeter())
            {
                std::swap(shapes[j], shapes[j+1]);
            }
        }
    }
}


void sort::write(const myStd::vector<Shape> & shapes, const std::string & filename)
{
    std::ofstream outFile(filename);
    if(!outFile.is_open())
    {
        std::cout << "Error unable to open " << filename << std::endl;
        exit(1);
    }

    for(const auto& shape : shapes)
    {
        outFile << "ID: " << shape.getID() << std::endl;
        outFile << "Area: " << shape.getArea() << std::endl;
        outFile << "Perimeter: " << shape.getPerimeter() << std::endl;
        outFile << std::endl;
    }
    outFile.close();
}
