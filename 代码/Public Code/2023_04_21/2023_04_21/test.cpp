#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int a = 10;

	return 0;
}



// È·ÊµÊÇ 1.5±¶À©ÈÝ
//int main()
//{
//	vector<int> v;
//	for (int i = 0; i < 100; i++)
//	{
//		if (v.capacity() == v.size())
//			std::cout << v.capacity() << std::endl;
//		v.push_back(i);
//	}
//	return 0; 
//}

// qqqqqqqqqqqqqqqqqqq
//11111111

//int main()
//{
//	int value = 1024;
//	char condition = *((char*)(&value));
//	if (condition) value += 1; condition = *((char*)(&value));
//	if (condition) value += 1; condition = *((char*)(&value));
//	printf("%d %d", value, condition);
//	return 0;
//}

//int main()
//{
//	char a = 101;
//	int sum = 200;
//	a += 27; sum += a;
//	printf("%d\n", sum);
//	return 0;
//}