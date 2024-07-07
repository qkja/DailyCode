#pragma once
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include "AttributeData.h"
#include <sstream>
class Configuration
{
	friend class ProprietaryProgram;
public:
	Configuration(const std::string& path = "./configuration.bin");
	~Configuration();
public:
	bool read();
	bool write(const AttributeData&);
private:
	void _write();

	 std::string serialization(const AttributeData&); // 序列化
	 AttributeData deserialization(const std::string&); // 反序列化
private:
	std::string _path; // 配置文件路径
	std::unordered_map<std::string, AttributeData> _all_datas; // 所有的数据
};

