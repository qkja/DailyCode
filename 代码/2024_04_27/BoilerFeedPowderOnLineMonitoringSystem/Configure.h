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
	void init();                   // ��ʼ��
	void alterAlarmLimitValue(const std::vector<std::string>&);   // �޸ı�����ֵ
	void alterSpout(const std::vector<std::string>&); // �޸�������
	void alterBackrest(const std::vector<std::string>&); // �޸�ϵ��
	void alterPassword(const std::string&); //�޸�����
	std::vector<std::string> getAllCoefficient();
private:
	void setPassword();           // ��������
	void setAlarmLimitValue();    // ����ȷ���Ľ���ֵ
	void setAlarmLimitRange();    // ���ñ����޵ķ�Χ
	void saveConfigurationFile(); // �����ļ�
	void setBackrest();           // ���ÿ�����ϵ��
	void setSpout();              // �趨������

signals:
	void setBackrestCanalSignals(const std::vector<std::string>&);
	void setSpoutSignals(const std::vector<std::string>&);
	void setPasswordSignals(const std::string&);
	void setAlarmLimitRangeSignals(const std::vector<std::string>&);
	void setAlarmLimitValueSignals(const std::vector<std::string>&);
private:
	std::string _configuration_file_path; // �����ļ�·��
	std::unordered_map<std::string, std::string> _info_map;
};
