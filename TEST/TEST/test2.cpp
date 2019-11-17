#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void length(int& score, const string pw)
{
	int size = pw.size();
	score += 5;
	if (size >= 5)
	{
		score += 5;
		if (size >= 8)
		{
			score += 15;
		}
	}
}

void letter(int& score, int& s, int& b, string pw)
{
	string::iterator it = pw.begin();
	while (it != pw.end())
	{
		if (*it >= 'a' && *it <= 'z')
		{
			s++;
		}
		else if (*it >= 'A' && *it <= 'Z')
		{
			b++;
		}
		*it++;
	}
	if (s > 0 || b > 0)
	{
		score += 10;
		if (s > 0 && b > 0)
		{
			score += 10;
		}
	}
}

void number(int& score, int& num, string pw)
{
	string::iterator it = pw.begin();
	while (it != pw.end())
	{
		if (*it >= '0' && *it <= '9')
		{
			num++;
		}
		*it++;
	}
	if (num > 0)
	{
		score += 10;
		if (num > 1)
		{
			score += 10;
		}
	}
}

void otherChar(int& score, int& other, string pw)
{
	string::iterator it = pw.begin();
	while (it != pw.end())
	{
		if ((*it >= 0x21 && *it <= 0x2F)
			|| (*it >= 0x3A && *it <= 0x40)
			|| (*it >= 0x5B && *it <= 0x60)
			|| (*it >= 0x7B && *it <= 0x7E))
		{
			other++;
		}
		*it++;
	}
	if (other > 0)
	{
		score += 10;
		if (other > 1)
		{
			score += 15;
		}
	}
}

int main()
{
	string pw;
	cin >> pw;
	if (pw == " ")
	{
		cout << "VERY_WEAK" << endl;
		return 0;
	}
	int num = 0, small = 0, big = 0, other = 0, score = 0;
	length(score, pw);
	letter(score, small, big, pw);
	number(score, num, pw);
	otherChar(score, other, pw);
	if (num > 0 && (small > 0 || big > 0))
	{
		score += 2;
		if (other > 0)
		{
			score += 3;
			if (small > 0 && big > 0)
			{
				score += 5;
			}
		}
	}
	if (score <= 90)
	{
		if (score <= 80)
		{
			if (score <= 70)
			{
				if (score <= 60)
				{
					if (score <= 50)
					{
						if (score <= 25)
						{
							cout << "VERY_WEAK" << endl;
							return 0;
						}
						cout << "WEAK" << endl;
						return 0;
					}
					cout << "AVERAGE" << endl;
					return 0;
				}
				cout << "STRONG" << endl;
				return 0;
			}
			cout << "VERY_STRONG" << endl;
			return 0;
		}
		cout << "SECURE" << endl;
		return 0;
	}
	cout << "VERY_SECURE" << endl;
	system("pause");
	return 0;
}
#if 0
int main()
{
	class Board 
	{
	public:
		bool checkWon(vector<vector<int> > board)
		{
			int i;
			if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
			{
				if (board[0][0] == 1)
				{
					return true;
				}
				else if (board[0][0] == -1)
				{
					return false;
				}
			}
			if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
			{
				if (board[1][1] == 1)
				{
					return true;
				}
				else if (board[1][1] == -1)
				{
					return false;
				}
			}
			for (i = 0; i < 3; i++)
			{
				if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][0] == board[i][2])
				{
					if (board[i][0] == 1)
					{
						return true;
					}
					else if (board[i][0] == -1)
					{
						return false;
					}
				}
				if (board[0][i] != 0 && board[0][i] == board[1][i] && board[0][i] == board[2][i])
				{
					if (board[0][i] == 1)
					{
						return true;
					}
					else if (board[0][i] == -1)
					{
						return false;
					}
				}
			}
			return false;
		}
	};
	Board b;
	vector<vector<int>> board;
	board = { {1,0,1},{1,-1,-1},{1,-1,0} };
	b.checkWon(board);
	system("pause");
	return 0;
}


