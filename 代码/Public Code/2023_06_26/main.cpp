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
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//
//int main()
//{
//	Student stu;
//	stu._name = "����";
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
	string _name; // ����
	string _sex;  // �Ա�
	int _age;     // ����
};
class Student : public Person
{
public:
	Student()
	{
		_name = "����";
		_sex = "��";
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