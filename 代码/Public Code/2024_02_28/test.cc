#include "test.hpp"
// int main()
// {
//   std::cout << "debug" << std::endl;
//   return 0;
// }

// 最大子序列和问题
// 给定一组数据,注意这些数据有可能是负数,求取他的最大子序列和.
// 为了方便起见,如果我们的最大的子序列和是负数,那么我们认为最大的子序列的和是0

// 方法一:
/**
 * 最粗暴的方法,既然我们是求子序列的最大和,如果我们可以将子序列穷举一下,分别求一下我们的和就可以了
 * 穷举子序列,我们可以先来固定两个边界,i和j代表
 */

int MaximumSubsequenceSum_1(const std::vector<int> &nums)
{
  if (nums.empty())
    return 0;
  int i = 0;
  int j = 0;
  int maxSum = 0;

  for (i = 0; i < nums.size(); ++i)
  {

    for (j = i; j < nums.size(); ++j)
    {
      // 在[i,j]位置求取我们的和
      int thisSum = 0;
      for (int k = i; k <= j; ++k)
      {
        thisSum += nums[k];
      }
      maxSum = std::max(maxSum, thisSum);
    }
  }
  return maxSum;
}

int main()
{
  std::vector<int> nums = {-2, 11, -4, 13, -5, -2};
  int maxSum = MaximumSubsequenceSum_1(nums);
  std::cout << maxSum << std::endl;
  return 0;
}