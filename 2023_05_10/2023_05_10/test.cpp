#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


// https://leetcode.cn/problems/two-sum/submissions/
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target) {
//		std::vector<int> result(2, -1);
//		if (nums.empty())
//			return result;
//		std::unordered_map<int, int> m;
//		for (size_t i = 0; i < nums.size(); i++)
//		{
//			int ret = target - nums[i];
//			m[ret] = i;
//		}
//
//		//遍历整个数组
//		for (size_t  i = 0; i < nums.size(); i++)
//		{
//			auto iter = m.find(nums[i]);
//			if (iter == m.end() || i == iter->second)
//				continue;
//			result[0] = i;
//			result[1] = iter->second;
//			break;
//		}
//		return result;
//	}
//};
// https://leetcode.cn/problems/4sum-ii/
//class Solution {
//public:
//	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//		if (nums1.empty() || nums2.empty() || nums3.empty() || nums4.empty())
//			return 0;
//		std::unordered_map<int, int> m;
//		for (size_t i = 0; i < nums1.size(); i++)
//		{
//			for (size_t j = 0; j < nums2.size(); j++)
//			{
//				m[nums1[i] + nums2[j]]++;
//			}
//		}
//		int count = 0;
//		for (size_t i = 0; i < nums3.size(); i++)
//		{
//			for (size_t j = 0; j < nums4.size(); j++)
//			{
//				int sum = - nums3[i] - nums4[j];
//				auto iter = m.find(sum);
//				if (iter != m.end())
//					count += iter->second;
//			}
//		}
//		return count;
//	}
//};
// https://leetcode.cn/problems/3sum/
//#include <iostream>
//class Solution {
//public:
//	vector<vector<int>> threeSum(vector<int>& nums) {
		//std::vector<std::vector<int>> result;
		//std::sort(nums.begin(), nums.end());

		////std::cout << "2" << std::endl;

		//for (size_t i = 0; i < nums.size(); i++)
		//{
		//	if (nums[i] > 0)
		//		break;
		//	if (i > 0 && nums[i] == nums[i - 1])
		//		continue;

		//	int left = i + 1;
		//	int right = nums.size() - 1;
		//	while (left < right)
		//	{
		//		int sum = nums[i] + nums[left] + nums[right];
		//		if (sum > 0)
		//		{
		//			right--;
		//		}
		//		else if (sum < 0)
		//		{
		//			left++;
		//		}
		//		else
		//		{
		//			// 这里也要去重
		//			std::vector<int> v;
		//			if (result.empty())
		//			{
		//				v.push_back(nums[i]);
		//				v.push_back(nums[left]);
		//				v.push_back(nums[right]);
		//			}
		//			else
		//			{
		//				const auto& it = result.back();
		//				if (it[1] == nums[left] && it[2] == nums[right])
		//				{
		//					left++;

		//					continue;
		//				}
		//				else
		//				{
		//					v.push_back(nums[i]);
		//					v.push_back(nums[left]);
		//					v.push_back(nums[right]);
		//				}
		//			}
		//			std::sort(v.begin(), v.end());
		//			result.push_back(std::move(v));
		//			left++;
		//		}
		//	}
		//}
		//return result;
//	}
//};
//
//int main()
//{
//	//std::vector<int> v = { -1, 0, 1, 2, -1, -4 };
//	std::vector<int> v = { 0,0,0,0 };
//	Solution().threeSum(v);
//	return 0;
//}


class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		std::vector<std::vector<int>> result;
		std::sort(nums.begin(), nums.end());

		for (int k = 0; k < nums.size(); k++)
		{
			if (nums[k] >target && nums[k] > 0)
				continue;
			if (k > 0 && nums[k] == nums[k - 1])
				continue;
			for (size_t i = k+1; i < nums.size(); i++)
			{
				if (nums[k] + nums[i] > target)
					break;
				if (i > k + 1 && nums[i] == nums[i - 1])
					continue;
			
				int left = i + 1;
				int right = nums.size() - 1;
				while (left < right)
				{
					int sum = nums[k] + nums[i] + nums[left] + nums[right];
					if (sum > target)
					{
						right--;
					}
					else if (sum < target)
					{
						left++;
					}
					else
					{
						// 这里也要去重
						std::vector<int> v;
						if (result.empty())
						{
							v.push_back(nums[k]);
							v.push_back(nums[i]);
							v.push_back(nums[left]);
							v.push_back(nums[right]);
						}
						else
						{
							const auto& it = result.back();
							if (it[1] == nums[left] && it[2] == nums[right])
							{
								left++;
								continue;
							}
							else
							{
								v.push_back(nums[k]);
								v.push_back(nums[i]);
								v.push_back(nums[left]);
								v.push_back(nums[right]);
							}
						}
						std::sort(v.begin(), v.end());
						result.push_back(std::move(v));
						left++;
					}
				}
			}
		}
		return result;
	}
};
