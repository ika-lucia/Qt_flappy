#ifndef SCENE_H
#define SCENE_H
#include<QGraphicsScene>
#include<QTimer>

class Scene: public QGraphicsScene {
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    QTimer* pillarTimer = new QTimer(this);
    void addNewPillar();
};

#endif
