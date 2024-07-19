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
	void myEmit(int);              // �����ź�, �����˿���ͨ��ѡ��,�����ǵ�ѡ��ʲô����ʲô�ź�
signals:
	// ���ñ����޵ķ�Χ
	void setAlarmLimitValueSignals(const std::vector<std::string>&); 
private:
	void saveConfigurationFile();  // �����ļ�
	void openFile();               // �򿪲������ļ�
private:
	std::string _configuration_file_path; // �����ļ�·��
	std::unordered_map<std::string, std::string> _info_map;
};
