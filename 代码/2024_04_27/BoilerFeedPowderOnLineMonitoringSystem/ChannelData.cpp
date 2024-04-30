#include "ChannelData.h"

ChannelData::ChannelData()
{
}

ChannelData::~ChannelData()
{
}

ChannelData::ChannelData(const ChannelData& data)
{
	if (this == &data)
		return;
	_name = data._name;
	_serial_number = data._serial_number;
	_slate_number = data._slate_number;
	_channel_number = data._channel_number;
	_type = data._type;
	_range = data._range;
	_measured_value = data._measured_value;
	_engineering_value = data._engineering_value;
}