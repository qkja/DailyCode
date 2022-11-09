/**
 * User: Qkj
 * Description:
 * Date: 2022-11-09
 * Time: 16:01
 */
#include <iostream>
#include <vector>
using namespace std;

int maxFour(int a, int b, int c, int d)
{
   int x = a > b ? a : b;
   int y = c > d ? c : d;

   return x > y ? x : y;
}

int main()
{
   int m = 0;
   int n = 0;
   cin >> m >> n;
   int rpos = 0; // 行
   int cpos = 0; // 列
   vector<vector<char>> vv(m, vector<char>(n));
   for (int i = 0; i < m; i++)
   {
       for (int j = 0; j < n; j++)
       {
           cin >> vv[i][j];
           if (vv[i][j] == '@')
           {
               rpos = i;
               cpos = j;
           }
       }
   }

   vector<vector<int>> result(m, vector<int>(n,0)); // 这里直接
   // f(i,j) 表示达到当前位置最大的黑色转款数
   //先来 初始化
   int max = 0;

   bool flag = true;
   int count = 0;
   for (int i = cpos + 1; i < n; i++)
   {
       if (flag == true && vv[rpos][i] == '.')
           result[rpos][i] = ++count;
       else
           flag = false;
       if (result[rpos][i] > max)
           max = result[rpos][i];
   }

   flag = true;
   count = 0;
   for (int i = cpos - 1; i >= 0; i--)
   {
       if (flag == true && vv[rpos][i] == '.')
           result[rpos][i] = ++count;
       else
           flag = false;
       if (result[rpos][i] > max)
           max = result[rpos][i];
   }

  /* flag = true;
   count = 0;
   for (int i = rpos + 1; i < m; i++)
   {
       if (flag == true && result[i][cpos] == '.')
           result[i][cpos] = ++count;
       else
           flag = false;
       if (result[i][cpos] > max)
           max = result[i][cpos];
   }

   flag = true;
   count = 0;

   for (int i = rpos - 1; i >= 0; i--)
   {
       if (flag == true && result[i][cpos] == '.')
           result[i][cpos] = ++count;
       else
           flag = false;

       if (result[i][cpos] > max)
           max = result[i][cpos];
   }*/

   for (int i = rpos - 1; i >= 0; i--)
   {
       for (int j = 0; j < n; j++)
       {
           /*if (j == cpos)
               continue;*/
          /* if (i == 6 && j == 5)
           {

           }
           cout << i <<"        " << j << endl;*/
           if (vv[i][j] == '#')
           {
               result[i][j] = 0;
           }
           else if (vv[i][j] == '.')
           {
               int a = 0;
               int b = 0;
               int c = 0;
               int d = 0;
               if (i -1 >= 0)
                   a = result[i - 1][j];
               if(i+1 < m)
                   b = result[i + 1][j];
               if (j - 1 >= 0)
                   c = result[i][j - 1];
               if (j + 1 < n)
                   d = result[i][j + 1];
               result[i][j] = maxFour(a,b,c,d) + 1;
               //result[i][j] = maxFour(result[i - 1][j], result[i + 1][j], result[i][j - 1], result[i][j + 1]) + 1;

               //if()
              /* if (i == 0 && j == 0)
               {
                   result[i][j] = maxFour(0, result[i + 1][j], 0, result[i][j + 1]) + 1;
               }
               else if (i == 0)
               {
                   result[i][j] = maxFour(0, result[i + 1][j], result[i][j - 1], result[i][j + 1]) + 1;
               }
               else if (j == 0)
               {
                   result[i][j] = maxFour(result[i - 1][j], result[i + 1][j], 0, result[i][j + 1]) + 1;
               }
               else
               {
                   result[i][j] = maxFour(result[i - 1][j], result[i + 1][j], result[i][j - 1], result[i][j + 1]) + 1;
               }*/

               if (result[i][j] > max)
                   max = result[i][j];
           }
       }
   }

   for (int i = rpos + 1; i < m; i++)
   {
       for (int j = 0; j < n; j++)
       {
          /* if (j == cpos)
               continue;*/
           if (vv[i][j] == '#')
           {
               result[i][j] = 0;
           }
           else if (vv[i][j] == '.')
           {
               int a = 0;
               int b = 0;
               int c = 0;
               int d = 0;
               if (i - 1 >= 0)
                   a = result[i - 1][j];
               if (i + 1 < m)
                   b = result[i + 1][j];
               if (j - 1 >= 0)
                   c = result[i][j - 1];
               if (j + 1 < n)
                   d = result[i][j + 1];
               result[i][j] = maxFour(a, b, c, d) + 1;
               /*if (i == 0 && j == 0)
               {
                   result[i][j] = maxFour(0, result[i + 1][j], 0, result[i][j + 1]) + 1;
               }
               else if (i == 0)
               {
                   result[i][j] = maxFour(0, result[i + 1][j], result[i][j - 1], result[i][j + 1]) + 1;
               }
               else if (j == 0)
               {
                   result[i][j] = maxFour(result[i - 1][j], result[i + 1][j], 0, result[i][j + 1]) + 1;
               }
               else
               {
                   result[i][j] = maxFour(result[i - 1][j], result[i + 1][j], result[i][j - 1], result[i][j + 1]) + 1;
               }*/

               if (result[i][j] > max)
                   max = result[i][j];
           }
       }
   }
   cout << max << endl;
   return 0;
}

