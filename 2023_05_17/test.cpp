#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//https://leetcode.cn/problems/symmetric-tree/submissions/
//class Solution {
//public:
//    bool _isSymmetric(TreeNode* n1, TreeNode* n2) 
//    {
//        if (n1 == nullptr || n2 == nullptr)
//        {
//            if (n1 == nullptr && n2 == nullptr)
//                return true;
//            else
//                return false;
//        }
//    
//        return n1->val == n2->val
//            && _isSymmetric(n1->left, n2->right)
//            && _isSymmetric(n1->right, n2->left);
//    }
//
//    bool isSymmetric(TreeNode* root) {
//        if (root == nullptr)
//            return false;
//        return _isSymmetric(root->left, root->right);
//    }
//};
// https://leetcode.cn/problems/combination-sum-iii/submissions/
//class Solution {
//public:
//	struct Node
//	{
//		std::vector<int> v;
//		int sum = 0;
//	};
//	void backtarning(vector<vector<int>>& result,
//		Node& node, int index, int k, int n)
//	{
//		if (node.v.size() == k && node.sum == n)
//		{
//			result.push_back(node.v);
//			return;
//		}
//
//		for (int i = index; i < 10; i++)
//		{
//			// 这里我们就是裁了一部分,也可以看  我们v的数量和剩余的放在一起也有可能达不到k
//			/*if (node.sum > n
//				|| node.v.size() >= k
//				|| (node.v.size() + 10 - index) < k)
//			{
//				continue;
//			}*/
//			if (node.sum > n || node.v.size() >= k)
//				continue;
//			node.v.push_back(i);
//			node.sum += i;
//			backtarning(result, node, i + 1, k, n);
//			node.v.pop_back();
//			node.sum -= i;
//		}
//	}
//
//    vector<vector<int>> combinationSum3(int k, int n) {
//		vector<vector<int>> result;
//		if (k <= 0 || n <= 0)
//			return result;
//		Node node;
//		int index = 1;
//		backtarning(result, node, index, k, n);
//		return result;
//    }
//};
//
// https://leetcode.cn/problems/wiggle-subsequence/submissions/
//class Solution {
//public:
//    int wiggleMaxLength(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//        if (nums.size() == 1)
//            return 1;
//        int prediff = 0;
//        int curdiff = 0;
//        int result = 1;
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            curdiff = nums[i + 1] - nums[i];
//            if ((curdiff > 0 && prediff <= 0)
//                || (curdiff < 0 && prediff >= 0))
//            {
//                result++;
//                prediff = curdiff;
//            }
//        }
//        return result;
//    }
//};
// https://leetcode.cn/problems/next-greater-element-i/submissions/
//class Solution {
//public:
//    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> v;
//        if (nums1.empty() || nums2.empty())
//            return v;
//
//        v.resize(nums1.size(), -1);
//        unordered_map<int, int> map;
//        for (size_t i = 0; i < nums1.size(); i++)
//        {
//            map[nums1[i]] = i;
//        }
//        stack<int> s;
//
//        for (size_t i = 0; i < nums2.size(); i++)
//        {
//            if (s.empty())
//            {
//                s.push(i);
//            }
//            else
//            {
//                while (!s.empty() && nums2[i] > nums2[s.top()])
//                {
//                    int val = nums2[s.top()];
//                    if (map.find(val) != map.end())
//                        v[map.find(val)->second] = nums2[i];
//                    s.pop();
//                }
//                s.push(i);
//            }
//        }
//        return v;
//    }
//};
// https://leetcode.cn/problems/climbing-stairs/
//class Solution {
//public:
//    /// <summary>
//    /// 
//    /// </summary>
//    /// <param name="index">当前位置</param>
//    /// <param name="n"> 我们要趴的位置</param>
//    /// <returns>我们的方法数</returns>
//    int process(int index, int n)
//    {
//        if (index > n)
//            return 0;
//        if (index = n)
//            return 1;
//        return process(index + 1, n) + process(index + 2, n);
//    }
//
//    // index[0,n]
//    int dp(int n)
//    {
//        vector<int> result(n + 2, 0);
//        result[n] = 1;
//        for (int i = n - 1; i >= 0; i--)
//        {
//            result[i] = result[i + 1] + result[i + 2];
//        }
//        return result[0];
//    }
//    int climbStairs(int n) {
//        if (n <= 0)
//            return 0;
//        return dp(n);
//    }
//};