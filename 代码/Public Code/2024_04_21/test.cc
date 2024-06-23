#include <vector>
#include <climits>
using namespace std;
// https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
// class Solution
// {
// public:
//   int findLengthOfLCIS(vector<int> &nums)
//   {
//     if (nums.empty())
//       return 0;
//     int result = 0;
//     int ret = 1;
//     int left = 0;
//     int right = left + 1;
//     while (right < nums.size())
//     {
//       if (nums[right] > nums[right - 1])
//       {
//         ret++;
//         right++;
//       }
//       else
//       {
//         result = std::max(result, ret);
//         ret = 1;
//         left = right;
//         right = left + 1;
//       }
//     }
//     return std::max(result, ret);
//   }
// };

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int preMin = INT_MAX;
    int maxVal = 0;
    for (int i = 0; i < prices.size(); ++i)
    {
      // 计算差值
      maxVal = std::max(prices[i] - preMin, maxVal);
      // 跟新最小值
      preMin = std::min(preMin, prices[i]);
    }
    return maxVal;
  }
};

int main()
{
  return 0;
}
