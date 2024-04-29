#include <iostream>
#include <vector>
using namespace std;

//https://leetcode.cn/problems/gas-station/
//class Solution {
//public:
//    // 暴力解法: 超出时间限制
//    //int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//    //  std::vector<int> diff(gas.size());
//    //  for(int i = 0; i < gas.size(); ++i)
//    //    diff[i] = gas[i] - cost[i];
//    //  int result = 0;
//    //  while(result < diff.size())
//    //  {
//    //    if(diff[result] < 0)
//    //    {
//    //      result++;
//    //      continue;
//    //    }
//    //    int sum = diff[result];
//    //    int j = 0;
//    //    // 看右侧的
//    //    for(j = result+1; j < diff.size(); ++j)
//    //    {
//    //      sum += diff[j];
//    //      if(sum < 0)
//    //        break;
//    //    }
//    //    if(j != diff.size())
//    //    {
//    //      result++;
//    //      continue;
//    //    }
//
//    //    // 看左侧的
//    //    for(j = 0; j < result; ++j)
//    //    {
//    //      sum += diff[j];
//    //      if(sum < 0)
//    //      {
//    //        break;
//    //      }
//    //    }
//    //    if(j == result)
//    //      return result;
//    //    result++;
//    //  }
//    //  return -1;
//    //}
//    
//    // 还是暴力解法,但是我们只使用一个for循环
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//      std::vector<int> diff(gas.size());
//      for(int i = 0; i < gas.size(); ++i)
//        diff[i] = gas[i] - cost[i];
//      int result = 0;
//      while(result < diff.size())
//      {
//        int sum = diff[result];
//        int i = 0;
//        for(i = result+1; i < result+diff.size(); ++i)
//        {
//          if(sum < 0)
//            break;
//          sum += diff[i%diff.size()];
//        }
//        if((i%(int)diff.size()) == result)
//          return result;
//        result++;
//      }
//      return -1;
//    }
//};

//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//std::vector<int> diff(gas.size());
//      for(int i = 0; i < gas.size(); ++i)
//        diff[i] = gas[i] - cost[i];
//      int result = 0;
//      while(result < diff.size())
//      {
//
//        std::cout << result << std::endl;
//        if(diff[result] < 0)
//        {
//            result++;
//            continue;
//        }
//        std::cout << result << std::endl;
//        int sum = diff[result];
//        int i = 0;
//        for(i = result+1; i < result+diff.size(); ++i)
//        {
//         sum += diff[i%diff.size()];
//         
//          if(sum < 0)
//            break;
//        }
//        if((i%(int)diff.size()) == result)
//          return result;
//        result++;
//      }
//      return -1;
//
//    }
//};
//
//int main()
//{
//  std::vector<int> v1 = {1,2,3,4,5};
//  std::vector<int> v2 = {3,4,5,1,2};
//  Solution().canCompleteCircuit(v1,v2);
//  return 0;
//}


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();

      for(int i = 0; i < n; ++i)
      {
        int rest = 0;
        int step = 0;
        for(; step < n; ++step)
        {
          int index = (i+step)%n;
          rest = rest + gas[index] - cost[index];
          if(rest < 0)
            break;
        }
        if(rest >= 0)
          return i;
        i += step;
      }
      return -1;
    }
};

