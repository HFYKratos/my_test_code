#include "game.h"

void memu()
{
	printf("************************\n");
	printf("******    1.PLAY   *****\n");
	printf("******    0.EXIT   *****\n");
	printf("************************\n");
	printf("��ѡ��");
}

void game()
{
	char A[H][L] = { 0 };
	char res = 'C';
	srand((unsigned) time(NULL));
	memset(A, 0, sizeof(A));
	board(A, H, L);
	while (res == 'C')
	{
		playermove(A, H, L);
		res = WOL(A, H, L);
		if (res == 'C')
		{
			commove(A);
			board(A, H, L);
			res = WOL(A, H, L);
		}
	}
	if (res == '*')
	{
		printf("��Ϸ���������ʤ����\n");
	}
	if (res == '+')
	{
		printf("��Ϸ����������ʤ����\n");
	}
	if (res == 'Q')
	{
		printf("��Ϸ������ƽ�֣�\n");
	}
}

int main()
{
	int input = 1;
	while (input != 0)
	{
		memu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); 
			break;
		case 0:break;
		default:printf("������ѡ��\n");
			break;
		}
	}
	return 0;
}