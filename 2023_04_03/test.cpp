#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     *
     * @param S string�ַ���
     * @param T string�ַ���
     * @return int����
     */
    int numDistinct(string S, string T) {

        int m = S.size();
        int n = T.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i < m + 1; i++)
        {
            dp[i][0] = 1;
        }

        // ��ʼ dp
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (S[i - 1] == T[j - 1])
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};
