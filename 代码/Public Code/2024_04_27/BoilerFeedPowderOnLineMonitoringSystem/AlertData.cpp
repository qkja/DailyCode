#include "AlertData.h"
/*
* ���һ�����ݵļ��ϣ���װ������
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
	_sensor_name = data._sensor_name; // ����������
	_alarm_type = data._alarm_type;  // ��������
	_initial_time_point = data._initial_time_point; // ��ʼʱ���
	_data = data._data; // ����
	_end_time_point = data._end_time_point;// ����ʱ���
}