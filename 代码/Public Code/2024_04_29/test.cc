#include <iostream>
#include <string>
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


//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//      int n = gas.size();
//
//      for(int i = 0; i < n; ++i)
//      {
//        int rest = 0;
//        int step = 0;
//        for(; step < n; ++step)
//        {
//          int index = (i+step)%n;
//          rest = rest + gas[index] - cost[index];
//          if(rest < 0)
//            break;
//        }
//        if(rest >= 0)
//          return i;
//        i += step;
//      }
//      return -1;
//    }
//};




//https://leetcode.cn/problems/monotone-increasing-digits
//class Solution {
//public:
//    int monotoneIncreasingDigits(int n) 
//    {
//      std::string str = std::to_string(n);
//      for(int i = 1; i < str.size(); ++i)
//      {
//        if(str[i] < str[i-1])
//        {
//          // 可以更新;了,找第一个相似的
//          for(int j = i-1; j >= 0; --j)
//          {
//            if(str[j] != str[i])
//            {
//              str[j] = str[j] -1;
//              j++;
//              for(;j < str.size(); j++)
//                str[j] = '9';
//              
//              if(str[0] == '0')
//                return std::stoi(str.erase(0,1));
//              else 
//                return stoi(str);
//            }
//          }
//        }
//      }
//      return 0;
//    }
//};



class Solution {
public:
    int monotoneIncreasingDigits(int n) {
      std::string str = to_string(n);
      int i = 0;
      for(i = 0; i < str.size()-1; ++i)
      {
        if(str[i] > str[i+1])
          break;
      }
      if(i == str.size() - 1)
        return n;
      int j = 0;
      for(j = i - 1; j >=0; --j)
      {
        if(str[j] != str[i])
          break;
      }
      // 将j+1 变换一下
      str[j+1] = str[j+1] - 1;
      for(j = j+2; j < str.size(); j++)
        str[j] = '9';
      if(str[0] == '0')
        return stoi(str.erase(0, 1));
      return stoi(str);
    }
};
