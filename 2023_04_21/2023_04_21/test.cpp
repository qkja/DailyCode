#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>

int main()
{
	int value = 1024;
	char condition = *((char*)(&value));
	if (condition) value += 1; condition = *((char*)(&value));
	if (condition) value += 1; condition = *((char*)(&value));
	printf("%d %d", value, condition);
	return 0;
}

//int main()
//{
//	char a = 101;
//	int sum = 200;
//	a += 27; sum += a;
//	printf("%d\n", sum);
//	return 0;
//}