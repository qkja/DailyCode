#include <algorithm>
#include <unordered_map>

using namespace std;

//https://leetcode.cn/problems/integer-replacement/description/
class Solution {
public:
  unordered_map<int, int> hash;
    int dfs(long long n)
    {
      if(hash.count(n))
        return hash[n];
      if(1 == n)
      {
        hash[1] = 0;
        return 0;
      }
      if(n % 2 == 0)
      {
       hash[n] = dfs(n/2) + 1;
       return hash[n];
      }
      else 
      {
        hash[n] = min(dfs(n+1), dfs(n-1)) + 1;
        return hash[n];
      }
    }
    int integerReplacement(int n) {
      return dfs(n);
    }
};
