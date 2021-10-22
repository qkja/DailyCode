#include<stdio.h>
#include<stdlib.h>

//int g_val1 = 10;
//int g_val2;

void test(void) 
{
  static int a = 1;
  a++;
  printf("%d ",a);
}
int main()
{
  
  int i = 0;
  /*while(i<10)
  {
    test();
    i++;
  }*/
  //printf("%d\n",a);
 while(i<10)
 {
   test();
   i++;
 }

  
  printf("\n");
   

  /*printf("code adder :%p\n",main);
  const char* str = "hello world";
  printf("read only :%p\n",str);

  printf("init g_val :%p\n",&g_val1);
  printf("uninit a_val :%p\n",&g_val2);


  char* p = (char*)malloc(10*sizeof(char));
  printf("heap addr :%p\n",p);
  printf("stack addr :%p\n",&str);
  printf("stack addr :%p\n",&p);
  free(p);
  p = NULL;*/

  /*   float a = 9.5f;
  printf("%d\n",a);

  //printf("%d\n",-10/3);*/
  
  

  return 0;
}
