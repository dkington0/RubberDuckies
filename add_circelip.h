#ifndef ADD_CIRCELIP_H
#define ADD_CIRCELIP_H

#include <QDialog>

namespace Ui {
class add_CircElip;
}

class add_CircElip : public QDialog
{
    Q_OBJECT

public:
    explicit add_CircElip(QWidget *parent = nullptr);
    ~add_CircElip();

private:
    Ui::add_CircElip *ui;
};

#endif // ADD_CIRCELIP_H
