#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//class Solution
//{
//public:
//    vector<vector<int>> arr = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 上下左右
//
//    void Dfs(vector<vector<char>>& image, int row, int col,
//        vector<vector<bool>>& book, int x, int y,
//        char newColor, char oldColor)
//    {
//        image[x][y] = newColor;
//        book[x][y] = false;
//
//        for (size_t i = 0; i < 4; i++)
//        {
//            // 四个位置
//            int newX = x + arr[i][0];
//            int newY = y + arr[i][1];
//
//            if (!(newX >= 0 && newX < row && newY >= 0 && newY < col))
//                continue;
//            if (image[newX][newY] == oldColor && book[newX][newY] == true)
//            {
//                Dfs(image, row, col, book, newX, newY, newColor, oldColor);
//            }
//        }
//    }
//    void solve(vector<vector<char>>& board)
//    {
//        if (board.empty())
//            return;
//        std::unordered_map<int, std::pair<int, int>> s;
//        int row = board.size();
//        int col = board[0].size();
//        int index = 0;
//        for (int i = 0; i < col; i++)
//        {
//            if (board[0][i] == 'O')
//                s[index++] = std::make_pair(0, i);
//            if (board[row - 1][i] == 'O')
//                s[index++] = std::make_pair(row - 1, i);
//        }
//
//        for (int i = 1; i < row - 1; i++)
//        {
//            if (board[i][0] == 'O')
//                s[index++] = std::make_pair(i, 0);
//            if (board[i][col - 1] == 'O')
//                s[index++] = std::make_pair(i, col - 1);
//        }
//
//        vector<vector<bool>> book(row, vector<bool>(col, true));
//        auto it = s.begin();
//        while (it != s.end())
//        {
//            if (board[it->second.first][it->second.second] == 'O')
//                Dfs(board, row, col, book, it->second.first, it->second.second, 'A', 'O');
//            it++;
//        }
//
//        for (int i = 0; i < row; i++)
//        {
//            for (size_t j = 0; j < col; j++)
//            {
//                if (board[i][j] == 'A')
//                    board[i][j] = 'O';
//                else
//                    board[i][j] = 'X';
//            }
//        }
//    }
//};
//
//
//int main()
//{
//    vector<vector<char>> v = { 
//        {'X', 'O', 'X', 'O', 'X', 'O'},
//        {'O', 'X', 'O', 'X', 'O', 'X'},
//        {'X', 'O', 'X', 'O', 'X', 'O'},
//        {'O', 'X', 'O', 'X', 'O', 'X'} };
//    Solution().solve(v);
//    return 0;
//}



//class A
//{
//public:
//	void func()const
//	{
//		std::cout << 'a: ' << a << std::endl;
//		std::cout << 'b: ' << b << std::endl;
//		
//		a = 20;
//	/*	A* p = const_cast<A*>(this);
//		p->a = 20;
//		p->b = 20;
//*/
//		std::cout << 'a: ' << a << std::endl;
//		std::cout << 'b: ' << b << std::endl;
//	}
//private:
//	mutable int a = 10;
//	int b = 10;
//};
//
//int main()
//{
//	A().func();
//	return 0;
//}