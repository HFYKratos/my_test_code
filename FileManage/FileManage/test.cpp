#pragma once
#include "md5.hpp"
#include"file.hpp"
#include"FileManage.hpp"

using namespace std;

void Start()
{
	cout << "**********************************" << endl;
	cout << "********欢迎使用FileManage********" << endl;
	cout << "**********************************" << endl;
	cout << "****          1.开始          ****" << endl;
	cout << "****          0.退出          ****" << endl;
	cout << "**********************************" << endl;
} 

int main()
{
	Start();
	int input = 1;
	while (input)
	{
		cout << "请选择->";
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
			cout << "非法输入！" << endl;
		}
	}
	return 0;
}