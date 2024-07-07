#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "BlockqQueue.hpp"
#include "Task.hpp"
#include <fstream>
using namespace std;

void parse(Task* task, const std::string& line)
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


void* consumer(void* args)
{
	BlockqQueue<Task>* p = (BlockqQueue<Task> *)args;

	while (true)
	{
		Task t = p->pop();
		t.run();
		t.show();
		std::cout << "我 [ " << std::this_thread::get_id() << " ] 消费了一个任务" << std::endl;
	}
}

void* producer(void* args)
{
	BlockqQueue<Task>* p = (BlockqQueue<Task> *)args;

	while (true)
	{
		std::string path = "./data.txt";
		std::ifstream ifs;
		ifs.open(path.c_str(), std::ifstream::in);

		string line;
		while (std::getline(ifs, line))
		{
			//std::cout << line << std::endl;
			Task task;
			parse(&task, line);
			p->push(task);
			std::cout << "我 [ " << std::this_thread::get_id() << " ] 生产了一个任务 " << std::endl;
			Sleep(1000);
		}
		ifs.close();
	}
}

int main()
{

	srand((unsigned long)time(nullptr));
	BlockqQueue<Task> bq;
	std::thread c(consumer, &bq);
	std::thread p(producer, &bq);

	c.join();
	p.join();

	return 0;
}