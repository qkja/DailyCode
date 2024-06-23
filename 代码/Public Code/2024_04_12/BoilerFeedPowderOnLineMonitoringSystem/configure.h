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
	Configure(QWidget* parent = nullptr);
	~Configure();
	void myEmit(int);              // 触发信号
	void myConnect();              // 链接信号和槽
signals:

	void setAlarmLimitValueSignals(std::string, std::string, std::string, std::string, std::string, std::string);  // 设置报警限的范围
	void setAlarmLimitRangeSignals(std::string, std::string, std::string, std::string, std::string, std::string);  // 设定报警限的确定值
	void setPasswordSignals(std::string);  // 设置密码
	void setBackrestCanalSignals(std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string);  // 设置靠背管系数
	void setSpoutSignals(std::string, std::string, std::string, std::string, std::string, std::string, std::string); //设定喷口面积
private:
	void saveConfigurationFile();  // 保存文件
	void init();                   // 初始化

private:
	std::string _configuration_file_path; // 配置文件路径
	std::unordered_map<std::string, std::string> _info_map;
};
