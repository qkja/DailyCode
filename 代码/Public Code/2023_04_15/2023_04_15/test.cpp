//#include <vector>
// 设置一个循环队列
//class MyCircularQueue
//{
//public:
//	//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//	MyCircularQueue(int k) 
//	{
//		_front = 0;
//		_tail = 0;
//		_cap = 0;
//		_v.resize(k + 1); // 注意这里我们不能使用resver
//	}
//
//	//enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//	bool enQueue(int value)
//	{
//		if (isFull())
//			return false;
//		_v[_tail] = value;
//		_tail = (_tail + 1) % _v.size();
//		_cap++;
//		return true;
//	}
//	// deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//
//	bool deQueue() {
//		if (isEmpty())
//			return false;
//		_cap--;
//		_front = (_front + 1) % _v.size();
//		return true;
//
//	}
//
//	//Front: 从队首获取元素。如果队列为空，返回 - 1 。
//	int Front() {
//		if (isEmpty())
//			return -1;
//		return _v[_front];
//	}
//
//	//Rear: 获取队尾元素。如果队列为空，返回 - 1 。
//	int Rear() 
//	{
//		if (isEmpty())
//			return -1;
//		// 拿到最后一个元素
//		if (0 == _tail)
//		{
//			return _v.back();
//		}
//		return _v[_tail - 1];
//	}
//
//	bool isEmpty() {
//		return _tail == _front;
//	}
//
//	bool isFull() {
//		return (_tail + 1) % (_v.size()) == _front;
//	}
//private:
//	size_t _front;
//	size_t _tail;  // 指向最后一个数据的下一个位置    
//	size_t _cap;   // 这里是有效数据的个数
//	std::vector<int> _v;
//};

// 来说一下我们常见的问题
// 一般我们会判断该循环队列里面的元素个数 -- 这个我们是由一个公式的
// 如果不超过 _tail - _front
// 超过    rear - front + N 
// 我们总结一下  (  rear - front + N ) % N


////////////////////////////////////////////////////////////////////////////////

// 下面我们学习间堆 我们这里简单点  -- 建立小堆
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
typedef int HPDataTytpe;
typedef struct Heap
{
	HPDataTytpe* elem;   // 指针
	size_t size;         // 数组的有限元素的个数
	size_t capacity;     // 数组的空间大小
}Heap;

//初始化  堆
void HeapInit(Heap* php)
{
	assert(php);
	php->elem = nullptr;
	php->capacity = php->size = 0;
}
//初始化  堆
void HeapInit(Heap* php);

//销毁 堆
void HeapDestroy(Heap* php);

//数据入堆
void HeapPush(Heap* php, HPDataTytpe val);

//数据出堆
void HeapPop(Heap* php);

//判断堆是不是 空
bool HeapEmpty(Heap* php);

//向上调整 
void adjustUp(HPDataTytpe* elem, int size);

//向下调整
void adjustDown(HPDataTytpe* elem, int size, size_t root);


//销毁 堆
void HeapDestroy(Heap* php)
{
	assert(php);
	if (php)
		delete[] php->elem;
	php->capacity = php->size = 0;
}

//数据入堆
void HeapPush(Heap* php, HPDataTytpe val)
{
	assert(php);
	// 判断堆是不是满了  --> 等一下
	if (php->size == php->capacity)
	{
		size_t newSize = php->capacity == 0 ? 4 : 2 * php->capacity;
		// 开辟空间
		//int* arr = (int*)malloc(sizeof(int)*newSize);
		int * arr = new int[newSize];
		for (int i = 0; i < php->size; i++)
		{
			arr[i] = php->elem[i];
		}
		delete[] php->elem;
		php->elem = arr;
		php->capacity = newSize;

	}
	// 入堆
	php->elem[(php->size)++] = val;
	// 向上调整
	adjustUp(php->elem, php->size);
}

//数据出堆
void HeapPop(Heap* php)
{
	assert(php);
	if (HeapEmpty(php))
		return;

	// 交换堆顶和堆未
	std::swap(php->elem[0], php->elem[--php->size]);
	//向下调整
	adjustDown(php->elem, php->size, 0);
}

//判断堆是不是 空
bool HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}

//向上调整 
void adjustUp(HPDataTytpe* elem, int size)
{
	assert(elem);
	int child = size - 1;
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (elem[child] < elem[parent])
			std::swap(elem[child], elem[parent]);
		else
			break;
	    child = parent;
		parent = (child - 1) / 2;
	}
}

//向下调整
void adjustDown(HPDataTytpe* elem, int size, size_t root)
{
	// 说一下参数
	// root --> 我们要向下调整的下表
	assert(elem);
	int parent = root;
	int child = 2 * parent + 1;
	while (child < size)
	{
		// 存在右孩子,并且有孩子为较小值
		if (child + 1 < size && elem[child + 1] < elem[child])
			child++;

		if (elem[child] < elem[parent])
			std::swap(elem[child], elem[parent]);
		else
			break;
		parent = child;
		child = 2 * parent + 1;
	}
}

//int main()
//{
//	Heap heap;
//	HeapInit(&heap);
//	HeapPush(&heap, 3);
//	HeapPush(&heap, 5);
//	HeapPush(&heap, 6);
//	HeapPush(&heap, 10);
//	HeapPush(&heap, 0);
//	//出堆
//	HeapPop(&heap);
//	for (int i = 0; i < (int)heap.size; i++)
//	{
//		printf("%d ", heap.elem[i]);
//	}
//	HeapDestroy(&heap);
//	return 0;
//}


////////////////////////////////////////////////////////////
// 堆排序  -- 所谓的堆排序就是我们根据 给的数组进行建立堆
// 此时我们这里在原数组上面经行操作

//void HeapSort(int* arr, int len)
//{
//	assert(arr);
//	for (int i = 1; i < len; i++)
//	{
//		adjustUp(arr, i + 1);
//	}
//	
//}
//
//void HeapSort(int *arr, int len)
//{
//	// 建堆 -- 必须确保我们下面也是一个堆
//	for (int parent = (len - 1 - 1) / 2; parent >= 0; parent--)
//	{
//		adjustDown(arr, len, parent);
//	}
//
//	// 建好了堆  这里开始去数字
//	// 见了小堆 -->堆顶元素最小 我们把元素放在最后一个元素   这里算是降序
//	for (size_t i = len - 1; i > 0; i--)
//	{
//		//123 -- 3
//		std::swap(arr[0], arr[i]);
//		// 这里的i是指元素的个数   例如123去掉3后还剩下2个元素
//		adjustDown(arr, i, 0);
//	}
//}
