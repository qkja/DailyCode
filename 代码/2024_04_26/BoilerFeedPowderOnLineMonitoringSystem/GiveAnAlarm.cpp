#include "GiveAnAlarm.h"

GiveAnAlarm::GiveAnAlarm(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::GiveAnAlarmClass())
{

	ui->setupUi(this);
	std::cout << "GiveAnAlarm()" << std::endl;
	this->setWindowTitle("设定报警限");
}

GiveAnAlarm::~GiveAnAlarm()
{
	std::cout << "~GiveAnAlarm()" << std::endl;
	delete ui;
}