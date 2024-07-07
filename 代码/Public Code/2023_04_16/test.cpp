#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using std::vector;
using std::string;
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

//7 活动选择
//有n个需要在同一天使用同一个教室的活动a1, a2, …, an，教室同一时刻只能由一个活动使用。每个活动a[i]都有一个
//开始时间s[i]和结束时间f[i]。一旦被选择后，活动a[i]就占据半开时间区间[s[i], f[i])。如果[s[i], f[i])和[s[j], f[j])互不重
//叠，a[i]和a[j]两个活动就可以被安排在这一天。求使得尽量多的活动能不冲突的举行的最大数量
//struct cmp
//{
//	bool operator()(const std::vector<int>& v1, const std::vector<int>& v2)
//	{
//		return v1[1] < v2[1];
//	}
//};
//int greedyActivitySelector(vector<vector<int>>& act)
//{
//	//v[0] --> 开始  v[1] --> 结束
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
//#include <unordered_map>
//#include <map>
//#include <stack>
//#include <queue>
//
////https://leetcode.cn/problems/largest-palindromic-number/
//class Solution {
//public:
//	string largestPalindromic(string num) {
//		if (num.empty())
//			return "";
//		std::map<char, int> m;
//		for (auto& e : num)
//		{
//			m[e]++;
//		}
//		//444947137
//
//		/*9-> 2
//		8-> 2;*/
//		std::priority_queue<char> one_queue;      // 建立大堆
//		std::priority_queue<char> other_queue;
//		for (auto& p : m)
//		{
//			if (p.second > 1)
//				other_queue.push(p.first);
//			else
//				one_queue.push(p.first);
//		}
//
//		int index = 0;
//		std::string result;
//		bool falg = true; // 这个是第一次
//
//		while (!other_queue.empty())
//		{
//			char ret = other_queue.top(); // 拿到大队顶
//			if (falg && ret == '0')
//			{
//				break;
//			}
//			else
//			{
//				falg = false;
//				result.insert(index, 2, ret);
//				index++;
//				// 2  3
//				m[ret] -= 2;
//				if (m[ret] == 0)
//				{
//					other_queue.pop();
//				}
//				if (m[ret] == 1)
//				{
//					other_queue.pop();
//					one_queue.push(ret);
//				}
//			}
//		}
//		if (!one_queue.empty())
//			result.insert(index, 1, one_queue.top());
//		if (result.empty())
//			result.insert(index, 1, '0');
//		return result;
//	}
//};
//
//int main()
//{
//	string str = "00009";
//	cout << Solution().largestPalindromic(str) << endl;
//	return 0;
//}

//int main()
//{
//	int myints[] = { 10,60,50,20 };
//
//	
//	std::priority_queue<int> second(myints, myints + 4);
//	while (!second.empty())
//	{
//		std::cout << second.top() << std::endl;
//		second.pop();
//	}
//	return 0;
//}


//class Solution {
//public:
//	int tatalSum(const std::vector<int>& v)
//	{
//		int sum = 0;
//		for (auto& e : v)
//		{
//			sum += e;
//		}
//		return sum;
//	}
//	vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
//		std::vector<int> result(2, -1);
//		//[下标][个数]
//		if (mat.empty())
//			return result;
//
//		for (size_t i = 0; i < mat.size(); i++)
//		{
//			int sum = tatalSum(mat[i]);
//			if (sum > result[1])
//			{
//				result[0] = i;
//				result[1] = sum;
//			}
//		}
//		return result;
//
//	}
//};