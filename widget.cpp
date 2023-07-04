#include "widget.h"
#include "./ui_widget.h"
#include<QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <iostream>

#include "constants.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setFixedHeight(WINDOW_HEIGHT);
    this->setFixedWidth(WINDOW_WIDTH);
    scene = new Scene(this);
    scene->setSceneRect(-WINDOW_WIDTH/2, -WINDOW_HEIGHT/2,
                        WINDOW_WIDTH, WINDOW_HEIGHT);
    ui->graphicsView->setScene(scene);
}

Widget::~Widget()
{
    delete ui;
}

