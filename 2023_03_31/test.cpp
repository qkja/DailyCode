#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;
//class Solution {
//public:
//	bool is_nondecreasing(vector<int>& nums) {
//
//		for (int i = 0; i < nums.size() - 1; i++)
//		{
//			if (nums[i] > nums[i + 1])
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//	bool checkPossibility(vector<int>& nums) {
//		if (nums.empty())
//			return true;
//
//		for (int i = 0; i < nums.size() - 1; i++)
//		{
//			if (nums[i] > nums[i + 1])
//			{
//				// x   y   z -->  9  10  8
//				if (i == 0)
//				{
//					// 不存在下面的数据   10  8
//					nums[0] = nums[1];
//				}
//				else
//				{
//					// 存在
//					if (nums[i + 1] < nums[i - 1])
//					{
//						//情况1: 9  10  1
//						nums[i + 1] = nums[i];
//
//					}
//					else
//					{
//						//情况1 12  15  18
//						nums[i] = nums[i + 1];
//					}
//
//				}
//
//				return is_nondecreasing(nums);
//			}
//		}
//		return true;
//	}
};


//class Solution {
//public:
//	bool checkPossibility(vector<int>& nums) {
//		if (nums.empty())
//			return true;
//		int count = 0;
//		for (int i = 0; i < nums.size() - 1; i++)
//		{
//			if (nums[i] > nums[i + 1])
//				count++;
//		}
//		return count;
//	}
//};



//class Solution {
//public:
//	bool checkPossibility(vector<int>& nums) {
//		if (nums.empty())
//			return true;
//		int count = 0;
//		for (size_t i = 1; i < nums.size(); i++)
//		{
//			if (nums[i] < nums[i - 1])
//			{
//				nums[i] = nums[i - 1];
//				count;
//			}
//		}
//		return 1 >= count;
//	}
//};




//int main()
//{
//	
//	return 0;
//}














//// �������
//class Solution {
//public:
//	double findMaxAverage(vector<int>& nums, int k) {
//		if (nums.empty() || k <= 0 || nums.size() < k)
//			return -1;
//		int start = 0;
//		int end = k;
//		int sum = 0;
//		for (int i = start; i < end; i++)
//		{
//			sum += nums[i];
//		}
//		int maxSum = sum;
//		for (int i = end; i < nums.size(); i++)
//		{
//			sum -= nums[start++];
//			sum += nums[i];
//			maxSum = max(sum, maxSum);
//		}
//		return 1.0 * maxSum / k;
//	}
//};





//class Solution {
//public:
//	double findMaxAverage(vector<int>& nums, int k) {
//		if (nums.empty() || k <= 0 || nums.size() < k)
//			return -1;
//		int start = 0;
//		int end = k;
//		int sum = 0;
//		for (int i = start; i < end; i++)
//		{
//			sum += nums[i];
//		}
//		for (int i = end; i < nums.size(); i++)
//		{
//			start++;
//
//			int ret = 0;
//			for (int j = start; j <= i; j++)
//			{
//				ret += nums[j];
//			}
//			sum = max(ret, sum);
//		}
//		return 1.0 * sum / k;
//	}
//};
//int main()
//{
//	vector<int> v = { 1, 12, -5, -6, 50, 3 };
//	int k = 4;
//	Solution().findMaxAverage(v, k);
//	return 0;
//}







//class Solution {
//public:
//    //https ://www.bilibili.com/video/BV1HL411o7xo/?spm_id_from=333.999.0.0&vd_source=f620d34672b4b63d0b8c61e24843d4c0
//    void rotate(vector<vector<int>>& matrix) {
//        if (matrix.empty())
//            return;
//        // ���Ͻ�
//        int a = 0;
//        int b = 0;
//
//        // ���½�
//        int c = matrix.size() - 1;
//        int d = matrix.size() - 1;
//        while (a < c)
//        {
//            rotateEdge(matrix, a++, b++, c--, d--);
//        }
//    }
//    void rotateEdge(vector<vector<int>>& matrix, int a, int b, int c, int d)
//    {
//        // ���￪ʼ��ת
//        for(int i = 0; i < c-a; i++)
//        {
//            // ���� ��������
//            int x = matrix[a][b+i];  
//            int y = matrix[a+i][d];
//			int m = matrix[c][d - i];
//			int n = matrix[c-i][b];
//
//			matrix[a][b + i] = n;
//			matrix[a + i][d] = x;
//			matrix[c][d - i] = y;
//			matrix[c - i][b] = m;
//        }
//    }
//
//};



