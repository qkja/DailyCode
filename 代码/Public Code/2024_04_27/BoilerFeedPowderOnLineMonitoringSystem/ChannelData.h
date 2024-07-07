#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif
#include <string>

struct ChannelData
{
	ChannelData();
	~ChannelData();

	ChannelData(const ChannelData&);
	std::string _name;
	std::string _serial_number;
	std::string	 _slate_number;
	std::string	_channel_number;
	std::string	_type;
	std::string	_range;
	std::string	_measured_value;
	std::string	_engineering_value;
};
