#include "widget.h"
#include "./ui_widget.h"
#include<QGraphicsPixmapItem>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    scene = new Scene(this);
    scene->setSceneRect(-200, -300, 400, 600);
    ui->graphicsView->setScene(scene);
    auto after_scale = QPixmap(":/graphics/background_day.png").scaledToHeight(600);
    QGraphicsPixmapItem* background =
        new QGraphicsPixmapItem(after_scale);

    background->setPos(QPointF(0,0) - QPointF(background->boundingRect().width()/2,
                                               background->boundingRect().height()/2));
    scene->addItem(background);
}

Widget::~Widget()
{
    delete ui;
}

