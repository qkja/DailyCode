#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.cn/problems/broken-calculator/description/
//class Solution {
//public:
//    int brokenCalc(int startValue, int target) {
//      int result = 0;
//      while(target != startValue)
//      {
//        if(target % 2 == 1)
//        {
//          ++target;
//          ++result;
//        }
//        else 
//        {
//          if(target <= startValue)
//          {
//            result = result + startValue - target;
//            break;
//          }
//          else 
//          {
//            result++;
//            target /= 2;
//          }
//        }
//      }
//      return result;
//    }
//};

// https://leetcode.cn/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

      vector<vector<int>> result;
      if(intervals.empty()) return result;
      // 排序
      std::sort(intervals.begin(), intervals.end());
      int left = intervals[0][0];
      int right = intervals[0][1];
      for(int i = 1; i < intervals.size(); ++i)
      {
        // 可以合并
        if(intervals[i][0] <= right)
        {
          right = max(right, intervals[i][1]);
        }
        else 
        {
          // 先收集结果
          vector<int> v;
          v.push_back(left);
          v.push_back(right);
          result.push_back(v);
          left = intervals[i][0];
          right = intervals[i][1];
        }
      }
      vector<int> v;
      v.push_back(left);
      v.push_back(right);
      result.push_back(v);
      return result;
    }
};

