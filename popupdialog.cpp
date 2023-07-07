#include "popupdialog.h"
#include"constants.h"
#include<QLabel>

PopupDialog::PopupDialog(QWidget *parent) : QDialog(parent)
{
    // Create the line edits and the button
    lineEdit1 = new QLineEdit(this);
    lineEdit1->setText(QString::number(SPEED)); // Set the text to the default value of scene moving speed
    lineEdit2 = new QLineEdit(this);
    lineEdit2->setText(QString::number(GAP_WIDTH)); // lineEdit2 in charge of the width of pillars
    lineEdit3 = new QLineEdit(this);
    lineEdit3->setText(QString::number(BAT_ROTATE_SPEED, 'f', 2)); // lineEdit3 in charge of the rotation speed of bats
    confirmButton = new QPushButton("Confirm", this);

    // Connect the button to the accept slot of the dialog
    connect(confirmButton, &QPushButton::clicked, this, &PopupDialog::accept);

    // Create a layout and add the widgets
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label1 = new QLabel("Speed of the scene:", this);
    layout->addWidget(label1);
    layout->addWidget(lineEdit1);
    QLabel *label2 = new QLabel("Gap Width", this);
    layout->addWidget(label2);
    layout->addWidget(lineEdit2);
    QLabel *label3 = new QLabel("Bat moving speed", this);
    layout->addWidget(label3);
    layout->addWidget(lineEdit3);
    layout->addWidget(confirmButton);

    // Set the layout and the window title
    setLayout(layout);
    setWindowTitle("Popup Dialog");
    resize(300, 200);
}
QStringList PopupDialog::getTexts() const {
    return {lineEdit1->text(), lineEdit2->text(), lineEdit3->text()};
}
