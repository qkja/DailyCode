/**
 * User: Qkj
 * Description:
 * Date: 2023-02-06
 * Time: 22:02
 */
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  string decodeString(string s)
  {
    string count;
    stack<int> s1;
    stack<char> s2;
    string result;
    vector<string> v;
    string sss;
    for(char ch:s)
    {
      
      if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
      {
        sss+=ch;
      }
      else if(ch == '[')
      {
        // 此时转换数字
        int ret = atoi(count.c_str());
        count.clear();
        // 入栈
        s1.push(ret);

        //s2.push()
      }
      else if(ch == ']')
      {
        if (!sss.empty())
        {
          v.push_back(sss);
          sss.clear();
        }
      }
      else 
      {
        if(!sss.empty())
        {
          v.push_back(sss);
          sss.clear();
        }
        count+=ch;
      }
    }
    for(int i = v.size()-1; i >0;i--)
    {
      int ret  = s1.top();
      s1.pop();
      for(int j = 0; j< ret;j++)
      {
        v[i-1] += v[i];
      }
    }

    int ret = s1.top();
    s1.pop();
    for (int j = 0; j < ret; j++)
    {
      v[0] += v[1];
    }

  return v[0];
  }
};

// class Solution
// {
// public:
//   bool checkAlmostEquivalent(string word1, string word2)
//   {
//     std::vector<int> v;
//     v.resize(26, 0);
//     for (char ch : word1)
//     {
//       v[ch - 'a']++;
//     }
//     for (char ch : word2)
//     {
//       v[ch - 'a']--;
//     }
//     for (int i = 0; i < v.size(); i++)
//     {
//       if (!(v[i] >= -3 && v[i] <= 3))
//         return false;
//     }
//     return true;
//   }
// };

// class Solution
// {
// public:
//   bool halvesAreAlike(string s)
//   {
//     const string str = "aeiouAEIOU";
//     int size = s.size();
//     if (size == 0 || size % 2 != 0)
//       return false;
//     int count = 0;
//     for (size_t i = 0; i < size; i++)
//     {
//       if (i < size / 2)
//       {
//         if (str.find(s[i]) != string::npos)
//           count++;
//       }
//       else
//       {
//         if (str.find(s[i]) != string::npos)
//           count--;
//       }
//     }
//     return count == 0;
//   }
// };

// class Solution
// {
// public:
//   /// @brief
//   /// @param s
//   /// @param t
//   /// @return
//   bool isAnagram(string s, string t)
//   {
//     unordered_map<char, int> m1;
//     // unordered_map<char, int> m2;

//     for (char ch : s)
//     {
//       m1[ch]++;
//     }

//     for (char ch : t)
//     {
//       int ret = m1[ch];
//       if (ret == 0)
//       {
//         return false;
//       }
//       else if (ret == 1)
//       {
//         m1.erase(ch);
//       }
//       else
//       {
//         m1[ch]--;
//       }
//     }
//     return m1.empty();
//   }
// };