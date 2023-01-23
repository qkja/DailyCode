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

int main()
{
  string s1;
  string s2;
  getline(cin, s1);
  getline(cin, s2);
  string str;
  for(auto& ch:s1)
  {
    if(s2.find(ch) == string::npos)
    {
      str+=ch;
    }
  }
  cout << str<<endl;
  return 0;
}
// 64 位输出请用 printf("%lld")
using namespace std;
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

int main()
{
  int n = 0;
  cin >> n;
  vector<long long> result;
  result.resize(3 * n);
  for (int i = 0; i < 3 * n; i++)
  {
    cin >> result[i];
  }
  sort(result.begin(), result.end()); // 默认是升序
  long long sum = 0;
  int j = result.size() - 2;
   for (int i = 0; i < n; i++)
  {
    sum += result[j];
    j-=2;
  }
  // for (int i = result.size() - 2; i >= 0; i -= 2)
  // {
  //   sum += result[i];
  // }
  cout << sum << endl;

  // cout << maxSum(result) << endl;
  return 0;
}

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
