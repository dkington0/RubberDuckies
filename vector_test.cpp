#include "vector.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"


/**
     * @brief : Main function to test for vector's memory leaks
     * @param : Shape objects to be loaded into vectors
     */
int main(int argc, char *argv[])
{
    myStd::vector<Shape*> container;
    Shape * rect = new rectangle(1, QRect(20, 200, 170, 100));
    Shape * circ = new circle(2, 250, 150, 200);

    container.push_back(rect);
    container.push_back(circ);

    for(Shape * shape : container)
    {
        delete shape;
    }

    return 0;
}
