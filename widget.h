#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"scene.h"
#include <QPushButton>
#include"popupdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    QPushButton* start_btn;
    ~Widget();
    // Override the keyPressEvent function to show the popup dialog when m is pressed
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::Widget *ui;
    Scene* scene;
    PopupDialog* popupDlg;
private slots:
    void onPopupAccepted();
};
#endif // WIDGET_H
