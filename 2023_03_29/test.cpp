#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
	/// <summary>
	/// ����һ����������
	/// </summary>
	/// <param name="w"> ���������� </param>
	/// <param name="v"> ��ֵ������ </param>
	/// <param name="bag"> ���������� </param>
	/// <returns> ���ر����������ֵ</returns>
	int maxVal(std::vector<int>& w, std::vector<int>& v, int bag)
	{
		// �����ж�
		if (w.empty() || v.empty() || w.size() != v.size())
			return -1;

		// ���Ժ��� 1
		return process(w, v, 0, bag);
	}

	/// <summary>
	/// ��������,��ģ�� ��ǰ���ǵ�index�Ż���, index���涼��������ѡ��
	/// ������ѡ���ܳ�������������
	/// ��������ֵ
	/// </summary>
	/// <param name="w"></param>
	/// <param name="v"></param>
	/// <param name="index"></param>
	/// <param name="bag"></param>
	/// <returns></returns>
	int process(std::vector<int>& w, std::vector<int>& v, int index, int bag)
	{
		if (bag < 0)
			return -1; // ���������Ѿ�С��0�� ���� Ϊ�β��� �� ���� 0  ������Ϊ ����0Ҳ���м�ֵ��
		if (index == w.size())
			return 0; // û�л���

		// �������ﻹ�л� �� �������пռ�
		// 1. ��Ҫ��ǰ�Ļ�
		int p1 = process(w, v, index + 1, bag);

		// 2. Ҫ��ǰ�Ļ�,��һ������Ҫ�ɹ�
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
//     * @param grid int����vector<vector<>>
//     * @return int����
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
//        // ���г�ʼ��  --> ��һ��
//        dp[0][0] = grid[0][0];
//        for (int i = 1; i < grid[0].size(); i++)
//        {
//            dp[0][i] = grid[0][i] + dp[0][i - 1];
//        }
//        // ��һ��
//        for (int i = 1; i < grid.size(); i++)
//        {
//            dp[i][0] = grid[i][0] + dp[i-1][0];
//        }
//
//        // ��ʼ��̬
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
//     * @param m int����
//     * @param n int����
//     * @return int����
//     */
//    int uniquePaths(int m, int n) {
//        // write code here
//        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));  // ���岢��ʶ��
//        
//        // ���� dp[0][0] = 0
//        //dp[0][0] = 0;  �������ⲻҪ�����
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