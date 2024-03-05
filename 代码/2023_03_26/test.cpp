#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

// int main()
//{
//	int arr[1 + 2] = { 1, 2, 3 };
//
//	return 0;
// }

/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param n int���� ���λ��
 * @return int����һά����
 * @return int* returnSize ������������
 */

// int* printNumbers(int n, int* returnSize) {
//	// write code here
//	if (returnSize == NULL)
//		return NULL;
//	// ��ӡ nλ��
//
//	int ret = (int)pow(10.0, 1.0*n);
//	for (size_t i = 0; i < ret - 1; i++)
//	{
//		*(returnSize + i) = i + 1;
//	}
//	return returnSize;
// }

// int* printNumbers(int n, int* returnSize) {
//	// write code here
//	if (n <= 0 || returnSize == NULL)
//		return NULL;
//	// ��ӡ nλ��
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
// }

// int main()
//{
//	int arr[10] = { 0 };
//	printNumbers(1, arr);
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
// }

// bool is_leap_year(int year)
//{
//	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
// }
// int calculate_the_number_of_days(int year, int month, int day)
//{
//	// Ĭ����ƽ��
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
// }
//
// int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	cin >> year >> month >> day;
//	cout << calculate_the_number_of_days(year, month, day) << endl;
//	return 0;
// }

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// bool nicochels_theorem(string& str, int ret)
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
//	int m = (retPow - sum) / ret; // ����Сֵ
//
//	// �ж��ǲ���
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
// }
// int main() {
//	int ret = 0;
//	cin >> ret;
//	string str;
//	if (nicochels_theorem(str, ret) == true)
//	{
//		cout << str << endl;
//	}
//	return 0;
// }
//  #include <iostream>
//  using namespace std;

// int main() {
// 	int n = 0;
// 	cin >> n;
// 	int sum = 0;
// 	int start = 2;
// 	for (int i = 0; i < n; i++)
// 	{
// 		sum += start;
// 		start += 3;
// 	}
// 	cout << sum << endl;
// 	return 0;
// }
// 64 λ������� printf("%lld")

// #include <stdio.h>
// int i;
// void prt()
// {
// 	for (i = 5; i < 8; i++)
// 		printf("%c", '*');
// 	printf("\t");
// }
// int main()
// {
// 	for (i = 5; i <= 8; i++)
// 		prt();
// 	return 0;
// }

// #include <iostream>
// #include <vector>
// #include <cstdio>
// using namespace std;

// int main()
// {
// 	int n = 0;
// 	std::cin >> n;
// 	vector<int> v(n, 0);

// 	int negativeNum = 0; // ��������
// 	int positiveNum = 0; // ��������
// 	int sum = 0;

// 	for(int i = 0; i < n; i++)
// 	{
// 		std::cin >> v[i];
// 		if(v[i] < 0)
// 		{
// 			negativeNum++;
// 		}
// 		else if(v[i] > 0)
// 		{
// 			sum += v[i];
// 			positiveNum++;
// 		}
// 	}
// 	if(positiveNum == 0)
// 	{
// 		printf("%d %0.1f\n", negativeNum, 0);
// 		//std::cout << negativeNum << " " << 0.0 << std::endl;
// 	}
// 	else
// 	{
// 		printf("%d %0.1f\n", negativeNum, 1.0 * sum / positiveNum);

// 		//std::cout << negativeNum << " " << 1.0*sum/positiveNum << std::endl;
// 	}
// 	return 0;
// }
#include <vector>
using namespace std;

// class Solution
// {
// public:
// 	int minNumberInRotateArray(vector<int> rotateArray)
// 	{
// 		if (rotateArray.empty() == true)
// 			return -1;

// 		int left = 0;
// 		int right = rotateArray.size() - 1;
// 		int target = rotateArray[0];

// 		while (left < right)
// 		{
// 			int mid = (left + right) / 2;
// 			if (rotateArray[mid] > target)
// 			{
// 				left = mid + 1;
// 			}
// 			else if (rotateArray[mid] == target)
// 			{
// 			}
// 			else
// 			{
// 				right = mid - 1;
// 			}
// 		}
// 		return rotateArray[left];
// 	}
// };

