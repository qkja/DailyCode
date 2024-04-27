#pragma once

#include <QWidget>
#include <iostream>
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
	void init();                   // 初始化
	void alterAlarmLimitValue(const std::vector<std::string>&);   // 修改报警限值
	void alterSpout(const std::vector<std::string>&); // 修改喷口面积
	void alterBackrest(const std::vector<std::string>&); // 修改系数
	void alterPassword(const std::string&); //修改密码
	std::vector<std::string> getAllCoefficient();
private:
	void setPassword();           // 设置密码
	void setAlarmLimitValue();    // 给定确定的界限值
	void setAlarmLimitRange();    // 设置报警限的范围
	void saveConfigurationFile(); // 保存文件
	void setBackrest();           // 设置靠背管系数
	void setSpout();              // 设定喷口面积

signals:
	void setBackrestCanalSignals(const std::vector<std::string>&);
	void setSpoutSignals(const std::vector<std::string>&);
	void setPasswordSignals(const std::string&);
	void setAlarmLimitRangeSignals(const std::vector<std::string>&);
	void setAlarmLimitValueSignals(const std::vector<std::string>&);
private:
	std::string _configuration_file_path; // 配置文件路径
	std::unordered_map<std::string, std::string> _info_map;
};
