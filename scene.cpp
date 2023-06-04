#include"scene.h"
#include"pillaritem.h"
Scene::Scene(QObject *parent): QGraphicsScene(parent) {
    // when timeout, add a new pillar and start over again
    connect(pillarTimer, &QTimer::timeout, this, &Scene::addNewPillar);
    pillarTimer->start(1500);
}

void Scene::addNewPillar() {
    PillarItem * p = new PillarItem();
    addItem(p);
}
