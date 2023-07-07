
#include "graphicsbutton.h"
#include "constants.h"
#include "scene.h"
GraphicsButton::GraphicsButton(QPixmap pm): QGraphicsPixmapItem(pm)
{
    this->setPos(QPointF(0,WINDOW_HEIGHT*0.15));
    this->setPixmap(pm);
}

void GraphicsButton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    this->setVisible(false);
    ((Scene*) this->scene())->restart();
}
