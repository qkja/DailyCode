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