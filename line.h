#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line  : public Shape
{
private:
    QLine line;
    int id;

public:
    Line() : line{20, 90, 100, 20} { id = num_shapes++ + 1; }
    Line(QLine l) : line{l} { id = num_shapes++ + 1; }
    Line(int i, QLine l) : id{i}, line{l} {}
    ~Line();

    void paintEvent(QPaintEvent *event) override;

};

#endif // LINE_H
