#include"MineSweep.hpp"

void memu()
{
	cout << "********************" << endl;
	cout << "****��ӭ����ɨ��****" << endl;
	cout << "********************" << endl;
	cout << "*****1.��ʼ��Ϸ*****" << endl;
	cout << "*****0.�˳���Ϸ*****" << endl;
	cout << "********************" << endl;
	cout << "��ѡ��";
}

int main()
{
	while (1)
	{
		memu();
		int input = 0;
		cin >> input;
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			return 0;
		default:
			cout << "�Ƿ����룡������ѡ��";
		}
	}
	return 0;
}