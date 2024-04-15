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

    QPainter painter(this); // �����this���Ǹ�������,����ָ���Ļ���
    std::cout << this->height() << std::endl;
    std::cout << this->width() << std::endl;
    // ��һ���߶�]
    painter.drawLine(20, 20, 200, 20);
}
