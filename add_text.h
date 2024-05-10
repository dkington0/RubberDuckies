#ifndef ADD_TEXT_H
#define ADD_TEXT_H

#include <QDialog>

namespace Ui {
class add_Text;
}

class add_Text : public QDialog
{
    Q_OBJECT

public:
    explicit add_Text(QWidget *parent = nullptr);
    ~add_Text();

private:
    Ui::add_Text *ui;
};

#endif // ADD_TEXT_H
