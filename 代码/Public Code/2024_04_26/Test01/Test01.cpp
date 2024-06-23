#include "Test01.h"
#include <iostream>
Test01::Test01(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test01Class())
{
    ui->setupUi(this);
    int left = this->height();
    int right = this->width();

    int a = 10;
}

Test01::~Test01()
{
    delete ui;
}

