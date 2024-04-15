#include "giveanalarm.h"
#include <qdebug.h>

GiveAnAlarm::GiveAnAlarm(QWidget *parent)
	: QWidget(parent), ui(new Ui::GiveAnAlarmClass())
{
	ui->setupUi(this);
	qDebug() << "GiveAnAlarm()";
	this->setWindowTitle("�趨��������");
	connect(ui->identify_pushButton, &QPushButton::clicked, [=]()
			{ emit fromGiveAnAlarmToMainScreenSignals(); });
	connect(ui->cancel_pushButton, &QPushButton::clicked, [=]()
			{ emit fromGiveAnAlarmToMainScreenSignals(); });
}

GiveAnAlarm::~GiveAnAlarm()
{
	delete ui;
	qDebug() << "~GiveAnAlarm()";
}