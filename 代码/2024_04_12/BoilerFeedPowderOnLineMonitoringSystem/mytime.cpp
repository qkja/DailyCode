#include "mytime.h"
#include <qdebug.h>
MyTime::MyTime(QWidget *parent)
	: QWidget(parent), ui(new Ui::MyTimeClass())
{
	qDebug() << "MyTime()";
	ui->setupUi(this);
	this->setWindowTitle("�޸�ʱ��");
	connect(ui->identify_pushButton, &QPushButton::clicked, [=]()
			{ emit fromMyTimeToMianScreenSignals(); });
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]()
			{ emit fromMyTimeToMianScreenSignals(); });
}

MyTime::~MyTime()
{
	qDebug() << "~MyTime()";
	delete ui;
}
