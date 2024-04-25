#include "systemsetting.h"
#include <qdebug.h>
SystemSetting::SystemSetting(QWidget *parent, Configure* configure)
	: QWidget(parent)
	, _configure(configure)
	, _mytime(new MyTime(nullptr))
	, _give_an_alarm(new GiveAnAlarm(nullptr, _configure))
	, _spout(new Spout(nullptr, _configure))
	, _backrest_canal(new BackrestCanal(nullptr, _configure))
	, _word_of_command(new WordOfCommand(nullptr, _configure))
{
	qDebug() << "SystemSetting()";
}

SystemSetting::~SystemSetting()
{
	delete _give_an_alarm;
	delete _mytime;
	delete _backrest_canal;
	delete _spout;
	delete _word_of_command;
	qDebug() << "~SystemSetting()";
}