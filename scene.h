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
#include "graphicsbutton.h"
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
    void restart();
    void stop();
    void incrementScore();
    void clearAll();
    void keyPressEvent(QKeyEvent* event);
    Bird* bird=0;
    GraphicsButton* start_btn;
//    QGraphicsPixmapItem* start_btn;
    std::deque<PillarItem*> pillars;
    std::deque<Coin*> coins;
    int score;
    int bestScore;
    int coinEarned;
    QGraphicsPixmapItem * gameOverPix=0;
    QGraphicsPixmapItem* gameOverTxt=0;
    QGraphicsTextItem * scoreTextItem=0;
private:
    void coinTimeOut();
};

#endif
