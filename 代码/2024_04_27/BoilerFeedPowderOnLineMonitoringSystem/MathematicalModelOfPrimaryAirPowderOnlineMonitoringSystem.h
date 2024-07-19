#pragma once
#include <iostream>
#include <cmath>
class MathematicalModelOfPrimaryAirPowderOnlineMonitoringSystem
{
public:
	enum UNITOPTION
	{
		FORCEOFPRESSURE,	  // ��˹��
		COLUMNOFMERCURY,	  // ���׹���
		TEMPERATUREINCELSIUS, // ���϶��±�
		TEMPERATUREINKELVIN	  // �������¶�
	};

private:
	/*
	 * ����������Ⱥ�ú�۱���
	 * specific_heat_of_air:��������
	 * specific_heat_of_pulverized_coal:ú�۱���
	 * temperature:�¶�
	 */
	static void specificHeat(double* specific_heat_of_air,
		double* specific_heat_of_pulverized_coal,
		double temperature,
		bool unit_temperature = UNITOPTION::TEMPERATUREINCELSIUS);
public:
	/*
	 * �������
	 * ���ٹܷ綴�궨ϵ��:   calibration_coefficient_for_tachometer_wind_tunnel
	 * �¶�:               temperature
	 * �����Ĳ�ѹ:          differential_pressure
	 */
	static void WindSpeed(double* wind_speed,
		double temperature,
		const double& differential_pressure,
		const double& calibration_coefficient_for_tachometer_wind_tunnel,
		bool unit_temperature = UNITOPTION::TEMPERATUREINCELSIUS,
		bool unit_option = UNITOPTION::FORCEOFPRESSURE);
	/*
	* ����ú��Ũ��
	* temperature: ������¶�
	* pulverized_coal_concentration:ú��Ũ��
	*/
	static void pulverizedCoalConcentration(double* pulverized_coal_concentration,
		double temperature_1,
		double temperature_2,
		double temperature_3);
	/*
	 * ����ú����������
	 * wind_speed:һ�η���
	 * cross_sectional_area_of_primary_duct:һ�η�ܽ����
	 * the_density_of_air_under_standard_conditions:�����ڱ�׼״���µ��ܶ�
	 * primary_air_temperature:һ�η���
	 * pulverized_coal_concentration:ú��Ũ��
	 * pulverized_coal_mass_flow_rate:ú����������
	 */
	static void pulverizedCoalMassFlowRate(double* pulverized_coal_mass_flow_rate,
		double wind_speed,
		double cross_sectional_area_of_primary_duct,
		double primary_air_temperature,
		double pulverized_coal_concentration,
		double the_density_of_air_under_standard_conditions = 1.29,
		bool unit_temperature = UNITOPTION::TEMPERATUREINCELSIUS);
	/*
	 * �������
	 * wind_speed:һ�Ρ����Ρ����η���
	 * cross_sectional_area_of_primary_duct:һ�Ρ����Ρ����η�ܽ����
	 */
	static void airVolume(double* air_volume,
		const double& wind_speed,
		const double& cross_sectional_area_of_primary_duct);
};
