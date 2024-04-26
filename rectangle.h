#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class rectangle : public Shape
{
private:
     Shape* shape;

public:
    rectangle();

    void DrawShape() override;
    void SetShape() override;
};

#endif // RECTANGLE_H
