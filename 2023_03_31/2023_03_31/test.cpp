#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	*
	*
	* @param str string�ַ���
	* @param k int����
	* @return int����
	*/
	int character_type_num(string& str, int index, int right)
	{
		unordered_set<char> s;
		for (size_t i = index; i <= right; i++)
		{
			s.insert(str[i]);
		}
		return s.size();
	}
	int getMaxValue(string str, int k) {
		// write code here
		return process(str, 0, 0, k);
	}
	// ���� ���� [0,inde] 
	// (index, size)

	int process(string& str, int begin, int end, int k)
	{
		if (1 == k)
		{
			int a = 10;
		}

		if (k == 1 || (end == str.size() && k == 1))
			return (str.size() - begin)* character_type_num(str, begin, str.size() - 1);
		if (end == str.size())
		{
			return -1;
		}
		int p1 = process(str, begin, end + 1, k);
		if (-1 == p1)
		{
			p1 = INT_MAX;
		}

		int p2 = (end - begin + 1)* character_type_num(str, begin, end) +
			process(str, end + 1, end + 1, k - 1);

		return min(p1, p2);

	}
};
int main()
{
	string str = "aba";
	int k = 2;
	cout << Solution().getMaxValue(str, k) << endl;
	return 0;
}


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