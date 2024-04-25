#include "mythread.h"
MyThread::MyThread(QObject *parent)
	: QThread(parent)
	, _flag(false)
{
	connect(this, &MyThread::saveCoefficientSignals, [=](
		std::string a1, std::string a2, std::string a3, std::string a4
		, std::string b1, std::string b2, std::string b3, std::string b4
		, std::string c1, std::string c2, std::string c3, std::string c4
		, std::string d1, std::string d2, std::string d3, std::string d4
		, std::string e1, std::string e2, std::string e3, std::string e4
		, std::string f1, std::string f2, std::string f3, std::string f4
		, std::string a,  std::string b,  std::string c,  std::string d, std::string e, std::string f, std::string all
		) 
		{
		    // 添加系数
			_coefficient_of_backrest_tube.clear();
			_coefficient_of_backrest_tube.push_back(std::stod(a1));
			_coefficient_of_backrest_tube.push_back(std::stod(a2));
			_coefficient_of_backrest_tube.push_back(std::stod(a3));
			_coefficient_of_backrest_tube.push_back(std::stod(a4));
			_coefficient_of_backrest_tube.push_back(std::stod(b1));
			_coefficient_of_backrest_tube.push_back(std::stod(b2));
			_coefficient_of_backrest_tube.push_back(std::stod(b3));
			_coefficient_of_backrest_tube.push_back(std::stod(b4));
			_coefficient_of_backrest_tube.push_back(std::stod(c1));
			_coefficient_of_backrest_tube.push_back(std::stod(c2));
			_coefficient_of_backrest_tube.push_back(std::stod(c3));
			_coefficient_of_backrest_tube.push_back(std::stod(c4));
			_coefficient_of_backrest_tube.push_back(std::stod(d1));
			_coefficient_of_backrest_tube.push_back(std::stod(d2));
			_coefficient_of_backrest_tube.push_back(std::stod(d3));
			_coefficient_of_backrest_tube.push_back(std::stod(d4));
			_coefficient_of_backrest_tube.push_back(std::stod(e1));
			_coefficient_of_backrest_tube.push_back(std::stod(e2));
			_coefficient_of_backrest_tube.push_back(std::stod(e3));
			_coefficient_of_backrest_tube.push_back(std::stod(e4));
			_coefficient_of_backrest_tube.push_back(std::stod(f1));
			_coefficient_of_backrest_tube.push_back(std::stod(f2));
			_coefficient_of_backrest_tube.push_back(std::stod(f3));
			_coefficient_of_backrest_tube.push_back(std::stod(f4));
			

			// 添加面积
			_area.clear();
			_area.push_back(std::stod(a));
			_area.push_back(std::stod(b));
			_area.push_back(std::stod(c));
			_area.push_back(std::stod(d));
			_area.push_back(std::stod(e));
			_area.push_back(std::stod(f));
			_area.push_back(std::stod(all));

		});
}
void MyThread::stopProcessing()
{
	_flag = true;
}
MyThread::~MyThread()
{

}

void MyThread::run()
{

	bool headerData = true;
	std::string path = "./test.csv";
	std::ifstream ifs;
	ifs.open(path.c_str(), std::ifstream::in);
	std::string line;  // 将每一行的数据存到line中
	while (!_flag)
	{
		if (_area.empty() || _coefficient_of_backrest_tube.empty())
		{
			std::cout << "area and coefficient_of_backrest_tube is empty" << std::endl;
			sleep(1);
			continue;
		}
		int j = 0;
		while (std::getline(ifs, line))
		{
			if (headerData)
			{
				// 如果是表头数据,我们就不读
				headerData = false;
				continue;
			}
			Task task;
			parse(&task, line);         // 解析字符串,得到数据
			task.run();                 // 数据处理
			emit produceDataSignals(task);  // 发送处理结果
			std::cout << "send " << ++j << std::endl;
			sleep(10000);
		}

	}

	ifs.close();
	// 子进程退出
	QThread::quit();
}

void MyThread::parse(Task *task, const std::string &line)
{
	std::vector<std::string> v;
	slicedString(&v, line); // 将数据放到我们的数组中

	for (int i = 0; i < 24; i++)
	{
		int j = 4 * i + 2;
		Data data;
		// 这里将 系数和面积都放进去
		data.set(v[1], std::stod(v[j]), std::stod(v[j+1]), std::stod(v[j+2]), std::stod(v[j+3]), _area[i / 4], _coefficient_of_backrest_tube[i]);
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