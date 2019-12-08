#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;
//有假币
int main()
{
	int num = 0;
	while (cin >> num)
	{
		int count = 1;
		if (num == 1)
		{
			count = 0;
		}
		while (num > 4)
		{
			num /= 2;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
#if 0
//求正数数组的最小不可组成和
int getFirstUnFormedNum(vector<int> arr, int len) 
{
	int sum = 0, min = arr[0];
	for (int i = 0; i < len; ++i)
	{
		sum += arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	vector<int> dp(sum + 1, 0);
	for (int i = 0; i < len; ++i)
	{
		for (int j = sum; j >= arr[i]; --j)
		{
			if (dp[j - arr[i]] + arr[i] > dp[j])
			{
				dp[j] = dp[j - arr[i]] + arr[i];
			}
		}
	}

	for (int i = min; i <= sum; ++i)
	{
		if (i != dp[i])
			return i;
	}
	return sum + 1;
}

int main()
{
	vector<int> arr = { 3,2,4 };
	int len = arr.size();
	int ret = getFirstUnFormedNum(arr, len);
	return 0;
}

int main()
{
	
	return 0;
}

int main()
{
	size_t n;
	while (cin >> n)
	{
		size_t x = pow(5, n) - 4;
		size_t y = pow(4, n) + n - 4;
		if (n == 0)
			break;
		else
		{
			cout << x << " " << y << endl;
		}
	}
	return 0;
}

void oddInOddEvenInEven(vector<int>& arr, int len)
{
	int i = 0, j = 1;
	while (i < len && j < len)
	{
		if (arr[i] % 2 != 0 && arr[j] % 2 == 0)
		{
			swap(arr[i], arr[j]);
			i += 2;
			j += 2;
			continue;
		}
		if (arr[i] % 2 == 0)
		{
			i += 2;
		}
		if (arr[j] % 2 != 0)
		{
			j += 2;
		}
	}
}

int main()
{
	vector<int> arr = { 7,7,9,5,1,6,7,9,3,2,6 };
	int len = arr.size();
	oddInOddEvenInEven(arr, len);
	return 0;
}

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if ((a + b > c) && (a + c > b) && (b + c > a))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}

int main()
{
	float n, r;
	while (cin >> n >> r)
	{
		if (n <= 2 * 3.14 * r)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}

int Jump(int num)
{
	if (num == 1)
	{
		return 1;
	}
	if (num == 2)
	{
		return 2;
	}
	int count = 1;
	for (int i = 1; i < num; i++)
	{
		count += Jump(num - i);
	}
	return count;
}

int jumpFloorII(int number)
{
	if (number == 1)
	{
		return 1;
	}
	if (number == 2)
	{
		return 2;
	}
	int count = 1;
	for (int i = 1; i < number; i++)
	{
		count += Jump(number - i);
	}
	cout << count << endl;
	return 0;
}

int main()
{
	int num = 3;
	cout << jumpFloorII(4) << endl;
	return 0;
}

int main()
{
	string num;
	while (cin >> num)
	{
		int cur = 0;
		while (num.size() > 1)
		{
			cur = 0;
			for (const auto& e : num)
			{
				cur += e - '0';
			}
			num = to_string(cur);
		}
		cout << cur << endl;
	}
	return 0;
}

void square(vector<vector<size_t>>& num)
{
	vector<vector<size_t>> num2 = { {1,1},{1,0} };
	size_t a = num[0][0] * num2[0][0] + num[1][0] * num2[0][1],
		b = num[0][0] * num2[0][1] + num[0][1] * num2[1][1],
		c = num[1][0] * num2[0][0] + num[1][1] * num2[1][0],
		d = num[1][0] * num2[0][1] + num[1][1] * num2[1][1];
	num[0][0] = a;
	num[0][1] = b;
	num[1][0] = c;
	num[1][1] = d;
}

int main()
{
	size_t num;
	while (cin >> num)
	{
		vector<size_t> count;
		for (size_t i = 0; i < num; i++)
		{
			size_t n = 0;
			cin >> n;
			count.push_back(n);
		}
		for (size_t i = 0; i < num; i++)
		{
			vector<vector<size_t>> number = { {1,1},{1,0} };
			for (size_t j = 1; j < count[i]; j++)
			{
				square(number);
			}
			vector<int> ret;
			ret.resize(5);
			int x = 0;
			while (number[0][0] != 0)
			{
				if (x == 4)
				{
					break;
				}
				ret[x] = number[0][0] % 10;
				number[0][0] /= 10;

				x++;
			}
			for (int i = 3; i >= 0; i--)
			{
				cout << ret[i];
			}
		}
		cout << endl;
	}
	return 0;
}

string ret;
string Down(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command);
string Up(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command);
string Left(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command);
string Right(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command)
{
	command += 'R';
	if (i == Kratos_ways.size() - 2 && j == Kratos_ways[i].size() - 2)
	{
		ret = command;
	}
	if (Kratos_ways[i][j + 1] == 0)
	{
		string tmp = command;
		Right(Kratos_ways, i, j + 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i + 1][j] == 0)
	{
		string tmp = command;
		Down(Kratos_ways, i + 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i - 1][j] == 0)
	{
		string tmp = command;
		Up(Kratos_ways, i - 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	return ret;
}
string Left(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command)
{
	command += 'L';
	if (i == Kratos_ways.size() - 2 && j == Kratos_ways[i].size() - 2)
	{
		ret = command;
	}
	if (Kratos_ways[i][j - 1] == 0)
	{
		string tmp = command;
		Left(Kratos_ways, i, j - 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i + 1][j] == 0)
	{
		string tmp = command;
		Down(Kratos_ways, i + 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i - 1][j] == 0)
	{
		string tmp = command;
		Up(Kratos_ways, i - 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	return ret;
}
string Down(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command)
{
	command += 'D';
	if (i == Kratos_ways.size() - 2 && j == Kratos_ways[i].size() - 2)
	{
		ret = command;	
	}
	if (Kratos_ways[i][j + 1] == 0)
	{
		string tmp = command;
		Right(Kratos_ways, i, j + 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i][j - 1] == 0)
	{
		string tmp = command;
		Left(Kratos_ways, i, j - 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i + 1][j] == 0)
	{
		string tmp = command;
		Down(Kratos_ways, i + 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	return ret;
}
string Up(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command)
{
	command += 'U';
	if (i == Kratos_ways.size() - 2 && j == Kratos_ways[i].size() - 2)
	{
		ret = command;
	}
	if (Kratos_ways[i][j + 1] == 0)
	{
		string tmp = command;
		Right(Kratos_ways, i, j + 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i][j - 1] == 0)
	{
		string tmp = command;
		Left(Kratos_ways, i, j - 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	if (Kratos_ways[i - 1][j] == 0)
	{
		string tmp = command;
		Up(Kratos_ways, i - 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = tmp;
	}
	return ret;
}
string Find(vector<vector<int>> Kratos_ways, size_t i, size_t j, string command)
{
	if (i == Kratos_ways.size() - 2 && j == Kratos_ways[i].size() - 2)
	{
		ret = command;
	}
	if (Kratos_ways[i][j + 1] == 0)
	{
		Right(Kratos_ways, i, j + 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = "";
	}
	if (Kratos_ways[i][j - 1] == 0)
	{
		Left(Kratos_ways, i, j - 1, command);
		if (ret != "")
		{
			return ret;
		}
		command = "";
	}
	if (Kratos_ways[i + 1][j] == 0)
	{
		Down(Kratos_ways, i + 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = "";
	}
	if (Kratos_ways[i - 1][j] == 0)
	{
		Up(Kratos_ways, i - 1, j, command);
		if (ret != "")
		{
			return ret;
		}
		command = "";
	}
	return ret;
}
int main()
{
	size_t n, m;
	while (cin >> n >> m)
	{
		vector<vector<int>> Kratos_ways;
		Kratos_ways.resize(n + 2);
		for (size_t i = 0; i < n + 2; i++)
		{
			Kratos_ways[i].resize(m + 2, 1);
			for (size_t j = 1; i > 0 && i < n + 1 && j <= m; j++)
			{
				cin >> Kratos_ways[i][j];
			}
		}
		ret = Find(Kratos_ways, 1, 1, "");
		cout << "(0,0)" << endl;
		int i = 0, j = 0;
		for (const auto& e : ret)
		{
			if (e == 'R')
			{
				j++;
				cout << "(" << i << "," << j << ")" << endl;
			}
			if (e == 'L')
			{
				j--;
				cout << "(" << i << "," << j << ")" << endl;
			}
			if (e == 'U')
			{
				i--;
				cout << "(" << i << "," << j << ")" << endl;
			}
			if (e == 'D')
			{
				i++;
				cout << "(" << i << "," << j << ")" << endl;
			}
		}
		ret = "";
	}
	return 0;
}

void Down(vector<vector<int> > board, size_t i, size_t j, int sum, int& max);
void Right(vector<vector<int> > board, size_t i, size_t j, int sum,int& max)
{
	j++;
	sum += board[i][j];
	if (i == board.size() - 1 && j == board[i].size() - 1)
	{
		if (max < sum)
		{
			max = sum;
		}
	}
	if (j != board[i].size() - 1)
	{
		Right(board, i, j, sum, max);
	}
	if (i != board.size() - 1)
	{
		Down(board, i, j, sum, max);
	}
}
void Down(vector<vector<int> > board, size_t i, size_t j, int sum,int& max)
{
	i++;
	sum += board[i][j];
	if (i == board.size() - 1 && j == board[i].size() - 1)
	{
		if (max < sum)
		{
			max = sum;
		}
	}
	if (j != board[i].size() - 1)
	{
		Right(board, i, j, sum, max);
	}
	if (i != board.size() - 1)
	{
		Down(board, i, j, sum, max);
	}	
}
int getMost(vector<vector<int> > board)
{
	int sum = board[0][0];
	int max = 0;
	size_t i = 0, j = 0;
	Right(board, i, j, sum, max);
	Down(board, i, j, sum, max);
	return max;
}
int main()
{
	vector<vector<int> > board;
	board.resize(6, { 1,2,3,4,5,6 });
	getMost(board);
	return 0;
}


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