#pragma once
#include "md5.hpp"
#include"file.hpp"
#include"FileManage.hpp"

using namespace std;

void Start()
{
	cout << "**********************************" << endl;
	cout << "********��ӭʹ��FileManage********" << endl;
	cout << "**********************************" << endl;
	cout << "****          1.��ʼ          ****" << endl;
	cout << "****          0.�˳�          ****" << endl;
	cout << "**********************************" << endl;
} 

int main()
{
	Start();
	int input = 1;
	while (input)
	{
		cout << "��ѡ��->";
		cin >> input;
		cin.ignore();
		system("cls");
		if (input == 1)
		{
			FileManage FM;
			FM.Work();
			Start();
		}
		else if(input == 0)
		{
			break;
		}
		else
		{
			Start();
			cout << "�Ƿ����룡" << endl;
		}
	}
	return 0;
}