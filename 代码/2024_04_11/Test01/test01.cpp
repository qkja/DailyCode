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
    // �����Ӵ��ڲ���ʾ
    myChildWin = new MyWidget;
    myChildWin->show();
    // ����������
    this->hide();
    connect(myChildWin, &MyWidget::ExitWin, [=]() {
        
        this->show();
        myChildWin->close();
    });
    // �����Ӵ��ڵĹر��źţ�������ʾ������
    //connect(myChildWin, SIGNAL(ExitWin()), this, SLOT(show()));
    //// �����Ӵ��ڲ���ʾ
    //childWin = new ChildWin_Widget(this);
    //childWin->show();

    //// ����������
    //this->hide();

    //// �����Ӵ��ڵĹر��źţ�������ʾ������
    //connect(childWin, SIGNAL(ExitWin()), this, SLOT(show()));
}
