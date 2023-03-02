#define  _CRT_SECURE_NO_WARNINGS

#include"game.h"

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

void menu()
{
	printf("***********************\n");
	printf("*****   0.exit    *****\n");
	printf("*****   1.play    *****\n");
	printf("***********************\n");
}

void game()
{
	char mine[ROWS][COLS];      //雷盘
	char show[ROWS][COLS];      //打印棋盘
	// 初始化棋盘
	Init_board(mine, ROWS, COLS, '0');
	Init_board(show, ROWS, COLS, '*');

	//打印棋盘
	/*Display(mine, ROW, COL);
	Display(show, ROW, COL);*/

	//设置雷
	Setmine(mine);
	//Display(mine, ROW, COL);
	Display(show, ROW, COL);

	//排查雷
	Searchmine(mine, show, ROW, COL);

}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{

		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("已退出\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("选择错误\n");
			break;

		}
	} while (input);
}

int main()
{
	test();
	return 0;
}