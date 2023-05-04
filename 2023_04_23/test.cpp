#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:

    
    //https://leetcode.cn/problems/binary-search/submissions/
    int search(vector<int>& nums, int target) {
        // 二分查找常见错误
        // 循环判断
        // left 和 right 的更新
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

    //https://leetcode.cn/problems/remove-element/
    int removeElement(vector<int>& nums, int val) {

        // 1. 使用库函数  注意erase 是O（n）
        //if (nums.empty())
        // return 0;
        //std::vector<int>::iterator iter = nums.begin();
        //while (iter != nums.end())
        //{
        //    if (*iter == val)
        //    {
        //        // 注意迭代器失效的问题
        //        iter = nums.erase(iter);
        //    }
        //    else
        //    {
        //        ++iter;
        //    }
        //}
        //return nums.size();

        // 2. 暴力实现 两层for循环 -- 这不说
        // 3. 双指针 思路O(n) 这里是快慢指针
        // 这个是利用一个幻想的空间来实现的,直接上代码
        if (nums.empty())
            return 0;
        int fast = 0;
        int slow = 0;
        for (fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] == val)
                continue;
            nums[slow++] = nums[fast];
        }
        return slow;
    }

    // https://leetcode.cn/problems/squares-of-a-sorted-array/
    vector<int> sortedSquares(vector<int>& nums) {
        if (nums.empty())
            return nums;
        // 1. 暴力解法 使用快速排序  -- O(N)logN
        // 2. 使用双指针   
        // 这里是由于我们的数组是非递减的,那么此时最左侧的一定不比最右的大,但是由于存在负数
        // 此时平方后就不一定的了,我们这里这样考虑
       /* int left = 0;
        int right = nums.size()-1;
        while (right > left)
        {
            int val = nums[right] * nums[right];
            int ret = nums[left] * nums[left];

            if (ret >= val)
            {
                nums[left] = nums[right];
                nums[right] = ret;
            }
            else
            {
                nums[right] = val;
            }
            right--;
        }
        return nums;*/

        std::vector<int> result(nums.size());
        int index = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i <= j; )
        {
            int left = nums[i] * nums[i];
            int right = nums[j] * nums[j];
            if (index == 0)
            {
                int c = 0;
            }
            if (left == right)
            {
                i++;
                j--;
                result[index--] = left;
                // 这里是为了 避免i == j 情况
                if(index >= 0)
                    result[index--] = left;
            }
            else if (left > right)
            {
                i++;
                result[index--] = left;
            }
            else
            {
                j--;
                result[index--] = right;
            }
        }
        return result;
    }
};


<<<<<<< HEAD
// int main()
// {

// 	return 0;
// }
=======
int main()
{
    std::vector<int> v = { -4,-1,0,3,10};
    std::vector<int> result = Solution().sortedSquares(v);
    for (auto& e : result)
        std::cout << e << " ";
    std::cout << std::endl;
    return 0;
}
>>>>>>> 54557ef4ba3f76ebef46231044ebe0d5dd21e8c3
