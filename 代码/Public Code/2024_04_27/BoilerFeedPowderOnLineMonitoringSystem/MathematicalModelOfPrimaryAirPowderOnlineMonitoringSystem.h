#pragma once
#include <iostream>
#include <cmath>
class MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem
{
public:
	enum UNITOPTION
	{
		FORCEOFPRESSURE,	  // 帕斯卡
		COLUMNOFMERCURY,	  // 厘米汞柱
		TEMPERATUREINCELSIUS, // 摄氏度温标
		TEMPERATUREINKELVIN	  // 开尔文温度
	};

private:
	/*
	 * 计算空气比热和煤粉比热
	 * specific_heat_of_air:空气比热
	 * specific_heat_of_pulverized_coal:煤粉比热
	 * temperature:温度
	 */
	static void specificHeat(double* specific_heat_of_air,
		double* specific_heat_of_pulverized_coal,
		double temperature,
		bool unit_temperature = UNITOPTION::TEMPERATUREINCELSIUS);
public:
	/*
	 * 计算风速
	 * 测速管风洞标定系数:   calibration_coefficient_for_tachometer_wind_tunnel
	 * 温度:               temperature
	 * 测量的差压:          differential_pressure
	 */
	static void WindSpeed(double* wind_speed,
		double temperature,
		const double& differential_pressure,
		const double& calibration_coefficient_for_tachometer_wind_tunnel,
		bool unit_temperature = UNITOPTION::TEMPERATUREINCELSIUS,
		bool unit_option = UNITOPTION::FORCEOFPRESSURE);
	/*
	* 计算煤粉浓度
	* temperature: 各点的温度
	* pulverized_coal_concentration:煤粉浓度
	*/
	static void pulverizedCoalConcentration(double* pulverized_coal_concentration,
		double temperature_1,
		double temperature_2,
		double temperature_3);
	/*
	 * 计算煤粉质量流量
	 * wind_speed:一次风速
	 * cross_sectional_area_of_primary_duct:一次风管截面积
	 * the_density_of_air_under_standard_conditions:空气在标准状况下的密度
	 * primary_air_temperature:一次风温
	 * pulverized_coal_concentration:煤粉浓度
	 * pulverized_coal_mass_flow_rate:煤粉质量流量
	 */
	static void pulverizedCoalMassFlowRate(double* pulverized_coal_mass_flow_rate,
		double wind_speed,
		double cross_sectional_area_of_primary_duct,
		double primary_air_temperature,
		double pulverized_coal_concentration,
		double the_density_of_air_under_standard_conditions = 1.29,
		bool unit_temperature = UNITOPTION::TEMPERATUREINCELSIUS);
	/*
	 * 计算风量
	 * wind_speed:一次、二次、三次风速
	 * cross_sectional_area_of_primary_duct:一次、二次、三次风管截面积
	 */
	static void airVolume(double* air_volume,
		const double& wind_speed,
		const double& cross_sectional_area_of_primary_duct);
};
