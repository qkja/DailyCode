#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//	bool is_self_dividing_number(int val)
//	{
//		// 拿到各位数
//		std::vector<int> v;
//		int num = val;
//		while (num)
//		{
//			int ret = num % 10;
//			if (ret == 0)
//				return false;
//			v.push_back(ret);
//			num /= 10;
//		}
//
//		for (auto& e : v)
//		{
//			if (val % e != 0)
//				return false;
//		}
//		return true;
//	}
//	vector<int> selfDividingNumbers(int left, int right) {
//		std::vector<int> result;
//		if (left > right)
//			return result;
//		for (size_t i = left; i <= right; i++)
//		{
//			if (is_self_dividing_number(i))
//				result.push_back(i);
//		}
//		return result;
//	}
// };

// class Solution {
// public:
//	vector<int> productExceptSelf(vector<int>& nums) {
//		std::vector<int> result;
//		if (nums.empty())
//			return result;
//		int len = nums.size();
//		result.resize(len, 1);
//
//		int left = 1;
//		int right = 1;
//
//		// 计算左侧的乘积
//		for (int i = 1; i < nums.size(); i++)
//		{
//			left = left*nums[i - 1];
//			// i=2 0
//			// i=1
//			result[i] = left;
//		}
//
//		// 计算右侧成绩
//		for (int i = len-1-1; i >= 0; i--)
//		{
//			right = right * nums[i + 1];
//			result[i] = result[i] * right;
//		}
//		return result;
//	}
// };

// int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	Solution().productExceptSelf(v);
//	return 0;
// }

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param num1 int整型
 * @param num2 int整型
 * @return int整型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
// int Add(int num1, int num2) {
//	// write code here
//	int anser = 0;
//	int ret = num2;
//	while (ret != 0)
//	{
//		anser = num1 ^ num2;
//		ret = (num1 & num2) << 1;
//		num1 = anser;
//		num2 = ret;
//	}
//	return num1;
// }

// class Solution {
// public:
//	vector<int> findDisappearedNumbers(vector<int>& nums) {
//		std::vector<int> result;
//		if (nums.empty())
//			return result;
//		std::vector<int> v;
//		v.resize(nums.size()+1, -1);
//		for (auto e : nums)
//		{
//			v[e] = e;
//		}
//		for (size_t i = 1; i < v.size(); i++)
//		{
//			if (v[i] == -1)
//				result.push_back(i);
//		}
//		return result;
//	}
// };

// #include <stdio.h>
// int main()
//{
//	int i = 1;
//	sizeof(i++);
//	printf("%d\n", i);
//	return 0;
// }

// class Solution {
// public:
//	int findMaxConsecutiveOnes(vector<int>& nums) {
//		if (nums.empty())
//			return -1;
//		int left = 0;
//		int right = 0;
//		int max = 0;
//		for (right = 0; right < nums.size(); right++)
//		{
//			left = right;
//			while (right < nums.size() && 1 == nums[right])
//			{
//				right++;
//			}
//			if (right-left > max)
//			{
//				max = right - left;
//			}
//
//		}
//		return max;
//	}
// };

// int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(0);
//	v.push_back(1);
//	Solution().findMaxConsecutiveOnes(v);
//	return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// void convention_numbers(std::vector<int>& v, int val)
//{
//	for (int i = 1; i < val; i++)
//	{
//		if (val % i == 0)
//			v.push_back(i);
//	}
// }
// int main()
//{
//	int n = 0;
//	std::cin >> n;
//	std::vector<int> v;
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		v.clear();
//		int sum = 0;
//		/*if (28 == i)
//		{
//			int b = 0;
//		}*/
//		convention_numbers(v, i);
//		for (auto & e : v)
//		{
//			sum += e;
//		}
//		if (i == sum)
//		{
//			count++;
//		}
//	}
//	std::cout << count << std::endl;
//
//	return 0;
// }
//  64 位输出请用 printf("%lld")

// int main()
//{
//	unsigned short x = 65530;
//	unsigned int y = x;
//	/*char c = 'A';
//	if ('0' <= c <= '9') printf("YES");
//	else printf("NO");*/
//	return 0;
// }

