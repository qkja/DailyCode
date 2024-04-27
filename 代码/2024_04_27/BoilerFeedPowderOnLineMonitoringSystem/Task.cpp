#include "Task.h"
Task::Task()
{
}

Task::~Task()
{
}

void Task::run()
{
	for (int i = 0; i < _primary_value.size(); i++)
	{
		struct Result result;

		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::WindSpeed(
			&result._wind_speed
			, _primary_value[i]._primaryAirTemperatureMeasuringPoint
			, _primary_value[i]._differentialPressure
			, _primary_value[i]._coefficient);
		// 计算煤粉浓度
		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::pulverizedCoalConcentration(
			&result._pulverized_coal_concentration
			, _primary_value[i]._primaryAirTemperatureMeasuringPoint
			, _primary_value[i]._pulverizedCoalTemperatureMeasuringPoint
			, _primary_value[i]._mixedTemperatureMeasuringPoint);

		// 煤粉质量流量
		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::pulverizedCoalMassFlowRate(
			&result._pulverized_coal_mass_flow_rate
			, result._wind_speed
			, _primary_value[i]._area
			, _primary_value[i]._primaryAirTemperatureMeasuringPoint
			, result._pulverized_coal_concentration);
		// 计算风量
		MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::airVolume(
			&result._air_volume
			, result._wind_speed
			, _primary_value[i]._area);
		// 时间转化
		result._time = timestampToString(_primary_value[i]._time);
		result._temperature = _primary_value[i]._primaryAirTemperatureMeasuringPoint;
		_primary_result.push_back(result);
	}
}

void Task::push_back(const Data& v)
{
	_primary_value.push_back(v);
}

void Task::show()
{
	for (int i = 0; i < _primary_result.size(); ++i)
	{
		std::cout << "个数: " << i << std::endl;
		std::cout << "时间: " << _primary_result[i]._time << std::endl;
		std::cout << "系数: " << _primary_value[i]._coefficient << std::endl;
		std::cout << "面积: " << _primary_value[i]._area << std::endl;
	}
}

std::string Task::timestampToString(const std::string& timestamp)
{
	time_t t = std::stoll(timestamp);
	tm local_time;
	localtime_s(&local_time, &t);
	char buffer[20];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &local_time);
	return buffer;
}

Data::Data()
{
}

Data::~Data()
{
}

Data::Data(const Data& n)
{
	_time = n._time;
	_differentialPressure = n._differentialPressure;
	_primaryAirTemperatureMeasuringPoint = n._primaryAirTemperatureMeasuringPoint;
	_pulverizedCoalTemperatureMeasuringPoint = n._pulverizedCoalTemperatureMeasuringPoint;
	_mixedTemperatureMeasuringPoint = n._mixedTemperatureMeasuringPoint;
	_area = n._area;
	_coefficient = n._coefficient;;
}

void Data::set(std::string time, double differentialPressure, double primaryAirTemperatureMeasuringPoint, double pulverizedCoalTemperatureMeasuringPoint, double mixedTemperatureMeasuringPoint, double area, double coefficient)
{
	_time = time;
	_differentialPressure = differentialPressure;
	_primaryAirTemperatureMeasuringPoint = primaryAirTemperatureMeasuringPoint;
	_pulverizedCoalTemperatureMeasuringPoint = pulverizedCoalTemperatureMeasuringPoint;
	_mixedTemperatureMeasuringPoint = mixedTemperatureMeasuringPoint;
	_area = area;
	_coefficient = coefficient;
}

Result::Result()
{
}

Result::~Result()
{
}

Result::Result(const Result& result)
{
	_time = result._time;
	_wind_speed = result._wind_speed;
	_pulverized_coal_concentration = result._pulverized_coal_concentration;
	_pulverized_coal_mass_flow_rate = result._pulverized_coal_mass_flow_rate;
	_air_volume = result._air_volume;
	_temperature = result._temperature;
}