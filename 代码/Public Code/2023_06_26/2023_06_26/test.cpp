#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/min-stack/
// ��Сջ
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
//		// ��s1 ��Ԫ�ط��� s2��
//		while (!s1.empty())
//		{
//			s2.push(s1.top());
//			s1.pop();
//		}
//		int ret = s2.top();
//		s2.pop();
//		// ���µ�������
//		while (!s2.empty())
//		{
//			s1.push(s2.top());
//			s2.pop();
//		}
//		return ret;
//	}
//private:
//	std::stack<int> s1;  // ֻ���� ��ջ
//	std::stack<int> s2;  // ֻ���� ��ջ
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
//	// �õ�ջ��Ԫ�ز��Ƴ�,��ʱ���Ǳ���s1��һ������Ԫ��
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
//			// ret ��ջ��Ԫ��,����ȥ������ȥ��
//			int result = get_the_element_at_the_bottom_of_the_stack(s1);
//			// ��ret ���Ԫ��������ջ
//			s1.push(ret);
//			return result;
//		}
//	}
//	void reverse_by_stack(std::stack<int>& s1)
//	{
//		if (s1.empty())
//			return;
//		// ��ջ��Ԫ��
//		int ret = get_the_element_at_the_bottom_of_the_stack(s1);
//		// ��ôϣ���ݹ�,�õ�����ջ�׵�Ԫ��,���Ұ����ջ�����
//		
//		reverse_by_stack(s1);
//		// ������뷨,������ջ��ֻ����һ��Ԫ�ص�ʱ��,��ʱ�����õ������Ԫ��,�����ݹ�,����
//		// ��,ֱ�ӷ���,��������ž��ǰ����Ԫ����ջ,��ʱ�����Ѿ���������õĲ���
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

// è������
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
		:Pet("dog") // ����û��Ĭ�Ϲ��캯��,������ʾ����
	{
	}
};

class Cat :public Pet
{
public:
	Cat()
		:Pet("cat") // ����û��Ĭ�Ϲ��캯��,������ʾ����
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

// ʵ��è������
class PetEnterQueue
{
public:
	PetEnterQueue(){}
	~PetEnterQueue(){}

public:
	void add(Pet& p)
	{
		// ���� ���� ֻ�� Ԫ�ظ���q1
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
		// �����ݷŻ���
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
		// �����ݷŻ���
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
		// ���� �������
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
		// ���� �������
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
	// ��������,ʵ�����ص��� ��һ�����,�����е�Ԫ�ط���q1����
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
		std::cout << "����" << std::endl;
	}
	return 0;
}