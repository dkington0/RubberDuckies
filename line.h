#ifndef LINE_H
#define LINE_H
#include <QPoint>
#include "shape.h"

class Line  : public Shape
{
private:
    QLineF line;
    int id;

public:
    Line() : line{20, 90, 100, 20} { id = num_shapes++ + 1; }
    Line(qreal x1, qreal y1, qreal x2, qreal y2) : line{x1, y1, x1, y2} { id = num_shapes++ + 1; }
    Line(int i, qreal x1, qreal y1, qreal x2, qreal y2) : id{i}, line{x1, y1, x1, y2} {}
    ~Line();

    void paintEvent(QPaintEvent *event) override;

};

#endif // LINE_H
