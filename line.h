#ifndef LINE_H
#define LINE_H
#include <QPoint>
#include "shape.h"

class Line : protected Shape
{
private:
    QPoint points[2];
     Shape* shape;


public:
    Line();
    ~Line();

    void DrawShape() override;
    void SetShape() override;

    // QPainter line(Line);

    // QPen pen(Line);
    // pen.setColor(Qt::green);
};

#endif // LINE_H
