#include "Test02.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test02 w;
    w.show();
    return a.exec();
}
