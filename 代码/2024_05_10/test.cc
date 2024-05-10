#include <algorithm>
#include <unordered_map>

using namespace std;

//https://leetcode.cn/problems/integer-replacement/description/
//class Solution {
//public:
//  unordered_map<int, int> hash;
//    int dfs(long long n)
//    {
//      if(hash.count(n))
//        return hash[n];
//      if(1 == n)
//      {
//        hash[1] = 0;
//        return 0;
//      }
//      if(n % 2 == 0)
//      {
//       hash[n] = dfs(n/2) + 1;
//       return hash[n];
//      }
//      else 
//      {
//        hash[n] = min(dfs(n+1), dfs(n-1)) + 1;
//        return hash[n];
//      }
//    }
//    int integerReplacement(int n) {
//      return dfs(n);
//    }
//};

class Solution {
public:
    int integerReplacement(int n) {
      int result = 0;
      while(1 != n)
      {
        if(0 == n % 2)
        {
          n /= 2;
        }
        else 
        {
          // 查看第二位
          if(3 == n || n % 4 == 1)
            n -= 1;
          else 
          {

            n  = n /2 +1;
            ++result;
          }
        }
        ++result;
      }
      return result;
    }
};
