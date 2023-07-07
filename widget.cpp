#include "widget.h"
#include "./ui_widget.h"
#include<QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include"constants.h"
#include <iostream>

#include "constants.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , popupDlg(new PopupDialog)
{
    ui->setupUi(this);

    this->setFixedHeight(WINDOW_HEIGHT);
    this->setFixedWidth(WINDOW_WIDTH);
    scene = new Scene(this);
    scene->setSceneRect(-WINDOW_WIDTH/2, -WINDOW_HEIGHT/2,
                        WINDOW_WIDTH, WINDOW_HEIGHT);
    ui->graphicsView->setScene(scene);
    connect(popupDlg, &PopupDialog::accepted, this, &Widget::onPopupAccepted);
}

Widget::~Widget()
{
    delete ui;
    delete popupDlg;
}

// Override the keyPressEvent function to show the popup dialog when m is pressed
void Widget::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_M)
    {
        popupDlg->show();
    }
}

void Widget::onPopupAccepted() {
    QStringList texts = popupDlg->getTexts();
    if (texts.size() == 3)
    {
        // Change the variables with the text values
        SPEED = texts[0].toInt();
        GAP_WIDTH = texts[1].toInt();
        BAT_ROTATE_SPEED = texts[2].toDouble();
    }
}
