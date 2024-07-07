#include "BoilerFeedPowderOnLineMonitoringSystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BoilerFeedPowderOnLineMonitoringSystem w;
    w.hide();
    return a.exec();
}
