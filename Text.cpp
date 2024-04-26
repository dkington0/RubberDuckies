#include "text.h"

text::text() {}

void text::paintEvent(QPaintEvent *event)
{
    QPainter mytext(this);
    mytext.setFont(QFont("Times"), 16, QFont::Bold);
    mytext.drawText(QPoint(20, 30), "Line");
}
