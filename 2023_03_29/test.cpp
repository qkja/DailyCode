#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
     */



    int minPathSum(vector<vector<int> >& grid) {
        if (grid.empty())
            return -1;
        std::vector<std::vector<int>> dp(grid.size());
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> v(grid[i].size(), -1);
            dp[i] = v;
        }

        // 进行初始化  --> 第一层
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
        {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        // 第一列
        for (int i = 1; i < grid.size(); i++)
        {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        // 开始动态
        for (int i = 1; i < grid.size(); i++)
        {
            for (int j = 1; j < grid[i].size(); j++)
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[grid.size() - 1][grid[grid.size() - 1].size() - 1];
    }
};

//class Solution {
//public:
//    /**
//     *
//     * @param m int整型
//     * @param n int整型
//     * @return int整型
//     */
//    int uniquePaths(int m, int n) {
//        // write code here
//        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));  // 定义并初识化
//        
//        // 这里 dp[0][0] = 0
//        //dp[0][0] = 0;  但是题意不要求这个
//        for (int i = 1; i < m; i++)
//        {
//            for (int j = 1; j < n; j++)
//            {
//                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//            }
//        }
//        return dp[m - 1][n - 1];
//    }
//};