/**
 * User: Qkj
 * Description:
 * Date: 2023-03-12
 * Time: 22:41
 */
#include <vector>
#include <deque>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    if (nums.empty() == true)
    {
      return -1;
    }
    vector<int> v(nums.begin(), nums.end());

    // 排序
    sort(v.begin(), v.end(), less<int>());

    // 找 左边界
    int left = -1;
    int right = -1;
    for (int i = 0; i < v.size(); i++)
    {
      if (v[i] != nums[i])
      {
        left = i;
        break;
      }
    }
    if (left == -1)
      return 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
      if (v[i] != nums[i])
      {
        right = i;
        break;
      }
    }
    return right - left + 1;
  }
};

/// @brief 这个可以使用排序.不过这里尝试下优先队列
// class Solution
// {
// public:
//   int thirdMax(vector<int> &nums)
//   {
//     if (nums.empty() == true)
//       return -1;
//     // 找第三个大的数字  -- 建立小堆

//     priority_queue<int, vector<int>, greater<int>> q; // 建立小对
//     unordered_set<int> set;
//     for (auto e : nums)
//     {
//       set.insert(e);
//     }
//     unordered_set<int>::iterator it = set.begin();
//     int i = 0;
//     while (it != set.end())
//     {
//       if (i < 3)
//       {
//         // 入堆
//         q.push(*it);
//         i++;
//       }
//       else
//       {
//         // 判断 如果 当前数据大于堆顶
//         int ret = q.top();
//         if (*it > ret)
//         {
//           q.pop();
//           q.push(*it);
//         }
//       }
//       ++it;
//     }
//     // for (size_t i = 0; i < nums.size(); i++)
//     // {
//     //   if (i < 3)
//     //   {
//     //     // 入堆

//     //     q.push(nums[i]);
//     //   }
//     //   else
//     //   {
//     //     // 判断 如果 当前数据大于堆顶
//     //     int ret = q.top();
//     //     if (nums[i] > ret)
//     //     {
//     //       q.pop();
//     //       q.push(nums[i]);
//     //     }
//     //   }
//     // }
//     if (q.size() != 3)
//     {
//       while (q.size() != 1)
//       {
//         q.pop();
//       }
//     }
//     return q.top();
//   }
// };