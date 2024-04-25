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
	    , std::string, std::string, std::string, std::string, std::string, std::string, std::string);   // 得到系数
	void produceDataSignals(Task);
protected slots:
	void stopProcessing();
private:
	void parse(Task *, const std::string &);
	void slicedString(std::vector<std::string>*, const std::string&);// 切分字符串
private:
    volatile bool _flag;
	std::vector<double> _area;   // 保存面积
	std::vector<double> _coefficient_of_backrest_tube;  // 保存靠背管系数
};
