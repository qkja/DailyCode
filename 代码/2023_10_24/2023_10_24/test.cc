#include <iostream>

//struct A{
//	void foo(){ printf("foo"); }
//	virtual void bar(){ printf("bar"); }
//	A(){ bar(); }
//};
//struct B :A{
//	void foo(){ printf("b_foo"); }
//	void bar(){ printf("b_bar"); }
//};
//
//int main()
//{
//	A *p = new B;
//	p->foo();
//	p->bar();
//	return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1)
//	{
//		std::cout << "A->" << val << std::endl;
//	}
//	virtual void test()
//	{
//		func();
//	}
//};
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	B*p = new B;
//	p->test();
//	return 0;
//}

//class A
//{
//public:
//	void foo()
//	{
//		printf("1");
//	}
//	virtual void fun()
//	{
//		printf("2");
//	}
//};
//class B : public A
//{
//public:
//	void foo()
//	{
//		printf("3");
//	}
//	void fun()
//	{
//		printf("4");
//	}
//};
//int main(void)
//{
//	A a;
//	B b;
//	A *p = &a;
//	p->foo();
//	p->fun();
//	p = &b;
//	p->foo();
//	p->fun();
//	A *ptr = (A *)&b;
//	ptr->foo();
//	ptr->fun();
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		printf("A ");
//	}
//	virtual ~A()
//	{
//		printf("deA ");
//	}
//};
//class B
//{
//public:
//	B()
//	{
//		printf("B ");
//	}
//	virtual ~B()
//	{
//		printf("deB ");
//	}
//};
//class C : public A, public B
//{
//public:
//	C()
//	{
//		printf("C ");
//	}
//	~C()
//	{
//		printf("deC ");
//	}
//};
//int main()
//{
//	A *a = new C();
//	delete a;
//	return 0;
//}
//#include <iostream>
//class Base{
//public:
//	int Bar(char x){
//		return (int)(x);
//	}
//	virtual int Bar(int x){
//		return (2 * x);
//	}
//};
//class Derived : public Base{
//public:
//	int Bar(char x){
//		return (int)(-x);
//	}
//	int Bar(int x){
//		return (x / 2);
//	}
//};
//int main(void){
//	Derived Obj;
//	Base *pObj = &Obj;
//	printf("%d,", pObj->Bar((char)(100)));
//	printf("%d,", pObj->Bar(100));
//}
//#include <iostream>
//using namespace std;
//
//class Test{
//public:
//	int a;
//	int b;
//	virtual void fun() {}
//	Test(int temp1 = 0, int temp2 = 0)
//	{
//		a = temp1;
//		b = temp2;
//	}
//	int getA()
//	{
//		return a;
//	}
//	int getB()
//	{
//		return b;
//	}
//};
//int main()
//{
//	Test obj(5, 10);
//	// Changing a and b
//	int* pInt = (int*)&obj;
//	*(pInt + 0) = 100;
//	*(pInt + 1) = 200;
//	cout << "a = " << obj.getA() << endl;
//	cout << "b = " << obj.getB() << endl;
//	return 0;
//}

#include <iostream>
using namespace std;
//class A
//{
//public:
//	void print()
//	{
//		cout << "A:print()";
//	}
//};
//class B : private A
//{
//public:
//	void print()
//	{
//		cout << "B:print()";
//	}
//};
//class C : public B
//{
//public:
//	void print()
//	{
//		A::print();
//	}
//};
//int main()
//{
//	C b;
//	b.print();
//}

//class A
//{
//public:
//	void FuncA()
//	{
//		printf("FuncA called\n");
//	}
//	virtual void FuncB()
//	{
//		printf("FuncB called\n");
//	}
//};
//class B : public A
//{
//public:
//	void FuncA()
//	{
//		A::FuncA();
//		printf("FuncAB called\n");
//	}
//	virtual void FuncB()
//	{
//		printf("FuncBB called\n");
//	}
//};
//void main(void)
//{
//	B b;
//	A *pa = nullptr;
//	pa = &b;
//	A *pa2 = new A;
//	pa->FuncA();
//	pa->FuncB();
//	pa2->FuncA();
//	pa2->FuncB();
//	delete pa2;
//}

#include<iostream>
using namespace std;
class Base
{
public:
	virtual int foo(int x)
	{
		return x * 10;
	}
	int foo(char x[14])
	{
		return sizeof(x)+10;
	}
};
class Derived : public Base
{
	int foo(int x)
	{
		return x * 20;
	}
	virtual int foo(char x[10])
	{
		return sizeof(x)+20;
	}
};
int main()
{
	Derived stDerived;
	Base *pstBase = &stDerived;
	char x[10];
	printf("%d\n", pstBase->foo(100) + pstBase->foo(x));
	return 0;
}