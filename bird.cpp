#include "bird.h"
#include <QTimer>
#include <QDebug>

Bird::Bird():
    wingPosition(WingPosition::Up),
    wingDirection(0)
{
    setPixmap(QPixmap(":/graphics/bird_blue_up.png"));
    QTimer * birdWingsTimer = new QTimer(this);
    connect(birdWingsTimer, &QTimer::timeout,
            [=](){
                updatePixmap();
    });
    birdWingsTimer->start(80);

    groundPosition = scenePos().y() + 290;
    yAnimation = new QPropertyAnimation(this, "y", this);
    rotationAnimation = new QPropertyAnimation(this, "rotation", this);
    fall();
}
void Bird::updatePixmap()
{
    if(wingPosition == WingPosition::Middle)
    {
        if(wingDirection)
        {
            setPixmap(QPixmap(":/graphics/bird_blue_up.png"));
            wingPosition = WingPosition::Up;
            wingDirection = 0;
        }
        else
        {
            setPixmap(QPixmap(":/graphics/bird_blue_down.png"));
            wingPosition = WingPosition::Down;
            wingDirection = 1;
        }
    }
    else
    {
        setPixmap(QPixmap(":/graphics/bird_blue_middle.png"));
        wingPosition = WingPosition::Middle;
    }
}

qreal Bird::rotation() const
{
    return m_rotation;
}

void Bird::setRotation(qreal newRotation)
{
    m_rotation = newRotation;

    QPointF c = boundingRect().center();
    QTransform t;
    t.translate(c.x(), c.y());
    t.rotate(newRotation);
    t.translate(-c.x(), -c.y());
    setTransform(t);
}

qreal Bird::y() const
{
    return m_y;
}

void Bird::setY(qreal newY)
{
    moveBy(0, newY - m_y);
    m_y = newY;
}

void Bird::rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve)
{
    rotationAnimation->stop();
    rotationAnimation->setStartValue(rotation());
    rotationAnimation->setEndValue(end);
    rotationAnimation->setEasingCurve(curve);
    rotationAnimation->setDuration(duration);
    rotationAnimation->start();
}



void Bird::up() {
    yAnimation->stop();
    rotateTo(-30, 120, QEasingCurve::InQuad);
    yAnimation->setStartValue(y());
    yAnimation->setEndValue(y()-100);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(200);
    connect(yAnimation, &QPropertyAnimation::finished, this, &Bird::fall);
    yAnimation->start();
}

void Bird::fall() {
    yAnimation->stop();
    yAnimation->setStartValue(y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1000);
    yAnimation->start();
    rotateTo(90, 1200, QEasingCurve::InQuad);
}

void Bird::failFall() {
    yAnimation->stop();
    yAnimation->setStartValue(y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(300);
    yAnimation->start();
    rotateTo(90, 60, QEasingCurve::Linear);
}

