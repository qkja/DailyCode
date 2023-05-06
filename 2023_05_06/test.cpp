#include <queue>
#include <iostream>

// 我们花可以最少的钱等于游乐园赚最多的钱
// 这个对于一个项目来说,每来一个人,按理来说我们应该赚够新的单间钱,但是由于我们每一次单价是减少的
// 故我们赚的钱是要减去我们前面的人的差价的

struct Node
{
	int Ki;
	int Bi;
	int people;
	Node(int k, int b)
		:Ki(k)
		,Bi(b)
		,people(0)
	{}
	int earn() const
	{
		return (2 * people + 1) * Ki + Bi;
	}
		
};

struct cmp
{
	bool operator()(const Node& n1, const Node& n2) {
		return n1.earn() < n2.earn(); // 这里应该就是大堆
	}
};

int enoughMoney(int n, std::vector<std::vector<int>>& games)
{
	cmp c;
	std::priority_queue<Node> q(c);
	for(auto& e:games)
	{
		q.push(Node(e[0], e[1]));
	}
	int ans = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (q.top().earn() <= 0)
			break;
		Node node = q.top();
		q.pop();
		ans += node.earn();
		node.people++;
		q.push(node);
	}
	return ans;
}

int main()
{
	std::vector<std::vector<int>> games = { {-2,10}, {-3, 10} };
	std::cout << enoughMoney(2, games);
	return 0;
}