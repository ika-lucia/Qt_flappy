
#include "pillaritem.h"
#include <iostream>
#include "scene.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include "bird.h"
#include "constants.h"
PillarItem::PillarItem():passed(false) // pipe_down是开口朝下的，放在上方
{
    int gapWidth=GAP_WIDTH;
    int gapHeight=GAP_HEIGHT;
    QPixmap pm = QPixmap(":/graphics/pipe_down.png");   
    pm = pm.scaled(QSize(gapWidth,pm.height())); // 增大宽度
    qpillarup = new QGraphicsPixmapItem(pm);
    pm = QPixmap(":/graphics/pipe_up.png");
    pm = pm.scaled(QSize(gapWidth,pm.height())); // 增大宽度
    qpillardown = new QGraphicsPixmapItem(pm);

    int width = qpillarup->boundingRect().width();
    int height= qpillarup->boundingRect().height();

    qpillarup -> setPos(-QPointF(gapWidth / 2,
                              height+gapHeight/2));
    qpillardown -> setPos(-QPointF( gapWidth / 2,
                        -gapHeight/2));
    addToGroup(qpillarup);
    addToGroup(qpillardown);
    //random y position
    yPos = QRandomGenerator::global()->bounded(-RANGE_Y,RANGE_Y);
    int xPos = QRandomGenerator::global()->bounded(-RANGE_X,RANGE_X);

    int start = WINDOW_WIDTH+xPos+width/2;
    int end = -WINDOW_WIDTH-width/2;

    // begin animation
    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(start);
    xAnimation->setEndValue(end);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration((start-end)/(double)SPEED*1000);
    // when done, delete this item to avoid memory leak

    xAnimation->start();
}

PillarItem::~PillarItem() {
    scene()->removeItem(this);
    delete xAnimation;
    delete qpillarup;
    delete qpillardown;
}
qreal PillarItem::x() const
{
    return m_x;
}

bool PillarItem::collide() {
    QList<QGraphicsItem *> items = qpillardown->collidingItems() ;
    items.append((qpillarup)->collidingItems());
    foreach(QGraphicsItem * i , items)
    {
        Bird * b = dynamic_cast<Bird *>(i);
        if (b) {
            return true;
        }
    }
    return false;
}

void PillarItem::setX(qreal newX)
{
    if (qFuzzyCompare(m_x, newX))
        return;
    m_x = newX;
    setPos(QPointF(m_x, yPos));

    if(newX < 0 && !passed)
    {
        passed = true;
        QGraphicsScene * mScene = scene();
        Scene * myScene = dynamic_cast<Scene*>(mScene);
        if(myScene)
        {
            myScene->incrementScore();
        }
    }
    if (PillarItem::collide()) {
        emit collided_signal();
    }
}

void PillarItem::freeze() {
    xAnimation->stop();
}
