
#ifndef GRAPHICSBUTTON_H
#define GRAPHICSBUTTON_H

#include <QGraphicsItem>

class GraphicsButton:public QGraphicsPixmapItem
{
public:
    GraphicsButton(QPixmap pm);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void show();
//    void hide();
//    void setPos(QPointF p);
};

#endif // GRAPHICSBUTTON_H
