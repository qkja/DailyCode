#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;






//int main()
//{
//	int arr[1 + 2] = { 1, 2, 3 };
//
//	return 0;
//}

/**
* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
*
*
* @param n int整型 最大位数
* @return int整型一维数组
* @return int* returnSize 返回数组行数
*/

//int* printNumbers(int n, int* returnSize) {
//	// write code here
//	if (returnSize == NULL)
//		return NULL;
//	// 打印 n位数
//
//	int ret = (int)pow(10.0, 1.0*n);
//	for (size_t i = 0; i < ret - 1; i++)
//	{
//		*(returnSize + i) = i + 1;
//	}
//	return returnSize;
//}

//int* printNumbers(int n, int* returnSize) {
//	// write code here
//	if (n <= 0 || returnSize == NULL)
//		return NULL;
//	// 打印 n位数
//
//	int ret = (int)pow(10.0, 1.0*n);
//	// 1 -> 10
//	int* arr = (int*)malloc(sizeof(int)*(ret - 1));
//	if (arr == NULL)
//		return NULL;
//
//	for (size_t i = 1; i < ret; i++)
//	{
//		arr[i - 1] = i;
//	}
//	*returnSize = ret - 1;
//	return arr;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	printNumbers(1, arr);
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//bool is_leap_year(int year)
//{
//	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
//}
//int calculate_the_number_of_days(int year, int month, int day)
//{
//	// 默认是平年
//	static int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int days = day;
//	for (int i = 1; i < month; i++)
//	{
//		if (2 == i && is_leap_year(year))
//			days += 29;
//		else
//			days += months[i];
//	}
//	return days;
//}
//
//int main() 
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	cin >> year >> month >> day;
//	cout << calculate_the_number_of_days(year, month, day) << endl;
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//bool nicochels_theorem(string& str, int ret)
//{
//	int retPow = (int)pow(ret, 3.0);
//	int sum = 0;
//	int j = 1;
//	for (int i = 0; i < ret; i++)
//	{
//		sum += j;
//		j += 2;
//	}
//
//	int m = (retPow - sum) / ret; // 求最小值
//
//	// 判断是不是
//	vector<int> v;
//	sum = 0;
//	j = 1;
//	for (int i = 0; i < ret; i++)
//	{
//		sum = sum + m + j;
//		v.push_back(m + j);
//		j += 2;
//	}
//	if (sum != retPow)
//		return false;
//
//	for (int i = 0; i < ret; i++)
//	{
//		str += to_string(v[i]);
//		if (i != ret - 1)
//
//		str += "+";
//	}
//	
//	return true;
//}
//int main() {
//	int ret = 0;
//	cin >> ret;
//	string str;
//	if (nicochels_theorem(str, ret) == true)
//	{
//		cout << str << endl;
//	}
//	return 0;
//}
#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int sum = 0;
	int start = 2;
	for (int i = 0; i < n; i++)
	{
		sum += start;
		start += 3;
	}
	cout << sum << endl;
	return 0;
}
// 64 位输出请用 printf("%lld")
