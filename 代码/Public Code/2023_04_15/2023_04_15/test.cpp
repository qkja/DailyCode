//#include <vector>
// ����һ��ѭ������
//class MyCircularQueue
//{
//public:
//	//MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//	MyCircularQueue(int k) 
//	{
//		_front = 0;
//		_tail = 0;
//		_cap = 0;
//		_v.resize(k + 1); // ע���������ǲ���ʹ��resver
//	}
//
//	//enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//	bool enQueue(int value)
//	{
//		if (isFull())
//			return false;
//		_v[_tail] = value;
//		_tail = (_tail + 1) % _v.size();
//		_cap++;
//		return true;
//	}
//	// deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
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
//	//Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//	int Front() {
//		if (isEmpty())
//			return -1;
//		return _v[_front];
//	}
//
//	//Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//	int Rear() 
//	{
//		if (isEmpty())
//			return -1;
//		// �õ����һ��Ԫ��
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
//	size_t _tail;  // ָ�����һ�����ݵ���һ��λ��    
//	size_t _cap;   // ��������Ч���ݵĸ���
//	std::vector<int> _v;
//};

// ��˵һ�����ǳ���������
// һ�����ǻ��жϸ�ѭ�����������Ԫ�ظ��� -- �����������һ����ʽ��
// ��������� _tail - _front
// ����    rear - front + N 
// �����ܽ�һ��  (  rear - front + N ) % N


////////////////////////////////////////////////////////////////////////////////

// ��������ѧϰ��� ��������򵥵�  -- ����С��
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
typedef int HPDataTytpe;
typedef struct Heap
{
	HPDataTytpe* elem;   // ָ��
	size_t size;         // ���������Ԫ�صĸ���
	size_t capacity;     // ����Ŀռ��С
}Heap;

//��ʼ��  ��
void HeapInit(Heap* php)
{
	assert(php);
	php->elem = nullptr;
	php->capacity = php->size = 0;
}
//��ʼ��  ��
void HeapInit(Heap* php);

//���� ��
void HeapDestroy(Heap* php);

//�������
void HeapPush(Heap* php, HPDataTytpe val);

//���ݳ���
void HeapPop(Heap* php);

//�ж϶��ǲ��� ��
bool HeapEmpty(Heap* php);

//���ϵ��� 
void adjustUp(HPDataTytpe* elem, int size);

//���µ���
void adjustDown(HPDataTytpe* elem, int size, size_t root);


//���� ��
void HeapDestroy(Heap* php)
{
	assert(php);
	if (php)
		delete[] php->elem;
	php->capacity = php->size = 0;
}

//�������
void HeapPush(Heap* php, HPDataTytpe val)
{
	assert(php);
	// �ж϶��ǲ�������  --> ��һ��
	if (php->size == php->capacity)
	{
		size_t newSize = php->capacity == 0 ? 4 : 2 * php->capacity;
		// ���ٿռ�
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
	// ���
	php->elem[(php->size)++] = val;
	// ���ϵ���
	adjustUp(php->elem, php->size);
}

//���ݳ���
void HeapPop(Heap* php)
{
	assert(php);
	if (HeapEmpty(php))
		return;

	// �����Ѷ��Ͷ�δ
	std::swap(php->elem[0], php->elem[--php->size]);
	//���µ���
	adjustDown(php->elem, php->size, 0);
}

//�ж϶��ǲ��� ��
bool HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}

//���ϵ��� 
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

//���µ���
void adjustDown(HPDataTytpe* elem, int size, size_t root)
{
	// ˵һ�²���
	// root --> ����Ҫ���µ������±�
	assert(elem);
	int parent = root;
	int child = 2 * parent + 1;
	while (child < size)
	{
		// �����Һ���,�����к���Ϊ��Сֵ
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
//	//����
//	HeapPop(&heap);
//	for (int i = 0; i < (int)heap.size; i++)
//	{
//		printf("%d ", heap.elem[i]);
//	}
//	HeapDestroy(&heap);
//	return 0;
//}


////////////////////////////////////////////////////////////
// ������  -- ��ν�Ķ�����������Ǹ��� ����������н�����
// ��ʱ����������ԭ�������澭�в���

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
//	// ���� -- ����ȷ����������Ҳ��һ����
//	for (int parent = (len - 1 - 1) / 2; parent >= 0; parent--)
//	{
//		adjustDown(arr, len, parent);
//	}
//
//	// �����˶�  ���￪ʼȥ����
//	// ����С�� -->�Ѷ�Ԫ����С ���ǰ�Ԫ�ط������һ��Ԫ��   �������ǽ���
//	for (size_t i = len - 1; i > 0; i--)
//	{
//		//123 -- 3
//		std::swap(arr[0], arr[i]);
//		// �����i��ָԪ�صĸ���   ����123ȥ��3��ʣ��2��Ԫ��
//		adjustDown(arr, i, 0);
//	}
//}
