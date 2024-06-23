#include "Test02.h"
#include <iostream>
#include <qtimer.h>
#include <qpushbutton.h>
Test02::Test02(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, &QPushButton::clicked,this, &Test02::f);

    QTimer* t = new QTimer;

    connect(t, &QTimer::timeout, this, []() {
        std::cout << "i" << std::endl;
        for (int i = 0; i < 100; i++)
        {
            std::cout << "i" << std::endl;   
        }
        });
    t->start(1000);
}

Test02::~Test02()
{}

void Test02::f()
{
    std::cout << "´øÄãÒ»ÏÂ" << std::endl;
    std::cout << "==============================================================================================================" << std::endl;
}
