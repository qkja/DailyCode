#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <string>
#include <queue>

using std::string;
using std::vector;
using std::queue;
using std::pair;
//bool Bfs(vector<vector<int>>& mat, int startx, int starty,
//	int endx, int endy)
//{
//	vector<vector<int>> v = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
//	queue<pair<int, int>> q;
//	int row = mat.size();
//	int col = mat[0].size(); // 这里我们就不判断了
//	vector<vector<bool>> book(row, vector<bool>(col, false));
//
//	// 入队列
//	q.push(std::make_pair(startx, starty));
//	book[startx][starty] = true;
//
//	while (!q.empty())
//	{
//		auto p = q.front();
//		q.pop();
//		if (p.first == endx && p.second == endy)
//			return true;
		//for (int i = 0; i < 4; i++)
		//{
		//	int nx = p.first + v[i][0];
		//	int ny = p.second + v[i][1];
		//	if (nx < 0 || nx >= row || ny < 0 || ny >= col)
		//		continue;
		//	if (mat[nx][ny] == 0 && book[nx][ny] == false)
		//	{
		//		q.push(std::make_pair(nx, ny));
		//		mat[nx][ny] = 1;
		//		book[nx][ny] = true;
		//	}
//		}
//	}
//	return false;
//}


//int main()
//{
//
//	return 0;
//}


