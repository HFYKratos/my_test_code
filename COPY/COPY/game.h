#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<Windows.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define NUM 10     //雷的个数

void setMine(char Mine[ROWS][COLS], int row, int col, int n);       //设置雷
void c_mine(char Mine[ROWS][COLS], int row, int col);              //初始化
void Print(char Mine[ROWS][COLS], int row, int col);               //打印
void c_show(char Mine[ROWS][COLS], int row, int col);              //初始化
int findMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col);      //找雷