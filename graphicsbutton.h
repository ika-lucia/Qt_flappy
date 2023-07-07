
#ifndef GRAPHICSBUTTON_H
#define GRAPHICSBUTTON_H

#include <QGraphicsItem>

class GraphicsButton:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    GraphicsButton(QPixmap pm);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;
};

class StartButton:public GraphicsButton
{
    Q_OBJECT
public:
    StartButton(QPixmap pm);
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
signals:
    void gameStartSignal();
};

class MenuButton:public GraphicsButton
{
    Q_OBJECT
public:
    MenuButton(QPixmap pm);
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
signals:
    void menuPopupSignal();
};

#endif // GRAPHICSBUTTON_H
