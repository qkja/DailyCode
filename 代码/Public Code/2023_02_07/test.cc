/**
 * User: Qkj
 * Description:
 * Date: 2023-02-07
 * Time: 19:54
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
  string multiplyChild(const string &str, char ch)
  {
    int i = str.size() - 1;
    int count = 0;
    string result;

    while (i >= 0)
    {
      int ret = (str[i] - '0') * (ch - '0');
      result += std::to_string(((ret + count) % 10));
      count = (count + ret) / 10;
      i--;
    }
    if (count != 0)
      result += to_string(count % 10);
    reverse(result.begin(), result.end());
    return result;
  }
  // 两个字符串相加
  void addition(string &s1, const string &s2)
  {
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    int count = 0;
    string result;
    while (i >= 0 && j >= 0)
    {
      int ret = (s1[i] - '0') + (s2[j] - '0') + count;
      result += to_string(ret % 10);
      count = ret / 10;
      i--;
      j--;
    }
    while (i >= 0)
    {
      // 此时s1还是存在剩余
      int ret = s1[i] - '0' + count;
      result += to_string(ret % 10);
      count = ret / 10;
      i--;
    }
    while (j >= 0)
    {
      // 此时s1还是存在剩余
      int ret = s2[j] - '0' + count;
      result += to_string(ret % 10);
      count = ret / 10;
      j--;
    }
    if (count != 0)
      result += to_string(count);
    reverse(result.begin(), result.end());
    s1 = result;
  }

  string multiply(string num1, string num2)
  {
    if (num1[0] == '0' || num2[0] == '0')
      return "0";
    if (num1.empty())
      return num2;
    if (num2.empty())
      return num1;

    string result;
    string s;
    for (int i = num2.size() - 1; i >= 0; i--)
    {
      // 这里判断一下字符是不是o
      if (num2[i] != '0')
      {
        addition(result, multiplyChild(num1, num2[i]) + s);
      }
      s += "0";
    }
    return result;
  }
};
// class Solution
// {
// public:
//   string multiplyChild(const string &str, char ch)
//   {
//     int i = str.size() - 1;
//     int count = 0;
//     string result;

//     while (i >= 0)
//     {
//       int ret = (str[i] - '0') * (ch - '0');
//       result += std::to_string(((ret + count) % 10));
//       count = (count + ret) / 10;
//       i--;
//     }
//     if (count != 0)
//       result += to_string(count % 10);
//     reverse(result.begin(), result.end());
//     return result;
//   }
//   // 两个字符串相加
//   void addition(string &s1, const string &s2)
//   {
//     int i = s1.size() - 1;
//     int j = s2.size() - 1;
//     int count = 0;
//     string result;
//     while (i >= 0 && j >= 0)
//     {
//       int ret = (s1[i] - '0') + (s2[j] - '0') + count;
//       result += to_string(ret % 10);
//       count = ret / 10;
//       i--;
//       j--;
//     }
//     while (i >= 0)
//     {
//       // 此时s1还是存在剩余
//       int ret = s1[i] - '0' + count;
//       result += to_string(ret % 10);
//       count = ret / 10;
//       i--;
//     }
//     while (j >= 0)
//     {
//       // 此时s1还是存在剩余
//       int ret = s2[j] - '0' + count;
//       result += to_string(ret % 10);
//       count = ret / 10;
//       j--;
//     }
//     if (count != 0)
//       result += to_string(count);
//     reverse(result.begin(), result.end());
//     s1 = result;
//   }

//   string multiply(string num1, string num2)
//   {
//     if (num1.empty())
//       return num2;
//     if (num2.empty())
//       return num1;

//     string result;
//     string s;
//     for (int i = num2.size() - 1; i >= 0; i--)
//     {
//       // 这里判断一下字符是不是o
//       if (num2[i] != '0')
//       {
//         addition(result, multiplyChild(num1, num2[i]) + s);
//       }
//       s += "0";
//     }

//     return result;
//   }
// };

// int main()
// {
//   string s1 = "123";
//   string s2 = "99";
//   Solution().addition(s1, s2);
//   cout << s1 << endl;
//   return 0;
// }

// int main()
// {
//   string s1 = "923";
//   string s2 = "99";
//   Solution().addition(s1, s2);
//   cout << s1 << endl;
//   return 0;
// }

// int main()
// {
//   string s1 = "130";
//   char s2 = '1';
//   cout << Solution().multiplyChild(s1, s2) <<endl;
//   return 0;
// }

// class Solution
// {
// public:
//   string compressString(string S)
//   {
//     if (S.empty())
//       return "";
//     int begin = 0;
//     int end = 0;
//     int count = 0;
//     string result;
//     while (end < S.size())
//     {

//       while (end < S.size() && S[end] == S[begin])
//       {
//         end++;
//         count++;
//       }
//       result+=S[begin];
//       result+=to_string(count);
//       count = 0;
//       begin = end;
//     }
//     if (result.size() < S.size())
//       return result;
//     else
//       return S;
//   }
// };

// class Solution
// {
// public:
//   string compressString(string S)
//   {
//     if (S.empty())
//       return "";
//     int begin = 0;
//     int end = 1;
//     int count = 1;
//     string result;
//     while (end < S.size())
//     {

//       while (end < S.size() && S[end] == S[begin])
//       {
//         end++;
//         count++;
//       }

//       result += S[begin];
//       result += to_string(count);
//       count = 1;
//       begin = end;
//       end++;
//     }
//     if (result.size() <= S.size())
//       return result;
//     else
//       return S;
//   }
// };

// class MyClass
// {
// public:
//   ~MyClass()
//   {
//     delete this;
//     this = NULL;
//   }

// private:
// };

// int main()
// {
//   MyClass m;
//   cout << 11 << endl;
//   /*string str = "leetcode";
//   cout << Solution().maxPower(str) << endl;*/
//   return 0;
// }

