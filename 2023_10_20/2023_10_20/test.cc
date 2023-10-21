// struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(nullptr) {}
// };
//
// class Solution {
// public:
//	/**
//	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//	*
//	*
//	* @param head ListNode��
//	* @param m int����
//	* @param n int����
//	* @return ListNode��
//	*/
//	ListNode* reverseBetween(ListNode* head, int m, int n) {
//		// write code here
//		if (head == nullptr || n < 1)
//		{
//			return nullptr;
//		}
//
//		int len = n - m + 1; // ����len���ڵ�
//		ListNode* prev = nullptr;
//		ListNode* cur = head;
//		--m;
//		while (m--)
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//
//		ListNode* old_prev = prev;
//		ListNode* old_tail = cur;
//
//		prev = nullptr;
//
//		while (len--)
//		{
//			ListNode* next = cur->next;
//			cur->next = prev;
//			prev = cur;
//			cur = next;
//		}
//		if (old_prev == nullptr)
//		{
//			old_tail->next = cur;
//			return prev;
//		}
//
//		// �����������
//		old_prev->next = prev;
//		if (old_tail)
//			old_tail->next = cur;
//
//		return head;
//	}
// };
// struct ListNode
// {
// 	int val;
// 	ListNode *next;
// 	ListNode() : val(0), next(nullptr) {}
// 	ListNode(int x) : val(x), next(nullptr) {}
// 	ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// class Solution
// {
// public:
// 	ListNode *removeZeroSumSublists(ListNode *head)
// 	{
// 		if (head == nullptr)
// 			return head;
// 		ListNode *i_cur = head;
// 		while (i_cur)
// 		{
// 			int ret = 0;
// 			ListNode *j_cur = i_cur;
// 			while (j_cur)
// 			{
// 				ret += j_cur->val;
// 				if (ret == 0)
// 				{
// 					i_cur = j_cur;
// 					break;
// 				}
// 				else
// 				{
// 					j_cur = j_cur->next;
// 				}
// 			}
// 			i_cur = i_cur->next;
// 		}
// 	}
// };
// #include <iostream>

// int main()
// {
// 	std::cout << "hello " << std::endl;
// 	return 0;
// }
// #include <unordered_map>

// struct ListNode
// {
// 	int val;
// 	ListNode *next;
// 	ListNode() : val(0), next(nullptr) {}
// 	ListNode(int x) : val(x), next(nullptr) {}
// 	ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// class Solution
// {
// public:
// 	ListNode *removeZeroSumSublists(ListNode *head)
// 	{
// 		if (nullptr == head)
// 			return head;
// 		std::unordered_map<int, ListNode *> m;
// 		ListNode *newHead = new ListNode(0);
// 		newHead->next = head;
// 		int sum = 0;
// 		for (ListNode *cur = newHead; cur != nullptr; cur = cur->next)
// 		{
// 			sum += cur->val;
// 			m[sum] = cur;
// 		}
// 		sum = 0;
// 		for (ListNode *cur = newHead; cur != nullptr; cur = cur->next)
// 		{
// 			sum += cur->val;
// 			cur->next = m[sum]->next;
// 		}
// 		// 这里我们内存泄漏 是newHead
// 		// 但是其他的节点是不是new出来的,我们不知道,所以这里我们不说了
// 		return newHead->next;
// 	}
// };
// #include <iostream>
// struct ListNode
// {
// 	int val;
// 	ListNode *next;
// 	ListNode(int x) : val(x), next(NULL) {}
// };

// class Solution
// {
// public:
// 	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
// 	{
// 		if (l1 == nullptr)
// 			return l2;
// 		if (l2 == nullptr)
// 			return l1;
// 		ListNode *newHead = new ListNode(0);
// 		ListNode *tail = newHead;
// 		int sum = 0;
// 		while (l1 && l2)
// 		{
// 			sum += (l1->val + l2->val);
// 			ListNode *cur = new ListNode(sum % 10);
// 			tail->next = cur;
// 			tail = cur;
// 			sum /= 10;
// 			l1 = l1->next;
// 			l2 = l2->next;
// 		}
// 		while (l1)
// 		{
// 			sum += l1->val;
// 			ListNode *cur = new ListNode(sum % 10);
// 			tail->next = cur;

// 			tail = cur;
// 			sum /= 10;
// 			l1 = l1->next;
// 		}
// 		while (l2)
// 		{
// 			sum += l2->val;
// 			ListNode *cur = new ListNode(sum % 10);
// 			tail->next = cur;

// 			tail = cur;
// 			sum /= 10;
// 			l2 = l2->next;
// 		}
// 		if (sum)
// 		{
// 			ListNode *cur = new ListNode(sum % 10);
// 			tail->next = cur;
// 			tail = cur;
// 		}
// 		return newHead->next;
// 	}
// };

