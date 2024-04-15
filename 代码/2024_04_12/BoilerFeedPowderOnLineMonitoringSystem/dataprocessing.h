#pragma once

#include <QWidget>
#include "alarmdatabase.h"
#include "channeldatabase.h"
#include <iostream>

class DataProcessing : public QWidget
{
	Q_OBJECT
	friend class BoilerFeedPowderOnLineMonitoringSystem;

public:
	DataProcessing(QWidget *parent);
	~DataProcessing();

private:
	AlarmDatabase *_alarm_database;		// �������ݿ�:
	ChannelDatabase *_channel_database; // ͨ�����ݿ�:
};
