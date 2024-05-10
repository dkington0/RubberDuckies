#ifndef TEXT_H
#define TEXT_H
#include "shape.h"

class text : public Shape
{
private:
    /**
     * @brief rect : QRect is the bounding rectangle of the Text
     */
    QRect rect;
    /**
     * @brief id : ID is the unique integer assigned to each instance of a derived Shape object.
     */
    int id;
    /**
     * @brief flags
     */
    int flags;
    QString strtext;
    QFont font;


public:
    text() : rect{250, 425, 500, 50}, flags{Qt::AlignCenter}, strtext{"Nothing Here!"} { id = num_shapes++ + 1; }
    text(QRect r, int fl, const QString &t, QFont fo) : rect{r}, flags{fl}, strtext{t}, font{fo} { id = num_shapes++ + 1; }
    text(int i, QRect r, int fl, const QString &t, QFont fo) : rect{r}, flags{fl}, strtext{t}, font{fo}, id{i} { }
    ~text();

    void paintEvent(QPaintEvent* event) override;
    // void setAttribute() override;
};

#endif // TEXT_H
