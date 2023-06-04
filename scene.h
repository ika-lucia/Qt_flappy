#ifndef SCENE_H
#define SCENE_H
#include<QGraphicsScene>
#include<QTimer>
#include<QKeyEvent>
#include"bird.h"
class Scene: public QGraphicsScene {
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    QTimer* pillarTimer = new QTimer(this);
    void addNewPillar();
    void addBird();
    void keyPressEvent(QKeyEvent* event);
    Bird* bird;
};

#endif
