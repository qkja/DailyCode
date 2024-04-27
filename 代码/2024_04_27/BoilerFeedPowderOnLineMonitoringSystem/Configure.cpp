#include "Configure.h"

Configure::Configure(QWidget* parent)
	: QWidget(parent)
{
	std::cout << "Configure()" << std::endl;
	init();
}

Configure::~Configure()
{
	saveConfigurationFile();
	std::cout << "~Configure()" << std::endl;
}

void Configure::setPassword()
{
	emit setPasswordSignals(_info_map["password"]);
}

void Configure::setAlarmLimitValue()
{
	std::vector<std::string> v;
	v.push_back(_info_map["lower_wind_speed_limit"]);
	v.push_back(_info_map["upper_wind_speed_limit"]);
	v.push_back(_info_map["lower_limit_of_pulverized_coal_concentration"]);
	v.push_back(_info_map["upper_limit_of_pulverized_coal_concentration"]);
	v.push_back(_info_map["lower_temperature_limit"]);
	v.push_back(_info_map["upper_temperature_limit"]);

	// 给定当前的设置值
	emit setAlarmLimitValueSignals(v);
}

void Configure::setAlarmLimitRange()
{
	std::vector<std::string> v;
	v.push_back(_info_map["wind_speed_min"]);
	v.push_back(_info_map["wind_speed_max"]);
	v.push_back(_info_map["pulverized_coal_concentration_min"]);
	v.push_back(_info_map["pulverized_coal_concentration_max"]);
	v.push_back(_info_map["temperature_limit_min"]);
	v.push_back(_info_map["temperature_limit_max"]);
	emit setAlarmLimitRangeSignals(v);
}

void Configure::setBackrest()
{
	std::vector<std::string> v;
	v.push_back(_info_map["A1"]);
	v.push_back(_info_map["A2"]);
	v.push_back(_info_map["A3"]);
	v.push_back(_info_map["A4"]);
	v.push_back(_info_map["B1"]);
	v.push_back(_info_map["B2"]);
	v.push_back(_info_map["B3"]);
	v.push_back(_info_map["B4"]);
	v.push_back(_info_map["C1"]);
	v.push_back(_info_map["C2"]);
	v.push_back(_info_map["C3"]);
	v.push_back(_info_map["C4"]);
	v.push_back(_info_map["D1"]);
	v.push_back(_info_map["D2"]);
	v.push_back(_info_map["D3"]);
	v.push_back(_info_map["D4"]);
	v.push_back(_info_map["E1"]);
	v.push_back(_info_map["E2"]);
	v.push_back(_info_map["E3"]);
	v.push_back(_info_map["E4"]);
	v.push_back(_info_map["F1"]);
	v.push_back(_info_map["F2"]);
	v.push_back(_info_map["F3"]);
	v.push_back(_info_map["F4"]);
	emit setBackrestCanalSignals(v);
}

void Configure::setSpout()
{
	std::vector<std::string> v;
	v.push_back(_info_map["area_of_spout_in_layer_A"]);
	v.push_back(_info_map["area_of_spout_in_layer_B"]);
	v.push_back(_info_map["area_of_spout_in_layer_C"]);
	v.push_back(_info_map["area_of_spout_in_layer_D"]);
	v.push_back(_info_map["area_of_spout_in_layer_E"]);
	v.push_back(_info_map["area_of_spout_in_layer_F"]);
	v.push_back(_info_map["pipe_nozzle_area"]);
	emit setSpoutSignals(v);
}

void Configure::saveConfigurationFile()
{
	std::vector<std::string> v;
	std::ifstream ifs;
	ifs.open(_configuration_file_path.c_str(), std::ifstream::in);
	if (ifs.is_open() == false)
	{
		std::cout << "open " << _configuration_file_path << " fail" << std::endl;
		return;
	}
	std::string str;
	while (std::getline(ifs, str))
	{
		v.push_back(str.substr(0, str.find(':')));
	}
	ifs.close();
	std::ofstream ofs(_configuration_file_path.c_str());
	for (size_t i = 0; i < v.size(); ++i)
	{
		ofs << v[i] << ":" << _info_map[v[i]] << std::endl;
	}
	ofs.close();
}

