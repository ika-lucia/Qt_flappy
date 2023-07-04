#include "widget.h"
#include "constants.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    initialize();
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
