#include <iostream>
#include <vector>
using namespace std;

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
// https://leetcode.cn/problems/combination-sum-iii/submissions/
class Solution {
public:
	struct Node
	{
		std::vector<int> v;
		int sum = 0;
	};
	void backtarning(vector<vector<int>>& result,
		Node& node, int index, int k, int n)
	{
		if (node.v.size() == k && node.sum == n)
		{
			result.push_back(node.v);
			return;
		}

		for (int i = index; i < 10; i++)
		{
			// 这里我们就是裁了一部分,也可以看  我们v的数量和剩余的放在一起也有可能达不到k
			/*if (node.sum > n
				|| node.v.size() >= k
				|| (node.v.size() + 10 - index) < k)
			{
				continue;
			}*/
			if (node.sum > n || node.v.size() >= k)
				continue;
			node.v.push_back(i);
			node.sum += i;
			backtarning(result, node, i + 1, k, n);
			node.v.pop_back();
			node.sum -= i;
		}
	}

    vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		if (k <= 0 || n <= 0)
			return result;
		Node node;
		int index = 1;
		backtarning(result, node, index, k, n);
		return result;
    }
};