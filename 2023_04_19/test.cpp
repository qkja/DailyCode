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