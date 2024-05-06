#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Shape.h"

class ellipse : public Shape
{
private:
    QRect rect;

public:
    ellipse() : rect{520, 200, 170, 100} {}
    ellipse(QRect r) : rect{r} {}
    ~ellipse();
};

#endif // ELLIPSE_H
