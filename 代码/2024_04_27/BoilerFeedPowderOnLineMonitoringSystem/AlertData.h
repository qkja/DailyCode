#pragma once
#include <string>

class AlertData
{
public:
	friend class AlarmDatabase;
	AlertData();
	~AlertData();

	AlertData(const AlertData&);
private:
	std::string _sensor_name; // 传感器名字
	std::string _alarm_type;  // 出限类型
	std::string _initial_time_point; // 起始时间点
	std::string	_data; // 数据
	std::string _end_time_point;// 结束时间点
};