// int maxFour(int a, int b, int c, int d)
// {
//   int x = a > b ? a : b;
//   int y = c > d ? c : d;

//   return x > y ? x : y;
// }

// int main()
// {
//   int m = 0;
//   int n = 0;
//   cin >> m >> n;
//   int rpos = 0; // 行
//   int cpos = 0; // 列
//   vector<vector<char>> vv(m, vector<char>(n));
//   for (int i = 0; i < m; i++)
//   {
//     for (int j = 0; j < n; j++)
//     {
//       cin >> vv[i][j];
//       if (vv[i][j] == '@')
//       {
//         rpos = i;
//         cpos = j;
//       }
//     }
//   }

//   vector<vector<int>>result(m, vector<int>(n, 0)); // 这里直接
//   // f(i,j) 表示达到当前位置最大的黑色转款数
//   //先来 初始化
//   int max = 0;

//   bool flag = true;
//   int count = 0;
//   for (int i = cpos + 1; i < n; i++)
//   {
//     if (flag == true && vv[rpos][i] == '.')
//       result[rpos][i] = ++count;
//     else
//       flag = false;
//     if (result[rpos][i] > max)
//       max = result[rpos][i];
//   }

//   flag = true;
//   count = 0;
//   for (int i = cpos - 1; i >= 0; i--)
//   {
//     if (flag == true && vv[rpos][i] == '.')
//       result[rpos][i] = ++count;
//     else
//       flag = false;
//     if (result[rpos][i] > max)
//       max = result[rpos][i];
//   }

//   flag = true;
//   count = 0;
//   for (int i = rpos + 1; i < m; i++)
//   {
//     if (flag == true && vv[rpos][i] == '.')
//       result[rpos][i] = ++count;
//     else
//       flag = false;
//     if (result[rpos][i] > max)
//       max = result[rpos][i];
//   }

//   flag = true;
//   count = 0;

//   for (int i = rpos - 1; i >= 0; i--)
//   {
//     if (flag == true && vv[rpos][i] == '.')
//       result[rpos][i] = ++count;
//     else
//       flag = false;

//     if (result[rpos][i] > max)
//       max = result[rpos][i];
//   }

//   for (int i = rpos - 1; i >= 0; i--)
//   {
//     for (int j = 0; j < n; j++)
//     {
//       if (vv[i][j] == '#')
//       {
//         result[i][j] = 0;
//       }
//       else if (vv[i][j] == '.')
//       {
//         if (i == 0 && j == 0)
//         {
//           result[i][j] = maxFour(0, result[i + 1][j], 0, result[i][j + 1]) + 1;
//         }
//         else if (i == 0)
//         {
//           result[i][j] = maxFour(0, result[i + 1][j], result[i][j - 1], result[i][j + 1]) + 1;
//         }
//         else if (j == 0)
//         {
//           result[i][j] = maxFour(result[i - 1][j], result[i + 1][j], 0, result[i][j + 1]) + 1;
//         }
//         else
//         {
//           result[i][j] = maxFour(result[i - 1][j], result[i + 1][j], result[i][j - 1], result[i][j + 1]) + 1;
//         }

//         if (result[i][j] > max)
//           max = result[i][j];
//       }
//     }
//   }

//   for (int i = rpos + 1; i < m; i++)
//   {
//     for (int j = 0; j < n; j++)
//     {
//       if (vv[i][j] == '#')
//       {
//         result[i][j] = 0;
//       }
//       else if (vv[i][j] == '.')
//       {
//         if (i == 0 && j == 0)
//         {
//           result[i][j] = maxFour(0, result[i + 1][j], 0, result[i][j + 1]) + 1;
//         }
//         else if (i == 0)
//         {
//           result[i][j] = maxFour(0, result[i + 1][j], result[i][j - 1], result[i][j + 1]) + 1;
//         }
//         else if (j == 0)
//         {
//           result[i][j] = maxFour(result[i - 1][j], result[i + 1][j], 0, result[i][j + 1]) + 1;
//         }
//         else
//         {
//           result[i][j] = maxFour(result[i - 1][j], result[i + 1][j], result[i][j - 1], result[i][j + 1]) + 1;
//         }

//         if (result[i][j] > max)
//           max = result[i][j];
//       }
//     }
//   }
//   cout << max << endl;
//   return 0;
// }
