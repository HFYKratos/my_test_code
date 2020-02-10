#include"MineSweep.hpp"

void memu()
{
	cout << "********************" << endl;
	cout << "****欢迎来到扫雷****" << endl;
	cout << "********************" << endl;
	cout << "*****1.开始游戏*****" << endl;
	cout << "*****0.退出游戏*****" << endl;
	cout << "********************" << endl;
	cout << "请选择：";
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
			cout << "非法输入！请重新选择：";
		}
	}
	return 0;
}