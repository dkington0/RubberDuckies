#ifndef TEXT_H
#define TEXT_H
#include "shape.h"

class text : public Shape
{
private:
    Shape* shape;
    QRect rect;
    QString* strtext;

public:
    text() : rect(250, 425, 500, 50) {}
    text(QRect r, const QString &t, QRect *boundingRect)
        : rect{r} {}
    ~text();

    void paintEvent(QPaintEvent* event) override;
};

#endif // TEXT_H
