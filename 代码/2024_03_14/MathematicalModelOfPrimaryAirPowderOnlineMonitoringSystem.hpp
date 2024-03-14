#include <iostream>
#include <cmath>
class MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem
{
public:
	enum UNITOPTION
	{
		FORCEOFPRESSURE,
		COLUMNOFMERCURY
	};
public:

	static void f()
	{
		std::cout << "debug" << std::endl;
	}
	/*
	* 计算风速
	* 测速管风洞标定系数:    calibration_coefficient_for_tachometer_wind_tunnel
	* 温度:               temperature
	* 测量的差压:          differential_pressure
	*/
	static void WindSpeed(double& wind_speed,
		const double& temperature,
		const double& differential_pressure,
		const double& calibration_coefficient_for_tachometer_wind_tunnel,
		bool unit_option = UNITOPTION::FORCEOFPRESSURE)
	{
		// 计算流速修正系数
		double flow_velocity_correction_factor
			= sqrt(calibration_coefficient_for_tachometer_wind_tunnel);
		// 计算输送气体的密度
		double density = 1.343 * 273.15 / (temperature + 273.15);
		// 计算风速
		wind_speed = flow_velocity_correction_factor * sqrt(differential_pressure / density);
		if (unit_option == UNITOPTION::FORCEOFPRESSURE)
			wind_speed = sqrt(2.0) * wind_speed;
		else
			wind_speed = 4.43 * wind_speed;
	}




};