void Down(int& sum, int num[]);
void Right(int& sum, int num[])
{
	int tmp = num[1];
	num[1]--;
	if (num[0] > 0 || num[1] > 0)
	{
		if (num[0] != 0)
		{
			int tmp1 = num[0];
			int tmp2 = num[1];
			Down(sum, num);
		}
		if (num[1] != 0)
		{
			int tmp1 = num[0];
			int tmp2 = num[1];
			Right(sum, num);
		}

	}
	if (num[0] == 0 && num[1] == 0)
	{
		sum++;
	}
	num[1] = tmp;
}
void Down(int& sum, int num[])
{
	int tmp = num[0];
	num[0]--;
	if (num[0] > 0 || num[1] > 0)
	{
		if (num[0] != 0)
		{
			int tmp1 = num[0];
			int tmp2 = num[1];
			Down(sum, num);
		}
		if (num[1] != 0)
		{
			int tmp1 = num[0];
			int tmp2 = num[1];
			Right(sum, num);
		}
		
	}
	if (num[0] == 0 && num[1] == 0)
	{
		sum++;
	}
	num[0] = tmp;
}
void calculate(int& sum, int num[])
{
	Down(sum, num);
	Right(sum, num);
}
int main()
{
	int num[4] = { 0 };
	cin >> num[0] >> num[1];
	int sum = 0;
	if (num[0] == 0 || num[1] == 0)
	{
		cout << sum << endl;
	}
	calculate(sum, num);
	cout << sum << endl;
	system("pause");
	return 0;
}

int bitAdd(int a, int b)
{
	if (b == 0)
		return a;
	if (b == -a)
	{
		return 0;
	}
	int sum = a ^ b;
	int carry = (a&b) << 1;
	return bitAdd(sum, carry);
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << bitAdd(a, b) << endl;
	system("pause");
	return 0;
}


int main()
{
	size_t a = 0, b = 0;
	cin >> a >> b;
	size_t min = a < b ? a : b;
	if (min == 1)
	{
		cout << a * b << endl;
		return 0;
	}
	size_t ret = 1;
	for (size_t i = 2; i <= min; i++)
	{
		while (a%i == 0 && b%i == 0)
		{
			a = a / i;
			b = b / i;
			ret = ret * i;
		}
		min = a < b ? a : b;
	}
	ret = a * b * ret;
	cout << ret << endl;
	system("pause");
	return 0;
}

bool lengths(const vector<string> strs)
{
	size_t length = strs.size();
	size_t i = 0;
	for (i = 0; i < length - 1; i++)
	{
		size_t size1 = strs[i].size();
		size_t size2 = strs[i + 1].size();
		if (size1 > size2)
		{
			return false;
		}
	}
	return true;
}

bool lexicographically(const vector<string> strs)
{
	size_t length = strs.size();
	size_t i = 0;
	for (i = 0; i < length - 1; i++)
	{
		string str1 = strs[i];
		string str2 = strs[i + 1];
		string::iterator it1 = str1.begin();
		string::iterator it2 = str2.begin();
		while (it1 != str1.end())
		{
			if (*it1 > *it2)
			{
				return false;
			}
			if (*it1 < *it2)
			{
				break;
			}
			it1++;
			it2++;
		}
	}
	return true;
}
int main()
{
	int n = 0;
	cin >> n;
	vector<string> strs;
	int flag1 = 0, flag2 = 0;
	strs.resize(n);
	for (int i = 0; i < n; i++)
	{
		string ch;
		cin >> ch;
		strs[i] = ch;
	}
	if (lexicographically(strs))
	{
		flag1++;
	}
	if (lengths(strs))
	{
		flag2++;
	}
	if (flag1 == 1 && flag2 == 1)
	{
		cout << "both" << endl;
	}
	if (flag1 == 1 && flag2 == 0)
	{
		cout << "lexicographically" << endl;
	}
	if (flag1 == 0 && flag2 == 1)
	{
		cout << "lengths" << endl;
	}
	if(flag1 == 0 && flag2 == 0)
	{
		cout << "none" << endl;
	}
	system("pause");
	return 0;
}

bool chkParenthesis(string A = "()(())", int n = 6)
{
	int flag = 0;
	if (n % 2 != 0)
	{
		return false;
	}
	string::iterator it = A.begin();
	while (it != A.end())
	{
		if (*it != '(' && *it != ')')
		{
			return false;
		}
		if (*it == '(')
		{
			flag++;
		}
		if (*it == ')')
		{
			flag--;
		}
		if (flag < 0)
		{
			return false;
		}
		it++;
	}
	if (flag == 0)
	{
		return true;
	}
	return false;
}
int main()
{
	chkParenthesis();
	system("pause");
	return 0;
}

