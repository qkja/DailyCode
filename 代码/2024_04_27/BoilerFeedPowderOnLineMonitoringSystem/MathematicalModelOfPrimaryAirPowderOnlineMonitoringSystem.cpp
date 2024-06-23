#include "MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem.h"

/*
*这个类是我们将拿到的数据进行结果得到结果的过程，这些函数的原理来自我们的文档
*/
void MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::specificHeat(double* specific_heat_of_air, double* specific_heat_of_pulverized_coal, double temperature, bool unit_temperature)
{
	if (unit_temperature == UNITOPTION::TEMPERATUREINCELSIUS)
		temperature = temperature + 273.15;

	*specific_heat_of_air = -0.415813 * pow(temperature, 4) + 1.70338 * pow(temperature, 3) - 1.90478 * pow(temperature, 2) + 0.890486 * pow(temperature, 1) + 0.86751;
	*specific_heat_of_pulverized_coal = 0.00865 * pow(temperature, 4) - 0.16581 * pow(temperature, 3) + 0.3307 * pow(temperature, 2) + 0.01550 * pow(temperature, 1) + 1.151;
}

void MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::WindSpeed(double* wind_speed, double temperature, const double& differential_pressure, const double& calibration_coefficient_for_tachometer_wind_tunnel, bool unit_temperature, bool unit_option)
{
	if (unit_temperature == UNITOPTION::TEMPERATUREINKELVIN)
		temperature = temperature + 273.15;

	// 计算流速修正系数
	double flow_velocity_correction_factor = sqrt(calibration_coefficient_for_tachometer_wind_tunnel);
	// 计算输送气体的密度
	double density = 1.343 * 273.15 / temperature;
	// 计算风速
	*wind_speed = flow_velocity_correction_factor * sqrt(differential_pressure / density);
	if (unit_option == UNITOPTION::FORCEOFPRESSURE)
		*wind_speed = sqrt(2.0) * *wind_speed;
	else
		*wind_speed = 4.43 * *wind_speed;
}

void MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::pulverizedCoalConcentration(double* pulverized_coal_concentration, double temperature_1, double temperature_2, double temperature_3)
{
	temperature_1 = (temperature_1 + 273.15) / 1000;
	temperature_2 = temperature_2 / 273.15;
	temperature_3 = (temperature_3 + 273.15) / 1000;

	double specific_heat_of_air_1;
	double specific_heat_of_air_2;
	double specific_heat_of_pulverized_coal_1;
	double specific_heat_of_pulverized_coal_2;

	specificHeat(&specific_heat_of_air_1, &specific_heat_of_pulverized_coal_1, temperature_1, UNITOPTION::TEMPERATUREINKELVIN);
	specificHeat(&specific_heat_of_air_2, &specific_heat_of_pulverized_coal_2, temperature_2, UNITOPTION::TEMPERATUREINKELVIN);

	// μ = （Cp1T1 - Cp2T3） / （Cc2T3 - Cc1T2） - 0.005
	*pulverized_coal_concentration =
		(specific_heat_of_air_1 * temperature_1 - specific_heat_of_air_2 * temperature_3) / (specific_heat_of_pulverized_coal_2 * temperature_3 - specific_heat_of_pulverized_coal_1 * temperature_2) - 0.005;
}

void MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::pulverizedCoalMassFlowRate(double* pulverized_coal_mass_flow_rate, double wind_speed, double cross_sectional_area_of_primary_duct, double primary_air_temperature, double pulverized_coal_concentration, double the_density_of_air_under_standard_conditions, bool unit_temperature)
{
	if (unit_temperature == UNITOPTION::TEMPERATUREINCELSIUS)
		primary_air_temperature = primary_air_temperature + 273.15;

	// Mc = 3600ωsρ(273 / T1)μ;

	*pulverized_coal_mass_flow_rate = 3600 * wind_speed * cross_sectional_area_of_primary_duct * the_density_of_air_under_standard_conditions * (273 / primary_air_temperature) * pulverized_coal_concentration;
}

void MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem::airVolume(double* air_volume, const double& wind_speed, const double& cross_sectional_area_of_primary_duct)
{
	// Q = 3600ωs
	*air_volume = 3600 * wind_speed * cross_sectional_area_of_primary_duct;
}