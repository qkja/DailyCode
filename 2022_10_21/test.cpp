#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;



// 矩阵置零
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//      if(matrix.empty())
//        return;
//      int row = matrix.size(); // 行
//      int col = matrix[0].size(); //列
//
//      // 记录所有为 0 的下标
//      unordered_multimap<int, int> unMap;
//
//      for(int i = 0; i < row; i++)
//      {
//        for(int j = 0; j < col; j++)
//        {
//          if(matrix[i][j] == 0)
//            unMap.insert(make_pair(i,j));
//        }
//
//      }
//
//      for(const pair<int, int>& p : unMap)
//      {
//        // 修理行
//        for(int i = 0; i < col; i++)
//        {
//          matrix[p.first][i] = 0;
//        }
//        // 修理列
//        for(int i = 0; i < row; i++)
//        {
//          matrix[i][p.second] = 0;
//        }
//      }
//    }
//};

// 有效的数独
//class Solution {
//public:
//    bool isValidSudoku(vector<vector<char>>& board) {
//      if(board.empty())
//        return false;
//
//      size_t row = board.size();   // 行
//      size_t col = board[0].size();// 列
//      //  判断 行
//      unordered_set<int> setCol;
//      for(size_t i = 0; i < row; i++)
//      {
//        int count = 0;
//        for(size_t j = 0; j < col; j++)
//        {
//          if(board[i][j] > '0' && board[i][j] <= '9')
//          {
//            count++;
//            setCol.insert(board[i][j] - '0');
//          }
//          else if(board[i][j] == '.')
//          {
//            // 什么都不做
//          }
//          else 
//          {
//            return false;
//          }
//        }
//
//        // 这里判断
//        if((int)setCol.size() != count)
//          return false;
//        setCol.clear();
//      }
//
//      // 判断 列 
//      unordered_set<int> setRow;
//      for(size_t i = 0; i < col; i++)
//      {
//
//        int count = 0;
//        for(size_t j = 0; j < row; j++)
//        {
//          if(board[j][i] > '0' && board[j][i] <= '9')
//          {
//            count++;
//            setRow.insert(board[j][i] - '0');
//          }
//          else if(board[j][i] == '.')
//          {
//            // 什么都不做
//          }
//          else 
//          {
//            return false;
//          }
//        }
//        if((int)setRow.size() != count)
//          return false;
//        setRow.clear();
//      }
//
//      // 判断九个区域
//      unordered_set<int> setArea;
//      for(size_t i = 0; i < col; i+=3)
//      {
//        for(size_t j = 0; j < row; j+=3)
//        {
//          // 这里开始判断区域
//          int count = 0;
//          for(size_t x = i; x < i+3; x++)
//          {
//            for(size_t y = j; y < j+3; y++)
//            {
//              // 记录
//              if(board[x][y] > '0' && board[x][y] <= '9')
//              {
//                count++;
//                setArea.insert(board[x][y] - '0');
//              }
//              else if(board[x][y] == '.')
//              {
//                // 什么都不做
//              }
//              else 
//              {
//                return false;
//              }
//            }
//          }
//          if((int)setArea.size() != count)
//            return false;
//          setArea.clear();
//        }
//      }
//      return true;
//    }
//};

// 242 有效的字母异或词
//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//      if(s.empty() && t.empty())
//        return true;
//      if(s.size() != t.size())
//        return false;
//      map<char, int> m;
//      for(char ch : t)
//        m[ch]++;
//      for(size_t i = 0; i < s.size(); i++)
//      {
//        auto it = m.find(s[i]);
//        if(it == m.end())
//          return false;
//        it->second--;
//        if(it->second == -1)
//          return false;
//      }
//      return true;
//    }
//    // 不对
//    // aa  
//    // bb
//    // 也可以
//    //bool isAnagram(string s, string t) {
//    //  if(s.empty() && t.empty())
//    //    return true;
//    //  if(s.size() != t.size())
//    //    return false;
//    //  int ret = 0;
//    //  for(size_t i = 0; i < s.size(); i++)
//    //  {
//    //    ret ^= s[i];
//    //    ret ^= t[i];
//    //  }
//    //  return ret == 0;
//    //}
//};
//
//
//
//
//
// 383 赎金信
//class Solution {
//public:
//    bool canConstruct(string ransomNote, string magazine) {
//      if(ransomNote.empty() && magazine.empty())
//        return true;
//      if(ransomNote.empty())
//        return true;
//      if(magazine.empty())
//        return false;
//
//
//      map<char,int> m;
//      for(char ch : magazine)
//        m[ch]++;
//      for(size_t i = 0;i < ransomNote.size(); i++)
//      {
//        auto it = m.find(ransomNote[i]);
//        if(it == m.end())
//          return false;
//
//        //这里找到了
//        it->second--;
//        if(it->second == -1)
//          return false;
//      }
//      return true;
//    }
//};

// 用 队列实现栈
//class MyStack {
//public:
//    MyStack() {
//      // 不用写
//    }
//    
//    void push(int x) {
//      // 入队列
//      pushQueue.push(x);
//    }
//    
//    int pop() {
//      if(pushQueue.empty())
//        return -1;
//
//      while(pushQueue.size() != 1)
//      {
//        // 入到pop中
//        popQueue.push(pushQueue.front());
//        pushQueue.pop();
//      }
//
//      int ret = pushQueue.front();
//      pushQueue.pop();
//      // 这里再给我回去
//      while(!popQueue.empty())
//      {
//        // 入到pop中
//        pushQueue.push(popQueue.front());
//        popQueue.pop();
//      }
//      return ret;
//
//    }
//    
//    int top() {
//      if(pushQueue.empty())
//        return -1;
//
//      int ret = 0;
//      while(!pushQueue.empty())
//      {
//        // 入到pop中
//        ret = pushQueue.front();
//        popQueue.push(ret);
//        pushQueue.pop();
//      }
//
//      // 这里再给我回去
//      while(!popQueue.empty())
//      {
//        // 入到pop中
//        pushQueue.push(popQueue.front());
//        popQueue.pop();
//      }
//      return ret;
//    }
//    
//    bool empty() {
//      return pushQueue.empty();
//    }
//private:
//    queue<int> pushQueue; // 所有元素入到这个
//    queue<int> popQueue;
//};




int main()
{

  return 0;
}

