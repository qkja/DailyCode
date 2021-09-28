#include<stdio.h>
void split_year(int day_of_year,int year,int *month,int *day)
{
if((year%4==0&&year%100!=0)||(year%400==0))
{



}
else 
{



}


}
int main()
{
  int day_of_year = 0;
  int year = 0;
  int month = 0;
  int day = 0;
  scanf("%d",&year);
  scanf("%d",&day_of_year);
  split_year(day_of_year,year,&month,&day);

  
  return 0;
}
