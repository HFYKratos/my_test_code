#include<stdio.h>
#include<iostream>
using namespace std;
namespace N1
{
	int a;
	int add(int a, int b)
	{
		return a + b;
	}
	namespace N3
	{
		int sub(int a, int b)
		{
			return a - b;
		}
	}
}
using N1::a;

void test()
{
	a = 20;
	int b;
	int c;
	cin >> b >> c;
	cout << a << " " << b << " " << c << endl;
}

void fun(int a, int b = 0, int c = 20)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	//test();
	fun(10);
	system("pause");
	return 0;
}