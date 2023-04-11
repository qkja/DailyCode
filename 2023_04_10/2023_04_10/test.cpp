#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		if (deck.empty())
			return false;
		std::unordered_map<int, int> result;
		for (auto e : deck)
		{
			result[e]++;
		}

		int count = 0;
		for (std::pair<const int, int>& p : result) 
		{
			count = gcd(count, p.second);
			if (count == 1) {
					return false;
			}
		}
		return count >= 2;
	}

	// 辗转相除法
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
};




//class Solution {
//public:
//	bool hasGroupsSizeX(vector<int>& deck) {
//		if (deck.size())
//			return false;
//		std::unordered_map<int, int> result;
//		for (auto e : deck)
//		{
//			result[e]++;
//		}
//
//		std::unordered_map<int, int>::iterator iter = result.begin();
//		int count = iter->second;
//		while (iter != result.end())
//		{
//			if (iter->second != count)
//				return false;
//			++iter;
//		}
//		return count > 1;
//	}
//};









//#include <iostream>
//using namespace std;
//int number_of_binary_ones(int val)
//{
//	int count = 0;
//	while(val)
//	{
//		val = val &(val - 1);
//		count++;
//	}
//	return count;
//}
//int main() 
//{
//	int n = 0;
//	while (std::cin >> n)
//	{
//		std::cout << number_of_binary_ones(n) << std::endl;
//	}
//	return 0;
//}


// 64 位输出请用 printf("%lld")

//struct A{
//	void foo(){ printf("foo"); }
//};
//struct B :A{
//	void foo(){ printf("b_foo"); }
//};
//
//int main()
//{
//	struct B b;
//	struct A* pa = &b;
//	pa->foo();
//	struct A& pa2 = b;
//	pa2.foo();
//	return 0;
//}










//class Person
//{
//public:
//	
//private:
//	string _name = "peter"; // 姓名
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
//int main()
//{
//	Student stu;
//	return 0;
//}

//class A
//{
//public:
//
//	int a1;
//private:
//	int a2;
//};
//
//
//class B :public A
//{
//public:
//	void func()
//	{
//		a1 = 10;
//		cout << "a1 " << a1 << endl;
//		A::a2 = -1;
//		cout << "a2 " << A::a2 << endl;
//	}
//private:
//
//};
//int main()
//{
//
//	return 0;
//}

//class Solution {
//public:
//	vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
//		int sumA = 0;
//		int sumB = 0;
//		for (auto& e : aliceSizes)
//			sumA += e;
//		for (auto& e : bobSizes)
//			sumB += e;
//		int data = (sumA - sumB) / 2;
//		std::unordered_set<int> rec(aliceSizes.begin(), aliceSizes.end());
//		std::vector<int> ans;
//		for (auto& y : bobSizes) {
//			int x = y + data;
//			if (rec.count(x)) {
//				ans = vector<int>{x, y};
//				break;
//			}
//		}
//		return ans;
//	}
//};