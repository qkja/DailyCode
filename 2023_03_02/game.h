//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//#define ROW 3       
//#define COL 3
//
////初始化棋盘
//extern void Init_board(char board[ROW][COL], int row, int col);
//
////打印棋盘
//extern void Show_board(char board[ROW][COL], int row, int col);
//
////玩家走
//extern void PlayerMove(char board[ROW][COL], int row, int col);
//
////电脑走
//extern void ComputerMove(char board[ROW][COL], int row, int col);
//
////判断输赢
//extern char Is_win(char board[ROW][COL], int row, int col);


#pragma once

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define MINE 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//初始化棋盘
extern void Init_board(char board[ROWS][COLS], int rows, int cols, char ch);

//打印棋盘
extern void Display(char board[ROWS][COLS], int row, int col);


//设置雷
extern void Setmine(char board[ROWS][COLS]);

//排查雷
extern void Searchmine(char boardmine[ROWS][COLS], char boardshow[ROWS][COLS], int row, int col);