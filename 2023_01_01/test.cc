#include <vector>
#include <algorithm>
using std::vector;
using std::max;
using std::min;
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
  return zuo(1,n);
}
// 目前锁定这个数字在[left, right]范围之间
// 
int zuo(int left, int right)
{
  // 终止条件
  if(left == right)
  return 0;
  if(left == right-1)
  {
    return left; //永远最倒霉,也就是一定会错,我们选小的
  }
  
  // 我们就猜left
  int p1 = left+zuo(left+1,right);
  int p2 = right+ zuo(left, right-1);
  // p1 p2 都可以找到确保可以找到,我们虽然最倒霉,但是还要想要最好的,所以选择较小的 
  int minGold = min(p1,p2);
  for(int i = left+1;i<right;i++)
  {
    int l = zuo(left, i-1);
    int r = zuo(i+1, right);
    int cur = i+max(l,r); // 永远最倒霉
    // 这为何要 要最小 
    minGold = min(cur, minGold);
  }
  return minGold;
}