// #include <iostream>
// using namespace std;
//
// int main() {
//	int n = 0;
//	std::cin >> n;
//	vector<int> v;
//	while (n)
//	{
//		v.push_back(n % 10);
//		n = n / 10;
//	}
//	for (auto& e : v)
//	{
//		std::cout << e;
//	}
//	std::cout << endl;
//	return 0;
// }
//  64 位输出请用 printf("%lld")

// #include <iostream>
// #include <vector>
// using namespace std;
//
// int main() {
//	int n = 0;
//	while (std::cin >> n)
//	{
//		vector<int> v;
//		while (n)
//		{
//			v.push_back(n % 10);
//			n = n / 10;
//		}
//		for (auto& e : v)
//		{
//			std::cout << e;
//		}
//		if (v.empty())
//			std::cout << 0;
//
//		std::cout << endl;
//	}
//
//	return 0;
// }

// class Solution {
// public:
//	/**
//	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//	*
//	*
//	* @param nums int整型vector
//	* @return int整型
//	*/
//	int findPeakElement(vector<int>& nums) {
//		// write code here
//		if (nums.empty())
//		{
//			return -1;
//		}
//		int left = 0;
//		int right = nums.size() - 1;
//		while (left < right)
//		{
//			int mid = (left + right) / 2;
//			if (nums[mid] < nums[mid+1])
//			{
//				right = mid;
//			}
//			else
//			{
//				left =  mid + 1;
//			}
//		}
//		return left;
//	}
// };
//  #include <algorithm>

// class Solution {
// public:
// 	/**
// 	*
// 	* @param numbers int整型vector
// 	* @param target int整型
// 	* @return int整型vector
// 	*/
// 	vector<int> twoSum(vector<int>& numbers, int target) {
// 		std::vector<int> result;
// 		if (numbers.empty())
// 			return result;
// 		// 6 ->
// 		std::vector<int> v;
// 		for (auto& e : numbers)
// 		{
// 			v.push_back(target - e);
// 		}

// 		// 这里开始查找
// 		int ret = 0;
// 		for (size_t i = 0; i < v.size(); i++)
// 		{
// 			int left = 0;
// 			int right = numbers.size() - 1;
// 			while (left < right)
// 			{
// 				if ((i != left && v[i] == numbers[left])
// 					|| (i != right &&v[i] == numbers[right]))
// 				{
// 					if (v[i] == numbers[left])
// 					{
// 						result.push_back(left + 1);
// 					}
// 					else
// 					{
// 						result.push_back(right + 1);
// 					}
// 					ret = v[i];
// 					i = v.size();
// 					break; // 想办法跳出循环
// 				}
// 				left++;
// 				right--;
// 			}
// 		}

// 		for (size_t i = 0; i < numbers.size(); i++)
// 		{
// 			if (numbers[i] == target - ret)
// 			{
// 				result.push_back(i+1);
// 				break;
// 			}
// 		}
// 		std::sort(result.begin(), result.end());
// 		return result;
// 	}
// };

// int main()
// {
// 	vector<int> v;
// 	v.push_back(3);
// 	v.push_back(2);
// 	v.push_back(4);
// 	int k = 6;
// 	Solution().twoSum(v, k);
// 	return 0;
// }
// #include <unordered_map>
// #include <algorithm>
// class Solution
// {
// public:
// 	/**
// 	 *
// 	 * @param numbers int整型vector
// 	 * @param target int整型
// 	 * @return int整型vector
// 	 */

// 	/// @brief 注意这道题存在问题,我们使用的是 map,这里被去重了,关心一下把
// 	/// @param numbers
// 	/// @param target
// 	/// @return
// 	vector<int> twoSum(vector<int> &numbers, int target)
// 	{
// 		std::vector<int> result;
// 		if (numbers.empty())
// 			return result;
// 		result.resize(2);
// 		std::unordered_map<int, int> m; // 元素,下标
// 		for (size_t i = 0; i < numbers.size(); i++)
// 		{
// 			m[numbers[i]] = i;
// 		}

