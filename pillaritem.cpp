
#include "pillaritem.h"
#include <iostream>
#include <QRandomGenerator>
#include <QGraphicsScene>
#include "bird.h"

PillarItem::PillarItem(int gapWidth, int gapHeight) // pipe_down是开口朝下的，放在上方
{
    QPixmap pm = QPixmap(":/graphics/pipe_down.png");
    pm = pm.scaled(QSize(gapWidth,pm.height())); // 增大宽度
    qpillarup = new QGraphicsPixmapItem(pm);
    pm = QPixmap(":/graphics/pipe_up.png");
    pm = pm.scaled(QSize(gapWidth,pm.height())); // 增大宽度
    qpillardown = new QGraphicsPixmapItem(pm);

    //int width = qpillarup->boundingRect().width();
    int height= qpillarup->boundingRect().height();

    qpillarup -> setPos(-QPointF(gapWidth / 2,
                              height+gapHeight/2));
    qpillardown -> setPos(-QPointF( gapWidth / 2,
                        -gapHeight/2));
    addToGroup(qpillarup);
    addToGroup(qpillardown);
    //random y position
    m_y = -75+QRandomGenerator::global()->bounded(150);

    // begin animation
    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(200);
    xAnimation->setEndValue(-200);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(2000);
    // when done, delete this item to avoid memory leak
    connect(xAnimation, &QPropertyAnimation::finished, [=](){
        delete this;
    });
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
    setPos(QPointF(m_x, m_y));
    if (PillarItem::collide()) {
        emit collided_signal();
    }
}

void PillarItem::freeze() {
    xAnimation->stop();
}
