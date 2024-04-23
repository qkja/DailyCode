#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/sort-the-people/
// class Solution
// {
// public:
//     vector<string> sortPeople(vector<string> &names, vector<int> &heights)
//     {
//         std::vector<std::string> result;
//         if (names.size() != heights.size())
//             return result;
//         std::vector<int> v(names.size());
//         for (int i = 0; i < names.size(); ++i)
//             v[i] = i;
//         // 经行排序, 重写个表达式
//         std::sort(v.begin(), v.end(), [&heights](int i, int j)
//                   { return heights[i] > heights[j]; });
//         for (int i = 0; i < v.size(); ++i)
//             result.push_back(names[v[i]]);
//         return result;
//     }
// };
// https://leetcode.cn/problems/advantage-shuffle/
// class Solution
// {
// public:
//     vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
//     {
//         vector<int> result(nums1.size());
//         if (nums1.empty() || nums1.size() != nums2.size())
//             return result;
//         std::sort(nums1.begin(), nums1.end());
//         std::vector<int> v(nums2.size());
//         for (int i = 0; i < v.size(); ++i)
//             v[i] = i;
//         std::sort(v.begin(), v.end(), [&nums2](int i, int j)
//                   { return nums2[i] < nums2[j]; });
//         int left = 0;
//         int right = nums2.size() - 1;
//         for (int i = 0; i < nums1.size(); ++i)
//         {
//             if (nums1[i] > nums2[v[left]])
//             {
//                 result[v[left++]] = nums1[i];

//                 // 比不过最小的,带走最大的
//             }
//             else
//             {
//                 result[v[right--]] = nums1[i];
//             }

//         }

//         vector<int> result(nums1.size());
//         for (auto x : nums1)
//          {
//             if (x > nums2[v[left]])
//                 result[v[left++]] = x;
//             else
//                 result[v[right--]] = x;
//         }
//         return result;
//     }
// };

// class Solution
// {
// public:
//     vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
//     {

//         std::sort(nums1.begin(), nums1.end());
//         std::vector<int> v(nums2.size());
//         for (int i = 0; i < v.size(); ++i)
//             v[i] = i;
//         std::sort(v.begin(), v.end(), [&nums2](int i, int j)
//                   { return nums2[i] < nums2[j]; });

//         int left = 0;
//         int right = nums2.size() - 1;
//         vector<int> result(nums1.size());
//         for (int i = 0; i < nums1.size(); ++i)
//         {

//             if (nums1[i] > nums2[v[left]])
//                 result[v[left++]] = nums1[i];
//             else
//                 result[v[right--]] = nums1[i];
//         }

//         return result;
//     }
// };