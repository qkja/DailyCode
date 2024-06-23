#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//public:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
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
//	stu._name = "张三";
//	stu._age = 20;
//	stu.Print();
//	return 0;
//}

class Person
{
public:
	void func()
	{
		cout << _name <<" "<< _sex <<" "<< _age << endl;
	}
protected:
	string _name; // 姓名
	string _sex;  // 性别
	int _age;     // 年龄
};
class Student : public Person
{
public:
	Student()
	{
		_name = "张三";
		_sex = "男";
		_age = 18;
	}
};

int main()
{
	Person per;
	Student stu;
	per = stu;
	per.func();
	return 0;
}