//class Solution {
//public:
//	/**
//	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//	*
//	*
//	* @param str string�ַ���
//	* @param k int����
//	* @return int����
//	*/
//	int character_type_num(string& str, int index, int right)
//	{
//		unordered_set<char> s;
//		for (size_t i = index; i <= right; i++)
//		{
//			s.insert(str[i]);
//		}
//		return s.size();
//	}
//	int getMaxValue(string str, int k) {
//		// write code here
//		return process(str, 0, 0, k);
//	}
//	// ���� ���� [0,inde] 
//	// (index, size)
//
//	int process(string& str, int begin, int end, int k)
//	{
//		if (1 == k)
//		{
//			int a = 10;
//		}
//
//		if (k == 1 || (end == str.size() && k == 1))
//			return (str.size() - begin)* character_type_num(str, begin, str.size() - 1);
//		if (end == str.size())
//		{
//			return -1;
//		}
//		int p1 = process(str, begin, end + 1, k);
//		if (-1 == p1)
//		{
//			p1 = INT_MAX;
//		}
//
//		int p2 = (end - begin + 1)* character_type_num(str, begin, end) +
//			process(str, end + 1, end + 1, k - 1);
//
//		return min(p1, p2);
//
//	}
//};
//int main()
//{
//	string str = "aba";
//	int k = 2;
//	cout << Solution().getMaxValue(str, k) << endl;
//	return 0;
//}


//class Solution {
//public:
//	/**
//	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//	*
//	*
//	* @param str string�ַ���
//	* @param k int����
//	* @return int����
//	*/
//	int character_type_num(string& str, int index)
//	{
//		unordered_set<char> s;
//		for (size_t i = index; i < str.size(); i++)
//		{
//			s.insert(str[i]);
//		}
//		return s.size();
//	}
//
//	int getMaxValue(string str, int k) {
//		// write code here
//		return process(str, 0, k);
//	}
//	// ���ǲ���ע [0, index) ֮ǰ��
//	// ֻ��ע [index, size)
//	// k �������зֵĴ���
//	int process(string& str, int index , int k)
//	{
//		if (k <= 0)
//		{
//			return 0;
//		}
//		if (index == str.size())
//			return 0; // ��ʱ����
//
//		// �����ⲻ�з�  
//		int num = character_type_num(str, index);
//		int len = str.size() - index;
//		int v1 = len * num + ;
//
//		int v2 = 1 + process(str, index + 1, k-1);
//		return min(v1, v2);
//	}
//};

//class Solution {
//public:
//	/**
//	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//	*
//	*
//	* @param str string�ַ���
//	* @param k int����
//	* @return int����
//	*/
//	int getMaxValue(string str, int k) {
//		// write code here
//		return process(str, 0);
//	}
//	// ���ǲ���ע [0, index) ֮ǰ��
//	// ֻ��ע [index, size)
//	int character_type_num(string& str, int index)
//	{
//		unordered_set<char> s;
//		for (size_t i = index; i < str.size(); i++)
//		{
//			s.insert(str[i]);
//		}
//		return s.size();
//	}
//	int process(string& str, int index)
//	{
//		if (index == str.size())
//			return 0; // ��ʱ����
//
//		// �����ⲻ�з�
//		int num = character_type_num(str, index);
//		int len = str.size() - index;
//		int v1 = len * num;
//
//		int v2 = 1 + process(str, index + 1);
//		return min(v1, v2);
//	}
//};