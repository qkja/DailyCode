/**
 * User: Qkj
 * Description:
 * Date: 2023-03-19
 * Time: 15:27
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
  int maximumProduct(vector<int> &nums)
  {
    if (nums.size() < 3)
    {
      return -1;
    }
    sort(nums.begin(), nums.end(), greater<int>()); // 默认是升序  ,这里我们改成降序
    int max1 = nums[0] * nums[1] * nums[2]; // 都是整数,或者都是负数
    int max2 = nums[0] * nums[nums.size() - 2] * nums[nums.size() - 1]; // 正数和负数混在
    return max(max1, max2);
  }
};

/// @brief 种花问题
// class Solution
// {
// private:
//   bool canPlaceFlowersChild(vector<int> &flowerbed, int left, int right, int n)
//   {
//     if (n == 0)
//     {
//       return true;
//     }
//     if (left > right)
//       return false;
//     if (flowerbed[left] == 0)
//     {
//       // 此时判断 左侧和右侧有没有 花
//       int i = 0;
//       int j = left + 1;
//       /// 更新 i j
//       if (left - 1 >= 0)
//         i = left - 1;
//       if (left + 1 > right)
//         j = right;

//       if (flowerbed[i] == 0 && flowerbed[j] == 0)
//       {
//         // 此时可以了
//         flowerbed[left] = 1;
//         n--;
//       }
//     }
//     return canPlaceFlowersChild(flowerbed, ++left, right, n);
//   }

// public:
//   /// @brief  递归写法
//   /// @param flowerbed
//   /// @param n
//   /// @return
//   bool canPlaceFlowers(vector<int> &flowerbed, int n)
//   {

//     return canPlaceFlowersChild(flowerbed, 0, flowerbed.size() - 1, n);
//   }

//   bool canPlaceFlowers(vector<int> &flowerbed, int n)
//   {
//     flowerbed.insert(flowerbed.begin(), 0);
//     flowerbed.insert(flowerbed.end(), 0);

//     for (int i = 1; i < flowerbed.size() - 1; i++)
//     {
//       if (!flowerbed[i] && !flowerbed[i - 1] && !flowerbed[i + 1])
//       {
//         flowerbed[i] = 1;
//         n--;
//       }
//     }

//     return n <= 0;
//   }
//     /// @brief 给数组的头部和尾部分别添加一个0，然后从下标1开始到倒数第二个遍历数组。
//     ///       如果前一个元素和后一个元素为0，那么这个位置就可以插入1，然后res += 1，最后直接输出res >= n即可
//     /// @param flowerbed
//     /// @param n
//     /// @return
//     // bool canPlaceFlowers(vector<int> &flowerbed, int n)
//     // {
//     //   int count = 0;

//     //   for (size_t i = 0; i < flowerbed.size(); i++)
//     //   {

//     //     if (i == 0)
//     //     {
//     //       if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)
//     //       {
//     //         flowerbed[i] = 1;
//     //         count++;
//     //       }
//     //     }
//     //     else if (i == flowerbed.size() - 1)
//     //     {
//     //       if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
//     //       {
//     //         flowerbed[i] = 1;
//     //         count++;
//     //       }
//     //     }
//     //     else
//     //     {
//     //       if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
//     //       {
//     //         flowerbed[i] = 1;
//     //         count++;
//     //       }
//     //     }
//     //   }
//     //   return count >= n;
//     // }
//   };

// class Solution
// {
// private:
//   bool canPlaceFlowersChild(vector<int> &flowerbed, int left, int right, int n)
//   {
//     if(left > right)
//     {
//       return false;
//     }
//     if (n == 0 && left <= right)
//     {
//       return true;
//     }
//     if (flowerbed[left] == 0)
//     {
//       // 此时判断 左侧和右侧有没有 花
//       int i = 0;
//       int j = 0;
//       if (left - 1 >= 0)
//         i = left - 1;

//       j = left + 1;
//       if (left + 1 > right)
//         j = right;
//       if (flowerbed[i] == 0 && flowerbed[j] == 0)
//       {
//         // 此时可以了
//         flowerbed[left] = 1;
//         n--;
//       }
//     }
//     return canPlaceFlowersChild(flowerbed, ++left, right, n);
//   }

// public:
//   bool canPlaceFlowers(vector<int> &flowerbed, int n)
//   {

//     return canPlaceFlowersChild(flowerbed, 0, flowerbed.size() - 1, n);
//   }
// };