#include<stdio.h>

int fun(int arr[] , int target , int arrSize )
{
   int left = 0;
   int right=arrSize - 1;
   while(left <= right)
   {
      int ret = (left + right)/2;
      if(arr[ret] > target)
      {

      }
   }
}
int main()
{
  int arr[10]={0};
  int temp = 0;
  scanf("%d",&temp);
  for(int i=0;i<10;i++)
  {
    scanf("%d",&arr[i]);
  }
  int ret = fun(arr , temp , sizeof(arr)/sizeof(arr[0]));
  //zhaodaole fanhui xiaobiao 
  if(-1==ret)
  {
    printf("I cant' find it\n");
  }
  else   
  {
    printf("I find it ! It's :%d\n",ret);
  }
  return 0;
}
