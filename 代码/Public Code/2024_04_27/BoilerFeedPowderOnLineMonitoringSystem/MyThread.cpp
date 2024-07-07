#include "MyThread.h"
#include <ctime>
#include <iostream>
MyThread::MyThread(QObject* parent)
	: QThread(parent)
	, _quit_flag(false)
{
	std::cout << "MyThread()" << std::endl;
	init();
}

MyThread::~MyThread()
{
	std::cout << "~MyThread()" << std::endl;
}
// 初始化子线程

void MyThread::init()
{
	connect(this, &MyThread::saveCoefficientSignals, [=](const std::vector<std::string> data) {
		// 通过信号与槽传递我们设置的参数
		_coefficient_of_backrest_tube.clear();
		_area.clear();
		int i = 0;
		for (int i = 0; i < 24; i++)
		{
			_coefficient_of_backrest_tube.push_back(std::stod(data[i]));
		}
		for (; i < data.size(); i++)
		{
			_area.push_back(std::stod(data[i]));
		}
		});
}
// 线程一经启动,直接运行该函数
void MyThread::run()
{
	bool headerData = true;
	std::string path = "./test.csv"; // 数据读取的位置
	std::ifstream ifs;
	ifs.open(path.c_str(), std::ifstream::in);
	std::string line;  // 将每一行的数据存到line中
	std::getline(ifs, line); // 清除掉第一行

	while (!_quit_flag)
	{
		// 确定我们的参数已经可以拿去了
		if (_area.empty() || _coefficient_of_backrest_tube.empty())
		{
			std::cout << "area and coefficient_of_backrest_tube is empty" << std::endl;
			sleep(1);
			continue;
		}
		// 下面是模拟我们数据处理的结果,然后发送过去的
		int j = 0;
		int begin = time(NULL);

		while (!_quit_flag)
		{
			/*std::getline(ifs, line);*/
			Task task;

			/*	parse(&task, line);*/
			// 这是一个测试
			for (int i = 0; i < 24; i++)
			{
				std::string time = "1714029266";                             // 时间戳
				double differentialPressure = qrand() % 100;                           // 一次风动压测点
				double primaryAirTemperatureMeasuringPoint = qrand() % 100;            // 一次风温测点
				double pulverizedCoalTemperatureMeasuringPoint = qrand() % 100;        // 煤粉温度测点
				double mixedTemperatureMeasuringPoint = qrand() % 100;                 // 混合温度测点
				double area = 1.4;                                           // 面积
				double coefficient = 1.9;                                    // 测速管风洞标定系数
				Data data;  //Data 是一个检测点的所有的数据,我们需要使用24个检测点
				data.set(time, differentialPressure, primaryAirTemperatureMeasuringPoint, pulverizedCoalTemperatureMeasuringPoint, mixedTemperatureMeasuringPoint, area, coefficient);
				task.push_back(data);
			}

			task.run();                     // 这里一个task就是我们24个监测点所有的数据,run函数是数据处理
			cleanseData(task._primary_result);                  // 清洗报警数据
			emit produceAllDataSignals(task._primary_result);   // 发送处理结果
			std::cout << "send " << ++j << std::endl;
			if (j % 1000 == 0)
			{
				int end = time(NULL);
				std::cout << "=======================" << std::endl;
				std::cout << end - begin << std::endl;
				begin = time(NULL);
				std::cout << "=======================" << std::endl;
			}
			sleep(2);                       // 休息2s
		}
	}

	ifs.close();
	// 子进程退出
	QThread::quit();
}
// 退出线程,这个函数函数可以给主线程使用
void MyThread::quitThread()
{
	_quit_flag = true;
}

/*
* 如何清洗我们的,
*/
void MyThread::cleanseData(const std::vector<struct Result>& allData)
{
	// 数据 A1-A4 ...F1-F4 共24组数据
	// 报警数据
	std::vector<struct AlertData> alert;

	/*for (int i = 0; i < allData.size(); i++)
	{
		if(i <)
	}*/
	emit produceAlarmDataSignals(alert);      // 传递报警数据

	// 通道数据
	std::vector<struct ChannelData> channel;
	produceChannelDataSignals(channel);
}

void MyThread::parse(Task* task, const std::string& line)
{
	std::vector<std::string> v;
	slicedString(&v, line); // 将数据放到我们的数组中

	for (int i = 0; i < 24; i++)
	{
		int j = 4 * i + 2;
		Data data;
		// 这里将 系数和面积都放进去
		data.set(v[1], std::stod(v[j]), std::stod(v[j + 1]), std::stod(v[j + 2]), std::stod(v[j + 3]), _area[i / 4], _coefficient_of_backrest_tube[i]);
		task->push_back(data);
	}
}
// 切分字符串
void MyThread::slicedString(std::vector<std::string>* v, const std::string& str)
{
	int begin = 0;
	while (true)
	{
		int pos = str.find(',', begin);
		if (std::string::npos == pos)
		{
			v->push_back(str.substr(begin));
			break;
		}
		v->push_back(str.substr(begin, pos - begin));
		begin = pos + 1;
	}
}