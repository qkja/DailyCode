#include <string>
#include <unordered_map>
using namespace std;
//https://leetcode.cn/problems/longest-palindrome/submissions/526753886/
class Solution {
public:
    int longestPalindrome(string s) {
      int result = 0;
      std::unordered_map<char, int> m;
      for(auto& ch : s)
        m[ch]++;
      auto iter = m.begin();
      while(iter != m.end())
      {
        result += iter->second / 2 * 2;
        ++iter;
      }
      if(result != s.size())
        result++;
      return result;
    }   
};
