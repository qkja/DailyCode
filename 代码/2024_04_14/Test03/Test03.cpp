#include "Test03.h"
#include <qpainter.h>
Test03::Test03(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test03Class())
{
    ui->setupUi(this);
}

Test03::~Test03()
{
    delete ui;
}

void Test03::paintEvent(QPaintEvent* event)
{
    (void)event;
    int width = this->width();
    int height = this->height();

    QPainter painterBias;
    QPen penBias;
    penBias.setWidth(5);
    //penBias.setColor(QColor(0, 255, 0));
    painterBias.setPen(penBias);
    painterBias.drawLine(1, 1, 20, 20); // ����
    painterBias.drawLine(width, 0, (2 * width) / 3, (1 * height) / 3); // ����
    painterBias.drawLine(0, height, (1 * width) / 3, (2 * height) / 3); // ����
    painterBias.drawLine((2 * width) / 3, (2 * height) / 3, width, width); // ����
    //QPainter painter(this); // �����this���Ǹ�������,����ָ���Ļ���

    //// ��һ���߶�]
    //painter.drawLine(20, 20, 200, 20);
    //painter.drawLine(QPoint(20, 100), QPoint(200, 100));


    //// ��һ������
    //painter.drawRect(100,100, 300, 200);

    //// ��Բ��

    //painter.drawEllipse(100, 100, 20, 20);

    //// ��������
    //painter.drawText(0, 100, "hello");


    // �޸Ļ�����״����ɫ��Ϣ, ������ϸ, ��ɫ, ��ʽ(ʵ��,����,����)

}
