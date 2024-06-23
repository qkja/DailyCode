#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return nums[0];
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = std::max(std::max(dp[i - 1], nums[i]), dp[i - 2] + nums[i]);
        }
        return dp.back();
    }
};






//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        if (nums.empty())
//            return -1;
//        int left = nums[0];
//        int right = 0;
//        int maxSum = left;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            if (left < 0)
//            {
//                right = nums[i];
//            }
//            else
//            {
//                right = nums[i] + left;
//            }
//            if (right > maxSum)
//                maxSum = right;
//            left = right;
//        }
//
//        return  maxSum;
//    }
//};

//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        if (nums.empty())
//            return -1;
//        std::vector<int> dp(nums.size());
//        dp[0] = nums[0];
//        int maxSum = dp[0];
//        for (int i = 1; i < nums.size(); i++)
//        {
//            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
//            if (dp[i] > maxSum)
//                maxSum = dp[i];
//        }
//        
//        return  maxSum;
//    }
//};
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