#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

//https://leetcode.cn/problems/greatest-sum-divisible-by-three/description/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
      int sum = 0;
      const int INT = 0x3f3f3f3f;
      int x1 = INT, x2 = INT;
      int y1 = INT, y2 = INT;

      for(int i = 0; i < nums.size(); ++i)
      {
        sum += nums[i];
        if(nums[i] % 3 == 1)
        {
          if(nums[i] < x1)
          {
            x2 = x1;
            x1 = nums[i];
          }
          else if (nums[i] < x2)
          {
            x2 = nums[i];
          }
        }
        else if(nums[i] % 3 == 2)
        {
          if(nums[i] < y1)
          {
            y2 = y1;
            y1 = nums[i];
          }
          else if ( nums[i] < y2)
          {
            y2 = nums[i];
          }
        }
      }
      if(0 == sum % 3)
        return sum;
      else if(1 == sum % 3)
      return max(sum-x1, sum - y1-y2);
      else 
        return max(sum -x1-x2, sum -y1);
    }
};
