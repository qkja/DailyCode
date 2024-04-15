#pragma once

#include <QWidget>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
class Configure : public QWidget
{
	Q_OBJECT

public:
	Configure(QWidget *parent = nullptr);
	~Configure();
	void saveConfigurationFile();
	void configureIsReady();
signals:
	void _configureIsReady(std::unordered_map<std::string, std::string>);

private:
	void init();

private:
	std::string _configuration_file_path; // �����ļ�
	std::unordered_map<std::string, std::string> _info_map;
};
