#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<Windows.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define NUM 10     //�׵ĸ���

void setMine(char Mine[ROWS][COLS], int row, int col, int n);       //������
void c_mine(char Mine[ROWS][COLS], int row, int col);              //��ʼ��
void Print(char Mine[ROWS][COLS], int row, int col);               //��ӡ
void c_show(char Mine[ROWS][COLS], int row, int col);              //��ʼ��
int findMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col);      //����