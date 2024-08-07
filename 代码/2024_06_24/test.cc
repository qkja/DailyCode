#include <iostream>
int sum(int n)
{
    int i, partialSum;
    partialSum = 0;
    for (i = 0; i <= n; i++)
        partialSum = i * i * i;
    return partialSum;
}

long int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

long int fib(int n)
{
    if (n <= 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

// 最大子序列和

/*
方法1: 使用for循环,三层循环
i: 以位置为起点,n位置为重点,所有可能的子序列
j,k: 保证i位置的请款下,[i,j]的所有的子序列
时间复杂度: n^3
 */

//int maxSubsequenceSum(const int a[], int n)
//{
//    if (a == nullptr)
//        return 0;
//    int thisSum = 0;
//    int maxSum = 0;
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    for (; i < n; ++i)
//    {
//        for (j = i; j < n; ++j)
//        {
//            thisSum = 0;
//            for (k = i; k <= j; ++k)
//                thisSum += a[k];
//            if (thisSum > maxSum)
//                maxSum = thisSum;
//        }
//    }
//    return maxSum;
//}


/*
 * 方法2: 使用两层for循环,时间复杂度 n^2
 */
 
//int maxSubsequenceSum(const int a[], int n)
//{
//  if(nullptr == a)
//    return 0;
//  int maxSum = 0;
//  for(int i = 0; i < n; ++i)
//  {
//    int thisSum = 0;
//    for(int j = i; j < n; ++j)
//    {
//      thisSum += a[j];
//      // 在这里判断就可以知道是以i位置为开始, 结束位置随意变化的的所有情况
//      if(maxSum < thisSum)
//        maxSum = thisSum;
//    }
//  }
//  return maxSum;
//}

int _maxSubsequenceSum(const int a[], int left, int right)
{
  if(left >= right)
    return a[left] > 0 ? a[left] : 0;
  int mid = (left+right) / 2;
  int leftMaxSum = _maxSubsequenceSum(a, left, mid);
  int rightMaxSum = _maxSubsequenceSum(a, left, mid);
}
int maxSubsequenceSum(const int a[], int n)
{
  if(a == nullptr)
    return 0;
  return _maxSubsequenceSum(a, 0, n-1);
}
int main()
{

    return 0;
}
