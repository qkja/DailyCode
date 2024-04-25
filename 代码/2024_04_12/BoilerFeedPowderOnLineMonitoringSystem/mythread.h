#pragma once

#include <QThread>
#include "Task.hpp"
#include <iostream>
#include <fstream>
#include "configure.h"

class MyThread : public QThread
{
	Q_OBJECT
	friend class BoilerFeedPowderOnLineMonitoringSystem;
public:
	MyThread(QObject *parent = nullptr);
	~MyThread();
	void run() override;
signals:

	void saveCoefficientSignals(std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
		, std::string, std::string, std::string, std::string
	    , std::string, std::string, std::string, std::string, std::string, std::string, std::string);   // �õ�ϵ��
	void produceDataSignals(Task);
protected slots:
	void stopProcessing();
private:
	void parse(Task *, const std::string &);
	void slicedString(std::vector<std::string>*, const std::string&);// �з��ַ���
private:
    volatile bool _flag;
	std::vector<double> _area;   // �������
	std::vector<double> _coefficient_of_backrest_tube;  // ���濿����ϵ��
};
