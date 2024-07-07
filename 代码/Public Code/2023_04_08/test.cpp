#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        if (seats.empty())
            return 0;

    }
};

//class Solution {
//public:
//
//    bool is_magic_square(const std::string& str, const vector<vector<int>>& grid, int r1, int c1, int r2, int c2)
//    {
//        std::string& s;
//        for (int i = r1; i <= r2; i++)
//        {
//            for (int j = c1; j <= c2; j++)
//            {
//                s += std::to_string(grid[i][j]);
//                /*if (helper.find(grid[i][j]) == helper.end())
//                    return false;*/
//            }
//        }
//        if (s != str)
//            return false;
//        std::unordered_set<int> sum;
//        sum.insert(grid[r1][c1] + grid[r1][c1 + 1] + grid[r1][c1 + 2]);
//        sum.insert(grid[r1+1][c1] + grid[r1+1][c1 + 1] + grid[r1+1][c1 + 2]);
//        sum.insert(grid[r1+2][c1] + grid[r1+2][c1+1] + grid[r1+2][c1+2]);
//
//        sum.insert(grid[r1][c1] + grid[r1 + 1][c1] + grid[r1 + 2][c1]);
//        sum.insert(grid[r1][c1+1] + grid[r1 + 1][c1+1] + grid[r1 + 2][c1+1]);
//        sum.insert(grid[r1][c1+2] + grid[r1+1][c1+2] + grid[r1+2][c1+2]);
//
//        sum.insert(grid[r1][c1] + grid[r1 + 1][c1 + 1] + grid[r1 + 2][c1 + 2]);
//        sum.insert(grid[r1][c2] + grid[r1 + 1][c2 - 1] + grid[r1 + 2][c2 - 2]);
//
//        return sum.size() == 1;
//    }
//
//
//    int numMagicSquaresInside(vector<vector<int>>& grid) {
//        if (grid.empty())
//            return 0;
//        //std::unordered_set<int> helper;
//        std::string helper;
//        for (int i = 1; i < 10; i++)
//            helper.insert(i);
//        int count = 0;
//        int r1 = 0;
//        int r2 = r1 + 2;
//
//        int c1 = 0;
//        int c2 = c1 + 2;
//
//        while (r2 < grid.size())
//        {
//            int begin = c1;
//            int end = c2;
//            while (end < grid[r1].size())
//            {
//                if (is_magic_square(helper, grid, r1, begin, r2, end))
//                    count++;
//                begin++;
//                end++;
//            }
//            r1++;
//            r2++;
//        }
//        return count;
//    }
//};
//class Solution {
//public:
//
//    bool is_magic_square(const vector<vector<int>>& grid, int r1, int c1, int r2, int c2)
//    {
//        // 0 - 9
//        int arr[10] = { 0 ,-1, -1, -1, -1, -1,-1, -1, -1, -1 };
//        for (int i = r1; i <= r2; i++)
//        {
//            for (int j = c1; j <= c2; j++)
//            {
//                if (grid[i][j] > 0 && grid[i][j] < 10)
//                {
//                    arr[grid[i][j]] = 0;
//                }
//                else
//                {
//                    return false;
//                }
//                /*if (helper.find(grid[i][j]) == helper.end())
//                    return false;*/
//            }
//        }
//        int ret = 0;
//        for (int i = 0; i < 10; i++)
//        {
//            ret += arr[i];
//        }
//        if (ret != 0)
//            return false;
//        std::unordered_set<int> sum;
//        sum.insert(grid[r1][c1] + grid[r1][c1 + 1] + grid[r1][c1 + 2]);
//        sum.insert(grid[r1 + 1][c1] + grid[r1 + 1][c1 + 1] + grid[r1 + 1][c1 + 2]);
//        sum.insert(grid[r1 + 2][c1] + grid[r1 + 2][c1 + 1] + grid[r1 + 2][c1 + 2]);
//
//        sum.insert(grid[r1][c1] + grid[r1 + 1][c1] + grid[r1 + 2][c1]);
//        sum.insert(grid[r1][c1 + 1] + grid[r1 + 1][c1 + 1] + grid[r1 + 2][c1 + 1]);
//        sum.insert(grid[r1][c1 + 2] + grid[r1 + 1][c1 + 2] + grid[r1 + 2][c1 + 2]);
//
//        sum.insert(grid[r1][c1] + grid[r1 + 1][c1 + 1] + grid[r1 + 2][c1 + 2]);
//        sum.insert(grid[r1][c2] + grid[r1 + 1][c2 - 1] + grid[r1 + 2][c2 - 2]);
//
//        return sum.size() == 1;
//    }
//
//
//    int numMagicSquaresInside(vector<vector<int>>& grid) {
//        if (grid.empty())
//            return 0;
// 
//        int count = 0;
//        int r1 = 0;
//        int r2 = r1 + 2;
//
//        int c1 = 0;
//        int c2 = c1 + 2;
//
//        while (r2 < grid.size())
//        {
//            int begin = c1;
//            int end = c2;
//            while (end < grid[r1].size())
//            {
//                if (is_magic_square(grid, r1, begin, r2, end))
//                    count++;
//                begin++;
//                end++;
//            }
//            r1++;
//            r2++;
//        }
//        return count;
//    }
//};
////[9, 5, 1, 9] , [2, 7, 6, 2]
//int main()
//{
//    //[[5,5,5],[5,5,5],[5,5,5]]
//    vector<vector<int>> v{ {5,5,5} , {5,5,5}, {5,5,5}};
//    int n = Solution().numMagicSquaresInside(v);
//    cout << n << endl;
//    return 0;
//}








