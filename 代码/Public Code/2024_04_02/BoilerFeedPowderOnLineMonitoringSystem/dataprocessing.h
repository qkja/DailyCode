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
	AlarmDatabase* _alarm_database;     // �������ݿ�:
	ChannelDatabase* _channel_database; // ͨ�����ݿ�:
};
