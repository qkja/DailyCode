#include "configure.h"

Configure::Configure(QWidget *parent)
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