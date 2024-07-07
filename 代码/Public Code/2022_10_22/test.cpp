#include <stack>
#include <assert.h>
#include <vector>
using namespace std;


// 重塑矩阵
//class Solution {
//public:
//    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
//      if(mat.empty() || r == 0 || c == 0 || (size_t)(r * c) != mat.size()*mat[0].size())
//        return mat;
//      vector<vector<int>> vv;
//      vv.resize(r);
//      for(int i = 0; i < r; i++)
//      {
//        vector<int> v(c);
//        vv[i] = v;
//      }
//
//
//      // 这里开始了
//      int row = 0;
//      int col = 0;
//
//      for(size_t i = 0; i < mat.size(); i++)
//      {
//        for(size_t j = 0; j < mat[i].size(); j++)
//        {
//          if(col == c)
//          {
//            row++;
//            col = 0;
//          }
//          vv[row][col++] = mat[i][j];
//        }
//      }
//
//      return vv;
//    }
//};


// 设计 循环队列
// 这里我们需要学习一下
//class MyCircularQueue {
//public:
//    MyCircularQueue(int k)
//    {
//      _v.resize(k+1);
//      _front = 0;
//      _tail = 0;
//      _cap = k+1;
//    }
//    
//    bool enQueue(int value) {
//      if(isFull())
//        return false;
//      _v[_tail] = value;
//      // 更新tail
//      if(_tail == _cap - 1)
//        _tail = 0;
//      else 
//        _tail++;
//      return true;
//    }
//    
//    bool deQueue() {
//      if(isEmpty())
//        return false;
//
//      //更新front
//      
//      if(_front == _cap - 1)
//        _front = 0;
//      else 
//        _front++;
//      return true;
//    }
//    
//    int Front() {
//
//      if(isEmpty())
//        return -1;
//      return _v[_front];
//    }
//    
//    int Rear() {
//
//      if(isEmpty())
//        return -1;
//      if(_tail == 0)
//        return _v[_cap-1];
//      return _v[_tail-1];
//    }
//    
//    bool isEmpty() {
//      return _front == _tail;
//    }
//    
//    bool isFull() {
//      size_t ret = _tail;
//
//      if(_tail == _cap-1)
//        ret = -1;
//      return (ret+1) == _front;
//    }
//private:
//    vector<int> _v;
//    size_t _tail;
//    size_t _front;
//    size_t _cap;
//};


// 用栈实现队列
//class MyQueue {
//public:
//    MyQueue() {
//
//    }
//    
//    void push(int x) {
//      // 入到 push中
//      pushStack.push(x);
//    }
//    
//    int pop() {
//      assert(!empty());
//      if(popStack.empty())
//      {
//        // 为空 吧 push导入 pop中
//        while(!pushStack.empty())
//        {
//          popStack.push(pushStack.top());
//          pushStack.pop();
//        }
//      }
//      int ret = popStack.top();
//      popStack.pop();
//      return ret;
//    }
//    
//    int peek() {
//      assert(!empty());
//      if(popStack.empty())
//      {
//        // 为空 吧 push导入 pop中
//        while(!pushStack.empty())
//        {
//          popStack.push(pushStack.top());
//          pushStack.pop();
//        }
//      }
//      return  popStack.top();
//    }
//    
//    bool empty() {
//      return popStack.empty() 
//        && pushStack.empty();
//    }
//private:
//    stack<int> popStack;
//    stack<int> pushStack;
//};

