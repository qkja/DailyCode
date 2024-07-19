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
	Configure(const std::string& path = "./configure.old.txt",QWidget* parent = nullptr);
	~Configure();
	void myEmit(int);              // 触发信号, 其他人可以通过选择,让我们的选择什么触发什么信号
signals:
	// 设置报警限的范围
	void setAlarmLimitValueSignals(const std::vector<std::string>&); 
private:
	void saveConfigurationFile();  // 保存文件
	void openFile();               // 打开并解析文件
private:
	std::string _configuration_file_path; // 配置文件路径
	std::unordered_map<std::string, std::string> _info_map;
};
