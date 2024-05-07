#ifndef TEXT_H
#define TEXT_H
#include "shape.h"

class text : public Shape
{
private:
    QRect rect;
    int flags;
    QString strtext;
    QFont font;
    int id;

public:
    text() : rect{250, 425, 500, 50}, flags{Qt::AlignCenter}, strtext{"Nothing Here!"} { id = num_shapes++ + 1; }
    text(QRect r, int fl, const QString &t, QFont fo) : rect{r}, flags{fl}, strtext{t}, font{fo} { id = num_shapes++ + 1; }
    ~text();

    void paintEvent(QPaintEvent* event) override;
    // void setAttribute() override;
};

#endif // TEXT_H
