#ifndef POPUPDIALOG_H
#define POPUPDIALOG_H

#include <QApplication>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QKeyEvent>

// A custom dialog class that has three line edits and a confirm button
class PopupDialog : public QDialog {
    Q_OBJECT

public:
    PopupDialog(QWidget *parent = nullptr);
    // A function to get the text from the line edits
    QStringList getTexts() const;
private:
    // The widgets
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QPushButton *confirmButton;

private slots:


};

#endif // POPUPDIALOG_H
