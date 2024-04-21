#pragma once

#include <QWidget>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
class Configure : public QWidget
{
	Q_OBJECT
		friend class BoilerFeedPowderOnLineMonitoringSystem;
public:
	Configure(QWidget *parent = nullptr);
	~Configure();
	void myEmit(int);              // 触发信号
	void myConnect();              // 链接信号和槽
signals:
	void setAlarmLimitValueSignals(std::string, std::string, std::string, std::string, std::string, std::string);
	void setAlarmLimitRangeSignals(std::string, std::string, std::string, std::string, std::string, std::string);
private:
	void saveConfigurationFile();  // 保存文件
	void init();                   // 初始化
	
private:
	std::string _configuration_file_path; // 配置文件路径
	std::unordered_map<std::string, std::string> _info_map;
};
