#include <unordered_map>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;




/// @brief 两数之和  -- 第三个解法很有意思
// class Solution
// {
// public:
//   /// @brief  代码有问题,除非我们记录每一个有效值,然后再次循环遍历数组-- 这个代码才可以
//   /// @param nums
//   /// @param target
//   /// @return
//   // vector<int> twoSum(vector<int> &nums, int target)
//   // {
//   //   // 首先我们需要排序-- 这里使用算法库
//   //   // 由于我们没有说 nums是不是可以被改变,所以我们需要重新创建一下
//   //   std::vector<int> help;
//   //   std::vector<int> result;
//   //   help.reserve(nums.size());
//   //   for (int ch : nums)
//   //   {
//   //     help.push_back(ch);
//   //   }
//   //   // 这里进行排序
//   //   std::sort(help.begin(), help.end()); // 默认是升序,这里我们需要复习仿函数,看看博客
//   //   // 此时进行产找
//   //   int left = 0;
//   //   int right = help.size() - 1;
//   //   int val = 0;
//   //   while (left < right)
//   //   {
//   //     int ret = help[left] + help[right];
//   //     if (ret == target)
//   //     {
//   //       val = help[left];
//   //       break;
//   //     }
//   //     else if (ret > target)
//   //     {
//   //       right--;
//   //     }
//   //     else
//   //     {
//   //       left++;
//   //     }
//   //   }
//   //   for (int i = 0; i < nums.size(); i++)
//   //   {
//   //     if (nums[i] == val || nums[i] == target - val)
//   //     {
//   //       result.push_back(i);
//   //     }
//   //   }
//   //   sort(result.begin(), result.end());
//   //   return result;
//   // }

//   /// @brief 下面还是有问题,由于map不可以重复,此时我们需要换一下,这里我们使用以下mul的
//   /// @param nums
//   /// @param target
//   /// @return
//   // vector<int> twoSum(vector<int> &nums, int target)
//   // {
//   //   // [值, 下标] 由于map的底层是搜索树,故他们已经帮助我们排序好了
//   //   std::map<int, int> help;
//   //   std::vector<int> result;
//   //   for (int i = 0; i < nums.size(); i++)
//   //   {
//   //     help[nums[i]] = i;
//   //   }

//   //   // 此时我们继续
//   //   std::map<int, int>::iterator left = help.begin();
//   //   std::map<int, int>::iterator right = help.end();
//   //   right--;
//   //   while (left != right)
//   //   {
//   //     int ret = left->first + right->first;
//   //     if (ret == target)
//   //     {
//   //       result.push_back(left->second);
//   //       result.push_back(right->second);
//   //       break;
//   //     }
//   //     else if (ret > target)
//   //     {
//   //       right--;
//   //     }
//   //     else
//   //     {
//   //       left++;
//   //     }
//   //   }
//   //   sort(result.begin(), result.end());
//   //   return result;
//   // }

//   // vector<int> twoSum(vector<int> &nums, int target)
//   // {
//   //   // [值, 下标] 由于map的底层是搜索树,故他们已经帮助我们排序好了
//   //   std::multimap<int, int> help;
//   //   std::vector<int> result;
//   //   for (int i = 0; i < nums.size(); i++)
//   //   {
//   //     help.insert(make_pair(nums[i],i));
//   //   }

//   //   // 此时我们继续
//   //   std::map<int, int>::iterator left = help.begin();
//   //   std::map<int, int>::iterator right = help.end();
//   //   right--;
//   //   while (left != right)
//   //   {
//   //     int ret = left->first + right->first;
//   //     if (ret == target)
//   //     {
//   //       result.push_back(left->second);
//   //       result.push_back(right->second);
//   //       break;
//   //     }
//   //     else if (ret > target)
//   //     {
//   //       right--;
//   //     }
//   //     else
//   //     {
//   //       left++;
//   //     }
//   //   }
//   //   sort(result.begin(), result.end());
//   //   return result;
//   // }

//   /// @brief 另外一个思想, 扫描数组,
//   /// 下面的代码有点凑巧,主要是提议上说了,我们必须有且只有一个答案,这就意味之我们两个个数除非自己相同,否则绝对不会出现相同的情况,我们也是可以使用map或者hash
//   /// 我们从左开始遍历,也就是意味这我们遍历过的数是为了后面的做铺垫,和的两个加数是互相补充的,这就是我们的思想
//   /// @param nums
//   /// @param target
//   /// @return
//   vector<int> twoSum(vector<int> &nums, int target)
//   {
//     // [值,下标] 使用hash查找的快
//     // std::unordered_multimap<int, int> help;
//     std::unordered_map<int, int> help;
//     std::vector<int> result;
//     for (int i = 0; i < nums.size(); i++)
//     {
//       int ret = target - nums[i];
//       // std::unordered_multimap<int, int>::iterator it = help.find(ret);
//       std::unordered_map<int, int>::iterator it = help.find(ret);
//       if (it == help.end())
//       {
//         // 没有找到,直接放入
//         help.insert(make_pair(nums[i], i));
//       }
//       else
//       {
//         // 找到了
//         result.push_back(it->second);
//         result.push_back(i);
//         break;
//       }
//     }
//     return result;
//   }
// };

/// @brief 斐波那契数列
// class Solution
// {
// public:
//   int fib(int n)
//   {
//     if (n == 0 || n == 1)
//       return n;
//     int l = 0;
//     int r = 1;
//     int result = 0;
//     for (int i = 2; i <= n; i++)
//     {
//       result = (l + r) % ((int)(1e9) + 7);
//       l = r;
//       r = result;
//     }
//     return result;
//   }
// };

/// @brief 爬楼梯
// class Solution
// {
// private:
//   /// @brief 这个时间复杂度很高
//   /// @param n
//   /// @return
//   int _climbStairs1(int n)
//   {
//     if (n == 1 || n == 2)
//     {
//       return n;
//     }
//     return _climbStairs1(n - 1) + _climbStairs1(n - 2);
//   }

//   /// @brief 这里我们使用一个map来保存我们已经求取的, 递归写法
//   /// @param n
//   /// @return
//   int _climbStairs2(int n, std::unordered_map<int, int> &result)
//   {
//     if (n == 1 || n == 2)
//     {
//       result[n] = n;
//     }
//     // 查找是不是可以找到
//     std::unordered_map<int, int>::iterator it = result.find(n);
//     if (it != result.end())
//     {
//       return result[n]; // 这里就是V值
//     }

//     int ret = _climbStairs2(n - 1, result) + _climbStairs2(n - 2, result);
//     result[n] = ret;
//     return ret;
//   }
//   /// @brief 循环,也是dp
//   /// @param n
//   /// @return
//   int process3(int n)
//   {
//     if (n == 1 || n == 2)
//     {
//       return n;
//     }
//     int left = 1;
//     int right = 2;
//     int result = 0;
//     for (size_t i = 3; i <= n; i++)
//     {
//       result = left + right;
//       left = right;
//       right = result;
//     }
//     return result;
//   }

// public:
//   int climbStairs(int n)
//   {
//     return process3(n);
//     // if (n <= 0)
//     // {
//     //   return 0;
//     // }
//     // std::unordered_map<int, int> result;
//     // _climbStairs2(n, result);
//     // // return _climbStairs(n);
//     // return result[n];
//   }
// };