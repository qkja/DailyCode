#define  _CRT_SECURE_NO_WARNINGS

#include "game.h"
// ��ʼ������
//void Init_board(char board[ROW][COL], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			board[i][j] = ' ';  // ��ʼ��Ϊ���ַ�
//		}
//	}
//}
//
//// ��ӡ����
//void Show_board(char board[ROW][COL], int row, int col)
//{
//
//
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			printf(" %c ", board[i][j]);
//			if (j < col - 1)
//				printf("|");
//		}
//
//		printf("\n");
//
//		if (i < row - 1)
//		{
//			for (int j = 0; j < col; j++)
//			{
//				printf("---");
//
//				if (j < col - 1)
//					printf("|");
//			}
//		}
//
//		printf("\n");
//
//	}
//}
//void PlayerMove(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	printf("�����>\n");
//	printf("������������� ��");
//
//	while (1)
//	{
//		scanf("%d %d", &x, &y);
//		if (x >= 1 && x <= row && y >= 1 && y <= col)//�жϺϷ����Ϸ�
//		{
//			if (board[x - 1][y - 1] == ' ')//�ǿ��ַ��ſ��Խ���*���Ž�ȥ
//			{
//				board[x - 1][y - 1] = '*';
//				break;
//			}
//			else
//			{
//				printf("�����걻ռ�ã����������룡\n");
//				printf("������������� ��");
//			}
//		}
//		else
//		{
//			printf("����Ƿ�����������!\n");
//			printf("������������� ��");
//		}
//	}
//
//
//}
//
//int Is_full(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			if (board[i][j] == ' ')
//				return 0;
//		}
//	}
//	return 1;
//}
//
//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	printf("������>\n");
//	int x = 0;
//	int y = 0;
//	while (1)
//	{
//		x = rand() % ROW;  //0 ~ ROW-1
//		y = rand() % COL;  //0 ~ COL-1
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = '#';
//			break;
//		}
//	}
//}
//
//char Is_win(char board[ROW][COL], int row, int col)
//{
//
//	int i = 0;
//	int j = 0;
//	//�ж� ��
//	for (i = 0; i < row; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
//			return  board[i][0];
//
//	}
//	//�ж���
//	for (j = 0; j < col; j++)
//	{
//		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
//			return  board[0][0];
//	}
//	//�ж϶Խ���
//	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
//	{
//		return  board[0][0];
//	}
//
//	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
//	{
//		return  board[1][1];
//	}
//
//	//�ж�����û��  ���� 1  δ�� 0
//	if (0 == Is_full(board, row, col))
//	{
//		return 'C';
//	}
//	return 'Q';
//
//}

void Init_board(char board[ROWS][COLS], int rows, int cols, char ch)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = ch;
		}
	}
}

void Display(char board[ROWS][COLS], int row, int col)
{
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}

		printf("\n");
	}

}

void Setmine(char board[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	int count = 0;


	while (count < MINE)
	{

		x = rand() % ROW + 1;
		y = rand() % COL + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count++;
		}
	}


}

int Findmine(char boardmine[ROWS][COLS], int x, int y)
{
	return  boardmine[x - 1][y] + boardmine[x + 1][y] + boardmine[x - 1][y - 1] + boardmine[x - 1][y + 1] +
		boardmine[x][y - 1] + boardmine[x][y + 1] + boardmine[x + 1][y - 1] + boardmine[x + 1][y + 1] - 8 * '0';
}

void Searchmine(char boardmine[ROWS][COLS], char boardshow[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;

	while (count < ROW*COL - MINE)
	{
		printf("������������꣺");
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y < col)
		{
			if (boardmine[x][y] == '1')
			{
				printf("���ź��㱻ը����\n");
				break;

			}
			else
			{
				int ret = Findmine(boardmine, x, y);
				boardshow[x][y] = ret + '0';
				Display(boardshow, ROW, COL);
				count++;
			}

		}
		else
		{
			printf("�����������,����������\n");
		}
	}//endofwhile

	if (count == ROW * COL - MINE)
	{
		printf("��Ӯ��!!!\n");
	}
}
