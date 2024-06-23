#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//class A
//{
//public:
//	void func1()
//	{
//		cout << "A:: func1()" << endl;
//	}
//private:
//	int _a;
//
//};
//
//class B : public A
//{
//	virtual void func1()
//	{
//		cout << "B:: func1()" << endl;
//
//	}
//};
//
//int main()
//{
//	B b;
//	A& a = b;
//	a.func1();
//	return 0;
//}
//
//class A
//{
//public:
//	virtual void func() 
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	// 检测这个函数在 父类中是否是虚函数
//	virtual void func() override
//	{
//		cout << "B:: func()" << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	return 0;
//}

#include<stdio.h>

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if ((n & (n - 1)) == 0)
//	{
//		printf("YES\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("Before a = %d b = %d\n", a, b);
//
//	a = a ^ b;
//	b = a ^ b;     //把 b 赋给 a
//	a = a ^ b;     //把 a 赋给 b
//	printf("After  a = %d b = %d\n", a, b);
//	return 0;
//}

#include<stdio.h>

//int main()
//{
//	int a = 10;
//	char ch = 'a';
//	int x = ch;   // 疑问1
//	ch = a;       // 疑问2
//	return 0;
//}

//输出什么
//#include <stdio.h>
//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//	int a = 2.9;
//	int b = -2.9;
//
//	printf("%d\n", a);
//	printf("%d\n", b);
//	return 0;
//}

//#include <stdio.h>
//#include <math.h> //因为使用了floor函数,需要添加该头文件
//
//int main()
//{
//	//本质是向-∞取整,注意输出格式要不然看不到结果
//	printf("%.1f\n", floor(-2.9)); //-3
//	printf("%.1f\n", floor(-2.1)); //-3
//	printf("%.1f\n", floor(2.9)); //2
//	printf("%.1f\n", floor(2.1)); //2
//
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	//本质是四舍五入
//	printf("%.1f\n", round(2.1));
//	printf("%.1f\n", round(2.9));
//	printf("%.1f\n", round(-2.1));
//	printf("%.1f\n", round(-2.9));
//
//	return 0;
//}

#include <stdio.h>
#include <math.h>

int main()
{
	int a = 10;
	int d = 3;
	printf("%d\n", a % d);
	return 0;
}