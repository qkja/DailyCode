#include <vector>
#include <stack>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// https://leetcode.cn/problems/binary-tree-level-order-traversal/
class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (root == nullptr)
            return result;
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int size = q.size();
            std::vector<int> v;
            while (size--)
            {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            result.push_back(v);
        }
        return result;
    }
};

class Solution {
public:
    void postorderTraversalChild(TreeNode* root, std::vector<int>& result)
    {
        if (root == nullptr)
            return;
        postorderTraversalChild(root->left, result);
        postorderTraversalChild(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        postorderTraversalChild(root, result);
        return result;
    }
};

//class Solution {
//public:
//    // µÝ¹é
//    void inorderTraversalChild(TreeNode* root, std::vector<int>& result)
//    {
//        if (root == nullptr)
//            return;
//        inorderTraversalChild(root->left, result);
//        result.push_back(root->val);
//        inorderTraversalChild(root->right, result);
//    }
//    // ·ÇµÝ¹é
//    void inorderTraversalChildR(TreeNode* root, std::vector<int>& result)
//    {
//        if (root == nullptr)
//            return;
//        std::stack<TreeNode*> s;
//        s.push(root);
//        while (true)
//        {
//            TreeNode* node = 
//        }
//    }
//    vector<int> inorderTraversal(TreeNode* root) {
//        std::vector<int> result;
//        //inorderTraversalChild(root, result);
//        inorderTraversalChildR(root, result);
//        return result;
//    }
//};
//https://leetcode.cn/problems/construct-string-from-binary-tree/submissions/
//class Solution {
//public:
//    void tree2strChild(TreeNode* root, std::string& result)
//    {
//        if (root == nullptr)
//            return;
//        result += std::to_string(root->val);
//        if (root->left)
//        {
//
//            result += '(';
//            tree2strChild(root->left, result);
//            result += ')';
//
//        }
//        else
//        {
//            if (root->right)
//            result += "()";
//        }
//        if (root->right)
//        {
//            result += '(';
//            tree2strChild(root->right, result);
//            result += ')';
//        }
//    }
//
//    string tree2str(TreeNode* root) {
//        std::string result;
//        tree2strChild(root, result);
//        return result;
//    }
//};