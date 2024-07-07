#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:

    
    //https://leetcode.cn/problems/binary-search/submissions/
    int search(vector<int>& nums, int target) {
        // ���ֲ��ҳ�������
        // ѭ���ж�
        // left �� right �ĸ���
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

        // 1. ʹ�ÿ⺯��  ע��erase ��O��n��
        //if (nums.empty())
        // return 0;
        //std::vector<int>::iterator iter = nums.begin();
        //while (iter != nums.end())
        //{
        //    if (*iter == val)
        //    {
        //        // ע�������ʧЧ������
        //        iter = nums.erase(iter);
        //    }
        //    else
        //    {
        //        ++iter;
        //    }
        //}
        //return nums.size();

        // 2. ����ʵ�� ����forѭ�� -- �ⲻ˵
        // 3. ˫ָ�� ˼·O(n) �����ǿ���ָ��
        // ���������һ������Ŀռ���ʵ�ֵ�,ֱ���ϴ���
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
        // 1. �����ⷨ ʹ�ÿ�������  -- O(N)logN
        // 2. ʹ��˫ָ��   
        // �������������ǵ������Ƿǵݼ���,��ô��ʱ������һ���������ҵĴ�,�������ڴ��ڸ���
        // ��ʱƽ����Ͳ�һ������,����������������
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
                // ������Ϊ�� ����i == j ���
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
