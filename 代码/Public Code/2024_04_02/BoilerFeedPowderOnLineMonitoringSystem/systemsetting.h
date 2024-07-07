#pragma once

#include <QWidget>
#include "backrestcanal.h"
#include "spout.h"
#include "giveanalarm.h"
#include "wordofcommand.h"
#include "mytime.h"
class SystemSetting  : public QWidget
{
	Q_OBJECT
    friend class MainScreen;
public:
	SystemSetting(QWidget *parent = nullptr);
	~SystemSetting();
private:
	GiveAnAlarm* _give_an_alarm;      //   设定报警限
	MyTime* _mytime;                  //   修定时间
	Spout* _spout;                    //   设定喷口面积
	BackrestCanal* _backrest_canal;   //   靠背管系数修正
	WordOfCommand* _word_of_command;  //   修改口令
};
