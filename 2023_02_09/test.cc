/**
 * User: Qkj
 * Description:
 * Date: 2023-02-09
 * Time: 21:09
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class A
{
public:
  void foo()
  {
    printf("1");
  }
  virtual void fun()
  {
    printf("2");
  }
};

class B : public A
{
public:
  void foo()
  {
    printf("3");
  }
  void fun()
  {
    printf("4");
  }
};


int main(void)
{
  A a;
  B b;
  A *p = &a;
  p->foo();
  p->fun();
  p = &b;
  p->foo();
  p->fun();
  A *ptr = (A *)&b;
  ptr->foo();
  ptr->fun();
  return 0;
}

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution
// {
// public:
//   TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//   {
//     if (root == nullptr)
//       return nullptr;

//     if (root == p || root == q)
//       return root;

//     TreeNode *left = lowestCommonAncestor(root->left, p, q);
//     TreeNode *right = lowestCommonAncestor(root->right, p, q);

//     if (left != nullptr && right != nullptr)
//       return root;
//     if (left == nullptr)
//       return right;
//     if (right == nullptr)
//       return left;
//     return nullptr;
//   }
// };

// /*
// struct TreeNode {
//   int val;
//   struct TreeNode *left;
//   struct TreeNode *right;
//   TreeNode(int x) :
//       val(x), left(NULL), right(NULL) {
//   }
// };*/
// class Solution
// {
// public:
//   void ConvertChild(TreeNode *root, TreeNode *&prev)
//   {
//     if (root == nullptr)
//       return;
//     ConvertChild(root->left, prev);
//     root->left = prev;
//     if (prev != nullptr)
//     {
//       prev->right = root;
//     }
//     prev = root;

//     ConvertChild(root->right, prev);
//   }
//   TreeNode *Convert(TreeNode *pRootOfTree)
//   {
//     if (pRootOfTree == nullptr)
//     {
//       return nullptr;
//     }
//     TreeNode *prev = nullptr;
//     ConvertChild(pRootOfTree, prev);
//     TreeNode *head = pRootOfTree;
//     while (head->left != nullptr)
//     {
//       head = head->left;
//     }
//     return head;
//   }
// };
// class Solution
// {
// public:
//   vector<string> buildArray(vector<int> &target, int n)
//   {
//     vector<string> v;
//     string s1 = "Push";
//     string s2 = "Pop";
//     int begin = 0;
//     for (int i = 1; i <= n; i++)
//     {
//       if (begin >= target.size())
//         return v;

//       if (target[begin] == i)
//       {
//         begin++;
//         v.push_back(s1);
//       }
//       else
//       {
//         v.push_back(s1);
//         v.push_back(s2);
//       }
//     }
//     return v;
//   }
// };

// class Solution
// {
// public:
//   vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
//   {
//     vector<vector<int>> result;
//     if (m * n != original.size())
//       return result;
//     result.resize(m, vector<int>(n));
//     int row = 0;
//     int col = 0;
//     for (int i = 0; i < original.size(); i++)
//     {
//       result[row][col++] = original[i];
//       if (col == n)
//       {
//         col = 0;
//         row++;
//       }
//     }
//     return result;
//   }
// };
