#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
	/// <summary>
	/// 这是一个背包问题
	/// </summary>
	/// <param name="w"> 重量的数组 </param>
	/// <param name="v"> 价值的数组 </param>
	/// <param name="bag"> 背包的容量 </param>
	/// <returns> 返回背包的最带价值</returns>
	int maxVal(std::vector<int>& w, std::vector<int>& v, int bag)
	{
		// 参数判断
		if (w.empty() || v.empty() || w.size() != v.size())
			return -1;

		// 尝试函数 1
		return process(w, v, 0, bag);
	}

	/// <summary>
	/// 来个尝试,就模仿 当前考虑到index号货物, index后面都可以自由选择
	/// 做出的选择不能超过背包的容量
	/// 返回最大价值
	/// </summary>
	/// <param name="w"></param>
	/// <param name="v"></param>
	/// <param name="index"></param>
	/// <param name="bag"></param>
	/// <returns></returns>
	int process(std::vector<int>& w, std::vector<int>& v, int index, int bag)
	{
		if (bag < 0)
			return -1; // 背包容量已经小于0了 这里 为何不能 是 等于 0  这里认为 我们0也是有价值的
		if (index == w.size())
			return 0; // 没有货了

		// 现在这里还有货 和 背包还有空间
		// 1. 不要当前的货
		int p1 = process(w, v, index + 1, bag);

		// 2. 要当前的货,不一定可以要成功
		int p2 = 0;
		int next = process(w, v, index + 1, bag - w[index]);
		if (-1 != next)
		{
			p2 = v[index] + next;
		}
		return std::max(p1, p2);
	}
};

int main()
{
	std::vector<int> w = { 3,2,4,7,3,1,7};
	std::vector<int> v = { 5,6,3,19,12,4,2 };

	int bag = 15;
	std::cout << Solution().maxVal(w, v, bag) << std::endl;

	return 0;
}


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