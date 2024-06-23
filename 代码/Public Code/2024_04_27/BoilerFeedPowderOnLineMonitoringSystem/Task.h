#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include "MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem.h"

// ��������һ�ε�
struct Data
{
	Data();
	~Data();

	Data(const Data&);

	void set(const std::string&, double, double, double, double, double, double);

	std::string _time;                               // ʱ���
	double _differentialPressure;                    // һ�η綯ѹ���
	double _primaryAirTemperatureMeasuringPoint;     // һ�η��²��
	double _pulverizedCoalTemperatureMeasuringPoint; // ú���¶Ȳ��
	double _mixedTemperatureMeasuringPoint;          // ����¶Ȳ��
	double _area;                                    // ���
	double _coefficient;                             // ���ٹܷ綴�궨ϵ��
};

struct Result
{
	Result();
	~Result();
	Result(const Result&);
	std::string _time;                      // ʱ��
	double _wind_speed;					    // ����
	double _pulverized_coal_concentration;  // ú��Ũ��
	double _pulverized_coal_mass_flow_rate; // ú����������
	double _air_volume;					    // ����
	double _temperature;                    // �¶�
};

class Task
{
private:
	std::string timestampToString(const std::string&);
public:
	Task();
	~Task();
	void run();
	void push_back(const Data&);
	void show();
	std::vector<struct Data> _primary_value;   // ���������
	std::vector<struct Result> _primary_result;// ���������
};
