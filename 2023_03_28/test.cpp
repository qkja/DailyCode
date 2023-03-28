
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
//	std::map<int, int> m; // 一个绝对值 ,一个 有效数据
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
//			// 求绝对值
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
//  64 位输出请用 printf("%lld")

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// bool parameter_analysis(std::vector<std::string>&result, std::string& str)
//{
//	if (str.empty())
//		return false;
//	//先来清洗 "" 不行,这里切分后有顺序
//
//	// 来个 数组
//	int index = 0;
//
//	while (1)
//	{
//		std::size_t pos = str.find(' ', index);
//		if (pos == std::string::npos)
//			break;
//		// 找到了
//		// 判断 从[start, pos)是否存在 "
//		//size_type find(const charT* s, size_type pos, size_type n) const;
//		//if (find('\"', ))
//	}
//
//	// 这里还要有个切分
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
//// 64 位输出请用 printf("%lld")

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;
// bool parameter_analysis(std::vector<std::string>&result, std::string& str)
//{
//	if (str.empty())
//		return false;
//
//	// 来个 数组 记录 " 的下表
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
//		// 找了了
//		if (index < v.size()&& pos > v[index])
//		{
//			index+=2; // 更新一下
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
//	// 这里还要有个切分
//	if (index < v.size())
//	{
//		// 这里应该是是一个  切分
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
//			// 此时
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
//				//此时可以切分
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
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
void get_dic_num(int val, std::vector<int> &v)
{
  for (size_t i = 2; i <= sqrt(val); i++)
  {
    if (val % i == 0)
    {
      v.push_back(i);
      if(val / i != i)
      {
        v.push_back(val/i);
      }
    }

  }
}

int Jump(int n, int m)
{
  std::vector<int> step(m + 1, INT_MAX);
  step[n] = 0; // 从n 到 n  0 步
  for (size_t i = n; i < step.size(); i++)
  {
    if (step[i] == INT_MAX)
      continue;
    std::vector<int> v;
    get_dic_num(i, v); // 获取 约数并保存
    for (size_t j = 0; j < v.size(); j++)
    {
      if (i + v[j] < step.size())
      {
        step[i + v[j]] = min(step[i + v[j]], step[i] + 1);
      }
    }
  }
  if (step[m] == INT_MAX)
    return -1;
  else
    return step[m];
}
int main()
{
  int n = 0;
  int m = 0;
  int minStep;
  while (cin >> n >> m)
  {
    minStep = Jump(n, m);
    cout << minStep << endl;
  }

  return 0;
}
// 64 位输出请用 printf("%lld")