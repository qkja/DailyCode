#include <stdio.h>
//int main() 
//{
//	char a[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 0 }, * p;
//	int i;
//	i = 8;
//	p = a + i;
//	printf("%s\n", p - 3);
//}
//#include <stdio.h>
//int main() {
//	long long a = 1, b = 2, c = 3;
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}
//#include<iostream>
//#include<cstdio>
//using namespace std;
//int main() {
//	/*int m = 0123, n = 123;
//	printf("%o %o\n", m, n);*/
//	int a[5] = { 1,3,5,7,9 };
//	int* p = (int*)(&a + 1);
//	printf("%d %d", *(a + 1), *(p - 1));
//	return 0;
//}
//#include <stdio.h>
//int cnt = 0;
//int fib(int n) {
//	cnt++;
//	if (n == 0)
//		return 1;
//	else if (n == 1)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//void main() {
//	fib(8);
//	printf("%d", cnt);
//}
//
//#pragma pack(4)
//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
//struct B
//{
//	int a;
//	short b;
//	char c;
//	int d;
//};
//
//int main()
//{
//	printf("%d %d", sizeof(A), sizeof(B));
//	printf("%d %d", sizeof(short), sizeof(long));
//	return 0;
//}
#include <string.h>

//int main()
//{
//	char p1[15] = "abcd", * p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s", str);
//}

#/*include<iostream>
#include<string>
using namespace std;
class A {
	friend long fun(A s) {
		if (s.x < 3) {
			return 1;
		}
		return s.x + fun(A(s.x - 1));
	}
public:
	A(long a) {
		x = a--;
	}
private:
	long x;
};
int main() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += fun(A(i));
	}
	cout << sum;
	return 0;
}*/
//#include <iostream>
//using namespace std;
//int main(void)
//{
//	const int a = 10;
//	int* p = (int*)(&a);
//	*p = 20;
//	cout << "a = " << a << ", *p = " << *p << endl;
//	return 0;
//}