#include<stdio.h>
#include<stdlib.h>

//template <typename T>


//void swap(T& a, T& b)
//{
//	T tmp =  a;
//	a = b;
//	b = tmp;
//}

template <class A>
A Add(A a, A b)
{
	return a + b;
}

int main()
{
	int a = 1, b = 2;
	char c = 'a', d = 'b';
	double e = 1.2, f = 2.2;
	//swap(a, b);
	//swap(c, d);
	//swap(e, f);
	Add(a, b);
	system("pause");
	return 0;
}