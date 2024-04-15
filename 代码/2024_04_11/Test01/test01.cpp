#include "test01.h"
#include <qpushbutton.h>
#include <iostream>
Test01::Test01(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test01Class())
{
    ui->setupUi(this);
    setFixedSize(800, 640);
   

    connect(ui->action2, &QAction::triggered, [=]() {
        NewBtnClick();
        });
}

Test01::~Test01()
{
    delete ui;
    std::cout << "3";
}

void Test01::NewBtnClick()
{
    // 创建子窗口并显示
    myChildWin = new MyWidget;
    myChildWin->show();
    // 隐藏主窗口
    this->hide();
    connect(myChildWin, &MyWidget::ExitWin, [=]() {
        
        this->show();
        myChildWin->close();
    });
    // 连接子窗口的关闭信号，重新显示主窗口
    //connect(myChildWin, SIGNAL(ExitWin()), this, SLOT(show()));
    //// 创建子窗口并显示
    //childWin = new ChildWin_Widget(this);
    //childWin->show();

    //// 隐藏主窗口
    //this->hide();

    //// 连接子窗口的关闭信号，重新显示主窗口
    //connect(childWin, SIGNAL(ExitWin()), this, SLOT(show()));
}