// class Solution
// {
// public:
// 	int minNumberInRotateArray(vector<int> rotateArray)
// 	{
// 		if (rotateArray.empty() == true)
// 			return -1;

// 		int left = 0;
// 		int right = rotateArray.size() - 1;

// 		while (left < right)
// 		{
// 			if(rotateArray[left] >= rotateArray[right])
// 			{
// 				left++;
// 			}
// 			else
// 			{
// 				right--;
// 			}
// 		}
// 		return rotateArray[left];
// 	}
// };

// int main()
// {
// 	int m, n;
// 	printf("Enter m,n;");
// 	scanf("%d%d", &m, &n);
// 	while (m != n) // 1
// 	{
// 		while (m > n)
// 			m = m - n; // 2
// 		while (n > m)
// 			n = n - m; // 3
// 	}
// 	printf("m=%d\n", m);
// 	return 0;
// }

// int main()
// {
// 	int n = 0;
// 	while (std::cin >> n)
// 	{
// 		int state = 0;

// 		for (int i = 0; i <= n - 1; i++) // (1)
// 			for (int j = n; j > i; j--)		 // (2)
// 				state++;
// 		std::cout << state << std::endl;
// 	}
// }
// #include <algorithm>
// #include <unordered_map>

// class Solution
// {
// public:
// 	vector<int> findErrorNums(vector<int> &nums)
// 	{
// 		std::vector<int> result(2, -1);
// 		if (nums.empty())
// 			return result;

// 		int theoreticalSum = ((1 + nums.size()) * (nums.size())) / 2; // ��͹�ʽ
// 		int actualSum = 0;

// 		std::unordered_map<int, int> m;
// 		for (auto &e : nums)
// 		{
// 			m[e]++;
// 			if (2 == m[e])
// 			{
// 				result[0] = e;
// 			}
// 			actualSum += e;
// 		}
// 		// ��ν��ȱʧ��������ָ 1-n ������һ����
// 		// ʵ��ֵ - �ظ����� + x = ʵ��ֵ
// 		result[1] = theoreticalSum - actualSum + result[0];
// 		return result;
// 	}
// };

// class Solution
// {
// public:
// 	vector<int> findErrorNums(vector<int> &nums)
// 	{
// 		std::vector<int> result(2, -1);
// 		if (nums.empty())
// 			return result;

// 		/// ������ �ظ�������
// 		std::unordered_map<int, int> m;
// 		for (auto &e : nums)
// 		{
// 			m[e]++;
// 			if (2 == m[e])
// 			{
// 				result[0] = e;
// 				break;
// 			}
// 		}
// 		int actualSum  = 0;
// 				// ��ν��ȱʧ��������ָ 1-n ������һ����
// 				int theoreticalSum = (1 + nums.size()) / 2;

// 		return result;
// 	}
// };

// class Solution
// {
// public:
// 	vector<int> findErrorNums(vector<int> &nums)
// 	{
// 		std::vector<int> result(2, -1);
// 		if (nums.empty())
// 			return result;

//     /// ������ �ظ�������
// 		std::unordered_map<int, int> m;
// 		for(auto& e:nums)
// 		{
// 			m[e]++;
// 			if(2 == m[e])
// 			{
// 				result[0] = e;
// 				break;
// 			}
// 		}
// 		/// ��������ȱʧ������
// 		std::sort(nums.begin(), nums.end(), less<int>()); // Ĭ�������� ,������Ҫ����һ��

// 		for (size_t i = 0; i < nums.size(); i++)
// 		{
// 			if (i != nums[i] - 1)
// 			{
// 				result[1] = i + 1;
// 				return result;
// 			}
// 		}

// 		return result;
// 	}
// };

// class Solution
// {
// public:
// 	vector<int> findErrorNums(vector<int> &nums)
// 	{
// 		std::vector<int> result(2, -1);
// 		if (nums.empty())
// 			return result;

