//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(nullptr) {}
//};
//
//class Solution {
//public:
//	/**
//	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//	*
//	*
//	* @param head ListNode类
//	* @param m int整型
//	* @param n int整型
//	* @return ListNode类
//	*/
//	ListNode* reverseBetween(ListNode* head, int m, int n) {
//		// write code here
//		if (head == nullptr || n < 1)
//		{
//			return nullptr;
//		}
//
//		int len = n - m + 1; // 逆置len个节点
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
//		// 这里存在问题
//		old_prev->next = prev;
//		if (old_tail)
//			old_tail->next = cur;
//
//		return head;
//	}
//};

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* removeZeroSumSublists(ListNode* head) {
		if (head == nullptr)
			return head;
		ListNode* i_cur = head;
		while (i_cur)
		{
			int ret = 0;
			ListNode* j_cur = i_cur;
			while (j_cur)
			{
				ret += j_cur->val;
				if (ret == 0)
				{
					i_cur = j_cur;
					break;
				}
				else
				{
					j_cur = j_cur->next;
				}
			}
			i_cur = i_cur->next;
		}
	}
};