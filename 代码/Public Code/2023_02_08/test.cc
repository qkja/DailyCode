/**
 * User: Qkj
 * Description:
 * Date: 2023-02-08
 * Time: 20:30
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int FindGreatestSumOfSubArray(vector<int> array)
  {
    if (array.size() == 0)
      return 0;

    int total = array[0];
    int maxSum = total;
    for (size_t i = 1; i < array.size(); i++)
    {
      if (total >= 0)
        total += array[i];
      else
        total = array[i];
      if (maxSum < total)
        maxSum = total;
    }
    return maxSum;
  }
};

// class Solution
// {
// public:
//   vector<int> sortArrayByParityII(vector<int> &nums)
//   {
//     vector<int> result(nums.size(),0);
//     vector<int> odd;  // 奇数
//     vector<int> even; // 偶数
//     for (int val : nums)
//     {
//       if (val % 2 == 0)
//       {
//         even.push_back(val);
//       }
//       else
//       {
//         odd.push_back(val);
//       }
//     }
//     int oddStart = 0;
//     int evenStart = 0;
//     for (int i = 0; i < result.size(); i++)
//     {
//       if (i % 2 == 0)
//       {
//         result[i] = even[evenStart++];
//       }
//       else
//       {
//         result[i] = odd[oddStart++];
//       }
//     }
//     return result;
//   }
// };

// int main()
// {
//   int arr[] = {4, 2, 5, 7};
//   vector<int> v;
//   for (int i = 0; i < 4; i++)
//   {
//     v.push_back(arr[i]);
//   }
//   vector<int> n = Solution().sortArrayByParityII(v);

//   return 0;
// }

// class Solution
// {
// public:
//   // 数组中出现次数超过一半的数字
//   int MoreThanHalfNum_Solution(vector<int> numbers)
//   {
//     if (numbers.empty())
//       return 0;
//     // 这里我们用 打擂台的方式
//     int ret = 0;
//     int flag = 0;

//     for (int i = 0; i < numbers.size(); i++)
//     {
//       if (flag == 0)
//       {
//         ret = numbers[i];
//         flag = 1;
//       }
//       else if (numbers[i] == ret)
//       {
//         flag++; // 遇到相同的 擂台上增加一个
//       }
//       else
//       {
//         flag--;
//       }
//     }
//     // 擂台上站的 一个或者 几个 就是我们要的
//     // 至于是不是要验证一下  这里看题意了
//     int count = 0;
//     for (int i = 0; i < numbers.size(); i++)
//     {
//       if (ret == numbers[i])
//       {
//         count++;
//         if (count > numbers.size() / 2)
//         {
//           return ret;
//         }
//       }
//     }
//     return 0;
//   }
// };

// class Solution
// {
// public:
//   vector<int> twoSum(vector<int> &numbers, int target)
//   {
//     vector<int> result(2, -1);
//     if (numbers.empty())
//       return result;
//     int left = 0;
//     int right = numbers.size() - 1;
//     while (left < right)
//     {
//       int ret = numbers[left] + numbers[right];
//       if (ret == target)
//       {
//         result[0] = left;
//         result[1] = right;
//         break;
//       }
//       else if (ret > target)
//       {
//         right--;
//       }
//       else
//       {
//         left++;
//       }
//     }
//     return result;
//   }
// };

// template <class T>
// struct sum
// {
//   static void foo(T op1, T op2)
//   {
//     cout << op1 << op2;
//   }
// };

// int main()
// {
//   sum<int>::foo(1, 3);
//   return 0;
// }