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
	c_mine(mine, ROWS, COLS);            //��ʼ������
	setMine(mine, ROW, COL, NUM);       //������
	c_show(show, ROWS, COLS);           //��ʼ��show
	//Print(mine, ROW, COL);          //��ӡ����
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
		printf("���������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game();
			break;
		case 0:  printf("�ɹ��˳�\n");
			break;
		default:printf("�����������������\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}
