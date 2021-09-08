#include<stdio.h>
int fun(void)
{
  int a=1;
  return (char)a;
}
int main()
{
  //int ret=fun();
  /*if(1==ret)
  {
    printf("xioaduan\n");
  }
  else if(0==ret)
  {
    printf("daduan\n");
  }*/


  char ch= -128;
  printf("%#x\n",ch);
  return 0;
}
