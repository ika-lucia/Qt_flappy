
#include "graphicsbutton.h"
#include "constants.h"
GraphicsButton::GraphicsButton(QPixmap pm): QGraphicsPixmapItem(pm)
{
    this->setPos(QPointF(0,WINDOW_HEIGHT*0.15));
    this->setPixmap(pm);
}

StartButton::StartButton(QPixmap pm): GraphicsButton(pm) {}
void StartButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit gameStartSignal();
}

MenuButton::MenuButton(QPixmap pm): GraphicsButton(pm) {}
void MenuButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit menuPopupSignal();
}
