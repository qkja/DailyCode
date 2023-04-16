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
//                // 可以到达, 更新最远位置
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
//	//首先选择最大面值的纸币
//	std::sort(moneyCount.begin(), moneyCount.end(), cmp());
//	// v[0]--> 面值
//	// v[1]--> 个数
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
//	存放纸币与数量: first:纸币，second:数量
//	vector<vector<int>> moneyCount = { { 1, 3 }, { 2, 1 }, { 5, 4 }, { 10, 3 }, { 20, 0
//	}
//	,{50, 1}, { 100, 10 } };
//	int money;
//	cout << "请输入要支付的钱" << endl;
//	cin >> money;
//	int res = solve(money, moneyCount);
//	if (res != -1)
//		cout << res << endl;
//	else
//		cout << "NO" << endl;
//	return 0;
//}
////// 很简单
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
//	cout << "请输入作业数和机器数" << endl;
//	cin >> n >> m;
//	vector<int> works(n);
//	vector<int> machines(m, 0);
//	for (int i = 0; i < n; ++i)
//		cin >> works[i];
//	cout << greedStrategy(works, machines) << endl;
////	return 0;
//}