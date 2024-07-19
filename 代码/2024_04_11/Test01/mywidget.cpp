#include "mywidget.h"
#include <iostream>

MyWidget::MyWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::MyWidgetClass())
{
	ui->setupUi(this);
	std::cout << "1" << std::endl;

}

MyWidget::~MyWidget()
{
	std::cout << "2" << std::endl;
	delete ui;
}

void MyWidget::closeEvent(QCloseEvent*)
{
	emit ExitWin();
}
