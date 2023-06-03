
#include "pillaritem.h"
#include <iostream>
#include <QRandomGenerator>
PillarItem::PillarItem(int gapWidth, int gapHeight) // pipe_down是开口朝下的，放在上方
{
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
    int yPos = QRandomGenerator::global()->bounded(150);
    xAnimation = new QPropertyAnimation(this,"x",this);
}


qreal PillarItem::x() const
{
    return m_x;
}

void PillarItem::setX(qreal newX)
{
    if (qFuzzyCompare(m_x, newX))
        return;
    m_x = newX;
    emit xChanged();
}
