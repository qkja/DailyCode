#include <iostream>
using namespace std;

//class Person
//{
//public:
//	Person(const char* name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	// 拷贝构造
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		:_num(num)
//		, Person(name)  //  这 才是  最正确  的动作
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		: _num(s._num)
//		//, Person(s) //  自己会 发生 切片
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//protected:
//	int _num; //学号
//};
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		:_num(num)
//		, Person(name)  //  这 才是  最正确  的动作
//	{
//		cout << "Student()" << endl;
//	}
//
//	~Student()
//	{
//		~Person();
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _num; //学号
//};
//
//int main()
//{
//	Student stu("jack", 18);
//
//	return 0;
//}
//int main()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	return 0;
//}

//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//void Test()
//{
//	Student sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	//2.基类对象不能赋值给派生类对象
//	/*sobj = pobj;*/
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	//pp = &sobj;
//	//Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
//	//ps1->_No = 10;
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//}
//
// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//}

// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);
//}
//int main()
//{
//	Test();
//	//cout << "--" << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//class B : virtual public A
//{
//public:
//	int _b;
//};
//class C : public A
//{
//public:
//	int _c;
//};
//
//class D
//{
//public:
//	int _d;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};

//int main()
//{
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	cout << sizeof(D) << endl;
//	cout << sizeof(int*) << endl;
//	/*D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//
//	d._b = 3;
//	d._c = 4;
//
//	d._d = 5;*/
//	return 0;
//}

// 如果存在   虚继承的话   此时  我们的 空间如何计算,主要是    考虑续集表指针 的问题
//class A
//{
//public:
//	void func()
//	{}
//public:
//	long long _p;
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//
//	cout << sizeof(B) << endl;
//	return 0;
//}

//class A
//{
//public:
//	int _a = 0x1122;
//};
//class B : virtual public A
//{
//public:
//	int _b = 0x3344;;
//};
//class C : public A
//{
//public:
//	int _c;
//};
//
//class D
//{
//public:
//	int _d;
//};
//
//
//int main()
//{
//	cout << sizeof(B) << endl;
//	B b;
//	/*cout << sizeof(C) << endl;
//	cout << sizeof(D) << endl;*/
//	cout << sizeof(int*) << endl;
//
//	return 0;
//}

int main()
{
	cout << -3 % 2 << endl;
	return 0;
}