/**
 * User: Qkj
 * Description:
 * Date: 2023-01-23
 * Time: 16:53
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void myReverse(string &str, int begin, int end)
{
  while (begin < end)
  {

    swap(str[begin], str[end]);
    begin++;
    end--;
  }
}
int main()
{
  string str;
  getline(cin, str);
  int begin = 0;

  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == ' ')
    {
      myReverse(str, begin, i - 1);
      begin = i + 1;
    }
  }
  myReverse(str, begin, str.size() - 1);

  // cout << "------------" << endl;
  myReverse(str, 0, str.size() - 1);
  cout << str << endl;
}
// 64 位输出请用 printf("%lld")

// int main()
// {
//   int n = 0;
//   cin >> n;

//   vector<int> v;
//   v.resize(n);
//   for (int i = 0; i < n; i++)
//   {
//     cin >> v[i];
//   }

//   bool flag = true;
//   if (v[0] < v[1])
//   {
//     flag = false;
//   }
//   int prev = 0;
//   int next = prev + 1;
//   int count = 0;
//   while (1)
//   {
//    if(flag)
//    {
//     while (next<n&& v[next]>=v[next-1])
//     {
//       next++;
//     }
//     if(next <n)
//     {
//       count++;
//       prev = next;
//       next++;
//       if (next < n && v[next] >= v[next - 1])
//     }
//    }
//    else
//    {

//    }
//   }

//   return 0;
// }

// int main()
// {
//   int n = 0;
//   cin >> n;
//   if (n == 1)
//   {
//     cout << 1 << endl;
//   }
//   vector<int> v;
//   v.resize(n);
//   for (int i = 0; i < n; i++)
//   {
//     cin >> v[i];
//   }

//   bool flag = true;
//   if (v[0] < v[1])
//   {
//     flag = false;
//   }
//   int prev = 0;
//   int next = prev + 1;
//   int count = 0;
//   while (next < n)
//   {
//     // 首先判断   flag
//     if(flag) // next > prev
//     {
//       prev++;
//       next++;
//       // next 探探头
//       if(next<n)
//       {
//         if(v[next]<v[prev])
//         {
//           count++;
//           prev++;
//           next++;
//           if (next < n && v[next] <= v[prev])
//           {
//             flag = false;
//           }
//           if (next < n && v[next] >= v[prev])
//           {
//             flag = true;
//           }
//         }
//       }
//     }
//     else
//     {

//     }
//   }

//   return 0;
// }

// int main()
// {
//   int n = 0;
//   cin >> n;
//   if (n == 1)
//   {
//     cout << 1 << endl;
//   }
//   vector<int> v;
//   v.resize(n);
//   for (int i = 0; i < n; i++)
//   {
//     cin >> v[i];
//   }

//   bool flag = true;
//   if (v[1] < v[2])
//   {
//     flag = false;
//   }
//   int prev = 0;
//   int next = prev + 1;
//   int count = 0;
//   while (next < n)
//   {

//     if (v[next] < v[prev] && flag == true)
//     {
//       count++;
//       flag = false;
//     }
//     if (v[next] > v[prev] && flag == false)
//     {
//       count++;
//       flag = false;
//     }

//     next++;
//     prev++;
//   }

//   return 0;
// }

// int main()
// {
//   string s1;
//   string s2;
//   getline(cin, s1);
//   getline(cin, s2);
//   string str;
//   for (auto &ch : s1)
//   {
//     if (s2.find(ch) == string::npos)
//     {
//       str += ch;
//     }
//   }
//   cout << str << endl;
//   return 0;
// }
// 64 位输出请用 printf("%lld")
// using namespace std;
// long long maxSum(vector<long long> &result)
// {
//   sort(result.begin(), result.end()); // 默认是升序
//   long long sum = 0;
//   for (int i = result.size() - 2; i > 0; i -= 2)
//   {
//     sum += result[i];
//   }
//   return sum;
// }

// int main()
// {
//   int n = 0;
//   cin >> n;
//   vector<long long> result;
//   result.resize(3 * n);
//   for (int i = 0; i < 3 * n; i++)
//   {
//     cin >> result[i];
//   }
//   sort(result.begin(), result.end()); // 默认是升序
//   long long sum = 0;
//   int j = result.size() - 2;
//    for (int i = 0; i < n; i++)
//   {
//     sum += result[j];
//     j-=2;
//   }
// for (int i = result.size() - 2; i >= 0; i -= 2)
// {
//   sum += result[i];
// }
//   cout << sum << endl;

//   // cout << maxSum(result) << endl;
//   return 0;
// }

// int main()
// {

//  // printf("%s , %5.3s\n", "computer", "computer");
//   //float f = 1.234f;
//   //printf("%5.2f\n", f);
//   //printf("%-5.2f\n", f);
//   //int a = 8;
//   //printf("%5.2d\n", a);
//   return 0;
// }
