#include <vector>
using namespace std;
// https://leetcode.cn/problems/jump-game-ii/
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//      int left = 0;
//      int right = 0;
//      int result = 0;
//      while(right < (int)nums.size()-1)
//      {
//        ++result;
//        // 先更新right
//        int i = 0;
//        int oldRight = right;
//        for(i = left; i <= oldRight; ++i)
//          right = std::max(right, nums[i]+i);
//        // 更新left
//        left = i;
//      }
//      return result;
//    }
//};


//https://leetcode.cn/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int left = 0;
      int right = 0;
      int maxPos = 0;
      while(left <= right)
      {
        if(maxPos >= nums.size() - 1)
          return true;
        for(int i = left; i <= right; i++)
          maxPos = std::max(maxPos, i+nums[i]);
        left = right+1;
        right = maxPos;
      }
      return  false;
    }
};
