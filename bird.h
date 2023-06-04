#ifndef BIRD_H
#define BIRD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QKeyEvent>

class Bird : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
    Q_PROPERTY(qreal y READ y WRITE setY)
public:
    explicit Bird();

    qreal rotation() const;
    void setRotation(qreal newRotation);

    qreal y() const;
    void setY(qreal newY);

    void rotateTo(const qreal & end, const int & duration, const QEasingCurve & curve);
    void up();
signals:

public slots:
private:
    void updatePixmap();
    void fall();
    // change between positions to simulate wing flapping
    enum WingPosition{
        Up,
        Middle,
        Down
    };
    // currently going up or falling down

    WingPosition wingPosition;
    bool wingDirection;
    qreal m_rotation;
    qreal m_y;
    QPropertyAnimation * yAnimation;
    QPropertyAnimation * rotationAnimation;
    qreal groundPosition;
protected:
};

#endif // BIRD_H
