#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <queue>
#include <functional>
#include<iostream>
#include<queue>
using namespace std;
//struct node
//{
//	int x;
//	int y;
//	bool operator>(const node& n) const
//	{
//		return x > n.x;
//	}
//};
//
//
//int main()
//{
//	node n1 = { 1, 2 };
//	node n2 = { 2, 4 };
//	node n3 = { 3, 4 };
//	priority_queue<node, vector<node>, greater<node>>q;
//	q.push(n1);
//	q.push(n2);
//	q.push(n3);
//
//	return 0;
//}

//struct node
//{
//	int x;
//	int y;
//};
//
//struct cmp
//{
//	bool operator()(const node& n1, const node& n2){
//		return n1.x > n2.x;
//	}
//	cmp(const cmp& c)
//	{
//
//	}
//	cmp()
//	{
//
//	}
//};
//int main()
//{
//	node n1 = { 1, 2 };
//	node n2 = { 2, 4 };
//	node n3 = { 3, 4 };
//	cmp c;
//	priority_queue<node, vector<node>, cmp> q(c);
//	q.push(n1);
//	q.push(n2);
//	q.push(n3);
//
//	return 0;
//}

//struct node
//{
//	int x;
//	int y;
//	bool operator<(const node& n) const
//	{
//		return x < n.x; // 这里可以控制是大堆还是小堆
//	}
//};
//
//
//int main()
//{
//	node n1 = { 1, 2 };
//	node n2 = { 2, 4 };
//	node n3 = { 3, 4 };
//	priority_queue<node>q;
//	q.push(n1);
//	q.push(n2);
//	q.push(n3);
//
//	return 0;
//}

//int main()
//{
//	node n1 = { 1, 2 };
//	node n2 = { 2, 4 };
//	node n3 = { 3, 4 };
//	q.push(n1);
//	q.push(n2);
//	q.push(n3);
//
//	return 0;
//}

//struct node
//{
//	int x;
//	int y;
//};
//
//struct cmp
//{
//	bool operator()(const node& n1, const node& n2){
//		return n1.x > n2.x;
//	}
//};
//int main()
//{
//	node n1 = { 1, 2 };
//	node n2 = { 2, 4 };
//	node n3 = { 3, 4 };
//	priority_queue<node, vector<node>, cmp>q;
//	q.push(n1);
//	q.push(n2);
//	q.push(n3);
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 10, 2, 1, 3, 5, 4, 0 };
//	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
//	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		q.push(arr[i]);
//	}
//	while (!q.empty())
//	{
//		std::cout << q.top() << " ";
//		q.pop();
//	}
//	return 0;
//}

//int main()
//{
//	int arr[] = { 10, 2, 1, 3, 5, 4, 0 };
//	std::priority_queue<int, std::vector<int>, std::less<int>> q;
//	for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
//	{
//		q.push(arr[i]);
//	}
//	while (!q.empty())
//	{
//		std::cout << q.top() << " ";
//		q.pop();
//	}
//	return 0;
//}

//template <class T, class Sequence = vector<T>,
//class Compare = less<typename Sequence::value_type> >
//class  priority_queue {
//public:
//	typedef typename Sequence::value_type value_type;
//	typedef typename Sequence::size_type size_type;
//	typedef typename Sequence::reference reference;
//	typedef typename Sequence::const_reference const_reference;
//protected:
//	Sequence c;
//	Compare comp;
//public:
//	priority_queue() : c() {}
//	explicit priority_queue(const Compare& x) : c(), comp(x) {}
//
//	priority_queue(const value_type* first, const value_type* last)
//		: c(first, last) {
//		make_heap(c.begin(), c.end(), comp);
//	}
//
//	void push(const value_type& x) {
//		__STL_TRY{
//		c.push_back(x);
//		push_heap(c.begin(), c.end(), comp);
//	}
//		__STL_UNWIND(c.clear());
//	}
//};