#ifndef SHAPE_EDITOR_H
#define SHAPE_EDITOR_H

#include <QDialog>

namespace Ui {
class shape_Editor;
}

class shape_Editor : public QDialog
{
    Q_OBJECT

public:
    explicit shape_Editor(QWidget *parent = nullptr);
    ~shape_Editor();

private:
    Ui::shape_Editor *ui;
};

#endif // SHAPE_EDITOR_H
