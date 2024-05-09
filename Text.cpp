#include "text.h"

text::~text() {}

void text::paintEvent(QPaintEvent *event)
{
    QPainter mytext(this);

    setPen(getPen());
    mytext.setFont(font);

    mytext.drawText(rect, flags, strtext);

}
/*
void text::setAttribute()
{

}
*/
