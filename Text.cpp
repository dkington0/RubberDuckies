#include "text.h"

text::~text() {}

void text::paintEvent(QPaintEvent *event)
{
    QPainter mytext(this);
    mytext.setFont(QFont("Times", 10, QFont::Bold));
    mytext.drawText(QPoint(20, 30), "Line");

}

