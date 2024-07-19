#include "Test03.h"
#include <qpainter.h>
Test03::Test03(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test03Class())
{
    this->setWindowTitle("你好");
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
    painterBias.drawLine(1, 1, 20, 20); // 左上
    painterBias.drawLine(width, 0, (2 * width) / 3, (1 * height) / 3); // 右上
    painterBias.drawLine(0, height, (1 * width) / 3, (2 * height) / 3); // 左下
    painterBias.drawLine((2 * width) / 3, (2 * height) / 3, width, width); // 右下
    //QPainter painter(this); // 这里的this不是父对象了,这是指定的画板

    //// 画一个线段]
    //painter.drawLine(20, 20, 200, 20);
    //painter.drawLine(QPoint(20, 100), QPoint(200, 100));


    //// 画一个矩形
    //painter.drawRect(100,100, 300, 200);

    //// 画圆形

    //painter.drawEllipse(100, 100, 20, 20);

    //// 绘制文字
    //painter.drawText(0, 100, "hello");


    // 修改绘制形状的颜色信息, 包含粗细, 颜色, 样式(实线,虚线,点线)

}
