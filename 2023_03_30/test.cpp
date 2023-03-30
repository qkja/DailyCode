#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        std::string result;
        if (paragraph.empty())
            return result;
        unordered_set<string> s;
        for (auto& e : banned)
        {
            s.insert(e);
        }


        // 清洗字符串

        string paragraphHelp;
        for (auto e : paragraph)
        {
            if (e >= 'a' && e <= 'z')
            {
                paragraphHelp += e;
            }
            else if (e >= 'A' && e <= 'Z')
            {
                paragraphHelp += (e + 'z' - 'Z');

            }
            else if (e == ' ')
            {
                paragraphHelp += e;
            }
            else
            {
                paragraphHelp += ' ';

            }
        }



        paragraph = paragraphHelp;

        // 1. 切分字符串
        unordered_map<string, int> m;

        int start = 0;
        while (start < paragraph.size())
        {
            size_t pos = paragraph.find(' ', start);
            if (pos == std::string::npos)
            {
                string str = paragraph.substr(start);
                if (s.find(str) == s.end())
                    m[str]++;
                break;
            }

            // 找到了
            string str = paragraph.substr(start, pos - start);
            if (s.find(str) == s.end())
                m[str]++;

            // 这里清洗一下连续的 ' '
            while (pos < paragraph.size() && paragraph[++pos] == ' ');

            start = pos;
        }

        result = m.begin()->first;

        int maxNum = m.begin()->second;

        auto iter = m.begin();
        while (iter != m.end())
        {
            if (iter->second > maxNum)
            {
                result = iter->first;
                maxNum = iter->second;
            }
            ++iter;
        }
        return result;
    }
};



//class Solution {
//public:
//    string mostCommonWord(string paragraph, vector<string>& banned) {
//        std::string result;
//        if (paragraph.empty())
//            return result;
//        unordered_set<string> s;
//        for (auto& e : banned)
//        {
//            s.insert(e);
//        }
//       
//
//        // 清洗字符串
//        
//        string paragraphHelp;
//        for (auto e : paragraph)
//        {
//            if (e >= 'a' && e <= 'z')
//            {
//                paragraphHelp += e;
//            }
//            else if (e >= 'A' && e <= 'Z')
//            {
//                paragraphHelp += (e + 'z'-'Z');
//
//            }
//            else if (e == ' ')
//            {
//                paragraphHelp += e;
//            }
//            else
//            {
//                paragraphHelp += ' ';
//            }
//        }
//
//       
//
//        paragraph = paragraphHelp;
//
//        // 1. 切分字符串
//        unordered_map<string, int> m;
//
//        int start = 0;
//        while (true)
//        {
//            size_t pos = paragraph.find(' ', start);
//            if (pos == std::string::npos)
//            {
//                string str = paragraph.substr(start);
//                if (s.find(str) == s.end())
//                    m[str]++;
//                break;
//            }
//
//            // 找到了
//            string str = paragraph.substr(start, pos-start);
//            if (s.find(str) == s.end())
//            {
//                m[str]++;
//            }
// 
//            while (pos < paragraph.size() && paragraph[++pos] == ' ');
//
//            start = pos;
//        }
//
//        result = m.begin()->first;
//
//        int maxNum = m.begin()->second;
//
//        auto iter = m.begin();
//        while (iter != m.end())
//        {
//            if (iter->second > maxNum)
//            {
//                result = iter->first;
//                maxNum = iter->second;
//            }
//            ++iter;
//        }
//        return result;
//    }
//};
//int main()
//{
//    //string str = "Bob hit a ball, the hit BALL flew far after it was hit.";
//    //vector<string> v;
//    //v.push_back("hit");
//
//    string str = "a.";
//    vector<string> v;
//    Solution().mostCommonWord(str, v);
//    return 0;
//}









//class Solution {
//public:
//    int repeatedStringMatch(string a, string b) {
//        // 这里需要参数判断,我们就不判断了
//        int count = 1;
//        if (a.size() >= b.size())
//        {
//            std::string str = a + a;
//            if (a.find(b) != std::string::npos)
//                return 1;
//            else if (str.find(b) != std::string::npos)
//                return 2;
//            else
//                return -1;
//        }
//        else
//        {
//            // 这里我们 
//            std::string str = a;
//            int  midRepCnt = b.size() / a.size() + 2;
//            while (count < midRepCnt)
//            {
//                if (str.find(b) != std::string::npos)
//                    return -1;
//
//                str += a;
//                count++;
//            }
//        }
//        return -1;
//    }
//};



//struct ListNode 
//{
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//
//
//class Solution {
//public:
//    void deleteNode(ListNode* node) {
//        if (nullptr == node || node->next == nullptr)
//            return;
//        ListNode* next = node->next;
//        while (next->next)
//        {
//            node->val = next->val;
//            node = next;
//            next = next->next;
//        }
//        // 覆盖一下
//        node->val = next->val;
//        node->next = nullptr;
//        delete next;
//    }
//};











