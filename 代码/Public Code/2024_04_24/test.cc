#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
//https://leetcode.cn/problems/longest-palindrome/submissions/526753886/
//class Solution {
//public:
//    int longestPalindrome(string s) {
//      int result = 0;
//      std::unordered_map<char, int> m;
//      for(auto& ch : s)
//        m[ch]++;
//      auto iter = m.begin();
//      while(iter != m.end())
//      {
//        result += iter->second / 2 * 2;
//        ++iter;
//      }
//      if(result != s.size())
//        result++;
//      return result;
//    }   
//};
//https://leetcode.cn/problems/longest-palindrome/description/
class Solution {
public:
    vector<int> diStringMatch(string s) {
      int n = s.size();
      std::vector<int> result(n+1, 0);
      int left = 0;
      int right = n;
      for(int i = 0; i < n; ++i)
      {
        if(s[i] == 'I')
          result[i] = left++;
        else 
          result[i] = right--;
      }
      result[n] = left;
      return result;
    }
};

