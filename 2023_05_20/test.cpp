#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

// https://leetcode.cn/problems/largest-rectangle-in-histogram/submissions/
//class Solution {
//public:
//    int largestRectangleArea(vector<int>& heights) {
//        if (heights.empty())
//            return 0;
//        int result = 0;
//        heights.push_back(0);
//        heights.insert(heights.begin(), 1);
//        stack<int> s;
//        s.push(0);
//        for (int i = 1; i < heights.size(); i++)
//        {
//            while (!s.empty()&& heights[i] < heights[s.top()])
//            {
//                int mid = s.top();
//                s.pop();
//                if (!s.empty())
//                {
//                    int left = s.top();
//                    int right = i;
//                    int h = heights[mid];
//                    int w = right - left - 1;
//                    result = std::max(h * w, result);
//                }
//            }
//            s.push(i);
//        }
//        return result;
//    }
//};

// https://leetcode.cn/problems/balanced-binary-tree/
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};

//class Solution {
//public:
//    int _isBalanced(TreeNode* root) {
//        if (root == nullptr)
//            return 0;
//        int left = _isBalanced(root->left);
//        int right = _isBalanced(root->right);
//        if(left >=0 && right >=0 && std::abs(left-right) < 2)
//        {
//            int max = left > right ? left : right;
//            return max + 1;
//        }
//        else
//        {
//            return -1;
//        }
//    }
//
//    bool isBalanced(TreeNode* root) {
//        return _isBalanced(root) >= 0;
//    }
//};
// https://leetcode.cn/problems/combination-sum-ii/
class Solution {
public:
    void backtraing(vector<vector<int>>& result, vector<int>& v, 
        int sum, int target, int index,
        vector<int>& candidates, vector<bool>& used)
    {
        if (sum > target)
            return;
        if (sum == target)
        {
            result.push_back(v);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (i > 0 && candidates[i] == candidates[i - 1]
                && used[i-1] == false)
                continue;
            v.push_back(candidates[i]);
            used[i] = true;
            backtraing(result, v, sum + candidates[i], target, i + 1, candidates, used);
            v.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty())
            return result;
        std::sort(candidates.begin(), candidates.end());

        vector<bool> used(candidates.size(), false);
        vector<int> v;
        backtraing(result, v, 0, target, 0, candidates, used);
        return result;
    }
};



// https://leetcode.cn/problems/jump-game/
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int cover = 0;
//        for (size_t i = 0; i <= cover; i++)
//        {
//            int ret = i + nums[i];
//            cover = std::max(cover, ret);
//            if (cover >= nums.size() - 1)
//                return true;
//        }
//        return false;
//    }
//};