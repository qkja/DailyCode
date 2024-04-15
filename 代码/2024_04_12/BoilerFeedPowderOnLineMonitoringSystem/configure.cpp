#include "configure.h"

Configure::Configure(QWidget *parent)
    : QWidget(parent)
{
    init();
}

Configure::~Configure()
{
}

void Configure::configureIsReady()
{
    emit _configureIsReady(_info_map);
}

void Configure::init()
{
    _configuration_file_path = "./configure.txt";
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
        std::cout << "�ļ��򲻿�" << std::endl;
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
    // �ı���д
    std::ofstream ofs(_configuration_file_path.c_str());
    for (size_t i = 0; i < v.size(); ++i)
    {
        ofs << v[i] << ":" << _info_map[v[i]] << std::endl;
    }
    ofs.close();
}