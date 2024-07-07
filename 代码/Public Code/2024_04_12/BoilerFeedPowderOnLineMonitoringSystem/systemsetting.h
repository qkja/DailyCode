#pragma once

#include "backrestcanal.h"
#include "configure.h"
#include "giveanalarm.h"
#include "mytime.h"
#include "spout.h"
#include "wordofcommand.h"
#include <iostream>
#include <QWidget>
class SystemSetting : public QWidget
{
	Q_OBJECT
		friend class BoilerFeedPowderOnLineMonitoringSystem;

public:
	SystemSetting(QWidget* parent = nullptr, Configure* configure = nullptr);
	~SystemSetting();
private:
	Configure* _configure;           //   这是为了使用信号与槽
	GiveAnAlarm* _give_an_alarm;	 //   设定报警限
	MyTime* _mytime;				 //   设定时间
	Spout* _spout;					 //   修改喷口面积
	BackrestCanal* _backrest_canal;	 //   修改靠背管系数
	WordOfCommand* _word_of_command; //   修改口令
};
