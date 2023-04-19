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
//	int col = mat[0].size(); // �������ǾͲ��ж���
//	vector<vector<bool>> book(row, vector<bool>(col, false));
//
//	// �����
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
//				// �õ���һ��Ԫ��
//				Node* ret = q.front();
//				q.pop();
//				v.push_back(ret->val);
//
//				// ���Ӻ���
//				for (int i = 0; i < ret->children.size(); i++)
//				{
//					if ((ret->children)[i]) // ���Ǳ���һ�°�
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
//		// �ҵ����е� ������
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
//		// ��ʼ������
//		while (!q.empty())
//		{
//			int size = q.size();
//			bool flag = false;
//
//			while (size--)
//			{
//				// �õ�Ԫ��
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
//		// �ж��Ƿ�ȫ���仵
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
//		// �ֵ���
//		std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
//		// �ж��Ƿ�������
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
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		std::unordered_set<std::string> dict(deadends.begin(), deadends.end());
		if (dict.find(target) != dict.end() || dict.find("0000") != dict.end())
			return -1;
		std::string str = "0000";
		std::queue<std::string> q;
		q.push(str);
		std::unordered_set<std::string> book;
		book.insert(str);
		int step = 0;
		while (!q.empty())
		{
			int size = q.size();
			while (size--)
			{
				std::string curStr = q.front();

				if (curStr == target)
					return step;
				q.pop();
				for (size_t i = 0; i < curStr.size(); i++)
				{
					char ch1 = curStr[i];
					char ch2 = curStr[i];
					// ��ת
					if (ch1 == '9')
						ch1 = '0';
					else
						ch1++;
					//��ת
					if (ch2 == '0')
						ch2 = '9';
					else
						ch2--;

					// ����ʼ�޸�
					std::string str1 = curStr;
					std::string str2 = curStr;

					str1[i] = ch1;
					str2[i] = ch2;

					if (dict.find(str1) == dict.end() && book.find(str1) == book.end())
					{
						q.push(str1);
						book.insert(str1);
					}
					if (dict.find(str2) == dict.end() && book.find(str2) == book.end())
					{
						q.push(str2);
						book.insert(str2);
					}

				}
			}
			step++;
		}
		return -1;
	}
};