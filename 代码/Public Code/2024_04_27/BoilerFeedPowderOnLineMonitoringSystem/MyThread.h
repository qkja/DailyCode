#pragma once
/*
* 这是一个线程类,这个线程主要就是将我们的数据进行计算
* 把计算的结果通过槽函数返回到主线程中
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
	void quitThread(); // 退出该线程
signals:
	void saveCoefficientSignals(const std::vector<std::string>);         // 得到系数
	void produceAllDataSignals(std::vector<struct Result>);              // 传递所有的数据
	void produceAlarmDataSignals(std::vector<struct AlertData>);         // 传递报警数据
	void produceChannelDataSignals(std::vector<struct ChannelData>);     // 传递报警数据
private:
	void cleanseData(const std::vector<struct Result>&); // 把我们的处理后的结果进行检测是否是报警数据
	void parse(Task*, const std::string&);
	void slicedString(std::vector<std::string>*, const std::string&);// 切分字符串
private:
	volatile bool _quit_flag;
	std::vector<double> _area;                          // 保存面积
	std::vector<double> _coefficient_of_backrest_tube;  // 保存靠背管系数
	std::unordered_map<std::string, std::unordered_map<std::string, std::pair<std::string, double>>> _hash_alarm;  // 惊醒报警数据的清洗工作
	std::unordered_map<std::string, std::unordered_map<std::string, std::pair<std::string, double>>> _hash_channe; // 惊醒通道数的清洗工作
};
