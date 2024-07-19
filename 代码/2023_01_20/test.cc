/**
* User: Qkj
* Description: 
* Date: 2023-01-20
* Time: 23:11
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      if(nums.size() == 0)
      return;
      int left = 0;
      int right = 0;
      while (1)
      {
        if(num)
      }
      
    }


    /// @brief 合并两个有序数组
    /// @param nums1 
    /// @param m 
    /// @param nums2 
    /// @param n 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      // 1. 使用sort
      // 2. 双指针法
      
      // 1230000 1112
      //int begin = m-n; // 还有
      // 我这里都写过,这里使用方法1
      for(int val:nums2)
      {
        nums1[m++] = val;
        //nums1[n++] = val; // 下表不一定对
      }
      sort(nums1.begin(), nums1.end()); // 默认是升序
    }
};