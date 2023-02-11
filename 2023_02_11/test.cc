/**
 * User: Qkj
 * Description:
 * Date: 2023-02-11
 * Time: 19:05
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include <algorithm>
using namespace std;

class Solution
{
public:
  struct myFunc
  {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
      return (p1.second > p2.second) || (p1.second ==  p2.second && p1.first < p2.first);
    }
  };

  vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
  {
    unordered_map<int, int> m;
    for (size_t i = 0; i < mat.size(); i++)
    {
      int ret = 0;
      for (size_t j = 0; j < mat[i].size(); j++)
      {
        ret += mat[i][j];
      }
      m.insert(make_pair(i, ret));
    }

    // topK问题  使用堆 这里
    priority_queue<pair<int, int>, vector<pair<int, int>>, myFunc> p;
    auto it = m.begin();
    while (it != m.end())
    {
      if (p.size() < k)
      {
        // 这里建堆
        p.push(*it);
      }
      else
      {
        // 判断 f 是下标  s 是  武力
        int f1 = it->first;
        int s1 = it->second;

        int f2 = p.top().first;
        int s2 = p.top().second();

        // 注意 我们建立的说大堆
        if (s1 < s2 || (s1 == s2 && f1 < f2))
        {
          p.pop();
          p.push(*it);
        }
      }
      it++;
    }

    // 拿到堆顶的元素额
    vector<int> v;
    v.resize(k);
    while (p.empty())
    {
      v[--k](p.top().first);
      p.pop();
    }
    return v;
  }
};

// class Solution
// {
// public:
//   vector<string> commonChars(vector<string> &words)
//   {
//     vector<string> result;

//     for (auto &e : words)
//     {

//     }
//   }
// };

// class Solution
// {
// public:
//   void duplicateRemoval(vector<string> &v, const string &str)
//   {
//     unordered_set<int> s;
//     for (auto &ch : str)
//     {
//       s.insert(ch);
//     }
//     string ret;
//     auto it = s.begin();
//     while (it != s.end())
//     {
//       ret += *it;
//       it++;
//     }
//     v.push_back(move(ret));
//   }

//   vector<string>
//   commonChars(vector<string> &words)
//   {
//     vector<string> result;
//     vector<string> v;
//     v.reserve(words.size());
//     for (auto &e : words)
//     {
//       duplicateRemoval(v, e);
//     }

//   }
// };
// class Solution
// {
// public:
//   string kthDistinct(vector<string> &arr, int k)
//   {
//     unordered_map<string, int> m;
//     for(auto& e:arr)
//     {
//       m[e]++;
//     }
//     for (auto &e : arr)
//     {
//       auto it = m.find(e);
//       if(it->second == 1)
//       {
//         k--;
//         if(k == 0)
//         {
//           return it->first;
//         }
//       }
//     }
//     return "";
//   }
// };

// class Solution
// {
// public:
//   void subStr(vector<string> &v, const string &str)
//   {
//     int begin = 0;
//     size_t pos = str.find(' ');

//     while (pos != string::npos)
//     {
//       v.push_back(str.substr(begin, pos - begin));
//       begin = pos + 1;
//       pos = str.find(' ', begin);
//     }
//     v.push_back(str.substr(begin, pos - begin));
//   }
//   vector<string> uncommonFromSentences(string s1, string s2)
//   {
//     vector<string> result;
//     vector<string> v;
//     unordered_map<string, int> m;
//     subStr(v, s1);
//     subStr(v, s2);
//     for (auto &e : v)
//     {
//       m[e]++;
//     }

//     // 遍历整个map
//     auto it = m.begin();
//     while (it != m.end())
//     {
//       if (it->second == 1)
//       {
//         result.push_back(it->first);
//       }
//       it++;
//     }
//     return result;
//   }
// };
// int main()
// {
//   string s1 = "this apple is sweet";
//   string s2 = "this apple is sour";
//   vector<string> v = Solution().uncommonFromSentences(s1, s2);
//   for (auto e : v)
//   {
//     cout << e << endl;
//   }
//   return 0;
// }

// class Solution
// {
// public:
//   bool isNotSame(const string &str)
//   {
//     unordered_set<char> s;
//     for (char ch : str)
//     {
//       s.insert(ch);
//     }
//     return s.size() == 3;
//   }

//   int countGoodSubstrings(string s)
//   {
//     int begin = 0;

//     int end = begin + 3;
//     int count = 0;
//     while (end <= s.size())
//     {
//       bool ret = isNotSame(s.substr(begin, end - begin));
//       if (ret == true)
//         count++;
//       begin++;
//       end++;
//     }
//     return count;
//   }
// };

// class Solution
// {
// public:
//   char findTheDifference(string s, string t)
//   {
//     unordered_map<char, int> m1;
//     unordered_map<char, int> m2;
//     for (char ch : s)
//     {
//       m1[ch]++;
//     }
//     for (char ch : t)
//     {
//       m2[ch]++;
//     }
//     for (char ch : t)
//     {
//       auto it1 = m1.find(ch);
//       if (it1 == m1.end())
//         return ch;
//       auto it2 = m2.find(ch);
//       if (it1->second != it2->second)
//       {
//         return it1->first;
//       }
//     }
//     return ' ';
//   }
// };

// class Solution
// {
// public:
//   char findTheDifference(string s, string t)
//   {
//     for (char ch : t)
//     {
//       if (s.find(ch) == string::npos)
//       {
//         return ch;
//       }
//     }
//     return ' ';
//   }
// };

// class Solution
// {
// public:
//   uint32_t reverseBits(uint32_t n)
//   {
//     int result = 0;
//     for (int i = 0; i < 32; i++)
//     {
//       // 拿到 最右侧的一位
//       int ret = (n >> i) & 1;
//       result <<= 1;
//       result = result | ret;
//     }
//     return result;
//   }
// };

// class Solution
// {
// public:
//   /**
//    * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//    *
//    *
//    * @param arr intvector
//    * @param k int
//    * @return int
//    */
//   int foundOnceNumber(vector<int> &arr, int k)
//   {
//     // write code here
//     int sum = 0;
//     for (int i = 31; i >= 0; i--)
//     { // int型32位，外层循环32次
//       int cnt = 0;
//       for (int j = 0; j < arr.size(); j++)
//       {
//         cnt += (arr[j] >> i) & 1; // 获得每个数字第i位的和O(n)
//       }
//       sum = 2 * sum + cnt % k;
//     }
//     return sum;
//   }
// };

