#include "test01.h"

#include <QWidget>
#include <QPainter>
Test01::Test01(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test01Class())
{
    ui->setupUi(this);
    QPainter* painter = new QPainter(this);
    (*painter).setPen(Qt::black);
    (*painter).drawLine(50, 50, 150, 50);   // top line
    (*painter).drawLine(150, 50, 150, 150); // right line
    (*painter).drawLine(150, 150, 50, 150); // bottom line
    (*painter).drawLine(50, 150, 50, 50);   // left line
}

Test01::~Test01()
{
    delete ui;
}
