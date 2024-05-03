#ifndef CONTACT_US_H
#define CONTACT_US_H

#include <QFile>
#include <QMessageBox>

class ContactUs:public QMessageBox
{
public:
    ContactUs(QWidget *parent = 0);
private:
    QFile logo;
};



#endif // CONTACT_US_H