void Configure::init()
{
	_configuration_file_path = "./configure.old.txt";
	std::ifstream ifs;
	ifs.open(_configuration_file_path.c_str(), std::ifstream::in);
	if (ifs.is_open() == false)
	{
		std::cout << "open " << _configuration_file_path << " fail" << std::endl;
		return;
	}

	std::string str;
	while (std::getline(ifs, str))
	{
		_info_map[str.substr(0, str.find(':'))] = str.substr(str.find(':') + strlen(":"));
	}
	ifs.close();
}

void Configure::alterAlarmLimitValue(const std::vector<std::string>& data)
{
	_info_map["lower_wind_speed_limit"] = data[0];
	_info_map["upper_wind_speed_limit"] = data[1];
	_info_map["lower_limit_of_pulverized_coal_concentration"] = data[2];
	_info_map["upper_limit_of_pulverized_coal_concentration"] = data[3];
	_info_map["lower_temperature_limit"] = data[4];
	_info_map["upper_temperature_limit"] = data[5];
}

void Configure::alterSpout(const std::vector<std::string>& data)
{
	_info_map["area_of_spout_in_layer_A"] = data[0];
	_info_map["area_of_spout_in_layer_B"] = data[1];
	_info_map["area_of_spout_in_layer_C"] = data[2];
	_info_map["area_of_spout_in_layer_D"] = data[3];
	_info_map["area_of_spout_in_layer_E"] = data[4];
	_info_map["area_of_spout_in_layer_F"] = data[5];
	_info_map["pipe_nozzle_area"] = data[6];
}

void Configure::alterBackrest(const std::vector<std::string>& data)
{
	_info_map["A1"] = data[0];
	_info_map["A2"] = data[1];
	_info_map["A3"] = data[2];
	_info_map["A4"] = data[3];
	_info_map["B1"] = data[4];
	_info_map["B2"] = data[5];
	_info_map["B3"] = data[6];
	_info_map["B4"] = data[7];
	_info_map["C1"] = data[8];
	_info_map["C2"] = data[9];
	_info_map["C3"] = data[10];
	_info_map["C4"] = data[11];
	_info_map["D1"] = data[12];
	_info_map["D2"] = data[13];
	_info_map["D3"] = data[14];
	_info_map["D4"] = data[15];
	_info_map["E1"] = data[16];
	_info_map["E2"] = data[17];
	_info_map["E3"] = data[18];
	_info_map["E4"] = data[19];
	_info_map["F1"] = data[20];
	_info_map["F2"] = data[21];
	_info_map["F3"] = data[22];
	_info_map["F4"] = data[23];
}

void Configure::alterPassword(const std::string& password)
{
	_info_map["password"] = password;
}

std::vector<std::string> Configure::getAllCoefficient()
{
	std::vector<std::string> v;
	v.push_back(_info_map["A1"]);
	v.push_back(_info_map["A2"]);
	v.push_back(_info_map["A3"]);
	v.push_back(_info_map["A4"]);
	v.push_back(_info_map["B1"]);
	v.push_back(_info_map["B2"]);
	v.push_back(_info_map["B3"]);
	v.push_back(_info_map["B4"]);
	v.push_back(_info_map["C1"]);
	v.push_back(_info_map["C2"]);
	v.push_back(_info_map["C3"]);
	v.push_back(_info_map["C4"]);
	v.push_back(_info_map["D1"]);
	v.push_back(_info_map["D2"]);
	v.push_back(_info_map["D3"]);
	v.push_back(_info_map["D4"]);
	v.push_back(_info_map["E1"]);
	v.push_back(_info_map["E2"]);
	v.push_back(_info_map["E3"]);
	v.push_back(_info_map["E4"]);
	v.push_back(_info_map["F1"]);
	v.push_back(_info_map["F2"]);
	v.push_back(_info_map["F3"]);
	v.push_back(_info_map["F4"]);
	v.push_back(_info_map["area_of_spout_in_layer_A"]);
	v.push_back(_info_map["area_of_spout_in_layer_B"]);
	v.push_back(_info_map["area_of_spout_in_layer_C"]);
	v.push_back(_info_map["area_of_spout_in_layer_D"]);
	v.push_back(_info_map["area_of_spout_in_layer_E"]);
	v.push_back(_info_map["area_of_spout_in_layer_F"]);
	v.push_back(_info_map["pipe_nozzle_area"]);
	return v;
}
