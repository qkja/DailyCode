#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.cn/problems/non-overlapping-intervals/description/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int result = 0;
      if(intervals.empty())
        return result;
      sort(intervals.begin(), intervals.end());
      int left = intervals[0][0];
      int right = intervals[0][1];
      for(int i = 1; i < intervals.size(); ++i)
      {
        int a = intervals[i][0];
        int b = intervals[i][1];
        if(right > a) // 此时重叠
        {
          ++result;
          right = min(right, b);
        }
        else 
        {
          left = a;
          right = b;
        }
      }
      return result;
    }
};
