#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class rectangle : public Shape
{
private:
    QRect rect;

public:
    rectangle() : rect{20, 200, 170, 100} {}
    rectangle(QRect r) : rect{r} {}
    ~rectangle();
    // void DrawShape() override;
    // void SetShape() override;
};

#endif // RECTANGLE_H