// 		for (size_t i = 0; i < numbers.size(); i++)
// 		{
// 			int ret = target - numbers[i];
// 			auto iter = m.find(ret);
// 			if (iter != m.end() && iter->second != i)
// 			{
// 				result[0] = i + 1;
// 				result[1] = iter->second + 1;
// 				break;
// 			}
// 		}
// 		std::sort(result.begin(), result.end());
// 		return result;
// 	}
// };

// class Solution
// {
// public:
// 	vector<int> masterMind(string solution, string guess)
// 	{
// 		std::vector<int> result;
// 		if (solution.size() != 4 && guess.size() != 4)
// 			return result;
// 		result.resize(2, 0);
// 		for (size_t i = 0; i < solution.size(); i++)
// 		{
// 			if (solution[i] == guess[i])
// 			{
// 				result[0]++;
// 				solution[i] = '*';
// 				guess[i] = '*';
// 			}
// 		}

// 		for (auto &e : guess)
// 		{
// 			if (e != '*')
// 			{
// 				// 开始查找
// 				auto pos = solution.find(e);
// 				if (pos != std::string::npos)
// 				{
// 					// 找到了
// 					result[1]++;
// 					solution[pos] = '*';
// 				}
// 			}
// 		}

// 		return result;
// 	}
// };
#include <unordered_map>
// class Solution
// {
// public:
// 	int romanToInt(string s)
// 	{
// 		if (s.empty())
// 			return 0;
// 		std::unordered_map<std::string, int> m;
// 		std::vector<std::pair<std::string, int>> v = {
// 				{"I", 1},
// 				{"V", 5},
// 				{"X", 10},
// 				{"L", 50},
// 				{"C", 100},
// 				{"D", 500},
// 				{"M", 1000},

// 				{"IV", 4},
// 				{"IX", 9},
// 				{"XL", 40},
// 				{"XC", 90},
// 				{"CD", 400},
// 				{"CM", 900},
// 		};
// 		for (auto &p : v)
// 		{
// 			m.insert(p);
// 		}

// 		int sum = 0;
// 		for (size_t i = 0; i < s.size(); i++)
// 		{
// 			std::string str;
// 			str += s[i];
// 			if (s[i] == 'I')
// 			{
// 				if(i + 1 < s.size() && s[i+1] == 'V')
// 				{
// 					sum += 4;
// 					i++;
// 				}
// 				else if (i + 1 < s.size() && s[i+1] == 'X')
// 				{
// 					sum += 9;
// 					i++;
// 				}
// 				else
// 				{
// 					sum += m[str];
// 				}
// 			}
// 			else if (s[i] == 'X')
// 			{
// 				if (i + 1 < s.size() && s[i + 1] == 'L')
// 				{
// 					sum += 40;
// 					i++;
// 				}
// 				else if (i + 1 < s.size() && s[i + 1] == 'C')
// 				{
// 					sum += 90;
// 					i++;
// 				}
// 				else
// 				{
// 					sum += m[str];
// 				}
// 			}
// 			else if (s[i] == 'C')
// 			{
// 				if (i + 1 < s.size() && s[i + 1] == 'D')
// 				{
// 					sum += 400;
// 					i++;
// 				}
// 				else if (i + 1 < s.size() && s[i + 1] == 'M')
// 				{
// 					sum += 900;
// 					i++;
// 				}
// 				else
// 				{
// 					sum += m[str];
// 				}
// 			}
// 			else
// 			{
// 				sum += m[str];
// 			}
// 		}
// 		return sum;
// 	}
// };
#include <algorithm>
// class Solution
// {
// public:
// 	string addBinary(string a, string b)
// 	{
// 		if (a.empty())
// 			return b;
// 		if (b.empty())
// 			return a;
// 		std::string result;

