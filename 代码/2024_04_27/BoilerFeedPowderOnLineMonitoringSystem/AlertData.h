#pragma once
#include <string>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")// ��ָ���֧��VS����
#endif
struct AlertData
{
public:
	AlertData();
	~AlertData();

	AlertData(const AlertData&);
	std::string _sensor_name; // ����������
	std::string _alarm_type;  // ��������
	std::string _initial_time_point; // ��ʼʱ���
	std::string	_data; // ����
	std::string _end_time_point;// ����ʱ���
};