// class Solution
// {
// public:
//   int maxPower(string s)
//   {
//     if (s.empty())
//       return 0;
//     int begin = 0;
//     int end = 1;
//     int max = 1;

//     while (end < s.size())
//     {
//       int count = 1;

//       while (end < s.size() && s[end] == s[begin])
//       {
//         end++;
//         count++;
//       }
//       if (count > max)
//       {
//         max = count;
//       }
//       begin = end;
//       end++;
//     }
//     return max;
//   }
// };
// int main()
// {
//   string str = "leetcode";
//   cout << Solution().maxPower(str) << endl;
//   return 0;
// }
// class Solution
// {
// public:
//   string reverseWords(string s)
//   {
//     auto begin = s.begin();
//     auto end = s.begin();
//     while (end != s.end())
//     {
//       if (*end == ' ')
//       {
//         reverse(begin, end);
//         end++;
//         begin = end;
//       }
//       else
//       {
//         end++;
//       }
//     }
//     reverse(begin, end);
//     return s;
//   }
// };

// #include <iostream>
// using namespace std;
// int main(void)
// {
//   const int a = 10;
//   int *p = (int *)(&a);
//   *p = 20;
//   cout << "a = " << a << ", *p = " << *p << endl;
//   return 0;
// }

// class Solution
// {
// public:
//   string decodeString(string s)
//   {

//     stack<pair<int, string>> s1;

//     string count;
//     string sss;
//     for (char ch : s)
//     {

//       if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
//       {
//         sss += ch;
//       }
//       else if (ch == '[')
//       {
//         int ret = atoi(count.c_str());
//         count.clear();
//         s1.push(make_pair(ret, sss));
//         sss.clear();
//       }
//       else if (ch == ']')
//       {
//         pair<int, string> ret = s1.top();
//         s1.pop();
//         string ssss;
//         for (int i = 0; i < ret.first; i++)
//         {
//           ssss += sss;
//         }
//         sss = ssss;
//         sss = ret.second + sss;
//       }
//       else
//       {
//         count += ch;
//       }
//     }
//     return sss;
//   }
// };
// class Solution
// {
// public:
//   string decodeString(string s)
//   {

//     stack<int> s1;
//     vector<string> v;
//     string count;
//     string sss;
//     for (char ch : s)
//     {

//       if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
//       {
//         sss += ch;
//       }
//       else if (ch == '[')
//       {
//         if(!s1.empty())
//         {

//         }
//         // 此时转换数字
//         int ret = atoi(count.c_str());
//         count.clear();
//         // 入栈
//         s1.push(ret);
//       }
//       else if (ch == ']')
//       {
//         if (!sss.empty())
//         {
//           v.push_back(sss);
//           sss.clear();
//         }
//       }
//       else

//         count += ch;
//       }
//     }

// };