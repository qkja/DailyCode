#pragma once

#include <QWidget>
#include "backrestcanal.h"
#include "spout.h"
#include "giveanalarm.h"
#include "wordofcommand.h"
#include "mytime.h"
#include <iostream>
#include "configure.h"
class SystemSetting : public QWidget
{
	Q_OBJECT
	friend class BoilerFeedPowderOnLineMonitoringSystem;

public:
	SystemSetting(QWidget *parent = nullptr, Configure* configure = nullptr);
	~SystemSetting();

private:
	Configure* _configure;             // 这是为了使用信号与槽
	GiveAnAlarm *_give_an_alarm;	 //   设定报警限
	MyTime *_mytime;				 //   设定时间
	Spout *_spout;					 //   
	BackrestCanal *_backrest_canal;	 //   ������ϵ�����
	WordOfCommand *_word_of_command; //   �޸Ŀ���
};
