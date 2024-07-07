#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#include <iostream>
using namespace std;
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	//遍历字符串
	for (int i = 0; i < str.length(); i++)
	{
		//用来记录重复字符数量
		int cnt = 0;
		//判断是不是字符串中的重复字符
		while (str[i] == str[i + 1])
		{
			i++;
			cnt++;
		}
		//先输出压缩的字符个数
		if (cnt != 0)
		{
			cout << cnt;
		}
		//再输出被压缩的字符
		cout << str[i];
	}
	return 0;
}
// 64 位输出请用 printf("%lld")







//#include <iostream>
//using namespace std;
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//#include <iostream>
//using namespace std;
//int calNum(int num, int n)
//{
//	int count = 0;
//	while (num)
//	{
//		// 6  2
//		if (num % n == 0)
//		{
//			++count;
//			num /= n;
//
//		}
//		else
//		{
//			break;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	std::cin >> n;
//	int num = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		num += calNum(i, 5) * (n - i + 1);
//	}
//	std::cout << num << std::endl;
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	std::cin >> n;
//	int num = 0;
//	for (size_t i = 1; i <=n; i++)
//	{
//		num += calNum(i, 5) * (n - i + 1);
//	}
//	std::cout << num << std::endl;
//	return 0;
//}











//struct Node
//{
//	int val;
//	Node* left;
//	Node* right;
//};
//void createTree(vector<Node>& array)
//{
//	for (size_t i = 0; i < array.size(); i++)
//	{
//		int left = 0;
//		int right = 0;
//		int val = 0;
//		std::cin >> left >> right >> val;
//		if (left == 0)
//			array[i].left = nullptr;
//		else
//			array[i].left = &(array[left - 1]);
//		if (right == 0)
//			array[i].right = nullptr;
//		else
//			array[i].right = &(array[right - 1]);
//		array[i].val = val;
//	}
//}
//
//Node* merge(Node* r1, Node* r2)
//{
//	if (r1 != nullptr && r2 != nullptr)
//	{
//		r1->left = merge(r1->left, r2->left);
//		r1->right = merge(r1->right, r2->right);
//		r1->val = r1->val + r2->val;
//		return r1;
//	}
//	return r1 == nullptr ? r2 : r1;
//}
//
//void Bfs(Node* root)
//{
//
//	queue<Node*> q;
//	q.push(root);
//	while (!q.empty())
//	{
//		Node* ret = q.front();
//		std::cout << ret->val << " ";
//		q.pop();
//		if (ret->left)
//			q.push(ret->left);
//		if (ret->right)
//			q.push(ret->right);
//	}
//	std::cout << std::endl;
//}
//
//int main()
//{
//	int first = 0;
//	int second = 0;
//	std::cin >> first >> second;
//	vector<Node> v1(first);
//	vector<Node> v2(second);
//	createTree(v1);
//	createTree(v2);
//
//	Node* root = merge(&v1[0], &v2[0]);
//
//	Bfs(root);
//	return 0;
//}













//int main() 
//{
//	int first = 0;
//	int second = 0;
//
//	std::cin >> first >> second;
//
//	int parent = 0;
//	int left = 0;
//	int right = 0;
//
//	std::vector<std::pair<int, std::pair<int, int>>> v1;
//	std::vector<std::pair<int, std::pair<int, int>>> v2;
//	for (size_t i = 0; i < first; i++)
//	{
//		std::cin >> parent >> left >> right;
//		v1.push_back(std::make_pair(parent, std::make_pair(left, right)));
//	}
//
//	for (size_t i = 0; i < second; i++)
//	{
//		std::cin >> parent >> left >> right;
//		v2.push_back(std::make_pair(parent, std::make_pair(left, right)));
//	}
//	std::vector<int> result;
//
//
//	return 0;
//}
