#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/min-stack/
// 最小栈
#include <map>
#include <stack>
#include <string>
#include <queue>
#include <iostream>
//class MinStack {
//public:
//	MinStack() {
//
//	}
//
//	void push(int val) {
//		s.push(val);
//		m[val]++;
//	}
//
//	void pop() {
//		if (s.empty())
//			return;
//		int ret = s.top();
//		s.pop();
//		m[ret]--; 
//		if (m[ret] == 0)
//			m.erase(ret);
//	}
//
//	int top() {
//		if (s.empty())
//			return -1;
//		return s.top();
//	}
//
//	int getMin() {
//		if (s.empty())
//			return -1;
//		return m.begin()->first;
//	}
//private:
//	std::map<int, int> m;
//	std::stack<int> s;
//};
//class MinStack {
//public:
//	MinStack() {
//
//	}
//
//	void push(int val) {
//		s1.push(val);
//		if (s2.empty() || s2.top() >= val)
//			s2.push(val);
//	}
//
//	void pop() {
//		if (s1.empty())
//			return;
//		int ret = s1.top();
//		s1.pop();
//		if (ret == s2.top())
//			return s2.pop();
//	}
//
//	int top() {
//		if (s1.empty())
//		return -1;
//		return s1.top();
//	}
//
//	int getMin() {
//		if (s2.empty())
//			return -1;
//		return s2.top();
//	}
//private:
//	std::stack<int> s1;
//	std::stack<int> s2;
//};
//class MinStack {
//public:
//	MinStack() {
//
//	}
//
//	void push(int val) {
//		s1.push(val);
//		if (s2.empty() || s2.top() >= val)
//			s2.push(val);
//		else
//			s2.push(s2.top());
//	}
//
//	void pop() {
//		if (s1.empty())
//			return;
//		s1.pop();
//		s2.pop();
//	}
//
//	int top() {
//		if (s1.empty())
//			return -1;
//		return s1.top();
//	}
//
//	int getMin() {
//		if (s2.empty())
//			return -1;
//		return s2.top();
//	}
//	std::stack<int> s1;
//	std::stack<int> s2;
//};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

// https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
//class CQueue {
//public:
//	CQueue() {
//
//	}
//
//	void appendTail(int value) {
//		push_stack.push(value);
//	}
//
//	int deleteHead() {
//		if (pop_stack.empty())
//		{
//			while (!push_stack.empty())
//			{
//				pop_stack.push(push_stack.top());
//				push_stack.pop();
//			}
//		}
//		if (pop_stack.empty())
//			return -1;
//		int ret = pop_stack.top();
//		pop_stack.pop();
//		return ret;
//	}
//private:
//
//	std::stack<int> push_stack;
//	std::stack<int> pop_stack;
//};

//class CQueue {
//public:
//	CQueue() {
//
//	}
//
//	void appendTail(int value) {
//		s1.push(value);
//	}
//
//	int deleteHead() {
//		if (s1.empty())
//			return -1;
//		// 把s1 的元素放在 s2中
//		while (!s1.empty())
//		{
//			s2.push(s1.top());
//			s1.pop();
//		}
//		int ret = s2.top();
//		s2.pop();
//		// 重新倒腾数据
//		while (!s2.empty())
//		{
//			s1.push(s2.top());
//			s2.pop();
//		}
//		return ret;
//	}
//private:
//	std::stack<int> s1;  // 只负责 入栈
//	std::stack<int> s2;  // 只负责 出栈
//};




/**
* Your CQueue object will be instantiated and called as such:
* CQueue* obj = new CQueue();
* obj->appendTail(value);
* int param_2 = obj->deleteHead();
*/

//class Solution {
//public:
//	void _reverse_by_stack(std::stack<int>& s1, std::stack<int>& s2)
//	{
//		if (!s1.empty())
//		{
//			s2.push(s1.top());
//			s1.pop();
//			_reverse_by_stack(s1, s2);
//		}
//	}
//	void reverse_by_stack(std::stack<int>& s1)
//	{
//		std::stack<int> s2;
//		_reverse_by_stack(s1, s2);
//		std::swap(s1, s2);
//	}
//};

