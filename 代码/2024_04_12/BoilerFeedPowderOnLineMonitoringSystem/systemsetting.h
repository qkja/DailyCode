#pragma once

#include <QWidget>
#include "backrestcanal.h"
#include "spout.h"
#include "giveanalarm.h"
#include "wordofcommand.h"
#include "mytime.h"
#include <iostream>

class SystemSetting : public QWidget
{
	Q_OBJECT
	friend class BoilerFeedPowderOnLineMonitoringSystem;

public:
	SystemSetting(QWidget *parent = nullptr);
	~SystemSetting();

private:
	GiveAnAlarm *_give_an_alarm;	 //   �趨������
	MyTime *_mytime;				 //   �޶�ʱ��
	Spout *_spout;					 //   �趨������
	BackrestCanal *_backrest_canal;	 //   ������ϵ������
	WordOfCommand *_word_of_command; //   �޸Ŀ���
};
