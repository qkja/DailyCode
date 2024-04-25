#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//https://leetcode.cn/problems/assign-cookies/
//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//      if(g.empty() || s.empty())
//        return 0;
//      std::sort(g.begin(), g.end());
//      std::sort(s.begin(), s.end());
//
//      int begin = 0;
//      for(int i = 0; i < s.size(); ++i)
//      {
//        if(begin < g.size() && s[i] >= g[begin])
//        {
//          ++begin;
//        }
//      }
//      return begin;
//    }
//};


//https://leetcode.cn/problems/optimal-division/
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
      string result;
      if(nums.empty())
        return result;
      if(1 == nums.size())
        return std::to_string(nums[0]);
      if(2 == nums.size())
        return std::to_string(nums[0]) + '/' + std::to_string(nums[1]);
      result = std::to_string(nums[0]) + "/(";
      for(int i = 1; i < nums.size(); ++i)
      {
        result += std::to_string(nums[i]);
        result += '/'; 
      }

      result.pop_back();
      result += ')'; 
      return result;
    }
};
