#ifndef ADD_SQUREC_H
#define ADD_SQUREC_H

#include <QDialog>

namespace Ui {
class add_SquRec;
}

class add_SquRec : public QDialog
{
    Q_OBJECT

public:
    explicit add_SquRec(QWidget *parent = nullptr);
    ~add_SquRec();

private:
    Ui::add_SquRec *ui;
};

#endif // ADD_SQUREC_H
