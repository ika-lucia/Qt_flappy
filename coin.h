#ifndef COIN_H
#define COIN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QPropertyAnimation>

class Coin : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX NOTIFY xChanged)
public:
    explicit Coin();
    ~Coin();
    QPropertyAnimation* xAnimation;
    qreal x() const;
    void setX(qreal newX);
    void freeze();

signals:
    void xChanged();
    void collided_signal();
private:
    void updatePixmap();
    void collide();
    QPixmap allPixmaps[8];
    int curPos;
    qreal m_x;
    qreal m_y;
};

#endif // COIN_H
