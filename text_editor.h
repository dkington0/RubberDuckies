#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <QDialog>

namespace Ui {
class Text_Editor;
}

class Text_Editor : public QDialog
{
    Q_OBJECT

public:
    explicit Text_Editor(QWidget *parent = nullptr);
    ~Text_Editor();

private:
    Ui::Text_Editor *ui;
};

#endif // TEXT_EDITOR_H
