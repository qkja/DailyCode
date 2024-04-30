#pragma once
#include <string>
class ChannelData
{
	friend class ChannelDatabase;
public:
	ChannelData();
	~ChannelData();

	ChannelData(const ChannelData&);
private:
	std::string _name;
	std::string _serial_number;
	std::string	 _slate_number;
	std::string	_channel_number;
	std::string	_type;
	std::string	_range;
	std::string	_measured_value;
	std::string	_engineering_value;
};
