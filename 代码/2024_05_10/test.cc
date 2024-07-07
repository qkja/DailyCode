#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
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

//class Solution {
//public:
//    int integerReplacement(int n) {
//      int result = 0;
//      while(1 != n)
//      {
//        if(0 == n % 2)
//        {
//          n /= 2;
//        }
//        else 
//        {
//          // 查看第二位
//          if(3 == n || n % 4 == 1)
//            n -= 1;
//          else 
//          {
//
//            n  = n /2 +1;
//            ++result;
//          }
//        }
//        ++result;
//      }
//      return result;
//    }
//};
//https://leetcode.cn/problems/russian-doll-envelopes/
//class Solution {
//public:
//    int maxEnvelopes(vector<vector<int>>& envelopes) {
//      if(envelopes.empty())
//        return 0;
//      int result = 1;
//      int n = envelopes.size();
//      vector<int> dp(n, 1);
//      sort(envelopes.begin(), envelopes.end());
//      dp[0] = 1;
//      for(int i = 1;  i < n; ++i)
//      {
//        for(int j = 0; j < i; ++j)
//        {
//          // 可以套
//          if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
//          {
//            dp[i] = max(dp[i], dp[j]+1);
//          }
//        }
//        result = max(result, dp[i]);
//      }
//      return result;
//    }
//};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      sort(envelopes.begin(), envelopes.end(), [&](vector<int> v1, vector<int> v2){
          return v1[0] != v2[0] ? v1[0] < v2[0] : v1[1] > v2[1];
          });
      vector<int> ret;
      ret.push_back(envelopes[0][1]);
      for(int i = 1; i < envelopes.size(); ++i)
      {
        int b = envelopes[i][1];
        if(b > ret.back())
        {
          ret.push_back(b);
        }
        else 
        {
          int left = 0;
          int right = ret.size()-1;
          while(left < right)
          {
            int mid = (left + right) / 2;
            if(ret[mid] >= b) right = mid;
            else 
              left = mid+1;
          }
          ret[left] = b;
        }
      }
      cout << ret[0] << endl; 
      cout << ret[1] << endl; 
      return ret.size();
    }
};

int main()
{
  vector<vector<int>> v = {{2,3},{5,4}, {6,1}};

  Solution().maxEnvelopes(v);
  return 0;
}
