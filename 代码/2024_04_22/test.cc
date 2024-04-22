#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/submissions/525879054/
// class Solution
// {
// public:
//     // 方式1: 双指针
//     int maxProfit(vector<int> &prices)
//     {
//         int profit = 0;
//         for (int left = 0; left < prices.size();)
//         {
//             int right = left + 1;
//             while (right < prices.size() && prices[right] > prices[right - 1])
//             {
//                 ++right;
//             }

//             // 收获收益
//             if (right <= prices.size())
//             {
//                 profit += prices[right - 1] - prices[left];
//             }
//             // 更新指针
//             left = right;
//         }
//         return profit;
//     }
//     // 方式2: 优化思路
//     // int maxProfit(vector<int> &prices)
//     // {
//     //     int profit = 0;
//     //     for (int i = 0; i < prices.size() - 1; i++)
//     //     {
//     //         if (prices[i] < prices[i + 1])
//     //             profit += prices[i + 1] - prices[i];
//     //     }
//     //     return profit;
//     // }
// };
//https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/submissions/525906601/
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        int negativeNumber = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                negativeNumber++;
        }

        std::sort(nums.begin(), nums.end());
        int maxSum = 0;

        if (negativeNumber >= k)
        {
            int j = 0;
            while (j < k)
            {
                nums[j] = -nums[j];
                j++;
            }
            for (int i = 0; i < nums.size(); ++i)
            {
                maxSum += nums[i];
            }
        }
        else
        {
            // 先将所有的负数变成整数
            int j = 0;
            while (j < negativeNumber)
            {
                nums[j] = -nums[j];
                j++;
            }

            // 计算 剩余的个数
            k = k - negativeNumber;
            std::sort(nums.begin(), nums.end());

            if (k % 2 == 1)
            {
                nums[0] = -nums[0];
            }
            for (int i = 0; i < nums.size(); ++i)
            {
                maxSum  += nums[i];
            }
        }
        return maxSum;
    }
};

int main()
{
    vector<int> v = {7, 1, 5, 3, 6, 4};
    // std::cout << Solution().maxProfit(v) << std::endl;
    return 0;
}