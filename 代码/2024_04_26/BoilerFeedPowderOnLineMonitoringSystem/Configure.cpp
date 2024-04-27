#include "Configure.h"
Configure::Configure(const std::string& path, QWidget* parent)
	: QWidget(parent)
	, _configuration_file_path(path)
{
	std::cout << "Configure()" << std::endl;
	openFile();// 打开文件, 并解析
}



void Configure::myEmit(int choice)
{
	if (choice == 1)
	{
		// 设定报警限范围
		std::vector<std::string> v;
		v.push_back(_info_map["wind_speed_min"]);
		v.push_back(_info_map["wind_speed_max"]);
		v.push_back(_info_map["pulverized_coal_concentration_min"]);
		v.push_back(_info_map["pulverized_coal_concentration_max"]);
		v.push_back(_info_map["temperature_limit_min"]);
		v.push_back(_info_map["temperature_limit_max"]);
		emit setAlarmLimitValueSignals(v);
		
	}
}



void Configure::openFile()
{
	std::ifstream ifs;
	ifs.open(_configuration_file_path.c_str(), std::ifstream::in);
	if (ifs.is_open() == false)
	{
		std::cout << "打开文件失败: " << _configuration_file_path << std::endl;
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
		std::cout << _configuration_file_path.c_str() << std::endl;
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

Configure::~Configure()
{
	std::cout << "~Configure()" << std::endl;
}