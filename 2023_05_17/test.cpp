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