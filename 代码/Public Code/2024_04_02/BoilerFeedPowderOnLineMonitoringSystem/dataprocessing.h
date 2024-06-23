#pragma once

#include <QWidget>
#include "alarmdatabase.h"
#include "channeldatabase.h"
class DataProcessing  : public QWidget
{
	Q_OBJECT
		friend class MainScreen;

public:
	DataProcessing(QWidget *parent);
	~DataProcessing();
private:
	AlarmDatabase* _alarm_database;     // 报警数据库:
	ChannelDatabase* _channel_database; // 通道数据库:
};
