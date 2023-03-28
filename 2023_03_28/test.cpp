#include <unordered_set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
  int minimumTotal(vector<vector<int>> &triangle)
  {
      if (triangle.empty())
        return -2;
  }

  /// @brief 自上向下  这道题连题目都没有说清楚,线下的时候只能 垂直和右下
  /// @param triangle
  /// @return
  // int minimumTotal(vector<vector<int>> &triangle)
  // {
  //   if (triangle.empty())
  //     return -2;
  //   vector<vector<int>> dp(triangle.size());
  //   for (int i = 0; i < triangle.size(); ++i)
  //   {

  //     vector<int> v(i + 1, -1);
  //     dp[i] = v;
  //     ;
  //   }

  //   dp[0][0] = triangle[0][0];

  //   for (int i = 1; i < triangle.size(); i++)
  //   {
  //     for (int j = 0; j < triangle[i].size(); j++)
  //     {
  //       if (j != 0 && i == j)
  //       {
  //         dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
  //         continue;
  //       }

  //       int minNum = dp[i - 1][j];
  //       if (j - 1 >= 0)
  //       {
  //         minNum = min(minNum, dp[i - 1][j - 1]);
  //       }

  //       dp[i][j] = minNum + triangle[i][j];
  //     }
  //   }

  //   // 找最小值
  //   int result = dp[triangle.size() - 1][0];
  //   for (int i = 1; i < dp[triangle.size() - 1].size(); ++i)
  //   {
  //     if (result > dp[triangle.size() - 1][i])
  //       result = dp[triangle.size() - 1][i];
  //   }
  //   return result;
  // }
};

// class Solution
// {
// public:
//   int minimumTotal(vector<vector<int>> &triangle)
//   {
//     if (triangle.empty())
//       return -1;
//     vector<vector<int>> dp(triangle.size());
//     for (int i = 0; i < triangle.size(); ++i)
//     {
//       dp.push_back(vector<int>(i + 1, -1));
//     }
//     dp[0][0] = triangle[0][0];
//     for (int i = 1; i < triangle.size(); i++)
//     {
//       for (int j = 0; j < triangle[i].size(); j++)
//       {
//         if (j != 0 && i == j)
//         {
//           dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
//           continue;
//         }

//         int minNum = triangle[i - 1][j];
//         if (j - 1 >= 0)
//         {
//           minNum = min(minNum, triangle[i - 1][j - 1]);
//         }
//         if (j + 1 < triangle[i - 1].size())
//         {
//           minNum = min(minNum, triangle[i - 1][j + 1]);
//         }
//         dp[i][j] = minNum + triangle[i][j];
//       }
//     }

//     // 找最小值
//     int result = dp[triangle.size() - 1][0];
//     for (int i = 1; i < dp[triangle.size() - 1].size(); ++i)
//     {
//       if (result > dp[triangle.size() - 1][i])
//         result = dp[triangle.size() - 1][i];
//     }
//     return result;
//   }
// };

// class Solution
// {
// public:
//   bool wordBreak(string s, unordered_set<string> &dict)
//   {
//     if (s.empty() || dict.empty())
//       return true;
//     std::vector<bool> dp;
//     dp.resize(s.size() + 1, false);
//     dp[0] = true; // 初始化
//     for (size_t i = 1; i <= s.size(); i++)
//     {
//       for (int j = 0; j < i; j++)
//       {
//         // f(1) -> f(0) [1,1]
//         // f2  -> f0  1-2   0  1
//         string str = s.substr(j, i - j);
//         auto iter = dict.find(str);
//         if (dp[j] && iter != dict.end())
//         {
//           dp[i] = true;
//           break;
//         }
//       }
//     }

//     return dp[s.size()];
//   }
// };

// class Solution
// {
// public:
//   bool wordBreak(string s, unordered_set<string> &dict)
//   {
//     if (s.empty() || dict.empty())
//       return true;
//     std::vector<bool> dp;
//     dp.resize(s.size()+1, false);
//     dp[0] = true; // 初始化
//     for (size_t i = 0; i < s.size(); i++)
//     {
//       // i = 1
//       bool flag = false;
//       for(int j = 0; j < i+1; j++)
//       {
//         bool ret = dp[j];  // 0
//         string str = s.substr(j , i+1-j);
//         auto iter = dict.find(str);
//         if(iter != dict.end())
//         {
//           // 找到了
//           ret = ret & true;
//         }
//         else
//         {
//           ret = false;
//         }
//         flag |= ret;
//       }
//       dp[i + 1] = flag;
//     }

//     return dp[s.size()];
//   }
// };

// class BinInsert {
// public:
//	int binInsert(int n, int m, int j, int i) {
//
//		return (n | (m << j));
//	}
// };

// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <algorithm>
// #include <map>
// using namespace std;
// bool is_prime_numbers(int val)
//{
//	if (val < 2)
//		return false;
//
//	for (int i = 2; i < val; i++)
//	{
//		if (val % i == 0)
//			return false;
//	}
//	return true;
// }
//
// void pairs_of_prime_numbers(std::vector<int>& result, int val)
//{
//	result.resize(2, -1);
//	std::map<int, int> m; // һ������ֵ ,һ�� ��Ч����
//	for (int i = 2; i < val; i++)
//	{
//		/*if (i == 0)
//		{
//			std::cout << i << std::endl;
//
//		}*/
//		int ret = val - i;
//		if (is_prime_numbers(i) && is_prime_numbers(ret))
//		{
//			// �����ֵ
//			m[abs(ret - i)] = i;
//		}
//	}
//
//	if (m.empty())
//		return;
//	result[0] = m.begin()->second;
//	result[1] = val - m.begin()->second;
//	std::sort(result.begin(), result.end());
// }
//
// int main() {
//
//	int n = 0;
//	std::cin >> n;
//     std::vector<int> result;
//	pairs_of_prime_numbers(result, n);
//	if (result.size() == 2)
//	{
//		std::cout << result[0] << std::endl;
//		std::cout << result[1] << std::endl;
//	}
//
//	return 0;
// }
//  64 λ������� printf("%lld")

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// bool parameter_analysis(std::vector<std::string>&result, std::string& str)
//{
//	if (str.empty())
//		return false;
//	//������ϴ "" ����,�����зֺ���˳��
//
//	// ���� ����
//	int index = 0;
//
//	while (1)
//	{
//		std::size_t pos = str.find(' ', index);
//		if (pos == std::string::npos)
//			break;
//		// �ҵ���
//		// �ж� ��[start, pos)�Ƿ���� "
//		//size_type find(const charT* s, size_type pos, size_type n) const;
//		//if (find('\"', ))
//	}
//
//	// ���ﻹҪ�и��з�
// }
// int main() {
//
//	std::string str;
//	std::getline(std::cin, str);
//	std::vector<std::string> result;
//	//char ch = '\"';
//	//cout << ch << endl;
//	return 0;
// }
//// 64 λ������� printf("%lld")

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// bool parameter_analysis(std::vector<std::string>&result, std::string& str)
//{
//	if (str.empty())
//		return false;
//
//	// ���� ���� ��¼ " ���±�
//
//	std::vector<int> v;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == '"')
//			v.push_back(i);
//	}
//
//	int index = 0;
//	int start = 0;
//	while (1)
//	{
//		std::size_t pos = str.find(' ', start);
//		if (pos == std::string::npos)
//			break;
//
//		//aaaa bbb "C:\\program files aaa" "d:\"
//
//		// ������
//		if (index < v.size()&& pos > v[index])
//		{
//			index+=2; // ����һ��
//			std::size_t pos2 = str.find('"', pos);
//			std::string s = str.substr(start + 1, pos2 - start - 1);
//			result.push_back(s);
//			start = pos2 + 1 + 1;
//		}
//		else
//		{
//			std::string s = str.substr(start, pos - start);
//			result.push_back(s);
//			start = pos + 1;
//		}
//	}
//
//	// ���ﻹҪ�и��з�
//	if (index < v.size())
//	{
//		// ����Ӧ������һ��  �з�
//		std::string s = str.substr(start + 1, str.size() - 1 - start - 1);
//		result.push_back(s);
//	}
//	else
//	{
//		std::string s = str.substr(start);
//		result.push_back(s);
//	}
//	return true;
// }
// int main() {
//
//	std::string str;
//	std::getline(std::cin, str);
//	std::vector<std::string> result;
//	parameter_analysis(result, str);
//	for (auto & e: result)
//	{
//		cout << e << endl;
//	}
//	return 0;
// }

// #include <iostream>
// #include <string>
// #include <stack>
// #include <vector>
// using namespace std;
// bool parameter_analysis(std::vector<std::string>&result, std::string& str)
//{
//	if (str.empty())
//		return false;
//	std::stack<char> s;
//	int start = 0;
//	int end = 0;
//	while (end < str.size())
//	{
//		if (str[end] == '"')
//		{
//			// ��ʱ
//			if (s.empty())
//			{
//				s.push('"');
//				end++;
//
//			}
//			else
//			{
//				result.push_back(str.substr(start + 1, end - 1 - start));
//				end += 2;
//				start = end;
//				s.pop();
//			}
//		}
//		else if (str[end] == ' ')
//		{
//			if (s.empty())
//			{
//				//��ʱ�����з�
//				result.push_back(str.substr(start, end - start));
//				end++;
//				start = end;
//			}
//			else
//			{
//				end++;
//			}
//		}
//		else
//		{
//			end++;
//		}
//	}
//	if (start < str.size())
//	{
//		result.push_back(str.substr(start, end - start));
//
//	}
//	return true;
//}
// int main() {
//
//	std::string str;
//	std::getline(std::cin, str);
//	std::vector<std::string> result;
//
//	parameter_analysis(result, str);
//	cout << result.size() << endl;
//
//	for (auto & e : result)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}
// #include <iostream>
// #include <vector>
// #include <limits.h>
// #include <math.h>
// #include <algorithm>
// using namespace std;
// void get_dic_num(int val, std::vector<int> &v)
// {
//   for (size_t i = 2; i <= sqrt(val); i++)
//   {
//     if (val % i == 0)
//     {
//       v.push_back(i);
//       if(val / i != i)
//       {
//         v.push_back(val/i);
//       }
//     }

//   }
// }

// int Jump(int n, int m)
// {
//   std::vector<int> step(m + 1, INT_MAX);
//   step[n] = 0; // ��n �� n  0 ��
//   for (size_t i = n; i < step.size(); i++)
//   {
//     if (step[i] == INT_MAX)
//       continue;
//     std::vector<int> v;
//     get_dic_num(i, v); // ��ȡ Լ��������
//     for (size_t j = 0; j < v.size(); j++)
//     {
//       if (i + v[j] < step.size())
//       {
//         step[i + v[j]] = min(step[i + v[j]], step[i] + 1);
//       }
//     }
//   }
//   if (step[m] == INT_MAX)
//     return -1;
//   else
//     return step[m];
// }
// int main()
// {
//   int n = 0;
//   int m = 0;
//   int minStep;
//   while (cin >> n >> m)
//   {
//     minStep = Jump(n, m);
//     cout << minStep << endl;
//   }

//   return 0;
// }
// 64 λ������� printf("%lld")