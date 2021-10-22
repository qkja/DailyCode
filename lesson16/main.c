#include<stdio.h>
#include<stdlib.h>

int g_val1 = 10;
int g_val2 = 10;
int g_val3;
int g_val4;
int main()
{
 const char  *str = "abcdef";
 printf("code  : %p\n",main);
 printf("read only : %p\n",str);
 printf("init g_val1 : %p\n",&g_val1);
 printf("init g_val2 : %p\n",&g_val2);
 printf("uninit g_val2 : %p\n",&g_val3); 
 printf("uninit g_val2 : %p\n",&g_val4); 
 char* p1 = (char*)malloc(sizeof(char*)*10);
 char* p2 = (char*)malloc(sizeof(char*)*10); 
 printf("heap addr : %p\n",p1);
 printf("heap addr : %p\n",p2);
 printf("stack addr : %p\n",&str);
 printf("stack addr : %p\n",&p1);
 printf("stack addr : %p\n",&p2);


 
  



/* int a = 10;
  int b = 10;
  int c = 10;
  printf("stack addr a : %p\n",&a);
  printf("stack addr b : %p\n",&b);
  printf("stack addr c : %p\n",&c);
*/
  return 0;
}
