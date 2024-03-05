#include <vector>
#include <iostream>

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

////https://leetcode.cn/problems/remove-linked-list-elements/submissions/
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
//    ListNode* removeElements(ListNode* head, int val) {
//        if (head == nullptr)
//            return nullptr;
//        ListNode* new_head = nullptr;
//        ListNode* tail = nullptr;
//        ListNode* cur = head;
//        while (cur != nullptr)
//        {
//            if (cur->val != val)
//            {
//                if (tail == nullptr)
//                {
//                    new_head = cur;
//                    tail = cur;
//                }
//                else
//                {
//                    tail->next = cur;
//                    tail = cur;
//                }
//                cur = cur->next;
//
//            }
//            else
//            {
//                // 注意，这里我们需要回收内存
//                ListNode* node = cur;
//                cur = cur->next;
//                delete node;
//            }
//
//        }
//
//        if (tail)
//        {
//            tail->next = nullptr;
//        }
//        return new_head;
//    }
//};

//https://leetcode.cn/problems/design-linked-list/submissions/
//struct Node
//{
//    Node(int x)
//        :val(x)
//        ,next(nullptr)
//    {}
//    int val;
//    struct Node* next;
//};
//
//class MyLinkedList {
//    
//public:
//    MyLinkedList() {
//        _head = nullptr;
//        _size = 0;
//    }
//
//    int get(int index) {
//        if(index < 0 || index >= _size)
//            return -1;
//
//        Node* cur = _head;
//        // 返回 1 的位置
//        while (index--)
//        {
//            cur = cur->next;
//        }
//        return cur == nullptr ? -1 : cur->val;
//    }
//
//    void addAtHead(int val) {
//        Node* node = new Node(val);
//        if (_head == nullptr)
//        {
//            _head = node;
//        }
//        else
//        {
//            node->next = _head;
//            _head = node;
//        }
//        _size++;
//    }
//
//    void addAtTail(int val) {
//        addAtIndex(_size, val);
//    }
//
//    void addAtIndex(int index, int val) {
//        if (index < 0 || index > _size)
//            return;
//        if (index == 0)
//        {
//            // 头插
//            addAtHead(val);
//        }
//        else
//        {
//            Node* node = new Node(val);
//
//            Node* prev = nullptr;
//            Node* cur = _head;
//            // 寻找位置
//            while (index--)
//            {
//                prev = cur;
//                cur = cur->next;
//                if (cur == nullptr)
//                    break;
//            }
//
//            prev->next = node;
//            node->next = cur;
//        }
//        _size++;
//    }
//
//    void deleteAtIndex(int index) {
//
//        if (index < 0 || index >= _size)
//            return;
//        Node* cur = _head;
//        Node* prev = nullptr;
//
//        while (index > 0)
//        {
//            prev = cur;
//            cur = cur->next;
//            index--;
//        }
//        if (prev == nullptr)
//        {
//            _head = _head->next;
//            delete cur;
//        }
//        else
//        {
//            prev->next = cur->next;
//            delete cur;
//        }
//        _size--;
//    }
//    Node* _head;
//    int _size;
//};
//int main()
//{
//    MyLinkedList my;
//    my.addAtTail(1);
//    my.addAtTail(3);
//
//    std::cout << my.get(1) << std::endl;
//    return 0;
//}