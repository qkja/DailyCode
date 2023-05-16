#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// https://leetcode.cn/problems/invert-binary-tree/submissions/
class Solution {

public:
    void _invertTree(TreeNode* root) {
        if (root == nullptr)
            return;
        std::swap(root->left, root->right);
        _invertTree(root->left);
        _invertTree(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        _invertTree(root);
        return root;
    }
};