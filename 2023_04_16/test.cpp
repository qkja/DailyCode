#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
//class Solution {
//public:
//    //https://leetcode.cn/problems/jump-game/
//    bool canJump(vector<int>& nums) {
//        if (nums.empty())
//            return false;
//        int maxNum = nums[0];
//        for (int i = 1; i < nums.size(); i++)
//        {
//            if (i <= maxNum)
//            {
//                // ���Ե���, ������Զλ��
//                if (i + nums[i] > maxNum)
//                    maxNum = i + nums[i];
//            }
//            else
//            {
//                return false;
//            }
//        }
//        return maxNum >= nums.size() - 1;
//    }
//};

//struct cmp
//{
//	bool operator()(const vector<int>& v1, const vector<int>& v2)
//	{
//		return v1[0] > v2[0];
//	}
//};
//
//int solve(vector<vector<int>>& moneyCount, int money)
//{
//	int num = 0;
//	//����ѡ�������ֵ��ֽ��
//	std::sort(moneyCount.begin(), moneyCount.end(), cmp());
//	// v[0]--> ��ֵ
//	// v[1]--> ����
//	for (auto& v : moneyCount)
//	{
//		int n = money / v[0];
//		n = std::min(n, v[1]);
//		if (money <= 0)
//			break;
//		money -= (n * v[0]);
//		num += n;
//	}
//	if (money > 0)
//		num = -1;
//	return num;
//}

//int main()
//{
//	���ֽ��������: first:ֽ�ң�second:����
//	vector<vector<int>> moneyCount = { { 1, 3 }, { 2, 1 }, { 5, 4 }, { 10, 3 }, { 20, 0
//	}
//	,{50, 1}, { 100, 10 } };
//	int money;
//	cout << "������Ҫ֧����Ǯ" << endl;
//	cin >> money;
//	int res = solve(money, moneyCount);
//	if (res != -1)
//		cout << res << endl;
//	else
//		cout << "NO" << endl;
//	return 0;
//}
////// �ܼ�
//int greedStrategy(vector<int>& works, vector<int>& machines)
//{
//	std::sort(works.begin(), works.end(), std::greater<int>());
//	if (machines.size() >= works.size())
//	{
//		return works[0];
//	}
//
//	for (int i = 0; i < works.size(); i++)
//	{
//		machines[0] += works[i];
//		std::sort(machines.begin(), machines.end(), std::less<int>());
//	}
//
//	return machines.back();
//}
//
//int main()
//{
//	int n, m;
//	cout << "��������ҵ���ͻ�����" << endl;
//	cin >> n >> m;
//	vector<int> works(n);
//	vector<int> machines(m, 0);
//	for (int i = 0; i < n; ++i)
//		cin >> works[i];
//	cout << greedStrategy(works, machines) << endl;
////	return 0;
//}

//7 �ѡ��
//��n����Ҫ��ͬһ��ʹ��ͬһ�����ҵĻa1, a2, ��, an������ͬһʱ��ֻ����һ���ʹ�á�ÿ���a[i]����һ��
//��ʼʱ��s[i]�ͽ���ʱ��f[i]��һ����ѡ��󣬻a[i]��ռ�ݰ뿪ʱ������[s[i], f[i])�����[s[i], f[i])��[s[j], f[j])������
//����a[i]��a[j]������Ϳ��Ա���������һ�졣��ʹ�þ�����Ļ�ܲ���ͻ�ľ��е��������
//struct cmp
//{
//	bool operator()(const std::vector<int>& v1, const std::vector<int>& v2)
//	{
//		return v1[1] < v2[1];
//	}
//};
//int greedyActivitySelector(vector<vector<int>>& act)
//{
//	//v[0] --> ��ʼ  v[1] --> ����
//	std::sort(act.begin(), act.end(), cmp());
	//int count = 1;
	//int endTime = act[0][1];
	//for (auto& e : act)
	//{
	//	if (e[0] >= endTime)
	//	{
	//		count++;
	//		endTime = e[1];
	//	}
	//}
	//return count;
//}
//
//int main()
//{
//	int number;
//	cin >> number;
//	vector<vector<int>> act(number);
//
//	int ret = greedyActivitySelector(act);
//	cout << ret << endl;
//}

//class Solution {
//	struct cmp
//	{
//		bool operator()(const vector<int>& v1, const vector<int>& v2)
//		{
//			return v1[1] < v2[1];
//		}
//	};
//public:
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//
//		if (intervals.empty())
//			return 0;
//		std::sort(intervals.begin(), intervals.end(), cmp());
//		int count = 1;
//		int endTime = intervals[0][1];
//		for (auto& e : intervals)
//		{
//			if (e[0] >= endTime)
//			{
//				count++;
//				endTime = e[1];
//			}
//		}
//		return intervals.size()-count;
//
//    }
//};