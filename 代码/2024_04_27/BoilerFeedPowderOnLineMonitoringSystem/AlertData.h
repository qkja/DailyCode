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
	std::string _sensor_name; // ����������
	std::string _alarm_type;  // ��������
	std::string _initial_time_point; // ��ʼʱ���
	std::string	_data; // ����
	std::string _end_time_point;// ����ʱ���
};
