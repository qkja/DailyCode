#include <vector>
#include <string>
#include <queue>
using namespace std;
#include <unordered_set>
#include <unordered_map>


#include <vector>
#include <iostream>
using namespace std;
//vector<vector<int>> vv = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 上 下 左 右
//void backtraing(vector<vector<int>>& v, vector<std::pair<int, int>>& result,
//    vector<std::pair<int, int>>& path, int x, int y,
//    vector<vector<bool>>& falg)
//{
//    // 收集结果
//
//    if (x == v.size() - 1 && y == v.back().size() - 1 && v[x][y] == 0)
//    {
//        for (auto& e : path)
//        {
//            result.push_back(e);
//        }
//        return;
//    }
//
//    if (v[x][y] == 1)
//        return;
//
//    for (int i = 0; i < 4; i++)
//    {
//        // 先把 数据如进去
//        path.push_back({ x, y });
//        falg[x][y] = true;
//        int xx = x + vv[i][0];
//        int yy = y + vv[i][1];
//        if (xx >= 0 && xx < v.size() && yy >= 0 && yy < v.back().size()
//            && falg[xx][yy] == false)
//        {
// 
//            backtraing(v, result, path, xx, yy, falg);
//        }
//        path.pop_back();
//    }
//}
//int main()
//{
//    int n = 0; // 列
//    int m = 0; // 行
//    cin >> n >> m;
//    vector<vector<int>> v(n, vector<int>(m, 0));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            cin >> v[i][j];
//        }
//    }
//    vector<std::pair<int, int>> result;
//    vector<std::pair<int, int>> path;
//    vector<vector<bool>> falg(n, vector<bool>(m, false));
//    backtraing(v, result, path, 0, 0, falg);
//    for (auto& e : result)
//    {
//        cout << "(" << e.first << "," << e.second << ")" << endl;
//    }
//    return 0;
//}


//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//public:
//    vector<string> binaryTreePaths(TreeNode* root) {
//        vector<string> result;
//        if (root == nullptr)
//            return result;
//        std::queue<TreeNode*> q;
//        q.push(root);
//        while (true)
//        {
//            TreeNode* top = q.front(); 
//            if (top == nullptr)
//            {
//                result.push_back("null");
//            }
//            else
//            {
//                result.push_back(std::to_string(top->val));
//            }
//
//            q.pop();
//            if (top->left && top->right)
//            {
//                q.push(top->left); top->lefttop->left
//            }
//        }
//    }
//};

//class Solution
//{
//public:
//    int coinChange(vector<int>& coins, int amount)
//    {
//        int n = coins.size();
//        int m = amount;
//        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//        dp[0][0] = 0;
//        for (int i = 1; i <= m; i++)
//            dp[0][i] = -1;
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 0; j <= m; j++)
//            {
//                dp[i][j] = dp[i - 1][j];
//                if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != -1)
//                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
//            }
//        }
//        return dp[n][m] == -1 ? 0 : dp[n][m];
//    }
//};

//class Solution
//{
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target)
//    {
//        vector<vector<int>> v;
//        if (nums.empty())
//            return v;
//        sort(nums.begin(), nums.end());
//        int index = 0;
//
//        while (index < (int)(nums.size() - 3))  // 这里我非常恶习
//        {
//
//      
//            int begin = index + 1;
//            while (begin < (nums.size() - 2))
//            {
//                // 这里等一下
//                int left = begin + 1;
//                int right = nums.size() - 1;
//                // 这里开始在[l,r] 中找到   和等于  nums[begin]的
//                while (left < right)
//                {
//                    int sum = nums[left] + nums[right] + nums[begin] + nums[index];
//                    if (sum == target)
//                    {
//                        v.push_back({ nums[index], nums[begin], nums[left++], nums[right--] });
//                        while (left < right && nums[left] == nums[left - 1])
//                        {
//                            left++;
//                        }
//                        while (left < right && nums[right] == nums[right + 1])
//                        {
//                            right--;
//                        }
//                    }
//                    else if (sum > target)
//                    {
//                        right--;
//                    }
//                    else
//                    {
//                        left++;
//                    }
//                }
//                begin++;
//                while (begin < (nums.size() - 2) && nums[begin - 1] == nums[begin])
//                {
//                    begin++;
//                }
//            }
//
//            index++;
//            while (index < (nums.size() - 3) && nums[index - 1] == nums[index])
//            {
//                index++;
//            }
//        }
//        return v;
//    }
//};
//class Solution
//{
//public:
//    bool isRepeat(int left, int right, string& str)
//    {
//        if (left > right)
//            return false;
//        unordered_set<char> s;
//        for (int i = left; i <= right; i++)
//        {
//            s.insert(str[i]);
//        }
//        return (right - left + 1) == (int)s.size();
//    }
//
//    int lengthOfLongestSubstring(string s)
//    {
//        if (s.empty())
//            return 0;
//        int begin = 0;
//        int maxLen = 0;
//        int end = 0;
//        for (size_t end = 0; end < s.size(); end++)
//        {
//            if (isRepeat(begin, end, s))
//            {
//                maxLen = max(maxLen, (int)end - begin + 1);
//            }
//            else
//            {
//                while (!isRepeat(begin, end, s))
//                {
//                    begin++;
//                }
//            }
//        }
//        //maxLen = max(maxLen, (int)end - begin + 1);
//
//        return maxLen;
//    }
//};

