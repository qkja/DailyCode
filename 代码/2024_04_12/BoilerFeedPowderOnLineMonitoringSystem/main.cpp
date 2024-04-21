#include "boilerfeedpowderonlinemonitoringsystem.h"
#include <QtWidgets/QApplication>
#include <synchapi.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BoilerFeedPowderOnLineMonitoringSystem w;
    w.hide();
    return a.exec();
}
