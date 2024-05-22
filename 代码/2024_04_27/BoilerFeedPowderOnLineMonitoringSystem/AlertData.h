#pragma once
#include <string>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// 该指令仅支持VS环境
#endif
struct AlertData
{
public:
	AlertData();
	~AlertData();

	AlertData(const AlertData&);
	std::string _sensor_name; // 传感器名字
	std::string _alarm_type;  // 出限类型
	std::string _initial_time_point; // 起始时间点
	std::string	_data; // 数据
	std::string _end_time_point;// 结束时间点
};
