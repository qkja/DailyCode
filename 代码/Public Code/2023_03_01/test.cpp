#include <iostream>
#include <vector>

using namespace std;

//int main() 
//{
//	int w = 0; // 列号
//	int h = 0; // 行号
//
//	cin >> w >> h;
//	// 我们设计棋牌
//	vector<vector<int>> board(w, vector<int>(h, 1));
//
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < board[i].size(); j++)
//		{
//			// 判断 当前 节点 上下左右的 是不是应该存在循环
//			if (i == 0 && board[i][j] == 1)
//			{
//				if (i + 2 < h)
//				{
//					board[i + 2][j] = 0;
//				}
//			}
//			else if (i == h - 1 && board[i][j]==1)
//			{
//				if (i - 2 >= 0)
//				{
//					board[i - 2][j] = 0;
//				}
//			}
//			else
//			{
//				if (j == 0&&board[i][j] == 1)
//				{
//					if (j + 2 < w)
//					{
//						board[i][j + 2] = 0;
//					}
//					if ()
//				}
//				else if (j == w - 1 && board[i][j] == 1)
//				{
//
//				}
//				else
//				{
//
//				}
//			}
//		}
//	}
//	return 0;
//}
// 64 位输出请用 printf("%lld")

//int main()
//{
//	int w = 0; // 列号
//	int h = 0; // 行号
//
//	cin >> w >> h;
//	// 我们设计棋牌
//	vector<vector<int>> board(h, vector<int>(w, 1));
//
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < board[i].size(); j++)
//		{
//			int higth = i - 2;
//			int low = i + 2;
//			int left = j - 2;
//			int right = j + 2;
//			if (board[i][j] == 1 && higth >= 0 && left >= 0)
//			{
//				board[higth][left] = 0;
//			}
//			if (board[i][j] == 1 && higth >= 0 && right < w)
//			{
//				board[higth][right] = 0;
//			}
//
//			if (board[i][j] == 1 && low <h && left >= 0)
//			{
//				board[low][left] = 0;
//			}
//			if (board[i][j] == 1 && low <h && right < w)
//			{
//				board[low][right] = 0;
//			}
//
//			// 这里有 本行
//
//		}
//	}
//	int sum = 0;
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < board[i].size(); j++)
//		{
//			sum += board[i][j];
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}

//int main()
//{
//	int w = 0; // 列号
//	int h = 0; // 行号
//
//	cin >> w >> h;
//	// 我们设计棋牌
//	vector<vector<int>> board(h, vector<int>(w, 1));
//
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < board[i].size(); j++)
//		{
//			int higth = i - 2;
//			int low = i + 2;
//			if (board[i][j] == 1 && higth >= 0)
//			{
//				board[higth][j] = 0;
//			}
//
//			if (board[i][j] == 1 && low <h)
//			{
//				board[low][j] = 0;
//			}
//
//			int left = j - 2;
//			int right = j + 2;
//
//			if (board[i][j] == 1 && left >=0)
//			{
//				board[i][left] = 0;
//			}
//
//			if (board[i][j] == 1 && right < w)
//			{
//				board[i][right] = 0;
//			}
//		}
//	}
//	int sum = 0;
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < board[i].size(); j++)
//		{
//			sum += board[i][j];
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}
//
//int main()
//{
//	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//
//	// 
//	printf("%s", str);
//	return 0;
//}

//void main(){
//	int n[][3] = { 10, 20, 30, 40, 50, 60 };
//	int(*p)[3];
//	p = n;
//	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
//}
//
//#include <iostream>
//using namespace std;
//char fun(char x, char y) {
//	if (x < y)
//		return x;
//	return y;
//}
//int main() {
//	int a = '1', b = '1', c = '2';
//	cout << fun(fun(a, b), fun(b, c));
//	return 0;
//}

//struct One{
//	double d;
//	char c;
//	int i;
//};
//struct Two{
//	char c;
//	double d;
//	int i;
//};

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d", a, b);//只打印 a
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 0
//
//#include <stdio.h>
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	printf("a = %d b = %d b = %d\n", a, b, c);
//	return 0;
//}
