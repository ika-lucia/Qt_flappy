
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
    explicit PillarItem(int gapWidth=60,int gapHeight=300);
    void Animate();
    qreal x() const;
    void setX(qreal newX);
    ~PillarItem();

signals:
    void xChanged();

public slots:
private:
    QGraphicsPixmapItem* qpillarup;
    QGraphicsPixmapItem* qpillardown;
    QPropertyAnimation* xAnimation;
    qreal m_x;
    qreal m_y;
};

#endif // PILLARITEM_H