//class Solution {
//public:
//	// 拿到栈底元素并移除,此时我们保障s1中一定存在元素
//	int get_the_element_at_the_bottom_of_the_stack(std::stack<int>& s1)
//	{
//		int ret = s1.top();
//		s1.pop();
//		if (s1.empty())
//		{
//			return ret;
//		}
//		else
//		{
//			// ret 是栈底元素,我们去后面拿去吧
//			int result = get_the_element_at_the_bottom_of_the_stack(s1);
//			// 把ret 这个元素重新入栈
//			s1.push(ret);
//			return result;
//		}
//	}
//	void reverse_by_stack(std::stack<int>& s1)
//	{
//		if (s1.empty())
//			return;
//		// 拿栈底元素
//		int ret = get_the_element_at_the_bottom_of_the_stack(s1);
//		// 我么希望递归,拿到所有栈底的元素,并且把这个栈给清空
//		
//		reverse_by_stack(s1);
//		// 这里的想法,当我们栈中只存在一个元素的时候,此时我们拿到了这个元素,继续递归,出现
//		// 空,直接返回,下面紧接着就是把这个元素入栈,此时我们已经完成了逆置的操作
//		s1.push(ret);
//	}
//};
//int main()
//{
//	std::stack<int> s1;
//	for (int i = 1; i <= 5; i++)
//		s1.push(i);
//	// 1 2  3 
//	Solution().reverse_by_stack(s1);
//	while (!s1.empty())
//	{
//		std::cout << s1.top() << std::endl;
//		s1.pop();
//	}
//	return 0;
//}

// 猫狗队列
class Pet
{
public:
	Pet(std::string type)
		:_type(type)
	{}
	~Pet()
	{

	}
	std::string get_pet_type()
	{
		return _type;
	}
private:
	std::string _type;
};

class Dog :public Pet
{
public:
	Dog()
		:Pet("dog") // 父类没有默认构造函数,必须显示构造
	{
	}
};

class Cat :public Pet
{
public:
	Cat()
		:Pet("cat") // 父类没有默认构造函数,必须显示构造
	{
	}
};

//int main()
//{
//	Cat cat;
//	Pet& p1 = cat;
//	Pet p2 = cat;
//	std::cout << cat.get_pet_type() << std::endl;
//	std::cout << p2.get_pet_type() << std::endl;
//	return 0;
//}

// 实现猫狗队列
class PetEnterQueue
{
public:
	PetEnterQueue(){}
	~PetEnterQueue(){}

public:
	void add(Pet& p)
	{
		// 这里 我们 只把 元素给成q1
		q1.push(p);
	}
	std::vector<Pet> pollAll()
	{
		std::vector<Pet> v;
		while (!q1.empty())
		{
			v.push_back(q1.front());
			q1.pop();
		}
		return v;
	}

	std::vector<Pet> pollDog()
	{
		std::vector<Pet> v;
		while (!q1.empty())
		{
			Pet p = q1.front();
			if (p.get_pet_type() == "dog")
			{
				v.push_back(p);
			}
			else
			{
				q2.push(p);
			}
			q1.pop();
		}
		// 把数据放回来
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		return v;
	}
	std::vector<Pet> pollCat()
	{
		std::vector<Pet> v;
		while (!q1.empty())
		{
			Pet p = q1.front();
			if (p.get_pet_type() == "cat")
			{
				v.push_back(p);
			}
			else
			{
				q2.push(p);
			}
			q1.pop();
		}
		// 把数据放回来
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		return v;
	}
	bool isEmpty()
	{
		return q1.empty();
	}
	bool isDogEmpty()
	{
		// 遍历 这个数组
		bool flag = true;
		while (!q1.empty())
		{
			if (q1.front().get_pet_type() == "dog")
				flag = false;
			q2.push(q1.front());
			q1.pop();
		}
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		return flag;
	}
	bool isCatEmpty(){
		// 遍历 这个数组
		bool flag = true;
		while (!q1.empty())
		{
			if (q1.front().get_pet_type() == "cat")
				flag = false;
			q2.push(q1.front());
			q1.pop();
		}
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
		return flag;
	}

private:
	// 两个队列,实现来回倒腾 定一个规矩,把所有的元素放在q1里面
	std::queue<Pet> q1;  
	std::queue<Pet> q2;
};

int main()
{
	Dog d1;
	Dog d2;
	Dog d3;
	Cat c1;
	Cat c2;
	Cat c3;
	std::vector<Pet> v = { d1, d2, d3, c1, c2, c3 };
	std::vector<Pet> v2 = { Dog() };
	PetEnterQueue q;
	for (int i = 0; i < v.size(); i++)
	{
		q.add(v[i]);
	}
	if (!q.isDogEmpty())
	{
		std::vector<Pet> v3 = q.pollDog();
		q.pollDog();
		if (q.isDogEmpty())
			std::cout << "dog " << v3.size() << std::endl;
	}

	if (!q.isCatEmpty())
	{
		std::vector<Pet> v3 = q.pollCat();
		q.pollCat();
		if (q.isCatEmpty())
			std::cout << "cat " << v3.size() << std::endl;
	}
	if (q.isEmpty())
	{
		std::cout << "空了" << std::endl;
	}
	return 0;
}