#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
// class Solution
// {
// public:
// 	int maxDepth(string s)
// 	{
// 		if (s.empty())
// 			return 0;
// 		stack<char> s_char;
// 		int max_result = 0;
// 		for (int i = 0; i < s.size(); i++)
// 		{
// 			if(s[i] == '(')
// 			{
// 				s_char.push(s[i]);
// 				max_result = max(max_result, (int)s_char.size());
// 			}
// 			else if(s[i] == ')')
// 			{
// 				s_char.pop();
// 			}
// 		}
// 		return max_result;
// 	}
// };

// class Solution
// {
// public:
// 	string makeGood(string s)
// 	{
// 		if (s.empty())
// 			return s;
// 		string result;
// 		result += s[0];
// 		bool flag = false; // 默认是小写的
// 		if (result[0] >= 'A' && result[0] <= 'Z')
// 			flag = true;
// 		for (int i = 1; i < s.size(); i++)
// 		{
// 			if (flag)
// 			{
// 				// 找小写的
// 				while (i < s.size() && (s[i] >= 'a' && s[i] <= 'z') && (result.back() - s[i] == -26))
// 				{
// 					++i;
// 				}
// 				if (i < s.size())
// 				{
// 					result += s[i];
// 					if (s[i] >= 'a' && s[i] <= 'z')
// 						flag = false;
// 				}
// 			}
// 			else
// 			{
// 				// 我是小写的
// 				// 找大写的, 相同或的
// 				while (i < s.size() && (s[i] >= 'A' && s[i] <= 'Z') && (result.back() - s[i] == 26))
// 				{
// 					++i;
// 				}
// 				if (i < s.size())
// 				{
// 					result += s[i];
// 					if (s[i] >= 'A' && s[i] <= 'Z')
// 						flag = true;
// 				}
// 			}
// 		}
// 		return result;
// 	}
// };
// class Solution
// {
// public:
// 	string makeGood(string s)
// 	{
// 		string result;
// 		for (int i = 0; i < s.size(); ++i)
// 		{
// 			if (result.empty())
// 			{
// 				result += s[i];
// 			}
// 			else
// 			{
// 				char ch = result.back();
// 				if (abs(ch - s[i]) == 32)
// 				{
// 					result.pop_back();
// 				}
// 				else
// 				{
// 					result += s[i];
// 				}
// 			}
// 		}
// 		// cout << 'a'-'A' << endl;
// 		return result;
// 	}
// };
// #include <set>
// struct TreeNode
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// class Solution
// {
// public:
// 	void _numColor(TreeNode *root, set<int> &s)
// 	{
// 		if (nullptr == root)
// 			return;
// 		_numColor(root->left, s);
// 		s.insert(root->val);
// 		_numColor(root->right, s);
// 	}
// 	int numColor(TreeNode *root)
// 	{
// 		set<int> s;
// 		_numColor(root, s);
// 		return s.size();
// 	}
// };
// #include <stdio.h>
// #include <vector>
// struct TreeNode
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
// 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// class Solution
// {
// public:
// 	std::vector<string> ret;
// 	int str_int(const string &str)
// 	{
// 		char *end;
// 		return strtol(str.c_str(), &end, 2);
// 	}
// 	void BFS(TreeNode *root, string path)
// 	{
// 		path += to_string(root->val);
// 		if (root->left == nullptr && root->right == nullptr)
// 		{
// 			ret.push_back(path);
// 			return;
// 		}
// 		if (root->left)
// 			BFS(root->left, path);
// 		if (root->right)
// 			BFS(root->right, path);
// 	}

// 	int sumRootToLeaf(TreeNode *root)
// 	{
// 		string path;
// 		if (root == nullptr)
// 			return 0;
// 		BFS(root, path);
// 		int sum = 0;
// 		for (auto &e : ret)
// 			sum += str_int(e);
// 		return sum;
// 	}
// };

// int main()
// {
// 	cout << Solution().str_int("0101") << endl;
// 	cout << Solution().str_int("101") << endl;
// 	return 0;
// }

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution
// {
// public:
// 	int sum(TreeNode *root)
// 	{
// 		if (root == nullptr)
// 			return 0;
// 		int left = sum(root->left);
// 		int right = sum(root->right);
// 		return root->val + left + right;
// 	}
// 	void func(TreeNode *root)
// 	{
// 		if (root == nullptr)
// 			return;
// 		int ret = 0;
// 		if (root->left)
// 			ret = sum(root->left);
// 		if (root->right)
// 			ret -= sum(root->right);

// 		root->val = abs(ret);
// 		func(root->left);
// 		func(root->right);
// 	}

// 	int findTilt(TreeNode *root)
// 	{

