#include"scene.h"
#include"pillaritem.h"
#include<QDebug>
Scene::Scene(QObject *parent): QGraphicsScene(parent) {
    auto after_scale = QPixmap(":/graphics/background_day.png").scaledToHeight(600);
    QGraphicsPixmapItem* background =
        new QGraphicsPixmapItem(after_scale);

    background->setPos(QPointF(0,0) - QPointF(background->boundingRect().width()/2,
                                               background->boundingRect().height()/2));
    addItem(background);
    addLine(-400,0,400,0,QPen(Qt::blue));
    addLine(0,-300,0,300,QPen(Qt::blue));
    // when timeout, add a new pillar and start over again
    connect(pillarTimer, &QTimer::timeout, this, &Scene::addNewPillar);
    pillarTimer->start(1500);
    addBird();
}

void Scene::addNewPillar() {
    PillarItem * p = new PillarItem();
    addItem(p);
}

void Scene::addBird() {
    bird = new Bird();
    addItem(bird);
}

void Scene::keyPressEvent(QKeyEvent* event) {
    qDebug() << "Key pressed";
    if (event->key() == Qt::Key_Space) {
        bird->up();
    }
    QGraphicsScene::keyPressEvent(event);
}
