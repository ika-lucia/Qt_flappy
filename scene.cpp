#include "scene.h"
#include "pillaritem.h"
#include <QDebug>
#include "constants.h"
Scene::Scene(QObject *parent): QGraphicsScene(parent), stopped(false) {
//    auto after_scale = QPixmap(":/graphics/background_day.png").scaledToHeight(WINDOW_HEIGHT);
    auto after_scale = QPixmap(":/graphics/background_day.png").scaled(QSize(WINDOW_WIDTH,WINDOW_HEIGHT));
    QGraphicsPixmapItem* background =
        new QGraphicsPixmapItem(after_scale);

    background->setPos( - QPointF(WINDOW_WIDTH/2,
                        WINDOW_HEIGHT/2));
    addItem(background);
    addLine(-WINDOW_WIDTH,0,WINDOW_WIDTH,0,QPen(Qt::blue));
    addLine(0,-WINDOW_HEIGHT,0,WINDOW_HEIGHT,QPen(Qt::blue));
    // when timeout, add a new pillar and start over again


    start_btn = new QPushButton((QWidget*)parent);
    start_btn->resize(60,35);
    start_btn->move(QPoint(WINDOW_WIDTH/2-30,WINDOW_HEIGHT*0.65-17));
    start_btn->setText("Start");
    connect(start_btn,&QPushButton::clicked,[=](){
        start_btn->hide();
        start();
        //scene->startPillarTimer();
    });

    addBird();
    connect(pillarTimer, &QTimer::timeout, this, &Scene::addNewPillar);

}
void Scene::start(){
    // called when start_btn is hit
    stopped = false;
    pillarTimer->start(DISTANCE/(double)SPEED * 1000);
    bird->fall();
}
void Scene::stop(){
    // push ESC to return to the main interface
    bird->stop();
}
void Scene::addNewPillar() {
    PillarItem * p = new PillarItem();
    pillars.push_back(p);
    connect(p->xAnimation, &QPropertyAnimation::finished, [=](){
        auto x=pillars.front();
        pillars.pop_front();
        removeItem(x);
//        delete x;
    });
    connect(p, &PillarItem::collided_signal, this, &Scene::gameOver);
    addItem(p);
}

void Scene::addBird() {
    bird = new Bird();
    addItem(bird);
}
void Scene::clearAll(){
    removeItem(bird);

    while(!pillars.empty()){
        PillarItem* p = pillars.front();
        pillars.pop_front();
        removeItem(p);
    }

}
void Scene::gameOver() {
    // if already fail, don't restart falling
    if (stopped) return;
    bird->failFall();
    // stop pillar generation
    pillarTimer->stop();
    // freeze all pillars
    for(auto pillar: pillars){
        pillar->freeze();
    }
//    auto all = items();
//    for (auto i: all) {
//        PillarItem* pil = dynamic_cast<PillarItem*>(i);
//        if (pil) {
//            pil->freeze();
//        }
//    }
    auto after_scale = QPixmap(":/graphics/gameOver.png");
    QGraphicsPixmapItem* gameOverTxt = new QGraphicsPixmapItem(after_scale);
    gameOverTxt->setPos(- QPointF(gameOverTxt->boundingRect().width()/2,
                                  gameOverTxt->boundingRect().height()/2));
    addItem(gameOverTxt);
    start_btn->show();
    connect(start_btn,&QPushButton::clicked,[=](){
        start_btn->hide();
        clearAll();
        removeItem(gameOverTxt);
//        delete gameOverTxt;
        addBird();
        start();
    });
    stopped = true;
}
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{ // used for testing
    qDebug()<< e->pos() << e->screenPos()<<e->scenePos();
}
// bird up when pressing space
void Scene::keyPressEvent(QKeyEvent* event) {

    qDebug() << "Key pressed,stopped="<<stopped;
    if(event->key() == Qt::Key_Escape){ // resume

    }
    if (!stopped && event->key() == Qt::Key_Space) {
        bird->up();
    }
    QGraphicsScene::keyPressEvent(event);
}