//https://leetcode.cn/problems/n-queens/submissions/
//class Solution {
//public:
//    void Dfs(std::vector<std::vector<std::pair<int, int>>>& allRet,
//        std::vector<std::pair<int, int>>& curRet, int curRow, int n)
//    {
//        if (curRet.size() == n)
//        {
//            allRet.push_back(curRet);
//            return;
//        }
//        for (int i = 0; i < n; i++)
//        {
//            if (isValidPos(curRet, curRow, i))
//            {
//                curRet.push_back(std::make_pair(curRow, i));
//                Dfs(allRet, curRet, curRow + 1, n);
//                curRet.pop_back();
//            }
//        }
//    }
//
//    bool isValidPos(std::vector<std::pair<int, int>>& curRet, int curRow, int curCol)
//    {
//        for (auto& p : curRet)
//        {
//            if (p.second == curCol
//                || (p.first + p.second) == (curRow + curCol)
//                || (p.first - p.second) == (curRow - curCol))
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    void transResult(std::vector<std::vector<std::string>>& result,
//        std::vector<std::vector<std::pair<int, int>>>& allRet, int n)
//    {
//        string str;
//        for (int i = 0; i < n; i++)
//            str += '.';
//        result.resize(allRet.size(), std::vector<std::string>(n, str));
//        for (int i = 0; i < allRet.size(); i++)
//        {
//            for ( int j = 0; j < allRet[i].size(); j++)
//            {
//                int row = allRet[i][j].first;
//                int col = allRet[i][j].second;
//
//                result[i][row][col] = 'Q';
//            }
//        }
//    }
//
//    vector<vector<string>> solveNQueens(int n) {
//        std::vector<std::vector<std::string>> result;
//        if (n <= 0)
//            return result;
//  
//        std::vector<std::vector<std::pair<int, int>>> allRet;
//        std::vector<std::pair<int, int>> curRet;
//        Dfs(allRet, curRet, 0, n);
//        transResult(result, allRet, n);
//        return result;
//    }
//};
//
//class Solution {
//public:
//
//    void Dfs(std::vector<std::vector<std::pair<int, int>>>& allRet,
//        std::vector<std::pair<int, int>>& curRet, int curRow, int n)
//    {
//        if (curRet.size() == n)
//        {
//            allRet.push_back(curRet);
//            return;
//        }
//        for (int i = 0; i < n; i++)
//        {
//            if (isValidPos(curRet, curRow, i))
//            {
//                curRet.push_back(std::make_pair(curRow, i));
//                Dfs(allRet, curRet, curRow + 1, n);
//                curRet.pop_back();
//            }
//        }
//    }
//
//    bool isValidPos(std::vector<std::pair<int, int>>& curRet, int curRow, int curCol)
//    {
//        for (auto& p : curRet)
//        {
//            if (p.second == curCol
//                || (p.first + p.second) == (curRow + curCol)
//                || (p.first - p.second) == (curRow - curCol))
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    void transResult(std::vector<std::vector<std::string>>& result,
//        std::vector<std::vector<std::pair<int, int>>>& allRet, int n)
//    {
//        string str;
//        for (int i = 0; i < n; i++)
//            str += '.';
//        result.resize(allRet.size(), std::vector<std::string>(n, str));
//        for (int i = 0; i < allRet.size(); i++)
//        {
//            for (int j = 0; j < allRet[i].size(); j++)
//            {
//                int row = allRet[i][j].first;
//                int col = allRet[i][j].second;
//
//                result[i][row][col] = 'Q';
//            }
//        }
//    }
//
//
//    int totalNQueens(int n) {
//        std::vector<std::vector<std::string>> result;
//        if (n <= 0)
//            return 0;
//
//        std::vector<std::vector<std::pair<int, int>>> allRet;
//        std::vector<std::pair<int, int>> curRet;
//        Dfs(allRet, curRet, 0, n);
//        transResult(result, allRet, n);
//        return result.size();
//    }
//};


// Definition for a Node.
//class Node {
//public:
//	int val;
//	vector<Node*> children;
//
//	Node() {}
//
//	Node(int _val) {
//		val = _val;
//	}
//
//	Node(int _val, vector<Node*> _children) {
//		val = _val;
//		children = _children;
//	}
//};
//
//class Solution {
//public:
//	void BFS(vector<vector<int>>& result, Node* root)
//	{
//		queue<Node*> q;
//		q.push(root);
//		while (!q.empty())
//		{
//			int size = q.size();
//			vector<int> v;
//			while (size--)
//			{
//				// 拿到第一个元素
//				Node* ret = q.front();
//				q.pop();
//				v.push_back(ret->val);
//
//				// 入子孩子
//				for (int i = 0; i < ret->children.size(); i++)
//				{
//					if ((ret->children)[i]) // 还是避免一下吧
//						q.push((ret->children)[i]);
//				}
//			}
//			result.push_back(v);
//		}
//	}
//
//	vector<vector<int>> levelOrder(Node* root) {
//		vector<vector<int>> result;
//		if (root == nullptr)
//			return result;
//
//		BFS(result, root);
//		return result;
//	}
//};
//
//int main()
//{
//	Node node(1);
//	Solution().levelOrder(&node);
//	return 0;
//}
//https://leetcode.cn/problems/rotting-oranges/submissions/
//class Solution {
//public:
//	void Bfs(vector<vector<int>>& grid, int & step)
//	{
//		vector<vector<int>> v = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
//
//		// 找到所有的 坏橘子
//		int row = grid.size();
//		int col = grid[0].size();
//		queue<pair<int, int>> q;
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < col; j++)
//			{
//				if (grid[i][j] == 2)
//					q.push(std::make_pair(i, j));
//			}
//		}
//
//		// 开始走搜索
//		while (!q.empty())
//		{
//			int size = q.size();
//			bool flag = false;
//
//			while (size--)
//			{
//				// 拿到元素
//				auto p = q.front();
//				q.pop();
//				for (int i = 0; i < 4; i++)
//				{
//					int nx = p.first + v[i][0];
//					int ny = p.second + v[i][1];
//					if (nx < 0 || nx >= row || ny < 0 || ny >= col)
//						continue;
//					if (grid[nx][ny] == 1)
//					{
//						q.push(std::make_pair(nx, ny));
//						grid[nx][ny] = 2;
//						flag = true;
//					}
//				}
//			}
//			if (flag)
//				step++;
//		}
//	}
//
//	bool is_ture(vector<vector<int>>& grid)
//	{
//		for (auto& e : grid)
//		{
//			for (auto& p : e)
//			{
//				if (p == 1)
//					return false;
//			}
//		}
//		return true;
//	}
//	int orangesRotting(vector<vector<int>>& grid) {
//		if (grid.empty())
//			return 0;
//		// 判断是否全部变坏
//		int step = 0;
//		Bfs(grid, step);
//		if (!is_ture(grid))
//			return -1;
//		return step;
//	}
//};
#include <unordered_map>
#include <unordered_set>
//https://leetcode.cn/problems/word-ladder/
//class Solution {
//public:
//	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//
//		int step = 1;
//		std::queue<std::string> q;
//
//		// 字典序
//		std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
//		// 判断是否被搜索过
//		std::unordered_set<std::string> book;
//		q.push(beginWord);
//		book.insert(beginWord);
//		while (!q.empty())
//		{
//			int size = q.size();
//			while (size--)
//			{
//				string str = q.front();
//				if (str == endWord)
//					return step;
//				q.pop();
//				for (size_t i = 0; i < str.size(); i++)
//				{
//					std::string cutStr = str;
//					for (size_t j = 0; j < 26; j++)
//					{
//						cutStr[i] = 'a' + j;
//						if (dict.find(cutStr) != dict.end()
//							&& book.find(cutStr) == book.end())
//						{
//							q.push(cutStr);
//							book.insert(cutStr);
//						}
//					}
//				}
//			}
//			step++;
//		}
//
//		return 0;
//	}
//};
//https://leetcode.cn/problems/open-the-lock/submissions/
//class Solution {
//public:
//	int openLock(vector<string>& deadends, string target) {
//		std::unordered_set<std::string> dict(deadends.begin(), deadends.end());
//		if (dict.find(target) != dict.end() || dict.find("0000") != dict.end())
//			return -1;
//		std::string str = "0000";
//		std::queue<std::string> q;
//		q.push(str);
//		std::unordered_set<std::string> book;
//		book.insert(str);
//		int step = 0;
//		while (!q.empty())
//		{
//			int size = q.size();
//			while (size--)
//			{
//				std::string curStr = q.front();
//
//				if (curStr == target)
//					return step;
//				q.pop();
//				for (size_t i = 0; i < curStr.size(); i++)
//				{
//					char ch1 = curStr[i];
//					char ch2 = curStr[i];
//					// 正转
//					if (ch1 == '9')
//						ch1 = '0';
//					else
//						ch1++;
//					//逆转
//					if (ch2 == '0')
//						ch2 = '9';
//					else
//						ch2--;
//
//					// 来开始修改
//					std::string str1 = curStr;
//					std::string str2 = curStr;
//
//					str1[i] = ch1;
//					str2[i] = ch2;
//
//					if (dict.find(str1) == dict.end() && book.find(str1) == book.end())
//					{
//						q.push(str1);
//						book.insert(str1);
//					}
//					if (dict.find(str2) == dict.end() && book.find(str2) == book.end())
//					{
//						q.push(str2);
//						book.insert(str2);
//					}
//
//				}
//			}
//			step++;
//		}
//		return -1;
//	}
//};


//#include <iostream>
//#include <string>
//using namespace std;
//
//int strToInt(const string& str)
//{
//	if (str.size() == 1 && str[0] == 'i')
//		return 1;
//	int num = 0;
//	int flag = false;
//	for (auto& e: str)
//	{
//		if (e == '-')
//			flag = true;
//		else if (e == 'i')
//			continue;
//		else
//			num = 10 * num + e - '0';
//	}
//	if (flag)
//		num = -num;
//	return num;
//}
//
//int main()
//{
//	std::string one;
//	std::string two;
//	std::getline(std::cin, one);
//	std::getline(std::cin, two);
//
//	// a + bi
//	int str1 = strToInt(one.substr(0, one.find('+')));
//	int str2 = strToInt(one.substr(one.find('+') + 1));
//
//	// c +di
//	int str3 = strToInt(two.substr(0, two.find('+')));
//	int str4 = strToInt(two.substr(two.find('+') + 1));
//
//	int x = str1*str3 - str2*str4;
//	int y = str1*str4 + str2*str3;
//
//	string result = std::to_string(x);
//	//if (y >= 0) // 看题意我们这里不需要
//		result += '+';
//	result += std::to_string(y);
//	result += "i";
//	std::cout << result << std::endl;
//	//std::cout << one << std::endl;
//	//std::cout << two << std::endl;
//	// 开始拆分
//	return 0;
//}



//int main() 
//{
//	std::string one;
//	std::string two;
//	std::getline(std::cin, one);
//	std::getline(std::cin, two);
//	
//	// a + bi
//	int str1 = strToInt(one.substr(0, one.find('+')));
//	int str2 = strToInt(one.substr(one.find('+') + 1));
//
//	// c +di
//	int str3 = strToInt(two.substr(0, two.find('+')));
//	int str4 = strToInt(two.substr(two.find('+') + 1));
//	std::cout << str1 << " " << str2 << std::endl;
//	std::cout << str3 << " " << str4 << std::endl;
//
//	int x = str1*str3 - str2*str4;
//	int y = str1*str4 + str2*str3;
//	std::cout << x << " " << y << std::endl;
//
//	string result = std::to_string(x);
//	if (y >= 0)
//		result += '+';
//	result += std::to_string(y);
//	result += "i";
//	std::cout << result << std::endl;
//	//std::cout << one << std::endl;
//	//std::cout << two << std::endl;
//	// 开始拆分
//	return 0;
//}
// 64 位输出请用 printf("%lld")


#include <iostream>
using namespace std;

#include <iostream>
#include <string>
#include <vector>
//using namespace std;
//int stringToInt(string s) {
//	int count = 0;
//	for (int i = 0; i < s.size(); i++) {
//		count = count * 10 + (s[i] - '0');
//	}
//	return count;
//}
//int main() {
//	string s;
//	while (cin >> s) {
//		//用一个数组保存一年中当当前月累加的天数
//		static int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
//		};
//		vector<string> vec;
//		string s1;
//		//按照"-"分割年月日
//		for (int i = 0; i < s.size(); i++) {
//			if (s[i] == '-')
//			{
//				vec.push_back(s1);
//				//清空，保存下一部分
//				s1 = "";
//			}
//			else {
//				s1 += s[i];
//			}
//		}
//		//保存天
//		vec.push_back(s1);
//		//转整形
//		int year = stringToInt(vec[0]);
//		int month = stringToInt(vec[1]);
//		int day = stringToInt(vec[2]);
//		int ret = days[month - 1] + day;
//		//如果是闰年，并且包含2月，需要补一天
//		if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2)
//			ret++;
//		cout << ret << endl;
//	}
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
//void rollover(vector<string>& v, int k)
//{
//	int begin = 0;
//	int end = k;
//	while (end <= v.size())
//	{
//		std::reverse(v.begin() + begin, v.begin() + end);
//		begin = end;
//		end = begin + k;
//	}
//}
//
//int main()
//{
//	vector<string> v;
//	string str;
//	while (std::cin >> str)
//	{
//		if (str == "#")
//			break;
//		v.push_back(str);
//	}
//
//	int k = 0;
//	std::cin >> k;
//
//	rollover(v, k);
//
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		if (i == v.size() - 1)
//			std::cout << v[i] << std::endl;
//		else
//			std::cout << v[i] << "->";
//	}
//
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <limits.h>
//using namespace std;
//
//int main() {
//	int n = 0;
//	std::cin >> n;
//	std::vector<int> v(n);
//
//	for (size_t i = 0; i < n; i++)
//	{
//		std::cin >> v[i];
//	}
//
//	int first = v[0];
//	int second = INT_MAX;
//	int i = 0;
//	for (i = 1; i < n; i++)
//	{
//		if (v[i] < first)
//		{
//			first = v[i];
//			second = INT_MAX;
//		}
//		else if (v[i] > first && v[i] < second)
//		{
//			second = v[i];
//		}
//		else if (v[i] > first && v[i] > second)
//		{
//			break;
//		}
//	}
//	if (i == n)
//		std::cout << "false" << std::endl;
//	else
//		std::cout << "true" << std::endl;
//	return 0;
//}
// 64 位输出请用 printf("%lld")














//void rollover(vector<int>& v, int k)
//{
//	int begin = 0;
//	int end = k;
//	while (end <= v.size())
//	{
//		std::reverse(v.begin()+begin, v.begin() + end);
//		begin = end;
//		end = begin + k;
//	}
//}
//
//int main()
//{
//	vector<int> v;
//	int ch = 0;
//	while (std::cin >> ch)
//	{
//		if (ch == '#')
//			break;
//		v.push_back(ch);
//	}
//
//	int k = 0;
//	//getchar();
//	std::cin >> k;
//
//	rollover(v, k);
//
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		if (i == v.size() - 1)
//			std::cout << v[i] << std::endl;
//		else
//			std::cout << v[i] << "->";
//	}
//
//	return 0;
//}













//int main() 
//{
//	vector<char> v = { '1','2' };
//	char ch = 0;
//	while (std::cin>>ch)
//	{
//		if (ch == '#')
//			break;
//		v.push_back(ch);
//	}
//	int k = 0;
//	std::cin >> k;
//
//	rollover(v, 1);
//	//std::reverse(v.begin(), v.end());
//
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		if (i == v.size() - 1)
//			std::cout << v[i] << std::endl;
//		else
//			std::cout << v[i] << "->";
//	}
//
//	/*for (auto e : v)
//	{
//		std::cout << e << std::endl;
//	}*/
//}
// 64 位输出请用 printf("%lld")