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
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = p.first + v[i][0];
//			int ny = p.second + v[i][1];
//			if (nx < 0 || nx >= row || ny < 0 || ny >= col)
//				continue;
//			if (mat[nx][ny] == 0 && book[nx][ny] == false)
//			{
//				q.push(std::make_pair(nx, ny));
//				mat[nx][ny] = 1;
//				book[nx][ny] = true;
//			}
//		}
//	}
//	return false;
//}


int main()
{

	return 0;
}


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