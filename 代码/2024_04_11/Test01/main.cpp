#include "test01.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test01 w;
    w.show();
    return a.exec();
}
