#include<stdio.h>
#define RET(x,n)   x##e##n
int main()
{
  printf("%d\n",RET(3.14,2));
  printf("%d\n",RET(3.14,2));
  printf("%d\n",RET(3.14,2));
  printf("%d\n",RET(3.14,2));
  printf("%d\n",RET(3.14,2));
  printf("%d\n",RET(3.14,2));
  return 0;
}
