#pragma once

#include <QThread>
#include <iostream>
#include "Task.h"
#include <iostream>
#include <fstream>
class MyThread : public QThread
{
	Q_OBJECT

public:
	MyThread(QObject* parent = nullptr);
	~MyThread();
	void init();
	void run() override;
	void quitThread();
signals:
	void saveCoefficientSignals(const std::vector<std::string>);   // 得到系数
	void produceDataSignals(Task);
private:
	void parse(Task*, const std::string&);
	void slicedString(std::vector<std::string>*, const std::string&);// 切分字符串
private:
	volatile bool _quit_flag;
	std::vector<double> _area;                          // 保存面积
	std::vector<double> _coefficient_of_backrest_tube;  // 保存靠背管系数
};
