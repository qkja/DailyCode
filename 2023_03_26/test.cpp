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

#include <cstdio>
#include <vector>

#include <algorithm>
#include <unordered_map>

#include <iostream>
#include <string>
using namespace std;
bool is_password(const std::string &str)
{
	if (str.empty())
		return false;
	if (str[0] >= '0' && str[0] <= '9' || str.size() < 8)
		return false;
	std::vector<int> flags(3, 0);
	for (auto &e : str)
	{
		if (e >= 'a' && e <= 'z')
		{
			flags[0] = 1;
		}
		else if (e >= 'A' && e <= 'Z')
		{
			flags[1] = 1;
		}
		else if (e >= '0' && e <= '9')
		{
			flags[2] = 1;
		}
		else
		{
			return false;
		}
	} // end of for
	int sum = flags[0] + flags[1] + flags[2];
	return sum >= 2;
}

int main()
{
	int n = 0;

	std::cin >> n;
	getchar();
	while (n != 0)
	{
		n--;
		std::string str;
		char ch = '0';

		while ((ch = getchar()) != '\n')
		{
			str.push_back(ch);
		}
		// cout << str << endl;
		if (is_password(str))
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}