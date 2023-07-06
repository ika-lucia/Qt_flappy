#include "coin.h"
#include "bird.h"
#include "scene.h"
#include "constants.h"
#include <QRandomGenerator>
#include <QTimer>

Coin::Coin()
    : allPixmaps {
        QPixmap(":/graphics/coin1.png"),
        QPixmap(":/graphics/coin2.png"),
        QPixmap(":/graphics/coin3.png"),
        QPixmap(":/graphics/coin4.png"),
        QPixmap(":/graphics/coin5.png"),
        QPixmap(":/graphics/coin6.png"),
        QPixmap(":/graphics/coin7.png"),
        QPixmap(":/graphics/coin8.png"),
    }, curPos(0)
{

    setPixmap(allPixmaps[curPos]);
    QTimer * coinRotateTimer = new QTimer(this);
    connect(coinRotateTimer, &QTimer::timeout,
            [=](){
                updatePixmap();
            });
    coinRotateTimer->start(80);

    m_y = QRandomGenerator::global()->bounded(-RANGE_Y,RANGE_Y);
    int xPos = QRandomGenerator::global()->bounded(-RANGE_X,RANGE_X);
    int width = boundingRect().width();
    int start = WINDOW_WIDTH+xPos+width/2;
    int end = -WINDOW_WIDTH-width/2;
    // begin animation
    xAnimation = new QPropertyAnimation(this,"x",this);
    xAnimation->setStartValue(start);
    xAnimation->setEndValue(end);
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration((start-end)/(double)SPEED*1000);
    xAnimation->start();
}

void Coin::updatePixmap() {
    curPos++;
    curPos%=8;
    setPixmap(allPixmaps[curPos]);
}

void Coin::collide() {
    QList<QGraphicsItem *> items = collidingItems() ;
    foreach(QGraphicsItem * i , items)
    {
        Bird * b = dynamic_cast<Bird *>(i);
        if (b) {
            emit collided_signal();
            scene()->removeItem(this);
            return;
        }
    }
    return;
}

Coin::~Coin() {
    delete xAnimation;
}

qreal Coin::x() const {
    return m_x;
}

void Coin::setX(qreal newX) {
    if (qFuzzyCompare(m_x, newX))
        return;
    m_x = newX;
    setPos(QPointF(m_x, m_y));
    collide();
}

void Coin::freeze() {
    xAnimation->stop();
}