// 		// ����ֱ������
// 		std::sort(nums.begin(), nums.end(), less<int>()); // Ĭ�������� ,������Ҫ����һ��

// 		for (size_t i = 0; i < nums.size(); i++)
// 		{
// 			if (i != nums[i] - 1)
// 			{
// 				// ������Ǵ�
// 				result[0] = i;
// 				result[1] = i + 1;
// 				return result;
// 			}
// 		}

// 		return result;
// 	}
// };

// #include <iostream>
// #include <string>
// using namespace std;
// bool is_password(const std::string &str)
// {
// 	if (str.empty())
// 		return false;
// 	if (str[0] >= '0' && str[0] <= '9' || str.size() < 8)
// 		return false;
// 	std::vector<int> flags(3,0);
// 	for(auto & e : str)
// 	{
// 		if(e >= 'a' && e <= 'z')
// 		{
// 			flags[0] = 1;
// 		}
// 		else if (e >= 'A' && e <= 'Z')
// 		{
// 			flags[1] = 1;
// 		}
// 		else if (e >= '0' &&e <= '9')
// 		{
// 			flags[2] = 1;
// 		}
// 		else
// 		{
// 			return false;
// 		}
// 	} // end of for
// 	int sum = flags[0] + flags[1] + flags[2];
// 	return sum >= 2;
// }

// int main()
// {
// 	int n = 0;
// 	std::cin >> n;
// 	while (n != 0)
// 	{
// 		n--;
// 		std::string str;
// 		std::getline(std::cin, str);
// 		//std::getline(std::cin, str);
// 		if (is_password(str))
// 		{
// 			std::cout << "YES" << std::endl;
// 		}
// 		else
// 		{
// 			std::cout << "NO" << std::endl;
// 		}
// 	}
// 	return 0;
// }
// 64 λ������� printf("%lld")

// #include <cstdio>
// #include <vector>

// #include <algorithm>
// #include <unordered_map>

// #include <iostream>
// #include <string>
// using namespace std;
// bool is_password(const std::string &str)
// {
// 	if (str.empty())
// 		return false;
// 	if (str[0] >= '0' && str[0] <= '9' || str.size() < 8)
// 		return false;
// 	std::vector<int> flags(3, 0);
// 	for (auto &e : str)
// 	{
// 		if (e >= 'a' && e <= 'z')
// 		{
// 			flags[0] = 1;
// 		}
// 		else if (e >= 'A' && e <= 'Z')
// 		{
// 			flags[1] = 1;
// 		}
// 		else if (e >= '0' && e <= '9')
// 		{
// 			flags[2] = 1;
// 		}
// 		else
// 		{
// 			return false;
// 		}
// 	} // end of for
// 	int sum = flags[0] + flags[1] + flags[2];
// 	return sum >= 2;
// }

// int main()
// {
// 	int n = 0;

// 	std::cin >> n;
// 	getchar();
// 	while (n != 0)
// 	{
// 		n--;
// 		std::string str;
// 		char ch = '0';

// 		while ((ch = getchar()) != '\n')
// 		{
// 			str.push_back(ch);
// 		}
// 		// cout << str << endl;
// 		if (is_password(str))
// 		{
// 			std::cout << "YES" << std::endl;
// 		}
// 		else
// 		{
// 			std::cout << "NO" << std::endl;
// 		}
// 	}
// 	return 0;
// }

// class Solution
// {
// public:
// 	int GetNumberOfK(vector<int> data, int k)
// 	{
// 		if (data.empty())
// 			return -1;
// 		int left = 0;
// 		int right = data.size() - 1;

// 		while (left < right && data[left] < k)
// 		{
// 			++left;
// 		}
// 		while (left < right && data[right] > k)
// 		{
// 			right--;
// 		}

// 		return right - left + 1;
// 	}
// };

// class Solution
// {
// public:
// 	int GetNumberOfK(vector<int> data, int k)
// 	{
// 		if (data.empty())
// 			return 0;
// 		int left = 0;
// 		int right = data.size() - 1;