// 		int end1 = a.size() - 1;
// 		int end2 = b.size() - 1;
// 		int sum = 0;
// 		while (end1 >= 0 && end2 >= 0)
// 		{
// 			sum = a[end1] - '0' + b[end2] - '0' + sum;
// 			result += ((sum % 2) + '0');
// 			sum /= 2;
// 			end1--;
// 			end2--;
// 		}
// 		while (end1 >= 0)
// 		{
// 			sum = sum + a[end1] - '0';
// 			result += ((sum % 2) + '0');
// 			sum /= 2;
// 			end1--;
// 		}
// 		while (end2 >= 0)
// 		{
// 			sum = sum + b[end2] - '0';
// 			result += ((sum % 2) + '0');
// 			sum /= 2;
// 			end2--;
// 		}
// 		// 判断 sum 值
// 		if(sum != 0)
// 		{
// 			result += '1';
// 		}
// 		std::reverse(result.begin(), result.end());
// 		return result;
// 	}
// };

// class Solution
// {
// public:
// 	int countSegments(string s)
// 	{
// 		if (s.empty())
// 			return 0;
// 		// 统计空格的子数
// 		int count = 0;
// 		for (auto &e : s)
// 		{
// 			if (e == ' ')
// 				count++;
// 		}
// 		return count + 1;
// 	}
// };

// class Solution
// {
// public:
// 	int countSegments(string s)
// 	{
// 		if (s.empty())
// 			return 0;
// 		// 统计空格的子数  -- 不允许
// 		int count = 0;
// 		int start = 0;
// 		while (1)
// 		{
// 			while (start < s.size() && s[start] == ' ')
// 			{
// 				start++;
// 			}
// 			if (start == s.size())
// 			{
// 				break;
// 			}
// 			// 查找
// 			std::size_t pos = s.find(' ', start);
// 			if (pos == std::string::npos)
// 			{
// 				count++;
// 				break;
// 			}
// 			start = pos;
// 			count++;
// 		}
// 		return count;
// 	}
// };

// class Solution
// {
// public:
// 	bool validPalindrome(string s)
// 	{
// 		if(s.empty())
// 		return true;
// 		int left = 0;
// 		int right = s.size()-1;
// 		while (left <= right) // 注意这里我们特意用到的 = 号
// 		{
// 			if(s[left] != s[right])
// 			break;
// 			left ++;
// 			right--;
// 		}
// 		if(left <= right)
// 		{
// 			return (right - left) == 1;
// 		}
// 		return true;

// 	}
// };
// class Solution
// {
// public:
// 	bool is_palindrome_string(const std::string &str)
// 	{
// 		int left = 0;
// 		int right = str.size()-1;
// 		while (left < right)
// 		{
// 			if (str[left] != str[right])
// 				return false;
// 			left++;
// 			right--;
// 		}
// 		return true;
// 	}

// 	bool validPalindrome(string s)
// 	{
// 		if (s.empty())
// 			return true;
// 		// 先判断回文
// 		if (is_palindrome_string(s))
// 			return true;
// 		for (size_t i = 0; i < s.size(); i++)
// 		{
// 			std::string str = s;
// 			str.erase(i, 1);
// 			if (is_palindrome_string(str))
// 				return true;
// 		}
// 		return false;
// 	}
// };

// class Solution
// {
// public:
// 	bool is_palindrome_string(const std::string &str)
// 	{
// 		int left = 0;
// 		int right = str.size() - 1;
// 		while (left < right)
// 		{
// 			if (str[left] != str[right])
// 				return false;
// 			left++;
// 			right--;
// 		}
// 		return true;
// 	}

// 	bool validPalindrome(string s)
// 	{
// 		if (s.empty())
// 			return true;
// 		// 先判断回文
// 		if (is_palindrome_string(s))
// 			return true;
// 		int left = 0;
// 		int right = s.size() - 1;
// 		while (left < right)
// 		{
// 			if (s[left] != s[right])
// 			{
// 				string str = s;
// 				str.erase(left, 1);
// 				if (is_palindrome_string(str))
// 					return true;

// 				s.erase(right, 1);
// 				if (is_palindrome_string(s))
// 					return true;
// 				break;
// 			}
// 			left++;
// 			right--;
// 		}

// 		return false;
// 	}
// };
int main()
{

	return 0;
}