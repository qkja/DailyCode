#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
using std::vector;
//https://leetcode.cn/problems/number-of-islands/submissions/
//class Solution {
//public:
//    std::vector<std::vector<int>> v = { {1, 0},{-1,0},{0,1},{0,-1} };
//    void Dfs(const vector<vector<char>>& grid, int row, int col,
//        vector<vector<bool>>& book, int x, int y
//    )
//    {
//        book[x][y] = true;
//        for (int i = 0; i < 4; i++)
//        {
//            int newX = x + v[i][0];
//            int newY = y + v[i][1];
//            if (newX < 0 || newX >= row || newY < 0 || newY >= col)
//                continue;
//            if (grid[newX][newY] == '1' && book[newX][newY] == false)
//                Dfs(grid, row, col, book, newX, newY);
//        }
//
//    }
//    int numIslands(vector<vector<char>>& grid) {
//        if (grid.empty())
//            return -1;
//        int row = grid.size();
//        int col = grid[0].size();
//        std::vector<vector<bool>> book(row, std::vector<bool>(col, false));
//        int count = 0;
//        for (size_t i = 0; i < row; i++)
//        {
//            for (size_t j = 0; j < col; j++)
//            {
//                if (grid[i][j] == '1' && book[i][j] == false)
//                {
//                    Dfs(grid, row, col, book, i, j);
//                    count++;
//                }
//            }
//        }
//        return count;
//    }
//};
#include <iostream>
#include <string>
#include <unordered_map>
using std::string;
//class Solution {
//public:
//
//    void Dfs(std::unordered_map<char, std::string>& m, std::vector<std::string>& result,
//        const std::string& digits, std::string str, int index)
//    {
//        if (index == digits.size())
//        {
//            result.push_back(str);
//            return;
//        }
//
//        std::string s = m[digits[index]];
//        for (int i = 0; i < s.size(); i++)
//        {
//            str.push_back(s[i]);
//            Dfs(m, result, digits, str, index + 1);
//            str.erase(str.end()-1);
//        }
//
//    }
//    vector<string> letterCombinations(string digits) {
//        std::vector<std::string> result;
//        if (digits.empty())
//            return result;
//        std::string numToStr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//        std::unordered_map<char, std::string> m;
//        for (int i = 0; i < 10; i++)
//        {
//            m[i + '0'] = numToStr[i];
//        }
//        std::string str;
//        Dfs(m, result, digits, str, 0);
//        return result;
//    }
//};

//int main()
//{
//    std::string str = "2";
//  /*  while (!str.empty())
//    {
//        std::cout << str << std::endl;
//        str.erase(str.end()-1);
//    }*/
//    std::vector<std::string> result = Solution().letterCombinations(str);
//    for (auto e : result)
//    {
//        std::cout << e << std::endl;
//    }
//    //std::cout << result.size() << std::endl;
//	return 0;
//}

class Solution {
public:
    void Dfs(std::vector<std::vector<int>>& result, const std::vector<int>& candidates,
        std::vector<int>& cur, int sum, int target, int prev)
    {
        if (sum >= target)
        {
            if (sum == target)
                result.push_back(cur);
            return;
        }

        for (int i = prev; i < candidates.size(); i++)
        {
            cur.push_back(candidates[i]);
            Dfs(result, candidates, cur, sum + candidates[i], target, i);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        if (candidates.empty())
            return result;
        std::vector<int> cur;
        Dfs(result, candidates, cur, 0, target, 0);
        return result;
    }
};
//#include <unordered_set>
//class Solution {
//public:
//    void Dfs(std::unordered_set<std::string>& s, const string& tiles, string cur, std::vector<bool> book)
//    {
//        if (!cur.empty())
//            s.insert(cur);
//        for (size_t i = 0; i < tiles.size(); i++)
//        {
//            if (book[i] == true)
//            {
//                book[i] = false;
//                Dfs(s, tiles, cur + tiles[i], book);
//                book[i] = true;
//            }
//        }
//    }
//    int numTilePossibilities(string tiles) {
//        if (tiles.empty())
//            return 0;
//        std::vector<bool> book(tiles.size(), true);
//        std::unordered_set<std::string> s;
//        std::string cur;
//        Dfs(s, tiles, cur, book);
//        return s.size();
//
//    }
//};