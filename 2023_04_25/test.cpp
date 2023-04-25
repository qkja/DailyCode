#include <vector>
using std::vector;

//class Solution {
//public:
//    // https://leetcode.cn/problems/spiral-matrix-ii/submissions/
//    vector<vector<int>> generateMatrix(int n) {
//        std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
//
//        int ret = 0;
//        int count = 1;
//        int startx = 0;
//        int starty = 0;
//        int end = 1;
//
//        while (ret < n/2)
//        {
//            int i = startx;
//            int j = starty;
//            // 1. 上面
//            for (; j < n - end; j++)
//            {
//                result[i][j] = count++;
//            }
//            // 2. 右边
//            for (; i < n - end; i++)
//            {
//                result[i][j] = count++;
//            }
//            // 3. 下面
//            for (;j >= end; j--)
//            {
//                result[i][j] = count++;
//            }
//            // 4. 左侧
//            for (; i >= end; i--)
//            {
//                result[i][j] = count++;
//            }
//            end++;
//            startx++;
//            starty++;
//            ret++;
//        }
//        if (n % 2 == 1)
//        {
//            result[n/2][n / 2] = count++;
//        }
//        return result;
//    }
//};

//https://leetcode.cn/problems/remove-linked-list-elements/submissions/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        ListNode* new_head = nullptr;
        ListNode* tail = nullptr;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            if (cur->val != val)
            {
                if (tail == nullptr)
                {
                    new_head = cur;
                    tail = cur;
                }
                else
                {
                    tail->next = cur;
                    tail = cur;
                }
                cur = cur->next;

            }
            else
            {
                // 注意，这里我们需要回收内存
                ListNode* node = cur;
                cur = cur->next;
                delete node;
            }

        }

        if (tail)
        {
            tail->next = nullptr;
        }
        return new_head;
    }
};