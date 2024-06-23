//https://leetcode.cn/problems/unique-paths/
#include <vector>
//class Solution {
//public:
//    // 这是一个尝试,startx, starty 是我们当前所在的位置
//    //  aimx, aimy 是我们的目标
//    // 返回值是我们的路径数
//    int process1(int startx, int starty, int aimx, int aimy)
//    {
//        if (startx > aimx)
//            return 0;
//        if (starty > aimy)
//            return 0;
//        if (startx == aimx && starty == aimy)
//            return 1;
//        int p1 = process1(startx + 1, starty, aimx, aimy);
//        int p2 = process1(startx, starty + 1, aimx, aimy);
//        return p1 + p2;
//    }
//    // startx[0, m] starty[0, n]
//    int process2(int m, int n)
//    {
//        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
//        dp[m - 1][n - 1] = 1;
//        for (int i = m - 1; i >= 0; i--)
//        {
//            for (int j = n - 1; j >= 0; j--)
//            {
//                if (i == m - 1 && j == n - 1)
//                    continue;
//                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
//            }
//        }
//        return dp[0][0];
//    }
//    int uniquePaths(int m, int n) {
//        //return process1(0, 0, m - 1, n - 1);
//        return process2(m, n);
//    }
//};

// https://leetcode.cn/problems/count-complete-tree-nodes/submissions/
//struct TreeNode {
//    int val;    
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//public:
//    int _countNodes(TreeNode* root) {
//        if (root == nullptr)
//            return 0;
//        return 1 + _countNodes(root->left) + _countNodes(root->right);
//    }
//
//    int countNodes(TreeNode* root) {
//        return _countNodes(root);
//    }
//};
using namespace std;
//https://leetcode.cn/problems/combination-sum/submissions/
//class Solution {
//public:
//    void backtraing(vector<vector<int>>& result, vector<int>& candidates, vector<int>& v, int sum, int index, int target)
//    {
//        if (sum >= target)
//        {
//            if (sum == target)
//                result.push_back(v);
//            return;
//        }
//
//        for (int i = index; i < candidates.size(); i++)
//        {
//            sum += candidates[i];
//            v.push_back(candidates[i]);
//            backtraing(result, candidates, v, sum, i, target);
//            ;
//            sum -= candidates[i];
//            v.pop_back();
//        }
//    }
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<int>> result;
//        vector<int> v;
//        int sum = 0;
//        backtraing(result, candidates, v, sum, 0, target);
//        return result;
//
//    }
//};
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/submissions/
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if (prices.empty())
//            return 0;
//        int result = 0;
//        for (int i = 1; i < prices.size(); i++)
//        {
//            int val = prices[i] - prices[i - 1];
//            if (val > 0)
//                result += val;
//        }
//        return result;
//    }
//};
#include <stack>

// https://leetcode.cn/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        std::stack<int> s;
        int result = 0;
        for (size_t i = 0; i < height.size(); i++)
        {
            while (!s.empty() && height[i] > height[s.top()]) {
                int j = s.top();
                s.pop();
                if (!s.empty())
                {
                    int a = i-s.top()-1;
                    int b = std::min(height[i], height[s.top()]) - height[j];
                    result += (a * b);
                }
            }
            s.push(i);
        }
        return result;
    }
};