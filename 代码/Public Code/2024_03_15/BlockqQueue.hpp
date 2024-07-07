#pragma once
const size_t gDefaultCap = 5; // 队列的容量
#include <queue>
#include <mutex>
#include <iostream>
#include <condition_variable>

// 设计一个阻塞队列
template <class T>
class BlockqQueue
{

public:
	BlockqQueue(size_t cap = gDefaultCap)
		: _cap(cap)
	{
	}
	~BlockqQueue()
	{
	}

public:
	// 生产接口
	void push(const T& in)
	{
		//lockQueue();
		std::unique_lock<std::mutex> lock(_mutex);
		while (isFull())
		{
			// 数据已经满了,这个时候,我们可以让生产者暂时歇一会了
			proBlockWait(lock);
		}
		pushCore(in);
		lock.unlock();

		// 唤醒消费者
		wakeCon();
	}
	// 消费接口
	// void pop(T *out)
	T pop()
	{
		std::unique_lock<std::mutex> lock(_mutex);
		while (isEmpty())
		{
			conBlockWait(lock); // 消费者阻塞等待
		}

		T ret = popCore();
		// 唤醒生产者
		lock.unlock();
		wakePro();
		return ret;
	}
private:
	void wakeCon()
	{
		_conCond.notify_one();
	}
	void wakePro()
	{
		_proCond.notify_one();
	}
	T popCore()
	{
		T ret = _bq.front();
		_bq.pop();
		return ret;
	}
	bool isEmpty()
	{
		return _bq.empty();
	}

	void pushCore(const T& in)
	{
		_bq.push(in);
	}

	void proBlockWait(std::unique_lock<std::mutex>& lock)
	{
		_proCond.wait(lock);
	}
	void conBlockWait(std::unique_lock<std::mutex>& lock) {
		_conCond.wait(lock);
	}
	bool isFull()
	{
		return _bq.size() == _cap;
	}
private:
	size_t _cap; // 阻塞队列的容量
	std::queue<T> _bq;
	std::mutex _mutex;  // 一把锁
	std::condition_variable _conCond; // 消费者等待的条件变量
	std::condition_variable _proCond; // 生产者等待的条件变量
};
