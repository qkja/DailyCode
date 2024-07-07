#include <vector>
#include <algorithm>
using namespace std;
/// @brief  OJ 已过
/// @param n
/// @return
int minGold(int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  // 初始化所有格子都是 0 对角线不用填
  // 倒数第一条对角线
  for (size_t i = 1; i < n; i++)
  {
    dp[i][i + 1] = i;
  }

  // 开始进行推导 从那开始填
  for (int left = n - 2; left > 0; left--)
  {
    for (size_t right = left + 2; right <= n; right++)
    {
      // 我们就猜left
      int p1 = left + dp[left + 1][right];
      int p2 = right + dp[left][right - 1];
      // p1 p2 都可以找到确保可以找到,我们虽然最倒霉,但是还要想要最好的,所以选择较小的
      int minGold = min(p1, p2);
      for (int i = left + 1; i < right; i++)
      {
        // 5 6
        int l = dp[left][i - 1];
        int r = dp[i + 1][right];
        int cur = i + max(l, r); // 永远最倒霉 那么为何事最大
        // 这为何要 要最小  
        minGold = min(cur, minGold); 
      }
      dp[left][right] = minGold;
    }
  }
  return dp[1][n];
}