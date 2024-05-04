#include <QFile>
#include <QMessageBox>
#include "contact_us.h"

ContactUs::ContactUs(QWidget *parent)
{
    setMinimumSize(500, 500);
    if(logo.load(":/files/duck.png"))
    {
        int w = this->width();
        int h = this->height();
        logo.scaled(w, h, Qt::KeepAspectRatio);
        setPixmap(logo);
        //setText("file loaded");
    } else {
        setText("file didn't load");
    }
   // setPixmap(logo);
   // adjustSize();

}
