#include <stdio.h>

int MyAdd(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	int x = 0xA;
	int y = 0xB;
	int z = 0;

	z = MyAdd(x, y);
	printf("z = %d\n", z);
	return 0;
}

//int MyAdd(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int x = 0xA;
//	int y = 0xB;
//	int z = 0;
//
//	z = MyAdd(x, y);
//	printf("z = %d\n", z);
//	return 0;
//}