int fib(int n)//非递归形式
{
	int result;
	int pre_result;
	int next_older_result;
	result = pre_result = 1;
	while (n > 2)
	{
		n -= 1;
		next_older_result = pre_result;
		pre_result = result;
		result = pre_result + next_older_result;
	}
	if (n == 0)
	{
		return 0;
	}
	return result;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	int i = 0;
	int next = 0;
	while (1)
	{
		if (fib(i) >= num)
		{
			next = fib(i);
			break;
		}
		i++;
	}
	int prev = fib(i - 1);
	int step = num - prev;
	if (step > next - num)
	{
		cout << next - num << endl;
	}
	else
	{
		cout << step << endl;
	}
	system("pause");
	return 0;
}

int main()
{
	string str;
	char ch[100];
	cin.getline(ch, 100);
	str = ch;
	int len = str.length();
	if (len == 0)
	{
		return 0;
	}
	int result = 0;
	int flag = 1;
	int i = 0;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	if (str[i] == '+')
	{
		flag = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			i++;
		}
		if (str[i] >= '0'&&str[i] <= '9')
		{
			result = (result * 10 + flag * (str[i] - '0'));
			i++;
		}
		else
		{
			return 0;
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}

int main()
{
	vector<vector<int>> num;
	size_t x = 0, y = 0;
	for (size_t i = 0; i < 2; i++)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		if (i == 0)
		{
			x = tmp;
		}
		else
		{
			y = tmp;
		}
	}
	num.resize(x);
	for (size_t i = 0; i < x; i++)
	{
		num[i].resize(y, 0);
		for (size_t j = 0; j < y; j++)
		{
			if (i % 4 < 2)
			{
				if (j % 4 < 2)
				{
					num[i][j] = 1;
				}
			}
			else
			{
				if (j % 4 >= 2)
				{
					num[i][j] = 1;
				}
			}
		}
	}
	int sum = 0;
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			sum = sum + num[i][j];
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}

int add(int num, int n, const int *arr)
{
	int max = -10000, sum = 0;
	for (int j = 0; j <= n - num; j++)
	{
		for (int i = j; i < num + j; i++)
		{
			sum = sum + arr[i];
		}
		if (max < sum)
		{
			max = sum;
		}
		sum = 0;
	}
	return max;
}

