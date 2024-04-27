#include "MyThread.h"

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

void MyThread::init()
{
	connect(this, &MyThread::saveCoefficientSignals, [=](const std::vector<std::string> data) {
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

void MyThread::run()
{
	bool headerData = true;
	std::string path = "./test.csv";
	std::ifstream ifs;
	ifs.open(path.c_str(), std::ifstream::in);
	std::string line;  // 将每一行的数据存到line中
	while (!_quit_flag)
	{
		if (_area.empty() || _coefficient_of_backrest_tube.empty())
		{
			std::cout << "area and coefficient_of_backrest_tube is empty" << std::endl;
			sleep(1);
			continue;
		}
		// 下面是模拟我们数据处理的结果,然后发送过去的
		int j = 0;

		while (!_quit_flag)
		{
			Task task;
			for (int i = 0; i < 24; i++)
			{
				std::string time = "1714029266";                             // 时间戳
				double differentialPressure = qrand() % 100;                           // 一次风动压测点
				double primaryAirTemperatureMeasuringPoint = qrand() % 100;            // 一次风温测点
				double pulverizedCoalTemperatureMeasuringPoint = qrand() % 100;        // 煤粉温度测点
				double mixedTemperatureMeasuringPoint = qrand() % 100;                 // 混合温度测点
				double area = 1.4;                                           // 面积
				double coefficient = 1.9;                                    // 测速管风洞标定系数
				Data data;
				data.set(time, differentialPressure, primaryAirTemperatureMeasuringPoint, pulverizedCoalTemperatureMeasuringPoint, mixedTemperatureMeasuringPoint, area, coefficient);
				task.push_back(data);
			}
			task.run();                     // 数据处理
			emit produceDataSignals(task);  // 发送处理结果
			std::cout << "send " << ++j << std::endl;
			sleep(2);                       // 休息2s
		}
	}

	ifs.close();
	// 子进程退出
	QThread::quit();
}

void MyThread::quitThread()
{
	_quit_flag = true;
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