#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include"game.h"

//void menu()
//{
//	printf("********************\n");
//	printf("*****  1.paly  *****\n");
//	printf("*****  0.exit  *****\n");
//	printf("********************\n");
//}
//
//void PlayGame(void)
//{
//	char ret = 0;
//	char board[ROW][COL] = { 0 };
//
//	Init_board(board, ROW, COL);
//
//	Show_board(board, ROW, COL);
//
//	while (1)
//	{
//		//printf("玩家走>\n");
//		PlayerMove(board, ROW, COL);
//
//		Show_board(board, ROW, COL);
//		ret = Is_win(board, ROW, COL);
//		//玩家 *
//		//电脑 #
//		//平局 Q
//		//继续 C
//		if (ret != 'C')
//		{
//			break;
//		}
//
//		// printf("电脑走>\n");
//		ComputerMove(board, ROW, COL);
//
//		Show_board(board, ROW, COL);
//		ret = Is_win(board, ROW, COL);
//
//		if (ret != 'C')
//		{
//			break;
//		}
//	}
//	if (ret == '*')
//	{
//		printf("玩家赢\n");
//	}
//	else if (ret == '#')
//	{
//		printf("电脑赢\n");
//	}
//	else
//	{
//		printf("平局\n");
//	}
//
//}
//
//void test(void)
//{
//	srand((unsigned int)time(NULL));//后面会说
//
//	int input = 0;
//	do
//	{
//
//		menu();           //目录函数
//		printf("请选择：>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("下棋\n");
//			PlayGame();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//	} while (input);
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//void menu()
//{
//	printf("***********************\n");
//	printf("*****   0.exit    *****\n");
//	printf("*****   1.play    *****\n");
//	printf("***********************\n");
//}
//
//void game()
//{
//	char mine[ROWS][COLS];      //雷盘
//	char show[ROWS][COLS];      //打印棋盘
//	// 初始化棋盘
//	Init_board(mine, ROWS, COLS, '0');
//	Init_board(show, ROWS, COLS, '*');
//
//	//打印棋盘
//	/*Display(mine, ROW, COL);
//	Display(show, ROW, COL);*/
//
//	//设置雷
//	Setmine(mine);
//	//Display(mine, ROW, COL);
//	Display(show, ROW, COL);
//
//	//排查雷
//	Searchmine(mine, show, ROW, COL);
//
//}
//
//void test()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//
//		menu();
//		printf("请输入：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("已退出\n");
//			break;
//		case 1:
//			game();
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//
//		}
//	} while (input);
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//int main()
//{
//	int arr[] = { 5, 7, 1, 4, 9, 2, 10, 3, 8, 6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < sz - 1; i++)
//	{
//		if (arr[i] > arr[i + 1])
//		{
//			// 交换
//			int ret = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = ret;
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int arr[] = { 5, 7, 1, 4, 9, 2, 10, 3, 8, 6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	
//	// sz -1 是因为 n和元素只需要 n-1躺
//	for (int i = 0; i < sz - 1; i++)
//	{
//		// sz-1 是为了j+1 不越界 
//		// -i 是对每一趟都要少一个元素
//		for (int j = 0; j<sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				// 交换
//				int ret = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = ret;
//			}
//		}
//	}
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[] = { 10,1,2,3,4,5,7,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int flag = 0;
//	// sz -1 是因为 n和元素只需要 n-1躺
//	for (int i = 0; i < sz - 1; i++)
//	{
//		flag = 0;
//
//		for (int j = 0; j<sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				// 交换
//				int ret = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = ret;
//				flag = 1; // 此时交换才会修改标记位
//			}
//		}
//		if (0 == flag)
//		{
//			printf("提前有序了\n");
//			break;
//		}
//		
//	}
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

// 计算BinarySearch的时间复杂度？
//int BinarySearch(int* a, int n, int x)
//{
//	int begin = 0;
//	int end = n; //  注意  边界
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int x = 6;
//	int ret = BinarySearch(arr, sz, x);
//	if (ret != -1)
//	{
//		printf("找到了,下标是 %d\n", ret);
//	}
//	return 0;
//}

int searchInsert(int* nums, int numsSize, int target)
{
	int begin = 0;
	int end = numsSize;
	while (begin <end)
	{
		int mid = (begin + end) / 2;
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid] > target)
		{
			end = mid;
		}
		else
		{
			begin = mid + 1;
		}
	}
	return begin;
}