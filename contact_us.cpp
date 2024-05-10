#include <QFile>
#include <QMessageBox>
#include "contact_us.h"

ContactUs::ContactUs(QWidget *parent)
{
    setGeometry(0,0, 250,250);
    if(logo.load(":/files/duck.png")) {

        logo.scaled(50,50, Qt::KeepAspectRatio);
        setPixmap(logo);

    } else {
        setText("file didn't load");
    }
}
