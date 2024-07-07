#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    vector<vector<int>> largeGroupPositions(string s) {
//        std::vector<std::vector<int>> result;
//        if (s.empty())
//            return result;
//        int left = 0;
//        int right = 1;
//        while (right < s.size())
//        {
//            while (right < s.size() && s[right] == s[left])
//            {
//                right++;
//            }
//
//            int ret = right - left;
//            if (ret >= 3)
//            {
//                std::vector<int> v;
//                v.push_back(left);
//                v.push_back(right - 1);
//                result.push_back(std::move(v));
//            }
//            left = right;
//            right = right + 1;
//
//        }
//        return result;
//    }
//};




int main()
{
    std::string str = "abbxxxxzzy";
    Solution().largeGroupPositions(str);
    return 0;
}








//class Solution
//{
//public:
//	int dominantIndex(vector<int>& nums)
//	{
//
//		if (nums.size() < 2)
//			return -1;
//		std::unordered_map<int, int> m;
//		for (size_t i = 0; i < nums.size(); i++)
//		{
//			m[nums[i]] = i;
//		}
//		std::sort(nums.begin(), nums.end(), greater<int>());
//		int a = nums[0];
//		int b = nums[1];
//		if (a == b || a < 2 * b)
//			return -1;
//
//		return m[a];
//	}
//};

//class Solution
//{
//public:
//	int pivotIndex(vector<int>& nums)
//	{
//		if (nums.empty())
//			return -1;
//		int sum = 0;
//		for (auto& e : nums)
//			sum += e;
//
//		int leftSum = 0;
//		int rightSum = sum;
//		int index = 0;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			// 求 右侧和
//			rightSum = rightSum - nums[i];
//			// 求左侧和
//			if (0 != i)
//				leftSum = leftSum + nums[i - 1];
//			if (rightSum == leftSum)
//				return i;
//		}
//		return -1;
//	}
//};
//class Solution {
//public:
//    bool isOneBitCharacter(vector<int>& bits) {
//        if (bits.empty())
//            return true;
//
//        int start = 0;
//        while (start < bits.size() - 1)
//        {
//            if (bits[start] == 0)
//            {
//                start += 1;
//            }
//            else if (bits[start] == 1)
//            {
//                start += 2;
//            }
//        }
//
//        return start == bits.size() - 1;
//
//    }
//};