// 		while (left < right && data[left] < k)
// 		{
// 			++left;
// 		}
// 		while (left < right && data[right] > k)
// 		{
// 			right--;
// 		}
// 		if (right == left && data[left] != k)
// 			return 0;
// 		return right - left + 1;
// 	}
// };

// class Solution
// {
// public:
// 	void converting_binary(std::vector<int> v, int val)
// 	{
// 		while (val)
// 		{
// 			int ret = val % 2;
// 			v.push_back(ret);
// 			val /= 2;
// 		}
// 	}
// 	int convertInteger(int A, int B)
// 	{
// 		std::vector<int> va;
// 		std::vector<int> vb;
// 		bool falgA = false;
// 		bool falgB = false;
// 		if(A < 0)
// 		{
// 			falgA = true;
// 			A = -A;
// 		}
// 		if (B < 0)
// 		{
// 			falgB = true;
// 			B = -B;
// 		}

// 		converting_binary(va, A);
// 		converting_binary(vb, B);

// 		// 找两个数组中 容量比较大的数据
// 		va.resize(32, 0);
// 		vb.resize(32, 0);
//     if(falgA)
// 		{
// 			va[31] = 1;
// 		}
// 		if(falgB)
// 		{
// 			vb[31] = 1;
// 		}
// 		int count = 0;
// 		for (size_t i = 0; i < va.size(); i++)
// 		{
// 			if(va[i] != vb[i])
// 			count++;
// 		}
// 		return count;
// 	}
// };
// class Solution
// {
// public:
// 	int convertInteger(int A, int B)
// 	{
// 		int n = A ^ B; // 按位异或
// 		// 统计1的个数
// 		int count = 0;
// 		while (n)
// 		{
// 			count++;
// 			n = n & (n - 1); // n & (n-1)  会把二进制数列中最右边的1去掉
// 		}
// 		return count;
// 	}
// };
// int convertInteger(int A, int B)
// {
// 	int ret = A ^ B;
// 	// 按位异或  相同为0  相异为1
// 	// 求一的个数
// 	// 1110
// 	int count = 0;
// 	for (int i = 0; i < 32; i++)
// 	{
// 		if (((ret >> i) & 1) == 1)
// 		{
// 			count++;
// 		}
// 	}
// 	return count;
// }

// #define _CRT_SECURE_NO_WARNINGS 1
// #include <iostream>
// #include <vector>

// class Solution
// {
// public:
// 	void converting_binary(std::vector<int> &v, int val)
// 	{
// 		while (val)
// 		{
// 			int ret = val % 2;
// 			v.push_back(ret);
// 			val /= 2;
// 		}
// 	}
// 	int convertInteger(int A, int B)
// 	{
// 		std::vector<int> va;
// 		std::vector<int> vb;
// 		bool falgA = false;
// 		bool falgB = false;
// 		if (A < 0)
// 		{
// 			falgA = true;
// 			A = -A;
// 		}
// 		if (B < 0)
// 		{
// 			falgB = true;
// 			B = -B;
// 		}

// 		converting_binary(va, A);
// 		converting_binary(vb, B);

// 		// 找两个数组中 容量比较大的数据
// 		va.resize(32, 0);
// 		vb.resize(32, 0);
// 		if (falgA)
// 		{
// 			va[31] = 1;
// 		}
// 		if (falgB)
// 		{
// 			vb[31] = 1;
// 		}
// 		for (auto e : va)
// 		{
// 			std::cout << e << " ";
// 		}
// 		std ::cout << std::endl;
// 		for (auto e : vb)
// 		{
// 			std::cout << e << " ";
// 		}
// 		std::cout << std::endl;
// 		int count = 0;
// 		for (size_t i = 0; i < va.size(); i++)
// 		{
// 			if (va[i] != vb[i])
// 				count++;
// 		}
// 		return count;
// 	}
// };

// int main()
// {
// 	int a = 826966453;
// 	int b = -729934991;
// 	std::cout << Solution().convertInteger(a, b) << std::endl;
// 	return 0;
// }

