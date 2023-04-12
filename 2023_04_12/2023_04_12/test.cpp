#include <iostream>
#include <cstdio>

using namespace std;
//class Base {
//public:
//	Base() {
//		echo();
//	}
//	virtual void echo() {
//		printf("Base");
//	}
//};
//class Derived :public Base {
//public:
//	Derived() {
//		echo();
//	}
//	virtual void echo() {
//		printf("Derived");
//	}
//};
//int main() {
//	Base* base = new Derived();
//	base->echo();
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//class A {
//public:
//	virtual ~A() {
//		cout << "~A()";
//	}
//};
//class B{
//public:
//	virtual ~B() {
//		cout << "~B()";
//	}
//};
//class C : public A, public B {
//public:
//	~C() {
//		cout << "~C()";
//	}
//};
//int main() {
//	C * c = new C;
//	B * b1 = dynamic_cast<B *>(c);
//	A * a2 = dynamic_cast<A *>(b1);
//	delete a2;
//}

class A
{
public:
	A() :m_iVal(0){ test(); }
	virtual void func() { std::cout << m_iVal << ' '; }
	void test(){ func(); }
public:
	int m_iVal;
};
class B : public A
{
public:
	B(){ test(); }
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal << ' ';
	}
};
int main(int argc, char* argv[])
{
	A*p = new B;
	p->test();
	return 0;
}