#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <deque>
using namespace std;

// https://leetcode.cn/problems/implement-queue-using-stacks/submissions/
//class MyQueue {
//public:
//    MyQueue() {
//
//    }
//
//    void push(int x) {
//        push_stack.push(x);
//    }
//
//    int pop() {
//        if (empty())
//            return -1;
//        if (pop_stack.empty())
//        {
//            insert();
//        }
//        int ret = pop_stack.top();
//        pop_stack.pop();
//        return ret;
//    }
//
//    int peek() {
//        if (empty())
//            return -1;
//        if (pop_stack.empty())
//        {
//            insert();
//        }
//        return pop_stack.top();
//    }
//
//    bool empty() {
//        return push_stack.empty() && pop_stack.empty();
//    }
//private:
    //void insert()
    //{
    //    while (!push_stack.empty())
    //    {
    //        pop_stack.push(push_stack.top());
    //        push_stack.pop();
    //    }
    //}
//private:
//    std::stack<int> push_stack;
//    std::stack<int> pop_stack;
//};

// https://leetcode.cn/problems/implement-queue-using-stacks/submissions/
//class MyStack {
//public:
//    MyStack() {
//
//    }
//
//    void push(int x) {
//        q1.push(x);
//    }
//
//    int pop() {
//        if (empty())
//            return -1;
//        while (q1.size() != 1)
//        {
//            q2.push(q1.front());
//            q1.pop();
//        }
//        int ret = q1.front();
//        q1.pop();
//        insert();
//        return ret;
//    }
//
//    int top() {
//        if (empty())
//            return -1;
//        while (q1.size() != 1)
//        {
//            q2.push(q1.front());
//            q1.pop();
//        }
//        int ret = q1.front();
//        q1.pop();
//        q2.push(ret);
//        insert();
//        return ret;
//    }
//
//    bool empty() {
//        return q1.empty() && q2.empty();
//    }
//private:
//    void insert()
//    {
//        while (!q2.empty())
//        {
//            q1.push(q2.front());
//            q2.pop();
//
//        }
//    }
//private:
//
//    std::queue<int> q1; // 这里是主要的
//    std::queue<int> q2; // 辅助的
//};

// https://leetcode.cn/problems/valid-parentheses/submissions/
//class Solution {
//public:
//    bool isValid(string s) {
//        if (s.empty())
//            return true;
//        std::stack<char> stack_char;
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//            {
//                stack_char.push(s[i]);
//            }
//            else
//            {
//                if (stack_char.empty())
//                    return false;
//                char ret = stack_char.top();
//                stack_char.pop();
//                if ((s[i] == ')' && ret != '(')
//                    || (s[i] == ']' && ret != '[')
//                    || (s[i] == '}' && ret != '{'))
//                    return false;
//            }
//        }
//        return stack_char.empty();
//    }
//};
//https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/submissions/
//class Solution {
//public:
//    string removeDuplicates(string s) {
//        if (s.empty())
//            return s;
//        std::stack<char> stack_char;
//        for (auto e : s)
//        {
//            if (stack_char.empty())
//            {
//                stack_char.push(e);
//            }
//            else
//            {
//                int ret = stack_char.top();
//                if (ret == e)
//                    stack_char.pop();
//                else
//                    stack_char.push(e);
//            }
//        }
//        std::string result;
//        while(!stack_char.empty())
//        {
//            result += stack_char.top();
//            stack_char.pop();
//        }
//        reverse(result.begin(), result.end());
//        return result;
//    }
//};
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/submissions/
//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//        if (tokens.empty())
//            return 0;
//        std::stack<int> s;
//        for (auto& e : tokens)
//        {
//            if (e == "+"
//                || e == "-"
//                || e == "*"
//                || e == "/"
//                )
//            {
//                int right = s.top();
//                s.pop();
//                int left = s.top();
//                s.pop();
//                int ret = 0;
//                if (e == "+")
//                {
//                    ret = left + right;
//                }
//                else if (e == "-")
//                { 
//                    ret = left - right;
//                }
//                else if (e == "*")
//                {
//                    ret = left * right;
//                }
//                else
//                {
//                    ret = left / right;
//                }
//                s.push(ret);
//            }
//            else
//            {
//                int ret = std::stoi(e);
//                s.push(ret);
//            }
//        }
//        return s.top();
//    }
//};




