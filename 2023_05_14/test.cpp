#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};












// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/submissions/
//class Solution {
//public:
//    bool isInTree(TreeNode* tree, TreeNode* val)
//    {
//        if (tree == nullptr)
//            return false;
//        if (tree == val)
//            return true;
//        return isInTree(tree->left, val) || isInTree(tree->right, val);
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == nullptr)
//            return nullptr;
//        if (root == p || q == root)
//            return root;
//        bool pLeft = isInTree(root->left, p);
//        bool pRight = !pLeft;
//        bool qLeft = isInTree(root->left, q);
//        bool qRight = !qLeft;
//
//        if ((pLeft && qRight) || (pRight && qLeft))
//        {
//            return root;
//        }
//        else if (pLeft && qLeft)
//        {
//            return lowestCommonAncestor(root->left, p, q);
//        }
//        else if (pRight && qRight)
//        {
//            return lowestCommonAncestor(root->right, p, q);
//        }
//        else
//        {
//            return nullptr;
//        }
//
//    }
//};
//class Solution {
//public:
//    bool findPath(TreeNode* root, TreeNode* x, std::stack<TreeNode*>& s)
//    {
//        if (root == nullptr)
//            return false;
//        s.push(root);
//        if (x == root)
//            return true;
//        if (findPath(root->left, x, s))
//            return true;
//        if (findPath(root->right, x, s))
//            return true;
//
//        s.pop();
//        return false;
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == nullptr)
//            return nullptr;
//        std::stack<TreeNode*> s1;
//        std::stack<TreeNode*> s2;
//        findPath(root, p, s1);
//        findPath(root, q, s2);
//        if (s1.size() < s2.size())
//        {
//            std::swap(s1, s2);
//        }
//        // 
//        while (!s1.empty() && !s2.empty())
//        {
//            if (s1.size() == s2.size())
//            {
//                if (s1.top() == s2.top())
//                    return s1.top();
//                s1.pop();
//                s2.pop();
//            }
//            else
//            {
//                s1.pop();
//            }
//        }
//        return nullptr;
//    }
//};