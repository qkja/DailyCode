#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <string>

using std::string;
using std::vector;


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