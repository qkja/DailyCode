#include <iostream>
#include <stdio.h>

int main()
{
	int x = 6;
	if (x-- < 5) printf("%d\n", x);
	else printf("%d\n", x++);
	return 0;
}