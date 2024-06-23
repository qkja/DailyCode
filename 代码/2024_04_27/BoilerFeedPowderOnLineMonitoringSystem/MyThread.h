#pragma once
/*
* ����һ���߳���,����߳���Ҫ���ǽ����ǵ����ݽ��м���
* �Ѽ���Ľ��ͨ���ۺ������ص����߳���
*/
#include <QThread>
#include <iostream>
#include "Task.h"
#include <iostream>
#include <fstream>
#include "AlertData.h"
#include <unordered_map>
#include "ChannelData.h"
#include <unordered_set>

class MyThread : public QThread
{
	Q_OBJECT

public:
	MyThread(QObject* parent = nullptr);
	~MyThread();
	void init();
	void run() override;
	void quitThread(); // �˳����߳�
signals:
	void saveCoefficientSignals(const std::vector<std::string>);         // �õ�ϵ��
	void produceAllDataSignals(std::vector<struct Result>);              // �������е�����
	void produceAlarmDataSignals(std::vector<struct AlertData>);         // ���ݱ�������
	void produceChannelDataSignals(std::vector<struct ChannelData>);     // ���ݱ�������
private:
	void cleanseData(const std::vector<struct Result>&); // �����ǵĴ����Ľ�����м���Ƿ��Ǳ�������
	void parse(Task*, const std::string&);
	void slicedString(std::vector<std::string>*, const std::string&);// �з��ַ���
private:
	volatile bool _quit_flag;
	std::vector<double> _area;                          // �������
	std::vector<double> _coefficient_of_backrest_tube;  // ���濿����ϵ��
	std::unordered_map<std::string, std::unordered_map<std::string, std::pair<std::string, double>>> _hash_alarm;  // ���ѱ������ݵ���ϴ����
	std::unordered_map<std::string, std::unordered_map<std::string, std::pair<std::string, double>>> _hash_channe; // ����ͨ��������ϴ����
};
