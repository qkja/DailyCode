#include "Sub.h"
#include <iostream>

Sub::Sub(QWidget* parent, Test* t)
	: QWidget(parent)
	, ui(new Ui::SubClass())
	, _t(t)
{
	//setAttribute(Qt::WA_DeleteOnClose);
	std::cout << "Sub()" << std::endl;
	
	ui->setupUi(this);
	connect(_t, &Test::mySig, [=](const std::string& str) {
		
		int a = 10;
		*ui;
		std::cout << ui << std::endl;
		int b = 20;
		std::cout << str << std::endl;
		//ui->label->setText(str.c_str());
		ui->label->setText("aaaaaa");
	});
}

Sub::~Sub()
{
	std::cout << "~Sub()" << std::endl;
	delete ui;
	ui = nullptr;
}

void Sub::closeEvent(QCloseEvent*)
{
		emit subClose();           //发出关闭信号，父窗体接收信号后显示窗体
}
