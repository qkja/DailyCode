//#include <stdio.h>
//int main()
//{
//	// 这个long的大小还是按照不小于int来记吧
//	// 那本书描述的可能有点问题
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long*));
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//bool isPalindromeString(const string& str)
//{
//	int begin = 0;
//	int end = str.size() - 1;
//	while (begin < end)
//	{
//		if (str[begin] != str[end])
//		{
//			return false;
//		}
//		begin++;
//		end--;
//	}
//	return true;
//}
//
//int main() 
//{
//	string a;
//	string b;
//	std::getline(std::cin, a);
//	std::getline(std::cin, b);
//	int count = 0;
//	for (int i = 0; i <= a.size(); i++)
//	{
//		string str = a;
//		str.insert(i, b);
//		if (isPalindromeString(str) == true)
//			count++;
//	}
//	std::cout << count << std::endl;
//	return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <vector>


//int main() 
//{
//	int n = 0;
//	std::cin >> n;
//	std::vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> v[i];
//	}
//	std::vector<int> dp;
//	dp.resize(n);
//	dp[0] = v[0];
//	for (int i = 1; i < n; i++)
//	{
//		dp[i] = std::max(v[i], dp[i - 1] + v[i]);
//	}
//
//	// 找到最大值
//	int maxSum = dp[0];
//	for (auto e : dp)
//	{
//		if (e>maxSum)
//			maxSum = e;
//	}
//	std::cout << maxSum << std::endl;
//	return 0;
//}

// 优化一下

//int main()
//{
//	int n = 0;
//	std::cin >> n;
//	std::vector<int> v;
//	v.resize(n);
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> v[i];
//	}
//	int maxSum = v[0];
//	int left = maxSum;
//
//	for (int i = 1; i < n; i++)
//	{
//		int ret = std::max(left + v[i], v[i]);
//		if (ret > maxSum)
//		{
//			maxSum = ret;
//			
//		}
//		left = ret;
//	}
//
//	
//	std::cout << maxSum << std::endl;
//	return 0;
//}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 本来因该先写递归,可是我有点不太会,这里看看左神的视频
int isMaxSum(const std::vector<int> v, std::size_t begin, std::size_t end)
{

}

int main()
{

	int n = 0;
	std::cin >> n;
	std::vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}
	int  maxSum = isMaxSum(v, 0, v.size() - 1);

	std::cout << maxSum << std::endl;
	return 0;
}


//class Solution {
//public:
//	int StrToInt(string str) {
//		if (str.empty())
//			return 0;
//		int begin = 0;
//		bool flag = false;
//		if (str[0] == '-')
//		{
//			flag = true;
//			begin = 1;
//		}
//		if (str[0] == '+')
//		{
//			begin = 1;
//		}
//		long long result = 0;
//		for (; begin < str.size(); begin++)
//		{
//			if (str[begin] >= '0' && str[begin] <= '9')
//			{
//				result = 10 * result + str[begin] - '0';
//			}
//			else
//			{
//				return 0;
//			}
//		}
//		if (flag)
//			result = -result;
//		return result;
//	}
//};
