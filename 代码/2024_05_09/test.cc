#include <vector>
#include <algorithm>
using namespace std;

//https://leetcode.cn/problems/non-overlapping-intervals/description/
//class Solution {
//public:
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//      int result = 0;
//      if(intervals.empty())
//        return result;
//      sort(intervals.begin(), intervals.end());
//      int left = intervals[0][0];
//      int right = intervals[0][1];
//      for(int i = 1; i < intervals.size(); ++i)
//      {
//        int a = intervals[i][0];
//        int b = intervals[i][1];
//        if(right > a) // 此时重叠
//        {
//          ++result;
//          right = min(right, b);
//        }
//        else 
//        {
//          left = a;
//          right = b;
//        }
//      }
//      return result;
//    }
//};
//https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      int result = 0;
      if(points.empty())
        return result;
      sort(points.begin(), points.end());
      int left = points[0][0];
      int right = points[0][1];
      result = 1; // 表示第一支箭射雕一个区间
      for(int i = 1; i < points.size(); ++i)
      {
        int a = points[i][0];
        int b = points[i][1];
        if(right >= a) // 有重叠的
        {
          right = min(right, b); // 求交集
        }
        else 
        {
          ++result;
          left = a;
          right = b;
        }
      }
      return result;
    }
};
