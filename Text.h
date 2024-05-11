#ifndef TEXT_H
#define TEXT_H
#include "shape.h"

/**
 * @brief Text class
 * @details derived from the Shape class, an text object is confined by its bounding rectangle, which has differing lengths for width and height. The text can be further customized by adding
 *          alignment flags to determine position within the bounding rectangle, as well as font styles and the text it contains.
 */
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
     * @brief flags : the Qt:: enum flags for text alignment within the bounding rectangle
     */
    int flags;
    /**
     * @brief strtext : QString object holding the text to be displayed within the bounding rectangle
     */
    QString strtext;
    /**
     * @brief font : QFont properties for the object's QString text
     */
    QFont font;


public:
    /**
     * @brief text default constructor, sets default parameters for a text shape
     */
    text() : rect{250, 425, 500, 50}, flags{Qt::AlignCenter}, strtext{"Nothing Here!"} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::TextType); }

    /**
     * @brief text alternate constructor, to be used when creating new text shapes
     * @param r : QRect bounding rectangle for the text
     * @param fl : the QtLL enum flags for text alignment within the bounding rectangle
     * @param t : QString object holding the text to be displayed within the bounding rectangle
     * @param fo : QFont properties for the object's QString text
     */
    text(QRect r, int fl, const QString &t, QFont fo) : rect{r}, flags{fl}, strtext{t}, font{fo} { id = num_shapes++ + 1; setShapeTypeFlag(Shape::TextType); }

    /**
     * @brief text alternate constructor, to be used by the file parser
     * @param i : int ID of the incoming Shape object
     * @param r : QRect bounding rectangle for the text
     * @param fl : the QtLL enum flags for text alignment within the bounding rectangle
     * @param t : QString object holding the text to be displayed within the bounding rectangle
     * @param fo : QFont properties for the object's QString text
     */
    text(int i, QRect r, int fl, const QString &t, QFont fo) : rect{r}, flags{fl}, strtext{t}, font{fo}, id{i} { setShapeTypeFlag(Shape::TextType); }

    /**
     * @brief default text deconstructor
     */
    ~text();

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    void paintEvent(QPaintEvent* event) override;
    // void setAttribute() override;
};

#endif // TEXT_H
