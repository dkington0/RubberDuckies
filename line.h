#ifndef LINE_H
#define LINE_H
#include <QPoint>
#include "shape.h"

class Line  : public Shape
{
private:
    QPoint p1;
    QPoint p2;

public:
    Line() : p1{}, p2{} {}
    Line(QPoint& one, QPoint& two) : p1{one}, p2{two} {}
    ~Line() {}

    void setPoints(QPoint* p, QPoint* p2);
    void setPen() override;
    void setBrush() override;
    // void draw() override;

    void paintEvent(QPaintEvent *event) override;

};

#endif // LINE_H
