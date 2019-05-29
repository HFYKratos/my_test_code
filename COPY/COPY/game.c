#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void c_mine(char Mine[ROWS][COLS], int row, int col)            //初始化
{
	memset(Mine, '0', row*col * sizeof(Mine[0][0]));
}
void c_show(char Mine[ROWS][COLS], int row, int col)
{
	memset(Mine, '*', row*col * sizeof(Mine[0][0]));
}
void Print(char Mine[ROWS][COLS], int row, int col)           //打印雷区
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (j == 1)
				printf("%d %c", i, Mine[i][j]);
			else
				printf(" %c", Mine[i][j]);
		}
		printf("\n");
	}
}
static void moveMine(char Mine[ROWS][COLS], int x, int y)      //移动第一次踩到的雷
{
	int a = 0;
	int b = 0;
	while (1)
	{
		a = rand() % ROW + 1;
		b = rand() % COL + 1;
		if (Mine[a][b] != '1')
		{
			Mine[a][b] = '1';
			break;
		}
	}
	Mine[x][y] = '0';
}
void setMine(char Mine[ROWS][COLS], int row, int col, int n)       //随机放置雷
{
	int x = 0;
	int y = 0;
	while (n)
	{

		x = rand() % row + 1;
		y = rand() % col + 1;
		if (Mine[x][y] == '0')
		{
			Mine[x][y] = '1';
			n--;
		}
	}
}
static int mineCount(char Mine[ROWS][COLS], int x, int y)             //统计雷数
{
	int add = 0;
	add = Mine[x - 1][y - 1]
		+ Mine[x][y - 1]
		+ Mine[x + 1][y - 1]
		+ Mine[x + 1][y]
		+ Mine[x + 1][y + 1]
		+ Mine[x][y + 1]
		+ Mine[x - 1][y + 1]
		+ Mine[x - 1][y]
		- 8 * '0';

	return add;
}
static int opeanMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int x, int y)           //用递归实现展开未知区域
{
	if (mineCount(Mine, x, y) == 0)
	{
		Show[x][y] = '0';
		if ((x - 1) >= 1 && (x - 1) <= ROW && (y - 1) >= 1 && (y - 1) <= COL && Show[x - 1][y - 1] == '*')
			opeanMine(Mine, Show, x - 1, y - 1);
		if ((x) >= 1 && (x) <= ROW && (y - 1) >= 1 && (y - 1) <= COL && Show[x][y - 1] == '*')
			opeanMine(Mine, Show, x, y - 1);
		if ((x + 1) >= 1 && (x + 1) <= ROW && (y - 1) >= 1 && (y - 1) <= COL && Show[x + 1][y - 1] == '*')
			opeanMine(Mine, Show, x + 1, y - 1);
		if ((x + 1) >= 1 && (x + 1) <= ROW && (y) >= 1 && (y) <= COL && Show[x + 1][y] == '*')
			opeanMine(Mine, Show, x + 1, y);
		if ((x + 1) >= 1 && (x + 1) <= ROW && (y + 1) >= 1 && (y + 1) <= COL && Show[x + 1][y + 1] == '*')
			opeanMine(Mine, Show, x + 1, y + 1);
		if ((x) >= 1 && (x) <= ROW && (y - 1) >= 1 && (y - 1) <= COL && Show[x][y - 1] == '*')
			opeanMine(Mine, Show, x, y - 1);
		if ((x - 1) >= 1 && (x - 1) <= ROW && (y + 1) >= 1 && (y + 1) <= COL && Show[x - 1][y + 1] == '*')
			opeanMine(Mine, Show, x - 1, y + 1);
		if ((x - 1) >= 1 && (x - 1) <= ROW && (y) >= 1 && (y) <= COL && Show[x - 1][y] == '*')
			opeanMine(Mine, Show, x - 1, y);
	}
	else
	{
		Show[x][y] = mineCount(Mine, x, y) + '0';
	}
	return 0;
}
static int is_win(char Show[ROWS][COLS], int row, int col)        //判断赢
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (Show[i][j] == '*')
				count++;
		}
	}
	return count;
}
int findMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int flag = 1;           //创建标志，判断是否是第一步

	while (NUM != is_win(Show, row, col))      //获胜条件
	{
		//Print(Mine, ROW, COL);
		int count = 0;
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x < 1 || x > row || y < 1 || y > col)
		{
			printf("非法坐标，");
		}
		else if (Show[x][y] != '*')
		{
			printf("该坐标已被打开，");
		}
		else if (Mine[x][y] == '1' && flag == 1)
		{
			moveMine(Mine, x, y);
			opeanMine(Mine, Show, x, y);
			system("cls");
			Print(Show, ROW, COL);
			flag = 0;
		}
		else if (Mine[x][y] == '1' && flag == 0)
		{
			printf("你被炸死了\n\n");
			Print(Mine, ROW, COL);
			return 0;
		}
		else if (Mine[x][y] == '0')
		{
			opeanMine(Mine, Show, x, y);
			system("cls");
			Print(Show, ROW, COL);
			flag = 0;
		}
	}
	printf("恭喜你扫雷成功\n");
	return 0;
}
