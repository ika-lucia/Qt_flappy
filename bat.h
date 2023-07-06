#ifndef BAT_H
#define BAT_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QKeyEvent>

// each bat is generated with a coin, and move around it
class Bat: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal a READ a WRITE setA NOTIFY aChanged);
    Q_PROPERTY(qreal x READ getX WRITE setX NOTIFY xChanged);
public:
    explicit Bat(qreal yCenter);
    qreal getX() const;
    qreal a() const;
    void setX(qreal newX);
    void setA(qreal newA);
    QPropertyAnimation* xAnimation;
    QPropertyAnimation* aAnimation;
    qreal m_x;
    qreal m_a;
    qreal m_y;
signals:
    void collided_signal();
    void xChanged();
    void aChanged();
private:
    QPixmap allPixmaps[8];
    void updatePixmap();
    int curPos;//current pixmap phase
    void collide();
};

#endif // BAT_H
