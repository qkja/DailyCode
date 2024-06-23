#include <stdio.h>
//int func(int x)
//{
//	return (x);
//}
//int main()
//{
//	printf("%d\n", func(10));
//	return 0;
//}
//int func()
//{
//	return 5 * 7 - 3;
//}
//int main()
//{
//	printf("%d\n", func() / 13);
//	return 0;
//}
int a = 1;
int func(int c)
{
	static int a = 3;
	a = a + 1;
	c = c + 2;
	return (a + c);
}
int main()
{
	int k = 0;
	for (int i = 0; i < 2; ++i)
	{
		k = k + func(a);
		printf("%d %d\n", a, k);
	}
	return 0;
}


