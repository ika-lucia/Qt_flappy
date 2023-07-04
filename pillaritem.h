
#ifndef PILLARITEM_H
#define PILLARITEM_H


#include <QObject>
#include <QGraphicsItemGroup>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
class PillarItem : public QObject,public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX NOTIFY xChanged)
    // Q_PROPERTY 仅当继承了QObject时才能使用
public:
    explicit PillarItem();
    void Animate();
    qreal x() const;
    void setX(qreal newX);
    void freeze();
    ~PillarItem();
    QPropertyAnimation* xAnimation;
signals:
    void collided_signal();
    void xChanged();

public slots:
private:
    QGraphicsPixmapItem* qpillarup;
    QGraphicsPixmapItem* qpillardown;

    int yPos;
    bool collide();
    qreal m_x;
    qreal m_y;
};

#endif // PILLARITEM_H
