#include <vector>
using std::vector;

//https://leetcode.cn/problems/binary-search/submissions/
// 二分查找常见错误
// 循环判断
// left 和 right 的更新

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};

int main()
{

    return 0;
}