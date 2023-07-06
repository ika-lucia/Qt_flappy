#ifndef SCENE_H
#define SCENE_H
#include<QGraphicsScene>
#include<QTimer>
#include<QKeyEvent>
#include"bird.h"
#include <QGraphicsSceneMouseEvent>
#include <deque>
#include <QPushButton>
#include "pillaritem.h"
class Scene: public QGraphicsScene {
    Q_OBJECT
public:
    bool game_start = true;
    explicit Scene(QObject *parent = nullptr);
    bool stopped;
    QTimer* pillarTimer = new QTimer(this);
    void addNewPillar();
    void addBird();
    void gameOver();
    void start();
    void stop();
    void incrementScore();
    void clearAll();
    void keyPressEvent(QKeyEvent* event);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    Bird* bird;
    QPushButton* start_btn;
    std::deque<PillarItem*> pillars;
    int score;
    int bestScore;

    QGraphicsPixmapItem * gameOverPix;
    QGraphicsTextItem * scoreTextItem;
};

#endif
