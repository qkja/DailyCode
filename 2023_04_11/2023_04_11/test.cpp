#include <iostream>
#include <iostream>
using namespace std;
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

//class Base{
//public:
//
//	virtual int Bar(int x){
//		return (2 * x);
//	}
//};
//class Derived : public Base{
//public:
//
//	int Bar(int x){
//		return (x / 2);
//	}
//};
//int main(void){
//	Base Obj;
//	Base *pObj = &Obj;
//	printf("%d,", pObj->Bar(100));
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	void print()
//	{
//		cout << "A:print()";
//	}
//};
//class B : public A
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

class A
{
public:
	void FuncA()
	{
		printf("FuncA called\n");
	}
	virtual void FuncB()
	{
		printf("FuncB called\n");
	}
};
class B : public A
{
public:
	void FuncA()
	{
		A::FuncA();
		printf("FuncAB called\n");
	}
	virtual void FuncB()
	{
		printf("FuncBB called\n");
	}
};
void main(void)
{

	B b;
	A *pa;
	pa = &b;
	A *pa2 = new A;
	pa->FuncA();
	pa->FuncB();
	pa2->FuncA();
	pa2->FuncB();
	delete pa2;
}