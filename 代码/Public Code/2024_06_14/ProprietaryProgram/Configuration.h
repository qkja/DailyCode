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

	 std::string serialization(const AttributeData&); // ���л�
	 AttributeData deserialization(const std::string&); // �����л�
private:
	std::string _path; // �����ļ�·��
	std::unordered_map<std::string, AttributeData> _all_datas; // ���е�����
};

