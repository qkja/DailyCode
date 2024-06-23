#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    //https://leetcode.cn/problems/minimum-size-subarray-sum/
    int minSubArrayLen(int target, vector<int>& nums) {
        // 1. ����forѭ��
        int sum = 0;
        int result = INT_MAX;
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            sum += nums[j]; // �ռ���
            while (sum >= target)
            {
                result = std::min(j - i + 1, result);
                sum -= nums[i++];
            }
        }
        return  result == INT_MAX ? 0 : result;
    }
};