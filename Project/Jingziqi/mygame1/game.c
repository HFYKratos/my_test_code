#include "game.h"

void board(char A[H][L],int h,int l)
{
	int i, j;
	for (i = 0; i < h ; i++)
	{
		for (j = 0; j < l; j++)
		{
			printf("|%c ", A[i][j]); 
			
		}
		printf("\n");
		for (j = 0; j < l; j++)
		{
			printf(" —");
		}
		printf("\n");
	}
}

void playermove(char A[H][L], int h, int l)
{
	int x, y, input = 1;
	printf("请输入您的坐标：（示例：1.2——>第一行第二列）");
	while (input)
	{
		scanf("%d.%d", &x, &y);
		if (A[x - 1][y - 1] == '\0')
		{
			A[x - 1][y - 1] = '*';
			input = 0;
		}
		else
		{
			printf("已被占用，重新输入！");
		}
	}
	
}

void commove(char A[H][L])
{
	int x = 0;
	int y = 0;
	while (A[x][y] != '\0')
	{
		x = rand() % H;
		y = rand() % L;
	}
	A[x][y] = '+';
}

char WOL(char A[H][L], int h, int l)
{
	int i, j;
	if (A[0][0] != 0 && A[0][0] == A[1][1] && A[1][1] == A[2][2])
	{
		if (A[0][0] == '*')
		{
			return '*';
		}
		else if(A[0][0] == '+')
		{
			return '+';
		}
	}
	if (A[0][2] != 0 && A[0][2] == A[1][1] && A[1][1] == A[2][0])
	{
		if (A[1][1] == '*')
		{
			return '*';
		}
		else if (A[1][1] == '+')
		{
			return '+';
		}
	}
	for ( i = 0; i < h; i++)
	{
		if (A[i][0] != 0 && A[i][0] == A[i][1] && A[i][0] == A[i][2])
		{
			if (A[i][0] == '*')
			{
				return '*';
			}
			else if (A[i][0] == '+')
			{
				return '+';
			}
		}
		if (A[0][i] != 0 && A[0][i] == A[1][i] && A[0][i] == A[2][i])
		{
			if (A[0][i] == '*')
			{
				return '*';
			}
			else if (A[0][i] == '+')
			{
				return '+';
			}
		}
	}
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < l; j++)
		{
			if (A[i][j] == 0)
			{
				return 'C';
			}
		}
	}
	return 'Q';
}