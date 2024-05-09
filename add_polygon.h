#ifndef ADD_POLYGON_H
#define ADD_POLYGON_H

#include <QDialog>

namespace Ui {
class add_Polygon;
}

class add_Polygon : public QDialog
{
    Q_OBJECT

public:
    explicit add_Polygon(QWidget *parent = nullptr);
    ~add_Polygon();

private:
    Ui::add_Polygon *ui;
};

#endif // ADD_POLYGON_H
