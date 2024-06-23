#include "configure.h"

Configure::Configure(QWidget* parent)
	: QWidget(parent)
{
	init();
}

Configure::~Configure()
{
}

void Configure::myEmit(int choice)
{
	if (choice == 1)
	{
		// 设定报警限范围
		emit setAlarmLimitRangeSignals(_info_map["wind_speed_min"], _info_map["wind_speed_max"],
			_info_map["pulverized_coal_concentration_min"], _info_map["pulverized_coal_concentration_max"],
			_info_map["temperature_limit_min"], _info_map["temperature_limit_max"]);
	}
	else if (choice == 2)
	{
		// 给定当前的设置值
		emit setAlarmLimitValueSignals(_info_map["lower_wind_speed_limit"], _info_map["upper_wind_speed_limit"],
			_info_map["lower_limit_of_pulverized_coal_concentration"], _info_map["upper_limit_of_pulverized_coal_concentration"],
			_info_map["lower_temperature_limit"], _info_map["upper_temperature_limit"]);
	}
	else if (choice == 3)
	{
		emit setPasswordSignals(_info_map["password"]);
	}
	else if (choice == 4)
	{
		emit setBackrestCanalSignals(_info_map["A1"], _info_map["A2"], _info_map["A3"], _info_map["A4"]
			, _info_map["B1"], _info_map["B2"], _info_map["B3"], _info_map["B4"]
			, _info_map["C1"], _info_map["C2"], _info_map["C3"], _info_map["C4"]
			, _info_map["D1"], _info_map["D2"], _info_map["D3"], _info_map["D4"]
			, _info_map["E1"], _info_map["E2"], _info_map["E3"], _info_map["E4"]
			, _info_map["F1"], _info_map["F2"], _info_map["F3"], _info_map["F4"]);
	}
	else if (choice == 5)
	{
		emit setSpoutSignals(_info_map["area_of_spout_in_layer_A"], _info_map["area_of_spout_in_layer_B"], _info_map["area_of_spout_in_layer_C"], _info_map["area_of_spout_in_layer_D"], _info_map["area_of_spout_in_layer_E"], _info_map["area_of_spout_in_layer_F"], _info_map["pipe_nozzle_area"]);
	}
}

void Configure::myConnect()
{
}

void Configure::init()
{
	_configuration_file_path = "./configure.old.txt";
	std::ifstream ifs;
	ifs.open(_configuration_file_path.c_str(), std::ifstream::in);
	if (ifs.is_open() == false)
	{
		std::cout << "�ļ��򲻿�" << std::endl;
		std::cout << _configuration_file_path.c_str() << std::endl;
		std::cout << strerror(errno) << std::endl;
		return;
	}

	std::string str;
	while (std::getline(ifs, str))
	{
		_info_map[str.substr(0, str.find(':'))] = str.substr(str.find(':') + strlen(":"));
	}
	ifs.close();
}

void Configure::saveConfigurationFile()
{
	std::vector<std::string> v;
	std::ifstream ifs;
	ifs.open(_configuration_file_path.c_str(), std::ifstream::in);
	if (ifs.is_open() == false)
	{
		std::cout << "文件打不开" << std::endl;
		std::cout << _configuration_file_path.c_str() << std::endl;
		std::cout << strerror(errno) << std::endl;
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