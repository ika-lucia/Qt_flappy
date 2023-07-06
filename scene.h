#ifndef SCENE_H
#define SCENE_H
#include<QGraphicsScene>
#include<QTimer>
#include<QKeyEvent>
#include"bird.h"
#include"coin.h"
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
    QTimer* coinTimer = new QTimer(this);
    void addNewPillar();
    void addBird();
    void addCoin();
    void eatCoin();
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
    std::deque<Coin*> coins;
    int score;
    int bestScore;
    int coinEarned;
    QGraphicsPixmapItem * gameOverPix;
    QGraphicsTextItem * scoreTextItem;
private:
    void coinTimeOut();
};

#endif
