/**
 * User: Qkj
 * Description:
 * Date: 2023-02-22
 * Time: 22:58
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    // 水平翻转
    for (int i = 0; i < n / 2; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        swap(matrix[i][j], matrix[n - i - 1][j]);
      }
    }
    // 主对角线翻转
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};

// class Solution
// {
// public:
//   vector<string> commonChars(vector<string> &words)
//   {
//     vector<string> result;
//     int size = words.size();

//     // 开辟  size 个数组空间
//     vector<vector<int>> vv(size, vector<int>(52, 0));
//     int i = 0;
//     for (auto &val : words)
//     {
//       for (char ch : val)
//       {
//         if (ch >= 'a' && ch <= 'z')
//         {
//           vv[i][ch - 'a']++;
//         }
//         else if (ch >= 'A' && ch <= 'Z')
//         {
//           vv[i][ch - 'A' + 26]++;
//         }
//       }
//       i++;
//     }

//     // 开始遍历数组每一个列的元素,首先判断  这个每一列都要有元素
//     for (int col = 0; col < 52; col++)
//     {
//       int row = 0;
//       int min = vv[0][col];
//       for (row = 0; row < i; row++)
//       {
//         if (vv[row][col] == 0)
//         {
//           break;
//         }
//         else
//         {
//           if (vv[row][col] < min)
//           {
//             min = vv[row][col];
//           }
//         }
//       }
//       if (row == i)
//       {
//         // 此时 一定可以拿到相同的元素
//         string str;
//         if (col >=0 &&col<26)
//         {
//           // 小写
//           str += ('a'+col);
//         }
//         else
//         {
//           //大写
//           str += ('A' + col-26);
//         }
//         for(int k =0;k<min;k++)
//         {
//           result.insert(result.end(), str);
//         }
//       }
//     }
//     // 拿到结果
//     return result;
//   }
// };