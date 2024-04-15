#include "configurethread.h"


ConfigureThread::ConfigureThread()
{
    init();
}

ConfigureThread::~ConfigureThread()
{}

void ConfigureThread::run()
{
    // 这里属于派发我们的属性, 直接一个信号就可以可以了
    emit configureIsReady(_info_map);
}

void ConfigureThread::init()
{
    _configuration_file_path = "./configure.txt";
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
        _info_map[str.substr(0, str.find(':'))] = str.substr(str.find(':') + strlen(":"));
    }
    ifs.close();
}

void ConfigureThread::saveConfigurationFile()
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
    // 文本读写
    std::ofstream ofs(_configuration_file_path.c_str());
    for (size_t i = 0; i < v.size(); ++i)
    {
        ofs << v[i] << ":" << _info_map[v[i]] << std::endl;
    }
    ofs.close();
}