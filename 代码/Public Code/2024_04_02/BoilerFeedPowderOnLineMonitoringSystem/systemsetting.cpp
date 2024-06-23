#include "systemsetting.h"
#include <qdebug.h>
SystemSetting::SystemSetting(QWidget *parent)
	: QWidget(parent)
	,_give_an_alarm(new GiveAnAlarm(nullptr))
	,_mytime(new MyTime(nullptr))
	,_spout(new Spout(nullptr))
	,_backrest_canal(new BackrestCanal(nullptr))
	,_word_of_command(new WordOfCommand(nullptr))
{

	qDebug() << "SystemSetting()";
}

SystemSetting::~SystemSetting()
{
	// 为何需要手动析构,这是因为_give_an_alarm没有加入对象书
	// 为何不加入对象树,你会发现SystemSetting没有ui界面,导致_give_an_alarm不会显示出来
	delete _give_an_alarm; 
	delete _mytime;
	delete _backrest_canal;
	delete _spout;
	delete _word_of_command;
	qDebug() << "~SystemSetting()";
}