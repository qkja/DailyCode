// https://leetcode.cn/problems/reverse-linked-list/submissions/\
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr)
//            return nullptr;
//        ListNode* prev = nullptr;
//        ListNode* node = head;
//        ListNode* next = head->next;
//        while (node)
//        {
//            node->next = prev; 
//            prev = node;
//            node = next;
//            if (next)
//                next = next->next;
//        }
//        return prev;
//    }
//};

//https://leetcode.cn/problems/swap-nodes-in-pairs/
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        ListNode* newHead = new ListNode;
//        newHead->next = head;
//        ListNode* node = newHead;
//        while (node->next && node->next->next)
//        {
//            ListNode* next = node->next;
//            ListNode* nextNext = next->next->next;
//
//            node->next = next->next;
//            next->next->next = next;
//            next->next = nextNext;
//            node = next;
//        }
//        head = newHead->next;
//        delete newHead;
//        return head;
//    }
//};
//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if (head == nullptr)
//            return nullptr;
//        ListNode* fast = head;
//        while (n)
//        {
//            n--;
//            fast = fast->next;
//            if (fast == nullptr)
//                break;
//        }
//        if (fast == nullptr && n != 0)
//        {
//            return nullptr;
//        }
//
//        else if (fast == nullptr && n == 0)
//        {
//            ListNode* ret = head->next;
//            delete head;
//            return ret;
//        }
//        else
//        {
//            ListNode* low = head;
//            ListNode* prev = nullptr;
//            while (fast)
//            {
//                prev = low;
//                low = low->next;
//                fast = fast->next;
//            }
//            prev->next = low->next;
//            delete low;
//        }
//        return head;
//    }
//};
// https://leetcode.cn/problems/linked-list-cycle-ii/
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(nullptr) {}
//};
//
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head)
//    {
//        if (head == nullptr)
//            return nullptr;
//        ListNode* fast = head;
//        ListNode* low = head;
//
//        ListNode* node = nullptr;
//        while (fast && fast->next && low)
//        {
//            fast = fast->next->next;
//            low = low->next;
//            if (fast == low)
//            {
//                node = fast;
//                break;
//            }
//        }
//        if (node == nullptr)
//            return nullptr;
//        while (node != head)
//        {
//            node = node->next; 
//            head = head->next;
//        }
//        return head;
//    }
//};
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// https://leetcode.cn/problems/valid-anagram/submissions/
//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        std::unordered_map<char, int> m;
//        for (auto e : s)
//        {
//            m[e]++;
//        }
//        for (auto e : t)
//        {
//            int& ret = m[e];
//            if (ret == 0)
//                return false;
//            ret--;
//            if (ret == 0)
//                m.erase(e);
//        }
//        return m.empty();
//    }
//};
// https://leetcode.cn/problems/intersection-of-two-arrays/submissions/
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        std::vector<int> result;
//        if (nums1.empty() || nums2.empty())
//            return result;
//
//        std::unordered_set<int> s;
//        for (auto e : nums1)
//        {
//            s.insert(e);
//        }
//        for (auto& e : nums2)
//        {
//            auto iter = s.find(e);
//            if (iter == s.end())
//                continue;
//            result.push_back(e);
//            s.erase(e);
//        }
//
//        return result;
//    }
//};