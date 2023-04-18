#define _CRT_SECURE_NO_WARNINGS 
//template <class Type>
//Type bar(Type, Type);
//template <class Type>
//Type bar(Type, Type);
//template <class T1, class T2>
//void bar(T1, T2);
//template <typename C1, typename C2>
//void bar(C1, C2);
//
//int main()
//{
//
//	return 0;
//}

//��7.3.3 С���и����ĺ���putValues()��дΪģ�庯�����ҶԺ���ģ����в�����
//ʹ��������ģ�����һ��������Ԫ�ص�������һ��������ĳ����Լ�һ����������
//�ú���������һ�����������ͬʱ��������ģ�嶨��
//template<class Type, size_t SIZE>
//void putValues(Type (&arr)[SIZE])
//{
//
//}
//
//int main()
//{
//	int arr[10];
//	putValues(arr);
//	return 0;
//}


#include <vector>
#include <functional>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <map>
// ��������
void radixSort(std::vector<int>& v)
{
	if (v.empty())
		return;
	std::map<int, std::queue<int>> m;
	bool flag = true;
	int count = 1;
	while (1)
	{
		for (int i = 0; i < v.size(); i++)
		{
			m[(v[i] / count) % 10].push(v[i]);
		}
		count *= 10;
		int index = 0;
		// �ó���
		auto it = m.begin();
		while (it != m.end())
		{
			while (!it->second.empty())
			{
				int val = it->second.front();
				if (val != v[index])
					flag = false;
				v[index++] = val;
				it->second.pop();
			}
			it++;
		}
		if (flag)
			return;
		flag = true;
	}
}



//int main()
//{
//	std::vector<int> v = {19,1,1,13 };
//	radixSort(v);
	//for (auto e : v)
	//{
	//	std::cout << e << " ";
	//}
//	std::cout << std::endl;
//	return 0;
//}
#include <stdlib.h>
#include <time.h>
#include <string>
std::vector<std::string> name = { "��������", "ֱ�Ӳ�������" };



void interSort(std::vector<int>& v)
{
	// ���������Ǵӵ�ǰλ�ÿ�ʼ,����ѡ��һ����Сֵ,
	for (int i = 0; i < v.size()-1; i++)
	{
		int minNum = v[i];
		int index = i;
		for (int j = i+1; j < v.size(); j++)
		{
			if (v[j] < minNum)
			{
				minNum = v[j];
				index = j;
			}
		}
		std::swap(v[i], v[index]);
	}
}
void test1(std::function<void(std::vector<int>&)> fun)
{
	srand((unsigned int)time(NULL)); // ��һ�������
	std::vector<int> v;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(rand());
	}
	//for (auto e : v)
	//{
	//	std::cout << e << " ";
	//}
	//std::cout << std::endl;
	fun(v);
	//for (auto e : v)
	//{
	//	std::cout << e << " ";
	//}
	//std::cout << std::endl;
}

void test2(std::function<void(std::vector<int>&)> fun)
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(10 - i);
	}
	//for (auto e : v)
	//{
	//	std::cout << e << " ";
	//}
	//std::cout << std::endl;

	fun(v);
	//for (auto e : v)
	//{
	//	std::cout << e << " ";
	//}
	//std::cout << std::endl;

}


void test3(std::function<void(std::vector<int>&)> fun)
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i - 5);
	}
	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	fun(v);
	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}



void sort_performance_comparison(std::unordered_map < std::string,
	std::function < void(std::vector<int>&) >> &m)
{
	auto it = m.begin();
	while (it != m.end())
	{
		time_t begin_time = time(nullptr);
		std::cout << it->first << "��ʼ��" << std::endl;
		test1(it->second);
		time_t end_time = time(nullptr);
		std::cout << it->first << "������ "  << end_time - begin_time << std::endl;

		it++;
	}
}

// �������� ���������
void test()
{
	std::unordered_map < std::string, std::function < void(std::vector<int>&) >> m;
	std::vector<std::function<void(std::vector<int>&)>> v{
		radixSort, interSort
	};
	int index = 0;
	for (auto e : v)
	{
		m[name[index++]] = e;
	}

	sort_performance_comparison(m);
}

int main()
{
	//std::function<void(std::vector<int>&)> fun1 = interSort;
	//test1(fun);
	//test2(fun);
	//test3(fun);
	test();



	return 0;
}