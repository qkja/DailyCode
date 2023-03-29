#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     *
     * @param grid int����vector<vector<>>
     * @return int����
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

        // ���г�ʼ��  --> ��һ��
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
        {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        // ��һ��
        for (int i = 1; i < grid.size(); i++)
        {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        // ��ʼ��̬
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