#define _CRT_SECURE_NO_WARNINGS 1

/*
2022-09-27 17:20:37
���úû���
Ҫ��sum > muliti �������һ����Ϊ1��
���������˿ڴ�ʱ����ǰ��������1�����ܺ��滹���������˿ڴ������
ֱ��count += �ݹ�����

1 1 3 5 7
1 --�� 1 1 --�� 1 1 3 --�� 1 1 3 5����
1 1 5 --�� 1 1 5 7 ���� --��1 1 7
--�� ������
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
        else if (v[i] == 1) { // 1 1 3 5 7 Ҳ�п��ܵ�ǰ����1�����ܺ��滹�������˴��ӵ�
            count += GetLuckyPacketNum(n, v, i + 1, sum, multi);
        }
        else {
            break; // �������˴��� ��ǰ���ǣ����������Ҫ���󣬸��������ǣ�return count����
        }
        sum -= v[i];
        multi /= v[i]; // ȥ��������������
        // ����ȥ��
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
//	// Ĭ����ƽ��
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
//	/// ����һ����������
//	/// </summary>
//	/// <param name="w"> ���������� </param>
//	/// <param name="v"> ��ֵ������ </param>
//	/// <param name="bag"> ���������� </param>
//	/// <returns> ���ر����������ֵ</returns>
//	int maxVal(std::vector<int>& w, std::vector<int>& v, int bag)
//	{
//		// �����ж�
//		if (w.empty() || v.empty() || w.size() != v.size())
//			return -1;
//
//		// ���Ժ��� 1
//		//return process(w, v, 0, bag);
//		return process(w, v, 0, bag);
//	}
//
//
//
//	/// <summary>
//	/// ��������,��ģ�� ��ǰ���ǵ�index�Ż���, index���涼��������ѡ��
//	/// ������ѡ���ܳ�������������
//	/// ��������ֵ
//	/// </summary>
//	/// <param name="w"></param>
//	/// <param name="v"></param>
//	/// <param name="index"></param>
//	/// <param name="bag"></param>
//	/// <returns></returns>
//	int process(std::vector<int>& w, std::vector<int>& v, int index, int rest)
//	{
//		if (rest < 0)
//			return -1; // ���������Ѿ�С��0�� ���� Ϊ�β��� �� ���� 0  ������Ϊ ����0Ҳ���м�ֵ��
//		if (index == w.size())
//			return 0; // û�л���
//
//		// �������ﻹ�л� �� �������пռ�
//		// 1. ��Ҫ��ǰ�Ļ�
//		int p1 = process(w, v, index + 1, rest);
//
//		// 2. Ҫ��ǰ�Ļ�,��һ������Ҫ�ɹ�
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
//		// ��ʼ���
//		for (int index = row - 1-1; index >= 0; index--)
//		{
//			for (int rest = 0; rest < col; ++rest)
//			{
//				int p1 = result[index+ 1][ rest];
//
//				// 2. Ҫ��ǰ�Ļ�,��һ������Ҫ�ɹ�
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