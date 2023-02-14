/**
 * User: Qkj
 * Description:
 * Date: 2023-02-14
 * Time: 20:58
 */

#include <iostream>
using namespace std;
class Solution
{
public:
  bool oneEditAway(string first, string second)
  {
    // 直会存在两中情况
    //  替换     --  两个字符串的长度是相等的
    //  删除/增加  --  字符串长度 相差 1
    int s1 = first.size();
    int s2 = second.size();
    int count = 0;
    if (s1 == s2)
    {
      // 替换操作
      for (int i = 0; i < s1; i++)
      {
        if (first[i] != second[i])
          count++;
      }
    }
    else if (s1 - 1 == s2)
    {
      int begin1 = 0;
      int begin2 = 0;
      while (begin1 < s1 && begin2 < s2)
      {
        if (first[begin1] != second[begin2])
        {
          count++;
          begin1++;
        }
        else
        {
          begin1++;
          begin2++;
        }
      }

      // s1 插入了一个元素 或者 s2删除一个长度
    }
    else if (s2 - 1 == s1)
    {
      // s2 插入了一个元素 或者 s1删除一个长度
      int begin1 = 0;
      int begin2 = 0;
      while (begin1 < s1 && begin2 < s2)
      {
        if (first[begin1] != second[begin2])
        {
          count++;
          begin2++;
        }
        else
        {
          begin1++;
          begin2++;
        }
      }
    }
    else
    {
      return false;
    }

    // 这里我们只需要判断  计数器就可以了
    if (count > 1)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
};

// int func(int x, int y)
// {
//   int count = 0;
//   while (x != 0)
//   {
//     int ret = x % y;
//     count = 10 * count + ret;
//     x /= y;
//   }

//   return count;
// }
#include <string>
#include <algorithm>
string func(int x, int y)
{
  const string str = "0123456789ABCDEF";
  string result;
  while (x)
  {
    int ret = x % y; // 此时  ret 我们充当下标
    result += str[ret];
    x /= y;
  }

  // 逆置字符串
  reverse(result.begin(), result.end());
  return result;
}

int main()
{
  int a, b;
  while (cin >> a >> b)
  { // 注意 while 处理多个 case
    cout << func(a, b) << endl;
  }
}