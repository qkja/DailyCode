#include "Test02.h"
#include <QtWidgets/QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test02 w;
    w.show();
    //if (w.isVisible())
    //{
    //    std::cout << "hello" << std::endl;
    //}
    //else
    //{
    //    std::cout << "no" << std::endl;

    //}

    return a.exec();
}
