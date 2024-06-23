#pragma once
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
class Util
{
public:
	Util();
	~Util();
	static void processingConfigurationFiles(std::unordered_map<std::string, std::string>* info_map,
		const std::string& configuration_file)
	{
		std::ifstream ifs;
		ifs.open(configuration_file.c_str(), std::ifstream::in);
		if (ifs.is_open() == false)
		{
			std::cout << configuration_file << " :文件打不开" << std::endl;
			std::cout << strerror(errno) << std::endl;
			return;
		}

		std::string str;
		while (std::getline(ifs, str))
		{
			(*info_map)[str.substr(0, str.find(':'))] = str.substr(str.find(':') + strlen(":"));
		}
		ifs.close();
	}

	static void saveConfigurationFile(std::unordered_map<std::string, std::string> info_map,
		const std::string& configuration_file)
	{
		std::vector<std::string> v;
		std::ifstream ifs;
		ifs.open(configuration_file.c_str(), std::ifstream::in);
		if (ifs.is_open() == false)
		{
			std::cout << configuration_file << " :文件打不开" << std::endl;
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
		std::ofstream ofs(configuration_file.c_str());
		for (size_t i = 0; i < v.size(); ++i)
		{
			ofs << v[i] << ":" << info_map[v[i]] << std::endl;
		}
		ofs.close();
	}
private:

};
