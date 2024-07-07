#include "historicaltrendchart.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HistoricalTrendChart w;
    w.show();
    return a.exec();
}
