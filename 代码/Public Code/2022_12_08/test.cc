/*
 * @Author: 算法杰哥 qkj1205@163.com
 * @Date: 2022-12-07 23:30:55
 * @LastEditors: 算法杰哥 qkj1205@163.com
 * @LastEditTime: 2022-12-07 23:30:56
 * @FilePath: /2022_12_08/test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
// 给定一个有序数组
// 给定一个绳子
#include <assert.h>
int maxPoint(int *arr, int len, int l)
{
  assert(arr);
  assert(l > 0);
  int max = 0;
  for (size_t i = 0; i < len; i++)
  {
    int j = i;
    while (j < len && arr[j] - arr[i] <= len)
    {
      j++;
    }
    if (j < len && arr[j] - arr[i] > len)
    {
      int val = j - i;
      if (val > max)
        max = val;
    }
  }
  return max;
}
int main()
{

  return 0;
}