#include "AlertData.h"
/*
* 这个一个数据的集合，封装起来了
*/
AlertData::AlertData()
{
}

AlertData::~AlertData()
{
}

AlertData::AlertData(const AlertData& data)
{
	if (&data == this)
		return;
	_sensor_name = data._sensor_name; // 传感器名字
	_alarm_type = data._alarm_type;  // 出限类型
	_initial_time_point = data._initial_time_point; // 起始时间点
	_data = data._data; // 数据
	_end_time_point = data._end_time_point;// 结束时间点
}