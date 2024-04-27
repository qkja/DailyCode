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
	std::string line;  // ��ÿһ�е����ݴ浽line��
	while (!_quit_flag)
	{
		if (_area.empty() || _coefficient_of_backrest_tube.empty())
		{
			std::cout << "area and coefficient_of_backrest_tube is empty" << std::endl;
			sleep(1);
			continue;
		}
		// ������ģ���������ݴ���Ľ��,Ȼ���͹�ȥ��
		int j = 0;

		while (!_quit_flag)
		{
			Task task;
			for (int i = 0; i < 24; i++)
			{
				std::string time = "1714029266";                             // ʱ���
				double differentialPressure = qrand() % 100;                           // һ�η綯ѹ���
				double primaryAirTemperatureMeasuringPoint = qrand() % 100;            // һ�η��²��
				double pulverizedCoalTemperatureMeasuringPoint = qrand() % 100;        // ú���¶Ȳ��
				double mixedTemperatureMeasuringPoint = qrand() % 100;                 // ����¶Ȳ��
				double area = 1.4;                                           // ���
				double coefficient = 1.9;                                    // ���ٹܷ綴�궨ϵ��
				Data data;
				data.set(time, differentialPressure, primaryAirTemperatureMeasuringPoint, pulverizedCoalTemperatureMeasuringPoint, mixedTemperatureMeasuringPoint, area, coefficient);
				task.push_back(data);
			}
			task.run();                     // ���ݴ���
			emit produceDataSignals(task);  // ���ʹ�����
			std::cout << "send " << ++j << std::endl;
			sleep(2);                       // ��Ϣ2s
		}
	}

	ifs.close();
	// �ӽ����˳�
	QThread::quit();
}

void MyThread::quitThread()
{
	_quit_flag = true;
}

void MyThread::parse(Task* task, const std::string& line)
{
	std::vector<std::string> v;
	slicedString(&v, line); // �����ݷŵ����ǵ�������

	for (int i = 0; i < 24; i++)
	{
		int j = 4 * i + 2;
		Data data;
		// ���ｫ ϵ����������Ž�ȥ
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