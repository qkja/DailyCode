#pragma once

#include <QThread>
#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>
class ConfigureThread  : public QThread
{
	Q_OBJECT

public:
	ConfigureThread();
	~ConfigureThread();
	void run() override;
signals:
	void configureIsReady(std::unordered_map<std::string, std::string>);
private:
	void init();
	void saveConfigurationFile();
private:
	std::string _configuration_file_path;    // ÅäÖÃÎÄ¼ş
	std::unordered_map<std::string, std::string> _info_map;
};
