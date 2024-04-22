#include <vector>
#include <iostream>
using namespace std;
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/submissions/525879054/
class Solution
{
public:
    // 方式1: 双指针
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int left = 0; left < prices.size();)
        {
            int right = left + 1;
            while (right < prices.size() && prices[right] > prices[right - 1])
            {
                ++right;
            }

            // 收获收益
            if (right <= prices.size())
            {
                profit += prices[right - 1] - prices[left];
            }
            // 更新指针
            left = right;
        }
        return profit;
    }
    // 方式2: 优化思路
    // int maxProfit(vector<int> &prices)
    // {
    //     int profit = 0;
    //     for (int i = 0; i < prices.size() - 1; i++)
    //     {
    //         if (prices[i] < prices[i + 1])
    //             profit += prices[i + 1] - prices[i];
    //     }
    //     return profit;
    // }
};

int main()
{
    vector<int> v = {7, 1, 5, 3, 6, 4};
    std::cout << Solution().maxProfit(v) << std::endl;
    return 0;
}