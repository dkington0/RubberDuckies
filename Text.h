#ifndef TEXT_H
#define TEXT_H
#include "shape.h"

class text : public Shape
{
private:
    Shape* shape;
    QRectF rect;

public:
    text() : rect(250, 425, 500, 50) {}
    text(int x, int y, int width, int height, int flags, const QString &text, QRect *boundingRect)
        : rect(x, y, width, height) {}
    ~text();

    void paintEvent(QPaintEvent* event) override;
};

#endif // TEXT_H
