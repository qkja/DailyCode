#define _CRT_SECURE_NO_WARNINGS 1

/*
2022-09-27 17:20:37
利用好回溯
要想sum > muliti 必须得有一个数为1，
不满足幸运口袋时，当前数可能是1，可能后面还有满足幸运口袋的情况
直接count += 递归后面的

1 1 3 5 7
1 --》 1 1 --》 1 1 3 --》 1 1 3 5回溯
1 1 5 --》 1 1 5 7 回溯 --》1 1 7
--》 。。。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GetLuckyPacketNum(int n, vector<int>& v, int pos, int sum, int multi)
{
    int count = 0;
    for (int i = pos; i < n; ++i)
    {
        sum += v[i];
        multi *= v[i];
        if (sum > multi) {
            count = count + 1 + GetLuckyPacketNum(n, v, i + 1, sum, multi);
        }
        else if (v[i] == 1) { // 1 1 3 5 7 也有可能当前数是1，可能后面还是有幸运袋子的
            count += GetLuckyPacketNum(n, v, i + 1, sum, multi);
        }
        else {
            break; // 不是幸运袋子 当前不是，后面的数还要更大，更不可能是，return count就行
        }
        sum -= v[i];
        multi /= v[i]; // 去掉不满足条件的
        // 回溯去重
        while (i < n - 1 && v[i] == v[i + 1])
            ++i;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (size_t i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    cout << GetLuckyPacketNum(n, v, 0, 0, 1) << endl;
    return 0;
}


//#include <vector>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//int func(std::vector<int>& v, int n, int pos, int sum, int multi)
//{
//	int count = 0;
//	for (size_t i = pos; i < n; i++)
//	{
//		sum += v[i];
//		multi *= v[i];
//		if (sum > multi)
//			count++;
//		else
//		{
//
//		}
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> v;
//	for (size_t i = 0; i < n; i++)
//	{
//		int ret = 0;
//		cin >> ret;
//		v.push_back(ret);
//	}
//	std::sort(v.begin(), v.end());
//
//	cout << func(v, n, 0, 0, 1) << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//bool is_leap_year(int year)
//{
//	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
//}
//int calculate_the_number_of_days(int year, int month, int day)
//{
//	// 默认是平年
//	static int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int days = day;
//	for (int i = 1; i < month; i++)
//	{
//		if (2 == i && is_leap_year(year))
//			days += 29;
//		else
//			days += months[i];
//	}
//	return days;
//}
//
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	cin >> year >> month >> day;
//	cout << calculate_the_number_of_days(year, month, day) << endl;
//	return 0;
//}

//class Base {
//public:
//	Base(int j) : i(j) {}
//	virtual~Base() {}
//	void func1() {
//		i *= 10;
//		func2();
//	}
//	int getValue() {
//		return i;
//	}
//protected:
//	virtual void func2() {
//		i++;
//	}
//protected:
//	int i;
//};
//class Child : public Base {
//public:
//	Child(int j) 
//		: Base(j)
//	{}
//
//	void func1() {
//
//		i *= 100;
//		func2();
//	}
//protected:
//	void func2() {
//		i += 2;
//	}
//
//};
//
//int main() {
//	Base* pb = new Child(1);
//	pb->func1();
//	cout << pb->getValue() << endl; delete pb;
//}


//class Solution {
//public:
//	/// <summary>
//	/// 这是一个背包问题
//	/// </summary>
//	/// <param name="w"> 重量的数组 </param>
//	/// <param name="v"> 价值的数组 </param>
//	/// <param name="bag"> 背包的容量 </param>
//	/// <returns> 返回背包的最带价值</returns>
//	int maxVal(std::vector<int>& w, std::vector<int>& v, int bag)
//	{
//		// 参数判断
//		if (w.empty() || v.empty() || w.size() != v.size())
//			return -1;
//
//		// 尝试函数 1
//		//return process(w, v, 0, bag);
//		return process(w, v, 0, bag);
//	}
//
//
//
//	/// <summary>
//	/// 来个尝试,就模仿 当前考虑到index号货物, index后面都可以自由选择
//	/// 做出的选择不能超过背包的容量
//	/// 返回最大价值
//	/// </summary>
//	/// <param name="w"></param>
//	/// <param name="v"></param>
//	/// <param name="index"></param>
//	/// <param name="bag"></param>
//	/// <returns></returns>
//	int process(std::vector<int>& w, std::vector<int>& v, int index, int rest)
//	{
//		if (rest < 0)
//			return -1; // 背包容量已经小于0了 这里 为何不能 是 等于 0  这里认为 我们0也是有价值的
//		if (index == w.size())
//			return 0; // 没有货了
//
//		// 现在这里还有货 和 背包还有空间
//		// 1. 不要当前的货
//		int p1 = process(w, v, index + 1, rest);
//
//		// 2. 要当前的货,不一定可以要成功
//		int p2 = 0;
//		int next = process(w, v, index + 1, rest - w[index]);
//		if (-1 != next)
//		{
//			p2 = v[index] + next;
//		}
//		return std::max(p1, p2);
//	}
//	int dp(std::vector<int>& w, std::vector<int>& v, int bag)
//	{
//		if (w.empty() || v.empty() || w.size() != v.size())
//			return -1;
//		int row = w.size() + 1; 
//		int col = bag + 1;
//		std::vector<std::vector<int>> result(row, std::vector<int>(col, 0));
//
//		// 开始填充
//		for (int index = row - 1-1; index >= 0; index--)
//		{
//			for (int rest = 0; rest < col; ++rest)
//			{
//				int p1 = result[index+ 1][ rest];
//
//				// 2. 要当前的货,不一定可以要成功
//				int p2 = 0;
//				int next = rest - w[index] < 0 ? -1 : result[index + 1][rest - w[index]];
//				if (-1 != next)
//				{
//					p2 = v[index] + next;
//				}
//				result[index][rest] = std::max(p1, p2);
//			}
//		}
//
//		return result[0][bag];
//	}
//
//};
//
//int main()
//{
//	std::vector<int> w = { 3, 2, 4, 7, 3, 1, 7};
//	std::vector<int> v = { 5, 6, 3, 19, 12, 4, 2 };
//
//	int bag = 15;
//	std::cout << Solution().maxVal(w, v, bag) << std::endl;
//	std::cout << Solution().dp(w, v, bag) << std::endl;
//
//	return 0;
//}


//class Solution {
//public:
//    /**
//     *
//     * @param grid int整型vector<vector<>>
//     * @return int整型
//     */
//
//
//
//    int minPathSum(vector<vector<int> >& grid) {
//        if (grid.empty())
//            return -1;
//        std::vector<std::vector<int>> dp(grid.size());
//        for (int i = 0; i < grid.size(); i++)
//        {
//            vector<int> v(grid[i].size(), -1);
//            dp[i] = v;
//        }
//
//        // 进行初始化  --> 第一层
//        dp[0][0] = grid[0][0];
//        for (int i = 1; i < grid[0].size(); i++)
//        {
//            dp[0][i] = grid[0][i] + dp[0][i - 1];
//        }
//        // 第一列
//        for (int i = 1; i < grid.size(); i++)
//        {
//            dp[i][0] = grid[i][0] + dp[i-1][0];
//        }
//
//        // 开始动态
//        for (int i = 1; i < grid.size(); i++)
//        {
//            for (int j = 1; j < grid[i].size(); j++)
//            {
//                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
//            }
//        }
//        return dp[grid.size() - 1][grid[grid.size() - 1].size() - 1];
//    }
//};

//class Solution {
//public:
//    /**
//     *
//     * @param m int整型
//     * @param n int整型
//     * @return int整型
//     */
//    int uniquePaths(int m, int n) {
//        // write code here
//        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));  // 定义并初识化
//        
//        // 这里 dp[0][0] = 0
//        //dp[0][0] = 0;  但是题意不要求这个
//        for (int i = 1; i < m; i++)
//        {
//            for (int j = 1; j < n; j++)
//            {
//                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//            }
//        }
//        return dp[m - 1][n - 1];
//    }
//};