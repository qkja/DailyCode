#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include "MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem.h"

// 仅仅计算一次的
struct Data
{
	Data();
	~Data();

	Data(const Data&);

	void set(const std::string&, double, double, double, double, double, double);

	std::string _time;                               // 时间戳
	double _differentialPressure;                    // 一次风动压测点
	double _primaryAirTemperatureMeasuringPoint;     // 一次风温测点
	double _pulverizedCoalTemperatureMeasuringPoint; // 煤粉温度测点
	double _mixedTemperatureMeasuringPoint;          // 混合温度测点
	double _area;                                    // 面积
	double _coefficient;                             // 测速管风洞标定系数
};

struct Result
{
	Result();
	~Result();
	Result(const Result&);
	std::string _time;                      // 时间
	double _wind_speed;					    // 风速
	double _pulverized_coal_concentration;  // 煤粉浓度
	double _pulverized_coal_mass_flow_rate; // 煤粉质量流量
	double _air_volume;					    // 风量
	double _temperature;                    // 温度
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
	std::vector<struct Data> _primary_value;   // 输入的数据
	std::vector<struct Result> _primary_result;// 输出的数据
};
