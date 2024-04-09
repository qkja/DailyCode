#include "trendchart.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TrendChart w;
    w.show();
    return a.exec();
}
