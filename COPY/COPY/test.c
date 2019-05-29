#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("**********************\n");
	printf("*****  1. play   *****\n");
	printf("*****  0. exit   *****\n");
	printf("**********************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	c_mine(mine, ROWS, COLS);            //初始化雷区
	setMine(mine, ROW, COL, NUM);       //放置雷
	c_show(show, ROWS, COLS);           //初始化show
	//Print(mine, ROW, COL);          //打印雷区
	system("cls");
	Print(show, ROW, COL);
	findMine(mine, show, ROW, COL);


}
int main()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选项:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0:  printf("成功退出\n");
			break;
		default:printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