// 		func(root);
// 		return sum(root);
// 	}
// };
#include <vector>
// class Solution
// {
// public:
// 	string sortSentence(string s)
// 	{
// 		if (s.empty())
// 			return s;
// 		vector<string> v;
// 		// xxxxx   yyyy
// 		int begin = 0;
// 		while (1)
// 		{
// 			int pos = s.find(' ', begin);
// 			if (pos == string::npos)
// 			{
// 				v.push_back(s.substr(begin));
// 				break;
// 			}
// 			v.push_back(s.substr(begin, pos - begin));
// 			begin = pos + 1;
// 		}
// 		std::sort(v.begin(), v.end(), [](string s1, string s2){
// 			return s1.back() < s2.back();
// 		});
// 		for(auto e: v)
// 		{
// 			cout << e << endl;
// 		}
// 	}
// };

// class Solution
// {
// public:
// 	string sortSentence(string s)
// 	{
// 		if (s.empty())
// 			return s;
// 		vector<string> v;
// 		// xxxxx   yyyy
// 		int begin = 0;
// 		while (1)
// 		{
// 			int pos = s.find(' ', begin);
// 			if (pos == string::npos)
// 			{
// 				v.push_back(s.substr(begin));
// 				break;
// 			}
// 			v.push_back(s.substr(begin, pos - begin));
// 			begin = pos + 1;
// 		}
// 		std::sort(v.begin(), v.end(), [](string s1, string s2)
// 							{ return s1.back() < s2.back(); });
// 		string result;

// 		for (auto e : v)
// 		{
// 			result += e;
// 			result.pop_back();
// 			// result.erase(result.end());
// 			result += ' ';
// 		}
// 		// for(int i = 0; i < result.size()-1; ++i)
// 		// {

// 		// }
// 		result.pop_back();
// 		// result.erase(result.end());
// 		return result;
// 	}
// };
// #include <unordered_map>

// class Solution
// {
// public:
// 	int findLHS(vector<int> &nums)
// 	{
// 		unordered_map<int, int> m;
// 		for (auto e : nums)
// 			m[e]++;
// 		int result = 0;
// 		for (int i = 0; i < nums.size(); i++)
// 		{
// 			int ret = nums[i] + 1;
// 			if (m.find(ret) != m.end())
// 			{
// 				result = max(result, m[nums[i]] + m[ret]);
// 			}
// 		}
// 		return result;
// 	}
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
// 	// 递减
// 	bool isDecrease(const vector<int>& v)
// 	{
// 		if (v.size() == 1)
// 			return true;
// 		for (int i = 1; i < v.size(); i++)
// 		{
// 			if (v[i] >= v[i - 1])
// 				return false;
// 		}
// 		return true;
// 	}
// 	// 递增
// 	bool isIncrement(const vector<int>& v)
// 	{
// 		if (v.size() == 1)
// 			return true;
// 		for (int i = 1; i < v.size(); i++)
// 		{
// 			if (v[i] <= v[i - 1])
// 				return false;
// 		}
// 		return true;
// 	}
// 	bool isEvenOddTree(TreeNode* root) {
// 		if (root == nullptr)
// 			return true;

// 		// 层序遍历
// 		vector<vector<int>> vv;
// 		queue<TreeNode*> q;
// 		q.push(root);
// 		int sz = 1;
// 		vector<int> v;
// 		while (sz--)
// 		{
// 			// 出
// 			TreeNode* cur = q.front();
// 			v.push_back(cur->val);
// 			q.pop();
// 			if (cur->left)
// 				q.push(cur->left);

// 			if (cur->right)
// 				q.push(cur->right);
// 			if (sz == 0)
// 			{
// 				sz = q.size();
// 				vv.push_back(v);
// 				v.clear();
// 			}
// 		}

// 		// 判断
// 		int i = 0;
// 		for (vector<int> val : vv)
// 		{

// 			for (int key : val)
// 			{
// 				// 偶数 下标
// 				if (i % 2 == 0)
// 				{
// 					// 都是 奇数
// 					if (key % 2 == 0)
// 						return false;

// 				}
// 				else
// 				{
// 					// 都是  偶数
// 					if (key % 2 == 1)
// 						return false;

// 				}
// 			}
// 			if (i % 2 == 0)
// 			{
// 				if (!isIncrement(val))
// 				{
// 					return false;
// 				}
// 			}
// 			else
// 			{
// 				if (!isDecrease(val))
// 					return false;
// 			}
// 			++i;
// 		}
// 		return true;
// 	}
// };
#include <map>
class Solution
{
public:
	vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
	{
		map<int, int> m;
		for (auto e : arr1)
			m[e]++;
		int index = 0;
		for (int i = 0; i < arr2.size(); i++)
		{
			while (m[arr2[i]]--)
			{
				arr1[index++] = arr2[i];
			}
			m.erase(arr2[i]);
		}
		auto iter = m.begin();
		while (iter != m.end())
		{
			while (iter->second--)
			{
				arr1[index++] = iter->first;
			}
			iter++;
		}
		return arr1;
	}
};