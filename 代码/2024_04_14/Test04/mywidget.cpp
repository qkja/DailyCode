#include "mywidget.h"
#include <iostream>
MyWidget::MyWidget(QWidget *parent)
	: QWidget(parent)
{}

MyWidget::~MyWidget()
{
    std::cout << "1" << std::endl;
}

void MyWidget::paintEvent(QPaintEvent * event)
{
    (void)event;

    QPainter painter(this); // 这里的this不是父对象了,这是指定的画板
    std::cout << this->height() << std::endl;
    std::cout << this->width() << std::endl;
    // 画一个线段]
    painter.drawLine(20, 20, 200, 20);
}
