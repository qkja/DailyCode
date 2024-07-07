#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
using namespace std;

//https://leetcode.cn/problems/greatest-sum-divisible-by-three/description/
//class Solution {
//public:
//    int maxSumDivThree(vector<int>& nums) {
//      int sum = 0;
//      const int INT = 0x3f3f3f3f;
//      int x1 = INT, x2 = INT;
//      int y1 = INT, y2 = INT;
//
//      for(int i = 0; i < nums.size(); ++i)
//      {
//        sum += nums[i];
//        if(nums[i] % 3 == 1)
//        {
//          if(nums[i] < x1)
//          {
//            x2 = x1;
//            x1 = nums[i];
//          }
//          else if (nums[i] < x2)
//          {
//            x2 = nums[i];
//          }
//        }
//        else if(nums[i] % 3 == 2)
//        {
//          if(nums[i] < y1)
//          {
//            y2 = y1;
//            y1 = nums[i];
//          }
//          else if ( nums[i] < y2)
//          {
//            y2 = nums[i];
//          }
//        }
//      }
//      if(0 == sum % 3)
//        return sum;
//      else if(1 == sum % 3)
//      return max(sum-x1, sum - y1-y2);
//      else 
//        return max(sum -x1-x2, sum -y1);
//    }
//};
//https://leetcode.cn/problems/distant-barcodes/description/
//class Solution {
//public:
//    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
//
//      unordered_map<int, int> hash;
//      int maxVal = 0;
//      int maxCount = 0;
//      for(int i = 0; i < barcodes.size(); ++i)
//      {
//        hash[barcodes[i]]++;
//        if(hash[barcodes[i]] > maxCount)
//        {
//          maxCount = hash[barcodes[i]];
//          maxVal = barcodes[i];
//        }
//      }
//      // 先拿我们最大的
//      int i = 0;
//      while(maxCount--)
//      {
//        barcodes[i] = maxVal;
//        i+=2;
//      }
//      hash.erase(hash.find(maxVal));
//      auto iter = hash.begin();
//      while(iter != hash.end())
//      {
//        for(int j = 0; j < iter->second; ++j)
//        {
//          if(i >= barcodes.size())
//          {
//            i = 1;
//          }
//          barcodes[i] = iter->first;
//          i += 2;
//        }
//        ++iter;
//      }
//      return barcodes;
//    }
//};

//https://leetcode.cn/problems/reorganize-string/description/
class Solution {
public:
    string reorganizeString(string s) {
      unordered_map<char, int> hash;
      int maxCount = 0;
      char maxVal = ' ';
      for(auto e : s)
      {
        if(maxCount < ++hash[e])
        {
          maxCount = hash[e];
          maxVal = e;
        }
      }
      if(maxCount > (s.size()+1)/2)
        return "";
      int index = 0;
      for(int i = 0; i < maxCount; ++i)
      {
        s[index] = maxVal;
        index += 2;
      }
      hash.erase(hash.find(maxVal));
      for(auto iter = hash.begin(); iter != hash.end(); ++iter)
      {
        for(int i = 0; i < iter->second; ++i)
        {
          if(index >= s.size()) index = 1;
          s[index] = iter->first;
          index += 2;
        }
      }
      return s;
    }
};

