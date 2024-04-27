#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

//! [0]
class RenderArea : public QWidget
{
    Q_OBJECT

public:

    // will be replaced by our custom shapes
    enum Shape { Line, Polyline, Polygon, Rect, Square, Ellipse, Circle, Text };

    /**
     * @brief   RenderArea default constructor
     *
     * @param   takes a QWidget (usually itself).
     */
    explicit RenderArea(QWidget *parent = nullptr);

    /**
     * @brief   RenderArea alternate constructor
     *          used for loading shapes, such as from save file
     *
     * @param   takes a QWidget (usually itself), and a defined Shape object.
     */
    explicit RenderArea(QWidget *parent = nullptr, Shape shapeType = Polygon);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);

protected:
    /**
     * @brief   defines what happens to the RenderArea upon receiving a QPaintEvent (such as update)
     *
     * @param   takes a QPaintEvent
     */
    void paintEvent(QPaintEvent *event) override;

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
};
//! [0]

#endif // RENDERAREA_H
