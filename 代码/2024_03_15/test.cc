#include "BlockqQueue.hpp"
#include <iostream>
#include <Windows.h>
#include "BlockqQueue.hpp"
#include <time.h>
#include <string>
#include "Task.hpp"
#include <fstream>
std::string str = "+-*/%";
using namespace std;
void* consumer(void* args)
{
	BlockqQueue<Task>* p = (BlockqQueue<Task> *)args;

	while (true)
	{

		Task t = p->pop();
		int one = 0;
		int two = 0;
		char op = 0;
		t.get(&one, &two, &op);
		int result = t();
		std::cout << "我 [ " << std::this_thread::get_id() << " ] 消费了一个任务 "
			<< one << " " << op << " " << two << "=" << result
			<< std::endl;
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
			std::cout << line << std::endl;
		}
		while (true)
		{

		}
		int one = rand() % 10;
		int two = rand() % 10;
		char op = str[rand() % str.size()];
		Task t(one, two, op);
		p->push(t);
		std::cout << "我 [ " << std::this_thread::get_id() << " ] 生产了一个任务 "
			<< one << " " << op << " " << two << "=?" << std::endl;
		Sleep(1000);
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