// class Solution
// {
// public:
//   int numJewelsInStones(string jewels, string stones)
//   {
//     unordered_map<char, int> m;
//     for (auto &ch : stones)
//     {
//       m[ch]++;
//     }
//     int count = 0;
//     for (auto &e : jewels)
//     {
//       auto it = m.find(e);
//       if (it != m.end())
//       {
//         count += it->second;
//       }
//     }
//     return count;
//   }
// };

// class Solution
// {
// public:
//   vector<string> findWords(vector<string> &words)
//   {
//     vector<string> result;

//     if (words.empty())
//       return result;

//     unordered_map<char, int> m;
//     string s = "qwertyuiop";
//     for (char ch : s)
//     {
//       m[ch] = 0;
//     }
//     s = "asdfghjkl";
//     for (char ch : s)
//     {
//       m[ch] = 1;
//     }
//     s = "zxcvbnm";
//     for (char ch : s)
//     {
//       m[ch] = 2;
//     }
//     bool flag = false;
//     int ret = -1;
//     for (auto &e : words)
//     {
//       for (char ch : e)
//       {
//         auto it = m.find(tolower(ch));
//         if (ret == -1)
//         {
//           ret = it->second;
//         }
//         if (ret != it->second)
//         {
//           flag = true;
//           break;
//         }
//       }

//       if (flag == false)
//       {
//         result.push_back(e);
//       }
//       ret = -1;
//       flag = false;
//     }
//     return result;
//   }
// };
