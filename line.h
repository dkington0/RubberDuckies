#ifndef LINE_H
#define LINE_H
#include <QPoint>
#include "shape.h"

class Line : protected Shape
{
private:
    QPoint points[2];


public:
    Line();
    ~Line();

    void DrawShape() override;
    void SetShape() override;
};

#endif // LINE_H
