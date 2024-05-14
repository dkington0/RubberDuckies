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
    text() : rect{250, 425, 500, 50}, flags{Qt::AlignCenter}, strtext{"Nothing Here!"} { setId(1 + num_shapes++);  setShapeTypeFlag(Shape::TextType); }

    /**
     * @brief text alternate constructor, to be used when creating new text shapes
     * @param r : QRect bounding rectangle for the text
     * @param fl : the QtLL enum flags for text alignment within the bounding rectangle
     * @param t : QString object holding the text to be displayed within the bounding rectangle
     * @param fo : QFont properties for the object's QString text
     */
    text(QRect r, int fl, const QString &t, QFont fo) : rect{r}, flags{fl}, strtext{t}, font{fo} { setId(1 + num_shapes++);  setShapeTypeFlag(Shape::TextType); }

    /**
     * @brief text alternate constructor, to be used by the file parser
     * @param i : int ID of the incoming Shape object
     * @param r : QRect bounding rectangle for the text
     * @param fl : the QtLL enum flags for text alignment within the bounding rectangle
     * @param t : QString object holding the text to be displayed within the bounding rectangle
     * @param fo : QFont properties for the object's QString text
     */
    text(int i, QRect r, int fl, const QString &t, QFont fo) : rect{r}, flags{fl}, strtext{t}, font{fo} { setId(i); setShapeTypeFlag(Shape::TextType); }

    /**
     * @brief default text deconstructor
     */
    ~text();

    /**
     * @brief : paintEvent to be called upon a QPaintEvent, such as update()
     * @param : QPaintEvent being called
     */
    void draw(QPainter* event) override;
    // void setAttribute() override;

    /**
     * @brief getId will return the derived shape's unique ID
     * @return : returns the derived shape's unique ID
     */
    int getId() { return id; };


    /**
     * @brief getRect will return the derived shape's bounding rectangle
     * @return : returns the derived shape's QRect bounding rectangle
     */
    QRect getRect() const { return rect; }

    /**
     * @brief getFlags will return the text's alignment flags
     * @return : returns the text's alignment flag
     */
    int getFlags() const { return flags; }

    /**
     * @brief getStrText will return the text's string
     * @return : returns the text's string
     */
    QString getStrText() const { return strtext; }

    /**
     * @brief getFont will return the font data for the text
     * @return : returns the text's QFont object
     */
    QFont getFont() const { return font; }
};

#endif // TEXT_H
