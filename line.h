#ifndef LINE_H
#define LINE_H
#include <QPoint>
#include "shape.h"

class Line  : public Shape
{
private:
    QPoint points[2];
    Shape* shape;


public:
    Line() : points{}, shape{nullptr} {}
    ~Line();


    // void DrawShape() override;
    // void SetShape() override;
    // void setPen() override;
    // void setBrush() override;
    void paintEvent(QPaintEvent *event) override;

    // QPainter line(Line);

    // QPen pen(Line);
    // pen.setColor(Qt::green);

};

#endif // LINE_H
