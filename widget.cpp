#include "widget.h"
#include "./ui_widget.h"
#include<QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <iostream>
#include "bird.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setFixedHeight(600);
    this->setFixedWidth(400);
    scene = new Scene(this);
    scene->setSceneRect(-200, -300, 400, 600);
    ui->graphicsView->setScene(scene);

}

Widget::~Widget()
{
    delete ui;
}

