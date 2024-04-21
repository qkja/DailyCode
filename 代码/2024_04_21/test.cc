#include <vector>
using namespace std;
// https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
class Solution
{
public:
  int findLengthOfLCIS(vector<int> &nums)
  {
    if (nums.empty())
      return 0;
    int result = 0;
    int ret = 1;
    int left = 0;
    int right = left + 1;
    while (right < nums.size())
    {
      if (nums[right] > nums[right - 1])
      {
        ret++;
        right++;
      }
      else
      {
        result = std::max(result, ret);
        ret = 1;
        left = right;
        right = left + 1;
      }
    }
    return std::max(result, ret);
  }
};
int main()
{
  return 0;
}