// #include<stdio.h>
// #include <vector>
//
// #include <algorithm>
// #include <unordered_map>
//
// #include <iostream>
// #include <string>
// using namespace std;
// bool is_password(const std::string &str)
//{
//	if (str.empty())
//		return false;
//	if (str[0] >= '0' && str[0] <= '9' || str.size() < 8)
//		return false;
//	std::vector<int> flags(3, 0);
//	for (auto & e : str)
//	{
//		if (e >= 'a' && e <= 'z')
//		{
//			flags[0] = 1;
//		}
//		else if (e >= 'A' && e <= 'Z')
//		{
//			flags[1] = 1;
//		}
//		else if (e >= '0' &&e <= '9')
//		{
//			flags[2] = 1;
//		}
//		else
//		{
//			return false;
//		}
//	} // end of for
//	int sum = flags[0] + flags[1] + flags[2];
//	return sum >= 2;
// }
//
// int main()
//{
//	int n = 0;
//
//	std::cin >> n;
//
//	while (n != 0)
//	{
//		// 这里清空一下缓冲区
//		fflush(stdin);
//		n--;
//		std::string str;
//		//std::getline(std::cin, str);
//		char ch = '0';
//		while ((ch = getchar()) != '\n')
//		{
//			str.push_back(ch);
//		}
//		if (is_password(str))
//		{
//			std::cout << "YES" << std::endl;
//		}
//		else
//		{
//			std::cout << "NO" << std::endl;
//		}
//	}
//	return 0;
// }

// int main()
//{
//	int arr = 0;
//	printf("%d\n", arr);
//	std::unordered_map<int, int> map;
//	return 0;
// }
//

// #include<Windows.h>
//
// #include<stdio.h>
// #include<stdbool.h>
//
// #include<stdio.h>
// #include<windows.h>
//
// #include<stdio.h>
// #include <iostream>
// #include <vector>
// #include <cstdio>
//
// using namespace std;
// #include<stdio.h>
// #include<math.h>
//
// #include <stdio.h>
// #include <math.h> //因为使用了floor函数,需要添加该头文件
//
// #include <stdio.h>
// #include <math.h>
//
// #include <stdio.h>
// #include <math.h>
//
// #include<windows.h>
// #include<math.h>
// #include<float.h>
//
// #include<windows.h>
// #include<math.h>
// #include<float.h>
// #pragma pack(4)
// class CTest
//{
// public:
//	CTest() : m_chData('\0'), m_nData(0)
//	{
//	}
//	virtual void mem_fun() {}
//
// private:
//	char m_chData;
//	int m_nData;
//	static char s_chData;
// };
// char CTest::s_chData = '\0';
// int main(void)
//{
//	cout << sizeof(CTest) << std::endl;
//	// CChild *pChild = new CChild();
//	// CParent *pParent = (CParent *)pChild;
//	// pParent->Intro();
//	return (0);
// }
// int main()
//{
//	double x = 0.0;
//	if (fabs(x) < DBL_EPSILON)
//	{
//		printf("hehe\n");
//	}
//	return 0;
// }

// int main()
//{
//	double x = 1.0;
//	double y = 0.1;
//
//	if (fabs((x - 0.9) - 0.1) < DBL_EPSILON)
//	{
//		printf("You can see me!!!\n");
//	}
//	else
//	{
//		printf("oops!!!\n");
//	}
//	return 0;
// }

// int main()
//{
//
//	float num = 9.5f;
//	return 0;
// }

// int main()
//
//
//{
//
//	float num = 9.5f;
//
//	//int a = -10;
//	//int d = 3;
//	////printf("%d\n", a/d); //C语言中是-3,很好理解
//	//printf("%d\n", a % d);
//
//	return 0;
// }

// int main()
//{
//	//本质是四舍五入
//	printf("%.1f\n", round(2.1));
//	printf("%.1f\n", round(2.9));
//	printf("%.1f\n", round(-2.1));
//	printf("%.1f\n", round(-2.9));
//
//	return 0;
// }

