//
//int main()
//{
//	printf("hello\n");
//	return 0;
//}
//#include <stdio.h>
//main()
//{
//	int year, n;
//	n = 0;
//	for (year = 2020; year <= 2050; year++)
//	{
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		{
//			n++;
//			printf("%-7d", year);
//			if (n % 5 == 0)
//				printf("\n");
//		}
//		
//	}
//	printf("\n");
//	return 0;
//}

#include <stdio.h>
//#include <string.h>
//main()
//{
//	//char arr[100] = { 0 };
//	//scanf("%s", arr);
//	//int len = strlen(arr);
//	//for (int i = 0; i < len; i++)
//	//{
//	//	if (arr[i] >= 'A' && arr[i] <= 'Z')
//	//	{
//	//		arr[i] = arr[i] + 'a' - 'A';
//	//	}
//	//	else if (arr[i] >= '0' && arr[i] <= '9')
//	//	{
//	//		arr[i] = '*';
//	//	}
//	//}
//	//printf("%s", arr);
//
//	/*Relative melting time with Rayleigh number*/
//	/*	int k, a = 1, b = 3, c = 5; 
//		k = a>b ? a : b; 
//		k = k > c ? k : c;
//		printf("%d", k);*/
//	/*	int a = 1;
//		int b = 3;
//		int c = (a = 2, b = 4);
//		printf("%d", c);*/
//
//	//int i, j, sum = 0;
//	//for (i = 1; i <= 5; i++)
//	//for (j = 1; j <= 3; j++)
//	//	sum = sum + j;
//	//printf("%d\n", sum);
//	double a = 1.0;
//	scanf("%lf", &a);
//	printf("%lf", a);
//	return 0;
//}
////
//8: "%lf", &a
//9: s > a
//10: s + (n+1) / n

#include<stdio.h>
main()
{
	char c;
	c = '\0';
	while (scanf("%c", &c) != EOF)
	{
		if (c >= 'A' &&c <= 'Z')
		{
			c = c + 'a' - 'A';
			
		}
		else if (c >= '0' &&c <= '9')
		{
			c = '*';
		}
		printf("%c", c);
	}
}
