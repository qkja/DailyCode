#include <vector>
// 设置一个循环队列
class MyCircularQueue
{
public:
	//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
	MyCircularQueue(int k) 
	{
		_front = 0;
		_tail = 0;
		_cap = 0;
		_v.resize(k + 1); // 注意这里我们不能使用resver
	}

	//enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
	bool enQueue(int value)
	{
		if (isFull())
			return false;
		_v[_tail] = value;
		_tail = (_tail + 1) % _v.size();
		_cap++;
		return true;
	}
	// deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。

	bool deQueue() {
		if (isEmpty())
			return false;
		_cap--;
		_front = (_front + 1) % _v.size();
		return true;

	}

	//Front: 从队首获取元素。如果队列为空，返回 - 1 。
	int Front() {
		if (isEmpty())
			return -1;
		return _v[_front];
	}

	//Rear: 获取队尾元素。如果队列为空，返回 - 1 。
	int Rear() 
	{
		if (isEmpty())
			return -1;
		// 拿到最后一个元素
		if (0 == _tail)
		{
			return _v.back();
		}
		return _v[_tail - 1];
	}

	bool isEmpty() {
		return _tail == _front;
	}

	bool isFull() {
		return (_tail + 1) % (_v.size()) == _front;
	}
private:
	size_t _front;
	size_t _tail;  // 指向最后一个数据的下一个位置    
	size_t _cap;   // 这里是有效数据的个数
	std::vector<int> _v;
};

// 来说一下我们常见的问题
// 一般我们会判断该循环队列里面的元素个数 -- 这个我们是由一个公式的
// 如果不超过 _tail - _front
// 超过    rear - front + N 
// 我们总结一下  (  rear - front + N ) % N