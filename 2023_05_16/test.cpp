#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/combinations/submissions/
class Solution {
public:
    void backtracking(vector<int>& path, vector<vector<int>>& result,
        int n, int k, int index)
    {
        // 什么时候终止
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (size_t i = index; i <= n; i++)
        {
            // 这里做一个剪枝操作
            if (path.size() + 1 + n - index < k)
                continue;
            path.push_back(i);
            backtracking(path, result, n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (n <= 0 || k <= 0 || k > n)
            return result;
        vector<int> path;
        backtracking(path, result, n, k, 0);
        return result;
    }
};





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