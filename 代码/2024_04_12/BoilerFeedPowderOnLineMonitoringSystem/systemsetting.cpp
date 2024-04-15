#include "systemsetting.h"
#include <qdebug.h>
SystemSetting::SystemSetting(QWidget *parent)
	: QWidget(parent), _give_an_alarm(new GiveAnAlarm(nullptr)), _mytime(new MyTime(nullptr)), _spout(new Spout(nullptr)), _backrest_canal(new BackrestCanal(nullptr)), _word_of_command(new WordOfCommand(nullptr))
{

	qDebug() << "SystemSetting()";
}

SystemSetting::~SystemSetting()
{
	// Ϊ����Ҫ�ֶ�����,������Ϊ_give_an_alarmû�м��������
	// Ϊ�β����������,��ᷢ��SystemSettingû��ui����,����_give_an_alarm������ʾ����
	delete _give_an_alarm;
	delete _mytime;
	delete _backrest_canal;
	delete _spout;
	delete _word_of_command;
	qDebug() << "~SystemSetting()";
}