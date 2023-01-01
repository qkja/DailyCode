#include <vector>
using std::vector;
// 给定一个多叉树,该多叉树黑色节点所在路径都进行保留
// 放回新的多叉树的节点
/// @brief 由于是多叉树,我不知道如何表示
struct Node
{
  bool retain; // 是否保留
  vector<Node*> nexts; // 子节点的地址
  int val; // 当前节点的值
  Node(int v,bool r)
  {
    val = v;
    retain = r;
  }
};

Node* retain(Node* head)
{
  if(head->nexts.empty())
  {
    return head->retain?head:nullptr;
  }
  //head下层有节点 我们便利所有的节点
  vector<Node*> v;
  for(Node* p:head->nexts)
  {
    Node* newNext = retain(p);
    if(newNext != nullptr)
    {
      v.push_back(newNext);
    }
  }

  // newNext 是新的链表  nexts是老的链表
  if(!v.empty() || head->retain)
  {
    head->nexts = v;
    return head;
  }
  return nullptr;
}



// 猜数字游戏   笔试整理 第二题
// 正确数字就是1-n之间
// 每次猜错 就是钱数
// 
int minGold(int n)
{
  
}

