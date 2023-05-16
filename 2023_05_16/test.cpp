#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/fibonacci-number/submissions/
class Solution {
public:
    int process(int n)
    {
        if (n <= 1)
            return n;
        return process(n - 1) + process(n - 2);
    }
    // n--> [0, n]
    int dp(int n)
    {
        vector<int> result(n + 1, 0);
        result[0] = 0;
        result[1] = 1;
        for (int i = 2; i <= n; i++)
            result[i] = result[i - 1] + result[i - 2];
        return result[n];
    }
    int fib(int n) {
        if (n <= 1)
            return n;
        return dp(n);
    }
};

//https://leetcode.cn/problems/assign-cookies/
//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        if (g.empty() || s.empty())
//            return 0;
//        std::sort(g.begin(), g.end());
//        std::sort(s.begin(), s.end());
//        int i = s.size() - 1;
//        int j = g.size() - 1;
//        int count = 0;
//        while(i >= 0 && j>=0)
//        {
//            // 那我们的食物和胃口最大的孩子比较
//            if (s[i] >= g[j])
//            {
//                i--;
//                j--;
//                count++;
//            }
//            else
//            {
//                j--;
//            }
//        }
//        return count;
//    }
//};

// https://leetcode.cn/problems/combinations/submissions/
//class Solution {
//public:
//    void backtracking(vector<int>& path, vector<vector<int>>& result,
//        int n, int k, int index)
//    {
//        // 什么时候终止
//        if (path.size() == k)
//        {
//            result.push_back(path);
//            return;
//        }
//        for (size_t i = index; i <= n; i++)
//        {
//            // 这里做一个剪枝操作
//            if (path.size() + 1 + n - index < k)
//                continue;
//            path.push_back(i);
//            backtracking(path, result, n, k, i + 1);
//            path.pop_back();
//        }
//    }
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int>> result;
//        if (n <= 0 || k <= 0 || k > n)
//            return result;
//        vector<int> path;
//        backtracking(path, result, n, k, 0);
//        return result;
//    }
//};

//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};

// https://leetcode.cn/problems/invert-binary-tree/submissions/
//class Solution {
//
//public:
//    void _invertTree(TreeNode* root) {
//        if (root == nullptr)
//            return;
//        std::swap(root->left, root->right);
//        _invertTree(root->left);
//        _invertTree(root->right);
//    }
//    TreeNode* invertTree(TreeNode* root) {
//        if (root == nullptr)
//            return nullptr;
//        _invertTree(root);
//        return root;
//    }
//};