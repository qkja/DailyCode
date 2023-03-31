#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>

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
