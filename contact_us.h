#ifndef CONTACT_US_H
#define CONTACT_US_H

#include <QFile>
#include <QMessageBox>
#include <QLabel>

class ContactUs:public QLabel
{

public:
    /**
     * @brief ContactUs widget constructor
     * @param parent : QWidget parent calling the constructor
     */
    ContactUs(QWidget *parent = 0);

private:
    /**
     * @brief logo : QPixmap to hold the image which appears on the label
     */
    QPixmap logo;
};



#endif // CONTACT_US_H
