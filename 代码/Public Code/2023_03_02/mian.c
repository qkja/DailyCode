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
//		//printf("�����>\n");
//		PlayerMove(board, ROW, COL);
//
//		Show_board(board, ROW, COL);
//		ret = Is_win(board, ROW, COL);
//		//��� *
//		//���� #
//		//ƽ�� Q
//		//���� C
//		if (ret != 'C')
//		{
//			break;
//		}
//
//		// printf("������>\n");
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
//		printf("���Ӯ\n");
//	}
//	else if (ret == '#')
//	{
//		printf("����Ӯ\n");
//	}
//	else
//	{
//		printf("ƽ��\n");
//	}
//
//}
//
//void test(void)
//{
//	srand((unsigned int)time(NULL));//�����˵
//
//	int input = 0;
//	do
//	{
//
//		menu();           //Ŀ¼����
//		printf("��ѡ��>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("����\n");
//			PlayGame();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
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
//	char mine[ROWS][COLS];      //����
//	char show[ROWS][COLS];      //��ӡ����
//	// ��ʼ������
//	Init_board(mine, ROWS, COLS, '0');
//	Init_board(show, ROWS, COLS, '*');
//
//	//��ӡ����
//	/*Display(mine, ROW, COL);
//	Display(show, ROW, COL);*/
//
//	//������
//	Setmine(mine);
//	//Display(mine, ROW, COL);
//	Display(show, ROW, COL);
//
//	//�Ų���
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
//		printf("�����룺");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("���˳�\n");
//			break;
//		case 1:
//			game();
//			break;
//		default:
//			printf("ѡ�����\n");
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
//			// ����
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
//	// sz -1 ����Ϊ n��Ԫ��ֻ��Ҫ n-1��
//	for (int i = 0; i < sz - 1; i++)
//	{
//		// sz-1 ��Ϊ��j+1 ��Խ�� 
//		// -i �Ƕ�ÿһ�˶�Ҫ��һ��Ԫ��
//		for (int j = 0; j<sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				// ����
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
//	// sz -1 ����Ϊ n��Ԫ��ֻ��Ҫ n-1��
//	for (int i = 0; i < sz - 1; i++)
//	{
//		flag = 0;
//
//		for (int j = 0; j<sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				// ����
//				int ret = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = ret;
//				flag = 1; // ��ʱ�����Ż��޸ı��λ
//			}
//		}
//		if (0 == flag)
//		{
//			printf("��ǰ������\n");
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

// ����BinarySearch��ʱ�临�Ӷȣ�
//int BinarySearch(int* a, int n, int x)
//{
//	int begin = 0;
//	int end = n; //  ע��  �߽�
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
//		printf("�ҵ���,�±��� %d\n", ret);
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