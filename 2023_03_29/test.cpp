#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>

//class Solution {
//public:
//    /**
//     *
//     * @param m int����
//     * @param n int����
//     * @return int����
//     */
//    int uniquePaths(int m, int n) {
//        // write code here
//        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));  // ���岢��ʶ��
//        
//        // ���� dp[0][0] = 0
//        //dp[0][0] = 0;  �������ⲻҪ�����
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
