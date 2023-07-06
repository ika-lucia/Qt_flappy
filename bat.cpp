#include "bat.h"
#include"bird.h"
#include<QTimer>
#include"constants.h"
#include<QtMath>

Bat::Bat(qreal yCenter): allPixmaps {
        QPixmap(":/graphics/bat1.png").scaled(QSize(BAT_SIZE, BAT_SIZE)),
        QPixmap(":/graphics/bat2.png").scaled(QSize(BAT_SIZE, BAT_SIZE)),
        QPixmap(":/graphics/bat3.png").scaled(QSize(BAT_SIZE, BAT_SIZE)),
        QPixmap(":/graphics/bat4.png").scaled(QSize(BAT_SIZE, BAT_SIZE)),
        QPixmap(":/graphics/bat5.png").scaled(QSize(BAT_SIZE, BAT_SIZE)),
        QPixmap(":/graphics/bat6.png").scaled(QSize(BAT_SIZE, BAT_SIZE)),
        QPixmap(":/graphics/bat7.png").scaled(QSize(BAT_SIZE, BAT_SIZE)),
        QPixmap(":/graphics/bat8.png").scaled(QSize(BAT_SIZE, BAT_SIZE)),
    }, curPos(0), m_y(yCenter), m_a(0.0)
{
    setPixmap(allPixmaps[curPos]);
    //setPos(coin->x(), coin->y());
    QTimer * batMovingTimer = new QTimer(this);
    connect(batMovingTimer, &QTimer::timeout,
            [=](){
                updatePixmap();
            });
    batMovingTimer->start(80);
    xAnimation = new QPropertyAnimation(this,"x",this);
    qreal width = boundingRect().width();
    qreal start = WINDOW_WIDTH-width/2;
    int end = -WINDOW_WIDTH;
    xAnimation->setStartValue(start);
    xAnimation->setEndValue(end);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration((start-end)/(double)SPEED*1000);
    xAnimation->start();
    // animate the rotation around the coin
    aAnimation = new QPropertyAnimation(this,"a",this);
    qreal aStart = 0;
    qreal aEnd = 15;
    aAnimation->setStartValue(aStart);
    aAnimation->setEndValue(aEnd);
    aAnimation->setEasingCurve(QEasingCurve::Linear);
    aAnimation->setDuration((start-end)/(double)BAT_ROTATE_SPEED*1000);
    aAnimation->start();
}

void Bat::updatePixmap() {
    curPos++;
    curPos%=8;
    setPixmap(allPixmaps[curPos]);
}

qreal Bat::getX() const {
    return m_x;
}

void Bat::setX(qreal newX) {
    moveBy(newX - m_x, newX-m_x);
    m_x = newX;
    collide();
}

qreal Bat::a() const {
    return m_a;
}

void Bat::setA(qreal newA) {
    m_a = newA;
    qreal x = m_x+BAT_ROTATE_RADIUS*qCos(m_a);
    qreal y = m_y+BAT_ROTATE_RADIUS*qSin(m_a);
    setPos(x, y);
    collide();
}

void Bat::collide() {
    QList<QGraphicsItem *> items = collidingItems() ;
    foreach(QGraphicsItem * i , items)
    {
        Bird * b = dynamic_cast<Bird *>(i);
        if (b) {
            emit collided_signal();
            return;
        }
    }
    return;
}
