#include "Text.h"

text::~text() {}

void text::draw(QPainter *event)
{
   // QPainter mytext(this);

    setPen(getPen());
   event->setFont(font);

    event->drawText(rect, flags, strtext);

}
/*
void text::setAttribute()
{

}
*/