// int main()
//{
//	//本质是向-∞取整,注意输出格式要不然看不到结果
//	printf("%.1f\n", floor(-2.9)); //-3
//	printf("%.1f\n", floor(-2.1)); //-3
//	printf("%.1f\n", floor(2.9)); //2
//	printf("%.1f\n", floor(2.1)); //2
//
//	return 0;
// }

// int main()
//{
//	printf("%d\n", (int)trunc(2.9));
//	printf("%d\n", (int)trunc(-2.9));
//	return 0;
// }

// int main()
//{
//	int a = 2.9;
//	int b = -2.9;
//
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
// }

// int main()
//{
//	BOOL x = TRUE;
//	printf("%d", sizeof(BOOL));
//	return 0;
// }

// int main()
//{
//	bool f;
//	_Bool fag = 1;   //可以将1赋值给他
//	fag = true;
//	if (fag)
//	{
//		printf("%d", sizeof(fag));
//	}
//	return 0;
// }
#include <unordered_map>
#include <map>
#include <algorithm>
// class Solution
// {
// public:
// 	int dominantIndex(vector<int> &nums)
// 	{

// 		if (nums.size() < 2)
// 			return -1;
// 		std::unordered_map<int, int> m;
// 		for (size_t i = 0; i < nums.size(); i++)
// 		{
// 			m[nums[i]] = i;
// 		}
// 		std::sort(nums.begin(), nums.end(), greater<int>());
// 		int a = nums[0];
// 		int b = nums[1];
// 		if (a == b || a < 2 * b)
// 			return -1;

// 		return m[a];
// 	}
// };
// #include <unordered_set>
// class Solution
// {
// public:
// 	vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
// 	{
// 		std::vector<int> result;
// 		if (nums1.empty() || nums2.empty())
// 			return result;
// 		std::unordered_set<int> s;
// 		s.insert(nums1.begin(), nums1.end());
// 		for (auto &e : nums2)
// 		{
// 			auto iter = s.find(e);
// 			if (iter != s.end())
// 			{
// 				s.erase(iter);
// 				result.push_back(e);
// 			}
// 		}
// 		return result;
// 	}
// };

// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// int main() {
// 	std::string str;
// 	std::getline(std::cin, str);
// 	std::sort(str.begin(), str.end()); // 随机迭代器
// 	std::cout << str << std::endl;
// }
// // 64 位输出请用 printf("%lld")

// class Solution
// {
// public:
// 	int pivotIndex(vector<int> &nums)
// 	{
// 		if (nums.empty())
// 			return -1;
// 		int sum = 0;
// 		for (auto &e : nums)
// 			sum += e;

// 		int leftSum = 0;
// 		int rightSum = sum;
// 		int index = 0;
// 		for (int i = 0; i < nums.size(); i++)
// 		{
// 			// 求 右侧和
// 			rightSum = rightSum - nums[i];
// 			// 求左侧和
// 			if (0 != i)
// 				leftSum = leftSum + nums[i - 1];
// 			if (rightSum == leftSum)
// 				return i;
// 		}
// 		return -1;
// 	}
// };

// #include <iostream>
// #include <string>
// #include <unordered_set>
// using namespace std;

// int main()
// {
// 	std::string str;
// 	std::getline(std::cin, str);
// 	std::unordered_set<char> s;
// 	s.insert(str.begin(), str.end());
// 	std::cout << s.size() << std::endl;
// 	return 0;
// }
// 64 位输出请用 printf("%lld")

class Solution {
public:
    int majorityElement(vector<int>& nums) {
			if(nums.empty())
			return -1;
			std::unordered_map<int, int> m;
			for(auto& e: nums)
			{
				m[e]++;
			}
			int len = nums.size();
			// 遍历map
			auto iter = m.begin();
			while (iter != m.end())
			{
				if( iter->second  * 2 > len)
				{
					return iter->first;
				}
				++iter;
			}
			return -1;
    }
};