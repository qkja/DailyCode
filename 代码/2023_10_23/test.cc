#include <iostream>
using namespace std;
//class parent {
//	int i;
//protected:
//	int x;
//public:
//	parent() { x = 0; i = 0; }
//	void change() { x++; i++; }
//	void display();
//};
//class son :public parent {
//public:
//	void modify();
//};
//void parent::display() {
//	cout << "x=" << x << endl;
//}
//void son::modify() {
//	x++;
//}
//int main() {
//	son A;
//	parent B;
//	A.display();
//	A.change();
//	A.modify();
//	A.display();
//	B.change();
//	B.display();
//	return 0;
//}

//int main()
//{
//	const char* p = "aaa";
//	cout << sizeof(p) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class B
//{
//public:
//	B()
//	{
//		cout << "default constructor" << " ";
//	}
//	~B()
//	{
//		cout << "destructed" << " ";
//	}
//	B(int i) : data(i)
//	{
//		cout << "constructed by parameter" << data << " ";
//	}
//private: int data;
//};
//B Play(B b)
//{
//	return b;
//}
//int main(int argc, char* argv[])
//{
//	B temp = Play(5);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void print()
//	{
//		cout << "A::print()" << "\n";
//	}
//};
//class B : public A
//{
//public: virtual void print()
//{
//	cout << "B::print()" << "\n";
//}
//};
//class C : public A
//{
//public: virtual void print()
//{
//	cout << "C::print()" << "\n";
//}
//};
//void print(A a)
//{
//	a.print();
//}
//int main()
//{
//	A a, * aa, * ab, * ac;
//	B b;
//	C c;
//	aa = &a;
//	ab = &b;
//	ac = &c;
//	a.print();
//	b.print();
//	c.print();
//	aa->print();
//	ab->print();
//	ac->print();
//	print(a);
//	print(b);
//	print(c);
//}

//class A {
//public:
//	void test(float a) { cout << "1"; }
//};
//class B :public A {
//public:
//
//	void test(int b) { cout << "2"; }
//};
//
//int main()
//{
//	A* a = new A;
//	B* b = new B;
//	a = b;
//	a->test(1.1);
//}

//class Base {
//public:
//	Base(int j) : i(j) {}
//	virtual~Base() {}
//	void func1() {
//		i *= 10;
//		func2();
//	}
//	int getValue() {
//		return i;
//	}
//protected:
//	virtual void func2() {
//		i++;
//	}
//protected:
//	int i;
//};
//class Child : public Base {
//public:
//	Child(int j) : Base(j) {}
//	void func1() {
//		i *= 100;
//		func2();
//	}
//protected:
//	void func2() {
//		i += 2;
//	}
//};
//int main() {
//	Base* pb = new Child(1);
//	pb->func1();
//	cout << pb->getValue() << endl; delete pb;
//}

//#include<iostream>
//using namespace std;
//class A {
//public: A(const char* s) { cout << s << endl; } ~A() {}
//};
//class B : virtual public A {
//public: B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class C : virtual public A {
//public: C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class D : public B, public C {
//public: D(const char* s1, const char* s2, const char* s3, const char* s4) :B(s1, s2), C(s1, s3), A(s1)
//{
//	cout << s4 << endl;
//}
//};
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D"); delete p; return 0;
//}

//#include<iostream>
//using namespace std;
//class A {
//public: A(const char* s) { cout << s << endl; } ~A() {}
//};
//class B :  public A {
//public: B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class C :  public A {
//public: C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//class D : public B, public C {
//public: D(const char* s1, const char* s2, const char* s3, const char* s4) :B(s1, s2), C(s1, s3)
//{
//	cout << s4 << endl;
//}
//};
//int main() {
//	D* p = new D("class A", "class B", "class C", "class D"); delete p; return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//class B0 {
//public:
//	virtual void display() {
//		cout << "B0::display0" << endl;
//	}
//};
//class B1 :public B0 {
//public:
//	void display() { cout << "B1::display0" << endl; }
//};
//class D1 : public B1 {
//public:
//	void display() {
//		cout << "D1::display0" << endl;
//	}
//};
//void fun(B0 ptr) {
//	ptr.display();
//}
//int main() {
//	B0 b0;
//	B1 b1;
//	D1 d1;
//	fun(b0);
//	fun(b1);
//	fun(d1);
//}