//class Solution
//{
//public:
//    bool isRepeat(int left, int right, string& str)
//    {
//        if (left > right)
//            return false;
//        unordered_set<char> s;
//        for (int i = left; i <= right; i++)
//        {
//            s.insert(str[i]);
//        }
//        return (right - left + 1) == (int)s.size();
//    }
//
//    int lengthOfLongestSubstring(string s)
//    {
//        if (s.empty())
//            return 0;
//        int begin = 0;
//        int maxLen = 0;
//        int end = 0;
//        unordered_map<char, int> m;
//        for (size_t end = 0; end < s.size(); end++)
//        {
//            // 判断是不是在hash 表呢
//            auto iter = m.find(s[end]);
//            // 判断是不是在hash 表中
//            if (s[end] == 'a')
//            {
//                int b = 10;
//            }
//            if (iter == m.end())
//            {
//                // 进窗口
//                m[s[end]] = end;
//                maxLen = max(maxLen, (int)end - begin + 1);
//
//            }
//            else
//            {
//                while (iter != m.end()) // 找了这个元素
//                {
//                    m.erase(s[begin++]);
//                    iter = m.find(s[end]);
//                }
//                m[s[end]] = end;
//            }
//
//        }
//
//        return maxLen;
//    }
//};

//class Solution
//{
//public:
//    vector<int> findAnagrams(string s, string p)
//    {
//        vector<int> result;
//        if (s.empty() || p.empty())
//            return result;
//        vector<int> v(26, 0);
//        for (auto e : p)
//        {
//            v[e - 'a']++;
//        }
//        int k = 0;
//        int begin = 0;
//        int end = 0;
//        vector<int> ret(26, 0);
//        for (; end < s.size(); end++)
//        {
//            // 入窗口
//            ret[s[end] - 'a']++;
//            k++;
//
//            // 判断这个是否是合法的
//               // 不合法
//            while (ret[s[end] - 'a'] > v[s[end] - 'a'])
//            {
//                ret[s[begin++] - 'a']--;
//                k--;
//            }
//       
//            if (ret[s[end] - 'a'] <= v[s[end] - 'a'])
//            {
//                // 首先是 合法的
//                if (k == p.size())
//                {
//                    result.push_back(begin);
//                }
//            }
//        }
//        return result;
//    }
//};


//class Solution
//{
//public:
//    string minWindow(string s, string t)
//    {
//        string result;
//        if (s.size() < t.size())
//            return result;
//        // unordered_map<char, int> m1;
//        // unordered_map<char, int> m2;
//        vector<int> m1(26, 0);
//        vector<int> m2(26, 0);
//
//        for (auto& e : t)
//            m1[e - 'a']++;
//
//        int count = 0;
//        for (auto e : m1)
//            if (e)
//                count++;
//        int k = 0;
//        int begin = 0;
//        int end = 0;
//        for (; end < s.size(); end++)
//        {
//            // 直接如
//            m2[s[end] - 'a']++;
//            // 这里最好不要污染m1
//            // auto iter = m1.find(s[end]);
//            // 这避免一下我们 重复使用
//            // if (iter != m1.end() && m2[s[end]] - 1 < m1[s[end]] && m2[s[end]] >= m1[s[end]])
//            if (m1[s[end] - 'a'] != 0 && m2[s[end] - 'a'] - 1 < m1[s[end] - 'a'] && m2[s[end] - 'a'] >= m1[s[end - 'a']])
//                k++;
//            while (k == count)
//            {
//                // 此时绝对可以了
//                string str = s.substr(begin, end - begin + 1);
//                if (result.empty())
//                    result = str;
//                else
//                    result = str.size() < result.size() ? str : result;
//
//                // 这里需要出
//                m2[s[begin - 'a']]--;
//                // 判断   k 值是否需要变化
//                // 这里我们重点看到的是  begin的
//                // auto iter2 = m1.find(s[begin]);
//                // if (iter2 != m1.end() && m2[s[begin]-'a'] < m1[s[begin]-'a'])
//                if (m1[s[begin] - 'a'] != 0 && m2[s[begin] - 'a'] < m1[s[begin] - 'a'])
//                    k--;
//                begin++;
//            }
//        }
//        return result;
//    }
//};

class Solution
{
public:
    int minOperations(vector<int>& nums, int x)
    {
        if (nums.empty())
            return 0;
        // 正难则反
        int sum = 0;
        for (auto& e : nums)
            sum += e;

        x = sum - x;

        int begin = 0;
        int end = 0;
        sum = 0;
        int minLen = -1;
        for (; end < nums.size(); end++)
        {
            sum += nums[end];
            while (begin <= end && sum > x)
            {
                sum -= nums[begin++];
            }
            // 此时 我们
            if (sum == x)
            {
                minLen = max(minLen, end - begin + 1);
            }
        }
        return minLen == -1 ? -1 : nums.size() - minLen;
    }
};
int main()
{
    vector<int> v = { 1,1,4,2,3 };

    Solution().minOperations(v, 5);
    return 0;
}