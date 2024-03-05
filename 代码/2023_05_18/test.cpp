#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// https://leetcode.cn/problems/maximum-depth-of-binary-tree/submissions/
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
//    int _maxDepth(TreeNode* root) {
//        if (root == nullptr)
//            return 0;
//        return 1 + std::max(_maxDepth(root->right), _maxDepth(root->left));
//    }
//    int maxDepth(TreeNode* root) {
//        if (root == nullptr)
//            return 0;
//        return _maxDepth(root);
//    }
//};
// https://leetcode.cn/problems/minimum-depth-of-binary-tree/submissions/
//class Solution {
//public:
//    int minDepth(TreeNode* root) {
//        int left = 0;
//        int right = 0;
//        if (root == NULL)
//        {
//            return 0;
//        }
//        if (root->left == NULL && root->right == NULL)
//        {
//            return 1;
//        }
//        if (root->left == NULL)
//        {
//            return 1 + minDepth(root->right);
//        }
//        if (root->right == NULL)
//        {
//            return 1 + minDepth(root->left);
//        }
//        left = minDepth(root->left);
//        right = minDepth(root->right);
//        return left < right ? left + 1 : right + 1;
//    }
//};

//https://leetcode.cn/problems/letter-combinations-of-a-phone-number/submissions/
//class Solution {
//public:
//
//    void backtraing(const vector<string>& v, vector<string>& result,
//        string& digits, string& str, int index)
//    {
//        if (str.size() == digits.size())
//        {
//            result.push_back(str);
//            return;
//        }
//        for (size_t i = index; i < digits.size(); i++)
//        {
//            for (int j = 0; j < v[digits[i] - '0'].size(); j++) {
//                str.push_back(v[digits[i] - '0'][j]);
//                backtraing(v, result, digits, str, i + 1);
//                str.pop_back();
//            }
//        }
//    }
//    vector<string> letterCombinations(string digits) {
//
//        vector<string> v = { "","","abc","def",
//        "ghi","jkl","mno","pqrs","tuv","wxyz" };
//        /*  int n = 0;
//          for (auto& e : v)
//          {
//              cout << n++ << " " << e << endl;
//          }*/
//        vector<string> result;
//        if (digits.empty())
//            return result;
//        string str;
//
//        backtraing(v, result, digits, str, 0);
//
//        return result;
//    }
//};
// https://leetcode.cn/problems/maximum-subarray/
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//        int result = nums[0];
//        int sum = nums[0];
//        for (size_t i = 1; i < nums.size(); i++)
//        {
//            if (sum < 0)
//            {
//                sum = nums[i];
//            }
//            else
//            {
//                sum += nums[i];
//            }
//            if (sum > result)
//                result = sum;
//        }
//        return result;
//    }
//};
// https://leetcode.cn/problems/min-cost-climbing-stairs/
//class Solution {
//public:
//    // index 表示我们从当前位置开始,
//    // 返回值 我们所需要的代价
//    int process(int index, vector<int>& cost) {
//        if (index >= cost.size())
//            return 0;
//        int p1 = cost[index] + process(index + 1, cost);
//        int p2 = cost[index] + process(index + 2, cost);
//        return min(p1, p2);
//    }
//    // index[0, cost.size()+1]
//    //
//    int dp(vector<int>& cost)
//    {
//        vector<int> v(cost.size()+2, 0);
//        for (int i = cost.size() - 1; i >= 0; i--)
//        {
//            v[i] = cost[i] + std::min(v[i + 1], v[i + 2]);
//        }
//        return std::min(v[1], v[0]);
//    }
//    int minCostClimbingStairs(vector<int>& cost) {
//        if (cost.empty())
//            return 0;
//        
//        return dp(cost);
//    }
//    /*int minCostClimbingStairs(vector<int>& cost) {
//        if (cost.empty())
//            return 0;
//        int p1 = process(0, cost);
//        int p2 = process(1, cost);
//        return min(p1, p2);
//    }*/
//};



// https://leetcode.cn/problems/next-greater-element-ii/
//#include <stack>
//class Solution {
//public:
//    vector<int> nextGreaterElements(vector<int>& nums) {
//        vector<int> result;
//        if (nums.empty())
//            return result;
//        stack<int> s;
//        result.resize(nums.size(), -1);
//        for (int i = 0; i < nums.size(); i++)
//        {
//            while (!s.empty() && nums[i] > nums[s.top()])
//            {
//                result[s.top()] = nums[i];
//                s.pop();
//            }
//            s.push(i);
//        }
//        for (int i = 0; i < nums.size(); i++)
//        {
//            while (!s.empty() && nums[i] > nums[s.top()])
//            {
//                result[s.top()] = nums[i];
//                s.pop();
//            }
//            s.push(i);
//        }
//        return result;
//    }
//};
