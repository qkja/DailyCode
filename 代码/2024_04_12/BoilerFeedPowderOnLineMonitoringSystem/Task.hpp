#pragma once
#include <iostream>
#include <time.h>
#include "MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem.hpp"
struct Data
{
public:
	Data() {}

	Data(std::string time,
		 double temperature, double temperature_pulverized, double temperature_mixing,
		 double pressure_left, double pressure_right,
		 double area)
		: _time(time), _temperature(temperature), _temperature_pulverized(temperature_pulverized), _temperature_mixing(temperature_mixing), _pressure_left(pressure_left), _pressure_right(pressure_right), _area(area)
	{
	}
	Data(const Data &n)
	{
		_time = n._time;
		_temperature = n._temperature;
		_temperature_pulverized = n._temperature_pulverized;
		_temperature_mixing = n._temperature_mixing;
		_pressure_left = n._pressure_left;
		_pressure_right = n._pressure_right;
		_area = n._area;
	}
	std::string _time;
	double _temperature;			// 风温
	double _temperature_pulverized; // 煤粉温度
	double _temperature_mixing;		// 混合温度
	double _pressure_left;
	double _pressure_right;
	double _area;
};
struct Result
{
	std::string _time;
	double wind_speed;					   // 风速
	double pulverized_coal_concentration;  // 煤粉浓度
	double pulverized_coal_mass_flow_rate; // 煤粉质量流量
	double air_volume;					   // 风量
};

class Task
{
private:
	std::string timestampToString(const std::string &timestamp)
	{
		time_t t = std::stoll(timestamp);
		tm local_time;
		localtime_s(&local_time, &t);
		char buffer[20];
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &local_time);
		return buffer;
	}

public:
	Task()
	{
	}
	void set(const Data &v1, const Data &v2, const Data &v3)
	{
		primary_value = v1;
		secondary_value = v2;
		tertiary_value = v3;
	}
	void show()
	{
		std::cout << "-----------------一次----------------------" << std::endl;
		std::cout << "时间: " << primary_result._time << std::endl;
		std::cout << "煤粉浓度: " << primary_result.pulverized_coal_concentration << std::endl;
		std::cout << "煤粉质量流量: " << primary_result.pulverized_coal_mass_flow_rate << std::endl;
		std::cout << "风量: " << primary_result.wind_speed << std::endl;

		std::cout << "-----------------二次----------------------" << std::endl;
		std::cout << "时间: " << secondary_result._time << std::endl;
		std::cout << "煤粉浓度: " << secondary_result.pulverized_coal_concentration << std::endl;
		std::cout << "煤粉质量流量: " << secondary_result.pulverized_coal_mass_flow_rate << std::endl;
		std::cout << "风量: " << secondary_result.wind_speed << std::endl;

		std::cout << "-----------------三次----------------------" << std::endl;
		std::cout << "时间: " << tertiary_result._time << std::endl;
		std::cout << "煤粉浓度: " << tertiary_result.pulverized_coal_concentration << std::endl;
		std::cout << "煤粉质量流量: " << tertiary_result.pulverized_coal_mass_flow_rate << std::endl;
		std::cout << "风量: " << tertiary_result.wind_speed << std::endl;
	}
	void run()
	{
		// 计算一次的
		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::WindSpeed(
			&primary_result.wind_speed, primary_value._temperature, primary_value._pressure_right - primary_value._pressure_left, 1.0);

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::pulverizedCoalConcentration(
			&primary_result.pulverized_coal_concentration, primary_value._temperature, primary_value._temperature_pulverized, primary_value._temperature_mixing);

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::pulverizedCoalMassFlowRate(
			&primary_result.pulverized_coal_mass_flow_rate, primary_result.wind_speed, primary_value._area, primary_value._temperature, primary_result.pulverized_coal_concentration);

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::airVolume(
			&primary_result.air_volume, primary_result.wind_speed, primary_value._area);

		// 计算二次的
		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::WindSpeed(
			&secondary_result.wind_speed, secondary_value._temperature, secondary_value._pressure_right - secondary_value._pressure_left, 1.0);

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::pulverizedCoalConcentration(
			&secondary_result.pulverized_coal_concentration, secondary_value._temperature, secondary_value._temperature_pulverized, secondary_value._temperature_mixing);

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::pulverizedCoalMassFlowRate(
			&secondary_result.pulverized_coal_mass_flow_rate, secondary_result.wind_speed, secondary_value._area, secondary_value._temperature, secondary_result.pulverized_coal_concentration);

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::airVolume(
			&secondary_result.air_volume, secondary_result.wind_speed, secondary_value._area);
		// 计算三次的

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::WindSpeed(
			&tertiary_result.wind_speed, tertiary_value._temperature, tertiary_value._pressure_right - tertiary_value._pressure_left, 1.0);

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::pulverizedCoalConcentration(
			&tertiary_result.pulverized_coal_concentration, tertiary_value._temperature, tertiary_value._temperature_pulverized, tertiary_value._temperature_mixing);

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::pulverizedCoalMassFlowRate(
			&tertiary_result.pulverized_coal_mass_flow_rate, tertiary_result.wind_speed, tertiary_value._area, tertiary_value._temperature, tertiary_result.pulverized_coal_concentration);

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::airVolume(
			&tertiary_result.air_volume, tertiary_result.wind_speed, tertiary_value._area);

		// 时间转化

		primary_result._time = timestampToString(primary_value._time);
		secondary_result._time = timestampToString(secondary_value._time);
		tertiary_result._time = timestampToString(tertiary_value._time);
	}

private:
	struct Data primary_value;
	struct Data secondary_value;
	struct Data tertiary_value;

	struct Result primary_result;
	struct Result secondary_result;
	struct Result tertiary_result;
};
