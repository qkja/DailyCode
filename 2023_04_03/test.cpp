#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    /**
//     *
//     * @param S string字符串
//     * @param T string字符串
//     * @return int整型
//     */
//    int numDistinct(string S, string T) {
//
//        int m = S.size();
//        int n = T.size();
//        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
//        for (int i = 0; i < m + 1; i++)
//        {
//            dp[i][0] = 1;
//        }
//
//        // 开始 dp
//        for (int i = 1; i < m + 1; i++)
//        {
//            for (int j = 1; j < n + 1; j++)
//            {
//                if (S[i - 1] == T[j - 1])
//                {
//                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
//                }
//                else
//                {
//                    dp[i][j] = dp[i - 1][j];
//                }
//            }
//        }
//
//        return dp[m][n];
//    }
//};
//class Solution {
//public:
//    int findLengthOfLCIS(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//        int left = 0;
//        int right = left + 1;
//        int start = left;
//
//        int result = 1;
//        while (right < nums.size())
//        {
//            while (right < nums.size() && nums[right] > nums[left])
//            {
//                left++;
//                right++;
//            }
//            int ret = right - start;
//            if (ret > result)
//                result = ret;
//
//            start = right;
//            left = right;
//            right = right + 1;
//        }
//        return result;
//    }
//};
#include <unordered_map>


//class Solution {
//public:
//    int findShortestSubArray(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//        struct Node
//        {
//            int start = -1;
//            int end = -1;
//            int frequency = 0;
//        };
//
//        std::unordered_map<int, Node> m;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            auto it = m.find(nums[i]);
//            if (it == m.end())
//            {
//                m[nums[i]].start = i;
//                m[nums[i]].end = i;
//                m[nums[i]].frequency++;
//            }
//            else
//            {
//                m[nums[i]].end = i;
//                m[nums[i]].frequency++;
//            }
//        }
// 
//        auto iter = m.begin();
//        struct Node node = iter->second;
//
//        int maxNum = iter->second.frequency;
//         while (iter != m.end())
//   {
//        cout <<   iter->first<<endl;
//
//        iter++;
//   }
//        while (iter != m.end())
//        {
//            if (iter->second.frequency >= maxNum)
//            {
//                //cout << "jj" << iter->first << endl;
//                if (iter->second.frequency == maxNum)
//                {
//                    if (iter->second.end - iter->second.start < node.end - node.start)
//                        node = iter->second;
//                }
//                else
//                {
//                    maxNum = iter->second.frequency;
//                }
//            }
//            iter++;
//        }
//        //cout << node.frequency << node.end << node.start << endl;
//
//
//        return node.end - node.start + 1;
//    }
//};

//class Solution {
//public:
//    int findShortestSubArray(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//        struct Node
//        {
//            int start = -1;
//            int end = -1;
//            int frequency = 0;
//        };
//
//        std::unordered_map<int, Node> m;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            auto it = m.find(nums[i]);
//            if (it == m.end())
//            {
//                m[nums[i]].start = i;
//                m[nums[i]].end = i;
//                m[nums[i]].frequency++;
//            }
//            else
//            {
//                m[nums[i]].end = i;
//                m[nums[i]].frequency++;
//            }
//        }
//
//        auto iter = m.begin();
//        struct Node node = iter->second;
//
//        //int maxNum = iter->second.frequency;
//        while (iter != m.end())
//        {
//            cout << iter->first << endl;
//
//            iter++;
//        }
//       /* while (iter != m.end())
//        {
//            if (iter->second.frequency >= maxNum)
//            {
//                if (iter->second.frequency == maxNum)
//                {
//                    if (iter->second.end - iter->second.start < node.end - node.start)
//                        node = iter->second;
//                }
//                else
//                {
//                    maxNum = iter->second.frequency;
//                }
//            }
//            iter++;
//        }*/
//
//
//        return node.end - node.start + 1;
//    }
//};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        struct Node
        {
            int start = -1;
            int end = -1;
            int frequency = 0;
        };

        std::unordered_map<int, Node> m;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = m.find(nums[i]);
            if (it == m.end())
            {
                m[nums[i]].start = i;
                m[nums[i]].end = i;
                m[nums[i]].frequency++;
            }
            else
            {
                m[nums[i]].end = i;
                m[nums[i]].frequency++;
            }
        }

        auto iter = m.begin();
        struct Node node = iter->second;

        int maxNum = -1;

        while (iter != m.end())
        {

            if (iter->second.frequency >= maxNum)
            {
                //cout << "jj" <<   iter->first<<endl;


                if (iter->second.frequency == maxNum)
                {
                    if ((iter->second.end - iter->second.start) < (node.end - node.start))
                    {
                        node = iter->second;

                    }
                }
                else
                {
                    maxNum = iter->second.frequency;
                    node = iter->second;
                    //cout << "jj" <<   iter->first<<endl; 
                }
            }
            iter++;
        }



        return node.end - node.start + 1;
    }
};

int main()
{
    std::vector<int> v = { 1,2,2,3,1 };
    Solution().findShortestSubArray(v);
    //cout << Solution().findShortestSubArray(v) << endl;
    return 0;
}
//class Solution {
//public:
//    int findShortestSubArray(vector<int>& nums) {
//        if (nums.empty())
//            return 0;
//        std::unordered_map<int, int> m;
//        for (int i = 0; i < nums.size(); i++)
//            m[nums[i]]++;
//       
//        // 找最大值
//        auto iter = m.begin();
//        int maxNum = iter->first;
//        while (iter != m.end())
//        {
//            if (iter->second > maxNum)
//                maxNum = iter->second;
//            ++iter;
//        }
//
//        int left = 0;
//        while (left < nums.size())
//        {
//            if (nums[left] == maxNum)
//                break;
//            left++;
//            
//        }
//
//        int right = nums.size()-1;
//
//        while (right >= 0)
//        {
//            if (nums[right] == maxNum)
//                break;
//            right--;
//        }
//        return right - left + 1;
//    }
//};
//int main()
//{
//    std::vector<int> v = { 1 };
//    cout << Solution().findShortestSubArray(v) << endl;
//    return 0;
//}