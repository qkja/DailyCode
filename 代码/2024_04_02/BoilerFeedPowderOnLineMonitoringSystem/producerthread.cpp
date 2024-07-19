#include "producerthread.h"
#include <fstream>
#include <string>
ProducerThread::ProducerThread()
{
}

ProducerThread::~ProducerThread()
{}

void ProducerThread::run()
{
	while (true)
	{
		std::string path = "./data.txt";
		std::ifstream ifs;
		ifs.open(path.c_str(), std::ifstream::in);

		std::string line;
		while (std::getline(ifs, line))
		{
			Task task;
			parse(&task, line);
			task.run();
			emit produceSignals(task);
			std::cout << "我 [ " << std::this_thread::get_id() << " ] 生产了一个任务 " << std::endl;
			sleep(2);
		}
		ifs.close();
	}
}

void ProducerThread::parse(Task* task, const std::string& line)
{
	std::vector<std::string> v;
	int begin = 0;
	while (true)
	{
		int pos = line.find(' ', begin);
		if (pos == std::string::npos)
		{
			v.push_back(line.substr(begin));
			break;
		}
		v.push_back(line.substr(begin, pos - begin));
		begin = pos + 1;
	}
	std::cout << v.size() << std::endl;

	Data n1(v[0], std::stod(v[1]), std::stod(v[2]), std::stod(v[3]),
		std::stod(v[10]), std::stod(v[11]),
		std::stod(v[16]));
	Data n2(v[0], std::stod(v[4]), std::stod(v[5]), std::stod(v[6]),
		std::stod(v[12]), std::stod(v[13]),
		std::stod(v[17]));
	Data n3(v[0], std::stod(v[7]), std::stod(v[8]), std::stod(v[9]),
		std::stod(v[14]), std::stod(v[15]),
		std::stod(v[18]));

	task->set(n1, n2, n3);
}