// https://leetcode.cn/problems/sliding-window-maximum/submissions/
//class Solution {
//public:
//    class MyQueue
//    {
//    public:
//        void pop(int val)
//        {
//
//            int ret = d.front();
//            // 只有我们传入的元素和最大的元素相等,我们出
//            if (ret == val)
//                d.erase(d.begin());
//        }
//        void push(int x)
//        {
//
//            // 拿到我们的值
//            while (!d.empty() && d.back() < x)
//            {
//                d.pop_back();
//            }
//            d.push_back(x);
//
//        }
//        int getMax()
//        {
//            return d.front();
//        }
//    private:
//        std::deque<int> d;
//    };
//
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        std::vector<int> result;
//        if (nums.empty() || k <= 0 || k > nums.size())
//            return result;
//        int fast = 0;
//        int low = 0;
//        MyQueue q;
//        while (fast < nums.size())
//        {
//            if (fast < k)
//            {
//                q.push(nums[fast]);
//            }
//            else
//            {
//                result.push_back(q.getMax());
//                q.pop(nums[low]);
//                q.push(nums[fast]);
//                low++;
//            }
//            fast++;
//        }
//        result.push_back(q.getMax());
//        return result;
//    }
//};


// https://leetcode.cn/problems/top-k-frequent-elements/submissions/
//class Solution {
//public:
//    struct Cmp
//    {
//        // 建立小堆
//        bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
//        {
//            return p1.second > p2.second;
//        }
//    };
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        std::vector<int> result;
//        if (nums.empty() || k <= 0)
//            return result;
//        std::unordered_map<int, int> m;
//        for (auto e : nums)
//        {
//            m[e]++;
//        }
//        std::priority_queue<std::pair<int, int>, std::vector<pair<int, int>>, Cmp> q;
//        auto iter = m.begin();
//        int i = 0;
//        for (; iter != m.end(); iter++)
//        {
//            if (i < k)
//            {
//                q.push(*iter);
//                i++;
//            }
//            else
//            {
//                const std::pair<int, int>& p = q.top();
//                if (iter->second > p.second)
//                {
//                    q.pop();
//                    q.push(*iter);
//                }
//            }
//        }
//
//
//        while (!q.empty())
//        {
//            const std::pair<int, int>& p = q.top();
//            result.push_back(p.first);
//            q.pop();
//        }
//        std::sort(result.begin(), result.end());
//        return result;
//    }
//};

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

    vector<int> preorderTraversal(TreeNode* root) {

    }
};



//https://leetcode.cn/problems/binary-tree-preorder-traversal/submissions/
class Solution {
//public:
//    // 前序遍历 -- > 根左右
//    // 递归
//    void preorderTraversalChild(TreeNode* root, std::vector<int>& result)
//    {
//        if (root == nullptr)
//            return;
//        result.push_back(root->val);
//        preorderTraversalChild(root->left, result);
//        preorderTraversalChild(root->right, result);
//
//    }
//    // 非递归
//    void preorderTraversalChildR(TreeNode* root, std::vector<int>& result)
//    {
//        if (root == nullptr)
//            return; 
//        std::stack<TreeNode*> s;
//        s.push(root);
//        TreeNode* node = nullptr;
//        while (!s.empty())
//        {
//            node = s.top();
//            s.pop();
//            result.push_back(node->val);
//            if (node->right)
//                s.push(node->right);
//            if (node->left)
//                s.push(node->left);
//        }
//    }
//    vector<int> preorderTraversal(TreeNode* root) {
//        std::vector<int> result;
//        //preorderTraversalChild(root, result);
//        preorderTraversalChildR(root, result);
//        return result;
//    }
//};
//https://leetcode.cn/problems/binary-tree-postorder-traversal/submissions/
//class Solution {
//public:
//    void postorderTraversalChild(TreeNode* root, std::vector<int>& result)
//    {
//        if (root == nullptr)
//            return;
//        postorderTraversalChild(root->left, result);
//        postorderTraversalChild(root->right, result);
//        result.push_back(root->val);
//    }
//    vector<int> postorderTraversal(TreeNode* root) {
//        std::vector<int> result;
//        postorderTraversalChild(root, result);
//        return result;
//    }
//};
//https://leetcode.cn/problems/binary-tree-inorder-traversal/submissions/
//class Solution {
//public:
//    void  inorderTraversalChild(TreeNode* root, std::vector<int>& result)
//    {
//        if (root == nullptr)
//            return;
//        inorderTraversalChild(root->left, result);
//        result.push_back(root->val);
//        inorderTraversalChild(root->right, result);
//    }
//    vector<int> inorderTraversal(TreeNode* root) {
//        std::vector<int> result;
//        inorderTraversalChild(root, result);
//        return result;
//    }
//};