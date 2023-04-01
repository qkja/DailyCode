#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return -1;
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        int maxSum = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > maxSum)
                maxSum = dp[i];
        }
        
        return  maxSum;
    }
};
//class Solution {
//public:
//    string convert(string s, int numRows) {
//        int len = s.size();
//        if (numRows == 1 || numRows >= len)
//        {
//            return s;
//        }
//
//        std::string result;
//        result.resize(len);
//        int t = 2 * numRows - 2; // 这里是周期
//        int index = 0;
//        for (int i = 0; i < numRows; i++)
//        {
//            // i 当前来到第i 行
//            for (int j = i, nextColTop = t; j < len;  nextColTop += t,j+= t)
//            {
//                result[index++] = s[j];
//                if (i >= 1 && i <= numRows - 2 && nextColTop - i < len)
//                {
//                    result[index++] = s[nextColTop-i];
//                }
//            }
//        }
//        return result;
//    }
//};