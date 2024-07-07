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
//		std::priority_queue<char> one_queue;      // �������
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
//		bool falg = true; // ����ǵ�һ��
//
//		while (!other_queue.empty())
//		{
//			char ret = other_queue.top(); // �õ���Ӷ�
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
//		//[�±�][����]
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