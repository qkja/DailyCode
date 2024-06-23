#include <iostream>
#include <thread>
#include<windows.h>

#include <condition_variable>
std::condition_variable _con;
std::mutex _mutex;
std::unique_lock<std::mutex> lck(_mutex);
volatile bool quit = false; // 为了线程退出  volatile前面已经谈过了
void waitCommand()
{
	while (!quit)
	{

		_con.wait(lck);
		std::cout << "thread id  " << std::this_thread::get_id()
			<< " running" << std::endl;
	}
	_mutex.unlock();
	std::cout << "thread id  " << std::this_thread::get_id() << "  ending" << std::endl;
}

int main()
{

	// 初始化一个线程
	std::thread t1(waitCommand);
	std::thread t2(waitCommand);
	std::thread t3(waitCommand);

	while (true)
	{
		//  控制
		char n = 0;
		std::cout << "请输入你的commmand: ";
		std::cin >> n; // cin cout 交叉使用缓冲区会被强制刷新
		if (n == 'n')
		{
			// cout << "aaaaaaaaaaaa" << endl;
			// 唤醒一个线程
			_con.notify_one();
		}
		else
		{
			quit = true;
			_con.notify_all();
			break;
		}
		Sleep(1000);
	}

	t1.join();
	t2.join();
	t3.join();
	return 0;
}



//#include <iostream>
//#include <thread>
//#include <condition_variable>
//std::condition_variable _con;
//std::mutex _mutex;
//void* waitCommand()
//{
//	while (true)
//	{
//		_mutex.lock();
//		std::cout << "thread id  " << std::this_thread::get_id()
//			<< " running" << std::endl;
//		_mutex.unlock();
//	}
//}
//
//int main()
//{
//
//	// 初始化一个线程
//	std::thread t1(waitCommand);
//	std::thread t2(waitCommand);
//	std::thread t3(waitCommand);
//	t1.join();
//	t2.join();
//	t3.join();
//	return 0;
//}

//void func()
//{
//	while (1)
//	{
//		std::cout << "我是子线程: " << std::this_thread::get_id() << std::endl;
//	}
//}
//
//int main()
//{
//	// 初始化一个线程
//	std::thread newThread(func);
//	while (1)
//	{
//		std::cout << "我是主线程: " << std::this_thread::get_id() << std::endl;
//	}
//
//	newThread.join();
//
//	return 0;
//}