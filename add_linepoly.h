#ifndef ADD_LINEPOLY_H
#define ADD_LINEPOLY_H

#include <QDialog>

namespace Ui {
class add_LinePoly;
}

class add_LinePoly : public QDialog
{
    Q_OBJECT

public:
    explicit add_LinePoly(QWidget *parent = nullptr);
    ~add_LinePoly();

private:
    Ui::add_LinePoly *ui;
};

#endif // ADD_LINEPOLY_H
