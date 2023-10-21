//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(nullptr) {}
//};
//
//class Solution {
//public:
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