int main()
{
	int* arr;
	int n = 0;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		scanf("%d", &x);
		arr[i] = x;
	}
	if (n == 1 || n == 2)
	{
		if (n == 1)
		{
			cout << arr[0];
			return 0;
		}
		cout << arr[0] + arr[1];
		return 0;
	}
	int max = -10000;
	for (int i = 2; i <= n - 1; i++)
	{
		int tmp = add(i, n, arr);
		if (max < tmp)
		{
			max = tmp;
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}

bool isRever(string str)
{
	string re;
	for (auto it = str.rbegin(); it != str.rend(); ++it)
	{
		re += *it;
	}
	if (str.compare(re.c_str()) != 0)
	{
		return false;
	}
	return true;
}

int main()
{
	char a[100];
	char b[100];
	string A;
	string B;
	cin.getline(a, 100);
	cin.getline(b, 100);
	A = a;
	B = b;
	int count = 0;
	for (size_t i = 0; i <= A.length(); i++)
	{
		if (A.length() == 1)
		{
			break;
		}
		A.insert(i, B);
		if (isRever(A) == true)
		{
			count++;
		}
		A = a;
	}
	for (size_t i = 0; i <= B.length(); i++)
	{
		if (B.length() == 1)
		{
			break;
		}
		B.insert(i, A);
		if (isRever(B) == true)
		{
			count++;
		}
		B = b;
	}
	cout << count << endl;
	return 0;
}


int main()
{
	int* ret;
	int n = 0, flag = 0, num = 0, size = 2, tmp = 0, i = 0;
	for (size_t j = 0; j < 2; j++)
	{
		int x = 0;
		scanf("%d", &x);
		if (j == 0)
		{
			num = x;
		}
		else
		{
			n = x;
		}
	}
	if (num < 0)
	{
		flag = 1;
		num = -num;
	}
	if (n == 10 || num < n)
	{
		cout << num;
		return 0;
	}
	if (num == n)
	{
		cout << "10";
		return 0;
	}
	int max = n * n;
	if (num < max)
	{
		ret = (int*)malloc(sizeof(int) * (size));
		for (int j = 0; j < size; j++)
		{
			ret[size - 1 - j] = 0;
		}
		while (num > n)
		{
			num = num - n;
			tmp++;
		}
		ret[1] = tmp;
		ret[0] = num;
		if (flag == 1)
		{
			cout << "-";
		}
		for (int j = 0; j < size; j++)
		{
			if (ret[size - 1 - j] < 10)
			{
				cout << ret[size - 1 - j];
			}
			else
			{
				printf("%c", ret[size - 1 - j] - 10 + 'A');
			}
		}
		cout << endl;
		return 0;
	}
	while (num >= max)
	{
		max = max * n;
		size++;
	}
	ret = (int*)malloc(sizeof(int) * (size));
	for (int j = 0; j < size; j++)
	{
		ret[size - 1 - j] = 0;
	}
	max = max / n;
	while (num > n)
	{
		while (num >= max)
		{
			num = num - max;
			tmp++;
		}
		ret[size - 1 - i] = tmp;
		i++;
		tmp = 0;
		max = max / n;
	}
	ret[0] = num;
	if (flag == 1)
	{
		cout << "-";
	}
	for (int j = 0; j < size; j++)
	{
		if (ret[size - 1 - j] < 10)
		{
			cout << ret[size - 1 - j];
		}
		else
		{
			printf("%c", ret[size - 1 - j] - 10 + 'A');
		}
	}
	cout << endl;
	system("pause");
	return 0;
}


int main()
{
	int num[4];
	int A = 0, B = 0, C = 0;
	for (size_t i = 0; i < 4; i++)
	{
		int x = 0;
		scanf("%d", &x);
		num[i] = x;
	}
	A = (num[0] + num[2]) / 2;
	B = (num[1] + num[3]) / 2;
	C = num[3] - B;
	if (A + B == num[2] && B + C == num[3] && A - B == num[0] && B - C == num[1])
	{
		cout << A << " " << B << " " << C << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	system("pause");
	return 0;
}

int main()
{
	char ch[100];
	cin.getline(ch, 100);
	int len = strlen(ch);
	string re;
	for (int i = 0; i < len; i++)
	{
		char tmp[20] = { 0 };
		int j = 0;
		while (i < len && ch[i] != ' ')
		{
			tmp[j] = ch[i];
			j++;
			i++;
		}
		tmp[j] = ' ';
		re.insert(re.begin(), tmp, tmp + strlen(tmp));
	}
	cout << re << endl;
	system("pause");
	return 0;
}

int main()
{
	int* num;
	int n;
	int i;
	cin >> n;
	num = new int[n];
	if (n == 1 || n == 0)
	{
		cout << "1" << endl;
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		num[i] = x;
	}
	i = 0;
	int ret = 0;
	int flag = 0;
	while (i < n)
	{
		while (i + 1 < n && num[i] <= num[i + 1])
		{
			i++;
			flag = 1;
		}
		if (flag == 1)
		{
			ret++;
			i++;
			flag = 0;
		}
		while (i + 1 < n && num[i] >= num[i + 1])
		{
			i++;
			flag = 1;
		}
		if (flag == 1)
		{
			ret++;
			i++;
			flag = 0;
		}
		if (i >= n)
		{
			break;
		}
	}
	if (ret == 0)
	{
		cout << "1" << endl;
	}
	else
	{
		cout << ret << endl;
	}
	return 0;
}
#endif

#if 0
int main()
{
	int n = 0;
	cin >> n;
	int* num;
	num = (int*)malloc(sizeof(int) * 3 * n);
	for (int i = 0; i < 3 * n; i++)
	{
		int x;
		scanf("%d", &x);
		num[i] = x;
	}
	for (int i = 0; i < 3 * n; i++)
	{
		int max = num[0];
		for (int j = 1; j < 3 * n - i; j++)
		{
			if (max <= num[j])
			{
				max = num[j];
			}
			else
			{
				int tmp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = tmp;
			}
		}
	}
	int** a = nullptr;
	a = new int *[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[3];
	}
	for (int i = 0; i < n; i++)
	{
		a[i][0] = num[i];
		for (int j = 1; j < 3; j++)
		{
			a[i][j] = num[3 * n - 1 - i * 2 - 2];
			a[i][j + 1] = num[3 * n - i * 2];
			break;
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret = ret + a[i][1];
	}
	cout << ret << endl;
	system("pause");
	return 0;
}
#endif


#if 0
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

union F
{
	int a;
	char c;
};
int main()
{
	F f;
	f.a = 1;
	if (f.c == 0)
	{
		cout << "big end" << endl;
	}
	else
	{
		cout << "little end" << endl;
	}
	system("pause");
	return 0
}


class Student
{
public:
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintInfo()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

private:
	char _name[10];
	char _gender[10];
	int _age;

};
int main()
{
	Student s;//实例化
	s.SetStudentInfo("Peter", "male", 18);
	s.PrintInfo();
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:

	Date(int year = 1999, int month = 11, int day = 8)
	{
		_year = year;
		_month = month;
		_day = day;
		if (_year <= 0 || _month <= 0 || _month > 12 || _day <= 0 || _day > 28)
		{
			if (_month == 2)
			{
				if (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0)
				{
					if (_day > 29)
						cout << "日期违法重置为1—1—1" << endl;
					_year = 1;
					_month = 1;
					_day = 1;
				}
				else
				{
					if (_day > 28)
						cout << "日期违法重置为1—1—1" << endl;
					_year = 1;
					_month = 1;
					_day = 1;
				}
			}
			if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
			{
				if (_day > 30)
				{
					cout << "日期违法重置为1—1—1" << endl;
					_year = 1;
					_month = 1;
					_day = 1;
				}
			}
			else
			{
				if (_day > 31)
					cout << "日期违法重置为1—1—1" << endl;
				_year = 1;
				_month = 1;
				_day = 1;
			}
		}
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return *this -= (-day);
		}
		_day = day + _day;
		while (_day > 31)
		{
			if (_month == 2)
			{
				if (_day <= 28)
				{
					break;
				}
				if (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0)
				{
					_day = _day - 29;
					_month++;
				}
				else
				{
					_day = _day - 28;
					_month++;
				}
			}
			if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
			{
				if (_day <= 30)
				{
					break;
				}
				_day = _day - 30;
				_month++;
			}
			else
			{
				if (_day <= 31)
				{
					break;
				}
				_day = _day - 31;
				_month++;
			}
		}
		while (_month > 12)
		{
			_month = _month - 12;
			_year++;
		}
		return *this;
	}

	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += (-day);
		}
		_day = _day - day;
		while (_day <= 0)
		{
			if (_month == 2)
			{
				if (_day > 0)
				{
					break;
				}
				if (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0)
				{
					_day = _day + 29;
					_month--;
				}
				else
				{
					_day = _day + 28;
					_month--;
				}
			}
			if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
			{
				if (_day > 0)
				{
					break;
				}
				_day = _day + 30;
				_month--;
			}
			else
			{
				if (_day > 0)
				{
					break;
				}
				_day = _day + 31;
				_month--;
			}
		}
		while (_month <= 0)
		{
			_month = _month + 12;
			_year--;
		}
		return *this;
	}

	int operator-(const Date& d)
	{
		Date big;
		Date small;
		int count = 0;
		if (*this > d)
		{
			big = *this;
			small = d;
		}
		else
		{
			big = d;
			small = *this;
		}
		while (big != small )
		{
			small++;
			count++;
		}
		return count;
	}
	//++i
	Date& operator++()
	{
		return *this += 1;

	}
	//i++
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}
	//--i;
	Date& operator--()
	{
		return *this -= 1;
	}
	//i--
	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}

	bool operator>(const Date& d)const
	{
		if (_year > d._year)
		{
			return true;
		}
		if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	bool operator>=(const Date& d)const
	{
		if (_year > d._year)
		{
			return true;
		}
		if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			if (_month == d._month)
			{
				if (_day >= d._day)
				{
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	bool operator<(const Date& d)const
	{
		if (_year < d._year)
		{
			return true;
		}
		if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			if (_month == d._month)
			{
				if (_day < d._day)
				{
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	bool operator<=(const Date& d)const
	{
		if (_year < d._year)
		{
			return true;
		}
		if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			if (_month == d._month)
			{
				if (_day <= d._day)
				{
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	bool operator==(const Date& d)const
	{
		if (_year == d._year && _month == d._month && _day == d._day)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Date& d)const
	{
		if (_year != d._year || _month != d._month || _day != d._day)
		{
			return true;
		}
		return false;
	}

	void Print()
	{
		cout <<this->_year << "-" << this->_month << "-" << this->_day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2000, 11, 8);
	//d += -300;
	Date d2;
	int days = d - d2;
	cout << days << endl;
	system("pause");
	return 0;
}

#endif

