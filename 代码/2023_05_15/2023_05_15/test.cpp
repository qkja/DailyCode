#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            TreeNode* top = s.top();
            if (top->right == nullptr
                || top->right == prev)
            {
                v.push_back(top->val);
                s.pop();
                prev = top;
            }
            else
            {
                cur = top->right;
            }
        }
        return v;
    }
};



//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> v;
//        stack<TreeNode*> s;
//        TreeNode* cur = root;
//        while (cur || !s.empty())
//        {
//            while (cur)
//            {
//                s.push(cur);
//                cur = cur->left;
//            }
//            TreeNode* top = s.top();
//            v.push_back(top->val);
//            s.pop();
//            cur = top->right;
//        }
//        return v;
//    }
//};

//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> v;
//        stack<TreeNode*> s;
//        TreeNode* cur = root;
//        while (cur || !s.empty())
//        {
//            while (cur)
//            {
//                v.push_back(cur->val);
//                s.push(cur);
//                cur = cur->left;
//            }
//            TreeNode* top = s.top();
//            s.pop();
//            cur = top->right;
//        }
//        return v;
//    }
//};


//class Solution {
//public:
//    int find_index(vector<int>& inorder, int target)
//    {
//        for (size_t i = 0; i < inorder.size(); i++)
//        {
//            if (target == inorder[i])
//                return i;
//        }
//        return -1;
//    }
//    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& index, int left, int right)
//    {
//        if (index < 0)
//            return nullptr;
//        if (left > right)
//            return nullptr;
//        TreeNode* node = new TreeNode(postorder[index]);
//        --index;
//
//        int i = find_index(inorder, node->val);
//        node->right = _buildTree(inorder, postorder, index, i + 1, right);
//        node->left = _buildTree(inorder, postorder, index, left, i - 1);
//        return node;
//    }
//    // 
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//        int index = inorder.size() - 1;
//        return  _buildTree(inorder, postorder, index, 0, inorder.size() - 1);
//    }
//};

//class Solution {
//public:
//    int find_index(vector<int>& inorder, int target)
//    {
//        for (size_t i = 0; i < inorder.size(); i++)
//        {
//            if (target == inorder[i])
//                return i;
//        }
//        return -1;
//    }
//    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& index, int left, int right)
//    {
//        if (index >= preorder.size())
//            return nullptr;
//        if (left > right)
//            return nullptr;
//        TreeNode* node = new TreeNode(preorder[index]);
//        ++index;
//
//        int i = find_index(inorder, node->val);
//
//        node->left = _buildTree(preorder, inorder, index, left, i - 1);
//        node->right = _buildTree(preorder, inorder, index, i + 1, right);
//        return node;
//    }
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
//    {
//        int index = 0;
//        return  _buildTree(preorder, inorder, index, 0, preorder.size() - 1);
//    }
//};


int main()
{

    return 0;
}


//struct TreeNode 
//{
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//	TreeNode(int x) :
//		val(x), left(NULL), right(NULL) {
//	}
//};
//class Solution {
//public:
//	void InOrderConvert(TreeNode* cur, TreeNode*& prev)
//	{
//		if (cur == nullptr)
//			return;
//		InOrderConvert(cur->left, prev);
//		cur->left = prev;
//		if (prev)
//			prev->right = cur;
//		prev = cur; // 注意这里要给一个引用
//		InOrderConvert(cur->right, prev);
//	}
//	TreeNode* Convert(TreeNode* pRootOfTree) {
//		if (pRootOfTree == nullptr)
//			return nullptr;
//		TreeNode* prev = nullptr;
//		InOrderConvert(pRootOfTree, prev);
//
//		// 这里遍历数组
//		TreeNode* head = pRootOfTree;
//		while (head->left)
//		{
//			head = head->left;
//		}
//		return head;
//	}
//};