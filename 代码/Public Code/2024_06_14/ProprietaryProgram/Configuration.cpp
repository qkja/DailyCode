#include "Configuration.h"
Configuration::Configuration(const std::string& path)
	:_path(path)
{
	std::cout << "Configuration()" << std::endl;
}
Configuration::~Configuration()
{
	std::cout << "~Configuration()" << std::endl;

	_write();// 自动读写
}

bool Configuration::read()
{
	std::ifstream ifs(_path, std::ios_base::in | std::ios_base::binary);
	if (!ifs.is_open())
		return false;

	std::string line;
	while (std::getline(ifs, line))
	{
		AttributeData data = deserialization(line);
		_all_datas[data._name] = data;
	}
	return true;
}

bool Configuration::write(const AttributeData& data)
{
	_all_datas[data._name] = data;
	return true;
}

void Configuration::_write()
{
	// 二进制方式写
	std::ofstream ofs(_path, std::ios_base::out | std::ios_base::binary);

	auto iter = _all_datas.begin();
	while (iter != _all_datas.end())
	{
		std::string line = serialization(iter->second);
		ofs.write(line.c_str(), line.size());
		++iter;
	}
}
 std::string Configuration::serialization(const AttributeData& data)
{
	std::ostringstream oss;
	oss << data._name << data._gender << data._age << data._height << data._weight;
	return oss.str();
}

 AttributeData Configuration::deserialization(const std::string& line)
{
	std::istringstream iss(line);
	AttributeData data;
	iss >> data._name >> data._gender >> data._age >> data._height >> data._weight;
	return data;
}
