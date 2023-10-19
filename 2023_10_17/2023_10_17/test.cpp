#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	printf("hello\n");
//	return 0;
//}

//void func(char para[100])
//{
//	void *p = malloc(100);
//	printf("%d, %d\n", sizeof(para), sizeof(p));
//}
//int main()
//{
//	char arr[100] = { 0 };
//	func(arr);
//	/*char a = 101;
//	int sum = 200;
//	a += 27; 
//	sum += a;
//	printf("%d\n", sum);*/
//	/*int value = 1024;
//	char condition = *((char*)(&value));
//	if (condition) 
//		value += 1; 
//	condition = *((char*)(&value));
//	if (condition) 
//		value += 1; 
//	condition = *((char*)(&value));
//	printf("%d %d", value, condition);*/
//
//	//char ch = 0x12;
//	return 0;
//}

//#include <stdio.h>
//void func(char *p) { p = p + 1; }
//int main()
//{
//	char s[] = { '1', '2', '3', '4' };
//	func(s);
//	printf("%c", *s);
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <cmath>
//
//using namespace std;
//bool is_automorphic_number(int val)
//{
//	int len = std::to_string(val).size();
//	int ret = 1;
//	// 0
//	for (int i = 0; i < len; ++i)
//		ret *= 10;
//	if ((int)pow(val, 2) % ret == val)
//		return true;
//	return false;
//}
//int main() {
//	int n = 0;
//	std::cin >> n;
//	int result = 0;
//	for (int i = 0; i <= n; ++i)
//	{
//		if (is_automorphic_number(i))
//		{
//			++result;
//		}
//	}
//	std::cout << result << std::endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//bool is_prime_number(int val)
//{
//	if (val < 2)
//		return false;
//	for (int i = 2; i < val; ++i)
//	{
//		if (val % i == 0)
//			return false;
//	}
//	return true;
//}
//int main() {
//	int n = 0;
//	std::cin >> n;
//	int result = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		if (is_prime_number(i))
//			result++;
//	}
//	std::cout << result << std::endl;
//	return 0;
//}