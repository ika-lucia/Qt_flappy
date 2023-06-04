#include"scene.h"
#include"pillaritem.h"
#include<QDebug>
Scene::Scene(QObject *parent): QGraphicsScene(parent), stopped(false) {
    auto after_scale = QPixmap(":/graphics/background_day.png").scaledToHeight(600);
    QGraphicsPixmapItem* background =
        new QGraphicsPixmapItem(after_scale);

    background->setPos(QPointF(0,0) - QPointF(background->boundingRect().width()/2,
                                               background->boundingRect().height()/2));
    addItem(background);
    addLine(-400,0,400,0,QPen(Qt::blue));
    addLine(0,-300,0,300,QPen(Qt::blue));
    // when timeout, add a new pillar and start over again
    addBird();
    pillarTimer->start(1500);
    connect(pillarTimer, &QTimer::timeout, this, &Scene::addNewPillar);

}

void Scene::addNewPillar() {
    PillarItem * p = new PillarItem();
    connect(p, &PillarItem::collided_signal, this, &Scene::gameOver);
    addItem(p);
}

void Scene::addBird() {
    bird = new Bird();
    addItem(bird);
}

void Scene::gameOver() {
    // if already fail, don't restart falling
    if (stopped) {
        return;
    }
    bird->failFall();
    // stop pillar generation
    pillarTimer->stop();
    // freeze all pillars
    auto all = items();
    for (auto i: all) {
        PillarItem* pil = dynamic_cast<PillarItem*>(i);
        if (pil) {
            pil->freeze();
        }
    }
    stopped = true;
}

// bird up when pressing space
void Scene::keyPressEvent(QKeyEvent* event) {
    qDebug() << "Key pressed";
    if (event->key() == Qt::Key_Space) {
        bird->up();
    }
    QGraphicsScene::keyPressEvent(event);
}
