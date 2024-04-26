#ifndef TEXT_H
#define TEXT_H
#include "shape.h"

class text : public Shape
{
private:
    Shape* shape;

public:
    text();
    ~text();

    void paintEvent(QPaintEvent* event) override;
};

#endif // TEXT_H