//struct Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr)
//            return nullptr;
//        ListNode* prev = nullptr;
//        ListNode* node = head;
//        ListNode* next = head->next;
//        while (node)
//        {
//            next = node->next; // 保存 下一个节点
//
//            node->next = prev;
//            prev = node;
//            node = next;
//        }
//        return prev;
//    }
//};
//
//int main()
//{
//    int a = 0;
//    a = 10;
//    return 0;
//}



//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if (list1 == nullptr)
//            return list2;
//        if (list2 == nullptr)
//            return list1;
//        ListNode* head = nullptr;
//        ListNode* tail = head;
//        while (list1 && list2)
//        {
//            if (list1->val <= list2->val)
//            {
//                if (head == nullptr)
//                {
//                    head = list1;
//                    tail = head;
//                }
//                else
//                {
//                    tail->next = list1;
//                    tail = tail->next;
//                }
//                list1 = list1->next;
//            }
//            else
//            {
//                if (head == nullptr)
//                {
//                    head = list2;
//                    tail = head;
//                }
//                else
//                {
//                    tail->next = list2;
//                    tail = tail->next;
//                }
//                list2 = list2->next;
//            }
//        }
//        if (list1)
//        {
//            tail->next = list1;
//        }
//        if (list2)
//        {
//            tail->next = list2;
//
//        }
//        return head;
//    }
//};


//class Solution {
//public:
//    /**
//     *
//     * @param word1 string字符串
//     * @param word2 string字符串
//     * @return int整型
//     */
//    int minDistance(string word1, string word2) {
//        // write code here
//    }
//};




//class Solution {
//public:
//    /**
//     *
//     * @param s string字符串
//     * @return int整型
//     */
//    bool is_reply(std::string& str, int left, int right)
//    {
//        while (left < right)
//        {
//            if (str[left++] != str[right--])
//                return false;
//        }
//        return true;
//
//    }
//
//    int minCut(string s) {
//        if (s.empty())
//            return 0;
//
//        int len = s.size();
//        std::vector<int> dp(len + 1, 0);
//
//        for (int i = 2; i < len + 1; i++)
//        {
//            if (!is_reply(s, 0, i - 1))
//            {
//                int ret = dp[i - 1] + 1;
//                for (int j = 1; j < i; j++)
//                {
//                    if (is_reply(s, j, i - 1))
//                    {
//                        ret = std::min(ret, dp[j] + 1);
//                    }
//                }
//                dp[i] = ret;
//            }
//        }
//
//        return dp[len];
//    }
//};















//class Solution {
//public:
//    /**
//     *
//     * @param s string字符串
//     * @return int整型
//     */
//    bool is_reply(std::string& str, int left, int right)
//    {
//        while (left < right)
//        {
//            if (str[left++] != str[right--])
//                return false;
//        }
//        return true;
//
//    }
//
//    int minCut(string s) {
//        if (s.empty())
//            return 0;
//
//        int len = s.size();
//        std::vector<int> dp(len+1, 0);
//
//        for (int i = 2; i < len + 1; i++)
//        {
//            if (!is_reply(s, 0, i-1))
//            {
//                int ret = dp[i-1] + 1;
//                for (int j = 1; j < i; j++)
//                {
//                    if (is_reply(s, j, i - 1))
//                    {
//                        ret = std::min(ret, dp[j + 1] + 1);
//                    }
//                }
//                dp[i] = ret;
//            }
//        }
//
//        return dp[len];
//    }
//};

//class Solution {
//public:
//    /**
//     *
//     * @param s string字符串
//     * @return int整型
//     */
//    bool is_reply(std::string& str, int i)
//    {
//        int left = 0;
//        int right = str.size() - 1;
//        while (left < right)
//        {
//            if (str[left++] != str[right--])
//                return false;
//        }
//        return true;
//
//    }
//    int minCut(string s) {
//        // write code here
//    }
//
//    //0到index 不再进行关心, 我们只需要 关心index后面是否是回文串
//    // 我们的切割次数
//    int process(std::string& str, int index)
//    {
//        if (str.size() == index)  // ab
//            return 0;
//        // 判断是否回文
//        if (is_reply(str, index) == true)
//            return 0;
//        else
//        {
//            return 1 + process(str, index + 1);
//        }
//    }
//};


//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//	int maxVal(std::vector<int>& w, std::vector<int>& v, int bag)
//	{
//		// 参数判断
//		if (w.empty() || v.empty() || w.size() != v.size())
//			return -1;
//	}
//
//};
//
//int main() {
//	int n = 0;
//	std::cin >> n;
//	std::vector<int> c(n, 0);  // 价值
//	std::vector<int> w(n, 0);  // 重量
//	int bag = 0;
//	std::cin >> bag;
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> c[i] >> w[i];
//	}
//	std::cout << Solution().maxVal(w, c, bag) << std::endl;
//
//	return 0;
//}
