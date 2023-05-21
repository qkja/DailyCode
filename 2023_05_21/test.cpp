#include <vector>
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

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr)
            return result;
        std::queue<TreeNode*> q;
        q.push(root);
        while (true)
        {
            TreeNode* top = q.front(); 
            if (top == nullptr)
            {
                result.push_back("null");
            }
            else
            {
                result.push_back(std::to_string(top->val));
            }

            q.pop();
            if (top->left && top->right)
            {
                q.push(top->left); top->lefttop->left
            }
        }
    }
};