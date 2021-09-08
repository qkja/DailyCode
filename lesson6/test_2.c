#include<stdio.h>
#define STR(x,n)  x##e##n
int main()
{
  printf("%lf\n",STR(3.14,2));
  return 0;
}