//class MyClass
//{
//public:
//	int maxX(std::vector<int> nums)
//	{
//		if (nums.empty() || nums.size() <= 2)
//			return -1;
//		int preBest = nums[0];
//		int ans = 0;
//		for (int i = 1; i < nums.size(); i++)
//		{
//			ans = std::max(ans, nums[i] - i + preBest);
//			preBest = std::max(preBest, nums[i] - i);
//		}
//		return ans;
//	}
//	int zuo(std::vector<int> a, std::vector<int> b,int ai, int bi)
//	{
//		// 这是basc case
//		if (ai == a.size() && bi == b.size())
//			return 0;
//		if(ai == a.size() && bi != b.size())
//		{
//			// b 没有到头
//			// 删掉所有
//			return b[bi] + zuo(a, b, ai, bi + 1);
//		}
//		if (ai != a.size() && bi == b.size())
//		{
//			// a 没有到头
//			return a[ai] + zuo(a, b, ai+1, bi);
//		}
//
//		// 1 直接删掉 ai
//		int p1 = a[ai] + zuo(a, b, ai + 1, bi);
//		// 2 删掉bi
//		int p2 = b[bi] + zuo(a, b, ai, bi+1);
//		// 3 都删掉 -->这个 buff太大,它的代价小于 可能性
//		//int p3 = a[ai] +b[bi]+ zuo(a, b, ai + 1, bi+1);
//		 
//		// 4 变 代价是一样的
//		int p4 =  std::abs( a[ai]-b[bi]) + zuo(a, b, ai + 1, bi+1);
//
//		// 5 也许 可能一样  都不变  --> 被4包含了
//
//
//		return std::min(std::min(p1, p2), p4);
//	}
//	void add(int x, int y, std::vector<int> c, int r, 
//		std::queue<std::vector<int>>& q,
//		std::unordered_set<std::string>& visited)
//	{
//		// 这里不判断参数了,使用的时候判断了
//		std::string str = std::to_string(x) + "_" + str = std::to_string(y);
//		
//		if (visited.find(str) == visited.end() && distance(x, y, c) == r)
//		{
//			q.push({ x,y });
//			visited.insert(std::move(str));
//		}
//	}
//	
//	int distance(int x, int y, const std::vector<int>& c)
//	{
//		return std::abs(c[0] - x) + std::abs(c[1] - y);
//	}
//	
//	std::vector<int> find(int n, std::vector<int> a,
//		std::vector<int> b,
//		std::vector<int> c,
//
//		int ad, int bd, int cd)
//	{
//		std::vector<int> x1;
//		int r1 = INT_MAX;
//
//		std::vector<int> x2;
//		int r2 = INT_MAX;
//		std::vector<int> x3;
//		int r3 = INT_MAX;
//
//		if (ad < r1)
//		{
//			x1 = a;
//			r1 = ad;
//			x2 = b;
//			r2 = bd;
//			x3 = c;
//			r3 = cd;
//		}
//
//		if (bd < r1)
//		{
//			x1 = b;
//			r1 = bd;
//			x2 = a;
//			r2 = ad;
//			x3 = c;
//			r3 = cd;
//		}
//
//		if (cd < r1)
//		{
//			x1 = c;
//			r1 = cd;
//
//			x2 = a;
//			r2 = ad;
//
//			x3 = b;
//			r3 = bd;
//		}
//
//		// 这里  x1 r1 一定是最小的
//		std::vector<int> cur = { x1[0] - r1, x1[1] };
//
//		std::queue<std::vector<int>> queue;
//		std::unordered_set<std::string> visited;
//
//		std::vector<std::vector<int>> ans;
//
//		queue.push(cur);
//		std::string str = std::to_string(cur[0]) + "_" + std::to_string(cur[1]);
//		visited.insert(str);
//		while (!queue.empty())
//		{
//			cur = queue.front();
//			queue.pop();
//			if (cur[0] >= 1 && cur[0] <= n
//				&& cur[1] >= 1 && cur[1] <= n
//				&& distance(cur[0], cur[1], x2) == r2
//				&& distance(cur[0], cur[1], x3) == r3)
//			{
//				ans.push_back(cur);
//			}
//
//			if (ans.size() == 2)
//				break;
//	/*		void add(int x, int y, std::vector<int> c, int r,
//				std::queue<std::vector<int>>&q,
//				std::unordered_set<std::string>&ans)*/
//			add(cur[0] - 1, cur[1], x1, r1, queue, visited);
//			add(cur[0] + 1, cur[1], x1, r1, queue, visited);
//
//			add(cur[0], cur[1]-1, x1, r1, queue, visited);
//			add(cur[0], cur[1]+1, x1, r1, queue, visited);
//
//			add(cur[0] - 1, cur[1] - 1, x1, r1, queue, visited);
//			add(cur[0] + 1, cur[1] - 1, x1, r1, queue, visited);
//			
//			add(cur[0] - 1, cur[1]+1, x1, r1, queue, visited);
//			add(cur[0] + 1, cur[1]+1, x1, r1,queue, visited);
//		}
//
//		if (ans.size() == 1 || (ans[0][0] < ans[1][0]) ||
//			(ans[0][0] == ans[1][0] && ans[0][1] < ans[1][1]))
//		{
//			return ans[0];
//		}
//		else
//		{
//			return ans[1];
//		}
//	}
//};