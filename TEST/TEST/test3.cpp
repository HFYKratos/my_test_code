#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int count = 0;
		auto it1 = s1.begin();
		auto it2 = s2.begin();
		while (it1 != s1.end() && it2 != s2.end())
		{
			while (*it1 == *it2)
			{
				it1++;
				it2++;
			}
			auto tmp1 = it1;
			auto tmp2 = it2;

		}
		while (it1 != s1.end())
		{
			count++;
			it1++;
		}
		cout << count << endl;
	}
	return 0;
}


#if 0
int getValue(vector<int> gifts, int n)
{
	int max = INT32_MIN;
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		for (int j = i + 1; j < n; j++)
		{
			while (j < n && gifts[i] == gifts[j])
			{
				count++;
				j++;
			}
		}
		if (count > n / 2)
		{
			if (max < gifts[i])
			{
				max = gifts[i];
			}
		}
	}
	if (max > 0)
	{
		return max;
	}
	return 0;
}

int main()
{
	vector<int> gifts = { 1,2,3,2,2 };
	int n = 5;
	int ret = getValue(gifts, n);
	return 0;
}

int main()
{
	string str;
	while (cin >> str)
	{
		auto it = str.begin();
		while (it != str.end())
		{
			int flag = 0;
			auto nit = it + 1;
			while (nit != str.end())
			{
				while (nit != str.end() && *it == *nit)
				{
					flag = 1;
					str.erase(nit);
				}
				if (nit != str.end())
				{
					*nit++;
				}
			}
			if (flag == 1)
			{
				str.erase(it);
			}
			else
			{
				it++;
			}
		}
		if (str.empty())
		{
			cout << -1 << endl;
		}
		else
		{
			cout << str[0] << endl;
		}

	}
	return 0;
}


int FindYs(int s, int b)
{
	int sum = 1;
	for (int i = 1; i <= s; i++)
	{
		if (s % i == 0 && b % i == 0)
		{
			sum = i;
		}
	}
	return sum;
}
int main()
{
	int count, level;
	while (cin >> count >> level)
	{
		for (int i = 0; i < count; i++)
		{
			int beast = 0;
			cin >> beast;
			if (level >= beast)
			{
				level += beast;
			}
			else
			{
				level += FindYs(level, beast);
			}
		}
		cout << level << endl;
	}
	return 0;
}


//找两个数的最大公约数
int FindYs(int s, int b)
{
	int sum = 1;
	for (int i = 1; i <= s; i++)
	{
		if (s % i == 0 && b % i == 0)
		{
			sum = i;
		}
	}
	return sum;
}
int main()
{
	int s = 0, b = 0;
	while (cin >> s >> b)
	{
		if (s > b)
		{
			swap(s, b);
		}
		cout << FindYs(s, b) << endl;
	}
	return 0;
}

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
#endif