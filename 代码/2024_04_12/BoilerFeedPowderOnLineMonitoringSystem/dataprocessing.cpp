#include "dataprocessing.h"

DataProcessing::DataProcessing(QWidget* parent)
	: QWidget(parent), _alarm_database(new AlarmDatabase(nullptr)), _channel_database(new ChannelDatabase(nullptr))
{
}

DataProcessing::~DataProcessing()
{
	delete _alarm_database;
	delete _channel_database;
}