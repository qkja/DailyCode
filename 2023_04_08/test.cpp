#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <string>
class MyClass
{
public:
	int maxX(std::vector<int> nums)
	{
		if (nums.empty() || nums.size() <= 2)
			return -1;
		int preBest = nums[0];
		int ans = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			ans = std::max(ans, nums[i] - i + preBest);
			preBest = std::max(preBest, nums[i] - i);
		}
		return ans;
	}
	int zuo(std::vector<int> a, std::vector<int> b,int ai, int bi)
	{
		// ����basc case
		if (ai == a.size() && bi == b.size())
			return 0;
		if(ai == a.size() && bi != b.size())
		{
			// b û�е�ͷ
			// ɾ������
			return b[bi] + zuo(a, b, ai, bi + 1);
		}
		if (ai != a.size() && bi == b.size())
		{
			// a û�е�ͷ
			return a[ai] + zuo(a, b, ai+1, bi);
		}

		// 1 ֱ��ɾ�� ai
		int p1 = a[ai] + zuo(a, b, ai + 1, bi);
		// 2 ɾ��bi
		int p2 = b[bi] + zuo(a, b, ai, bi+1);
		// 3 ��ɾ�� -->��� buff̫��,���Ĵ���С�� ������
		//int p3 = a[ai] +b[bi]+ zuo(a, b, ai + 1, bi+1);
		 
		// 4 �� ������һ����
		int p4 =  std::abs( a[ai]-b[bi]) + zuo(a, b, ai + 1, bi+1);

		// 5 Ҳ�� ����һ��  ������  --> ��4������


		return std::min(std::min(p1, p2), p4);
	}
	void add(int x, int y, std::vector<int> c, int r, 
		std::queue<std::vector<int>>& q,
		std::unordered_set<std::string>& visited)
	{
		// ���ﲻ�жϲ�����,ʹ�õ�ʱ���ж���
		std::string str = std::to_string(x) + "_" + str = std::to_string(y);
		
		if (ans.find(str) == ans.end() && distance(x, y, c) == r)
		{
			q.push({ x,y });
			ans.insert(std::move(str));
		}
	}
	
	int distance(int x, int y, const std::vector<int>& c)
	{
		return std::abs(c[0] - x) + std::abs(c[1] - y);
	}
	
	std::vector<int> find(int n, std::vector<int> a,
		std::vector<int> b,
		std::vector<int> c,

		int ad, int bd, int cd)
	{
		std::vector<int> x1;
		int r1 = INT_MAX;

		std::vector<int> x2;
		int r2 = INT_MAX;
		std::vector<int> x3;
		int r3 = INT_MAX;

		if (ad < r1)
		{
			x1 = a;
			r1 = ad;
			x2 = b;
			r2 = bd;
			x3 = c;
			r3 = cd;
		}

		if (bd < r1)
		{
			x1 = b;
			r1 = bd;
			x2 = a;
			r2 = ad;
			x3 = c;
			r3 = cd;
		}

		if (cd < r1)
		{
			x1 = c;
			r1 = cd;

			x2 = a;
			r2 = ad;

			x3 = b;
			r3 = bd;
		}

		// ����  x1 r1 һ������С��
		std::vector<int> cur = { x1[0] - r1, x1[1] };

		std::queue<std::vector<int>> queue;
		std::unordered_set<std::string> visited;

		std::vector<std::vector<int>> ans;

		queue.push(cur);
		std::string str = std::to_string(cur[0]) + "_" + std::to_string(cur[1]);
		visited.insert(str);
		while (!queue.empty())
		{
			cur = queue.front();
			queue.pop();
			if (cur[0] >= 1 && cur[0] <= n
				&& cur[1] >= 1 && cur[1] <= n
				&& distance(cur[0], cur[1], x2) == r2
				&& distance(cur[0], cur[1], x3) == r3)
			{
				ans.push_back(cur);
			}

			if (ans.size() == 2)
				break;
	/*		void add(int x, int y, std::vector<int> c, int r,
				std::queue<std::vector<int>>&q,
				std::unordered_set<std::string>&ans)*/
			add(cur[0] - 1, cur[1], x1, r1, queue, visited);
			add(cur[0] + 1, cur[1], x1, r1, queue, visited);

			add(cur[0], cur[1]-1, x1, r1, queue, visited);
			add(cur[0], cur[1]+1, x1, r1, queue, visited);

			add(cur[0] - 1, cur[1] - 1, x1, r1, queue, visited);
			add(cur[0] + 1, cur[1] - 1, x1, r1, queue, visited);
			
			add(cur[0] - 1, cur[1]+1, x1, r1, queue, visited);
			add(cur[0] + 1, cur[1]+1, x1, r1,queue, visited);
		}

		if (ans.size() == 1 || (ans[0][0] < ans[1][0]) ||
			(ans[0][0] == ans[1][0] && ans[0][1] < ans[1][1]))
		{
			return ans[0];
		}
		else
		{
			return ans[1];
		}
	}
};