#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>

                                           //DAY 12
////有一个字符数组的内容为:"student a am i",
////请你将数组的内容改为"i am a student".
////要求：
////不能使用库函数。
////只能开辟有限个空间（空间个数和字符串的长度无关）。
int mystrlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
void Reverseword(char *left, char *right)
{
	assert(left);
	assert(right);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void Reversestr(char *str)
{
	char *tmp = NULL;
	char *left = str;
	char *right = str + mystrlen(str) - 1;
	Reverseword(left, right);
	while (*str)
	{
		tmp = str;
		while ((*str != ' ') && (*str != '\0'))
		{
			str++;
		}
		char *end = str - 1;
		Reverseword(tmp, end);
		if (*str == ' ')
		{
			str++;
		}
	}
}
int main()
{
	char arr[] = { "student a am I" };
	Reversestr(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}

//编程实现： 
//一组数据中只有一个数字出现了一次。
//其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//int main()
//{
//	int i;
//	int arr[] = { 1,2,3,5,3,2,1 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (i = 1; i < len; i++)
//	{
//		arr[0] = arr[0] ^ arr[i];
//	}
//	printf("%d\n", arr[0]);
//	system("pause");
//	return 0;
//}

//不使用（a + b） / 2这种方式，求两个数的平均值。
//int main()
//{
//	int a = 20;
//	int b = 10;
//	int t;
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = a;
//	}
//	int c = (a - b) / 2 + b;
//  int d = (a & b) + (a ^ b)>>1;
//	printf("%u\n", d);
//	system("pause");
//	return 0;
//}

//编写函数： 
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回 值value的二进制位模式从左到右翻转后的值。
//unsigned int reserse_bit(unsigned int value)
//{
//	int i = 0;
//	unsigned int num = 0;
//	for (i = 0; i < 32; i++)
//	{
//		num += ((value >> i) & 1)*pow(2, 31 - i);
//	}
//	return num;
//}
//int main()
//{
//	int value = 0;
//	int num = 0;
//	scanf("%d", &value);
//	num = reserse_bit(value);
//	printf("%u\n", num);
//	system("pause");
//	return 0;
//}

										     //DAY 10
//#define ROW 7
//int main()
//{
//	int i, j, sz;
//	int arr[ROW][ROW] = { 0 };
//	sz = sizeof(arr) / sizeof(arr[0]);
//	for ( i = 0; i < sz; i++)
//	{
//		arr[i][0] = 1;
//		arr[i][i] = 1;
//	}
//	for ( i = 2; i < sz; i++)
//	{
//		for ( j = 1; j <= i; j++)
//		{
//			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//		}
//	}
//	for ( i = 0; i < sz; i++)
//	{
//		for ( j = 0; j < sz - i; j++)
//		{
//			printf(" ");
//		}
//		for ( j = 0; j <= i; j++)
//		{
//			printf("%-2d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 4; i++)
//	{
//		int killer = 65 + i;
//		j = ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D'));
//		if (j == 3)
//		{
//			printf("杀人凶手是%c\n", killer);
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int A, B, C, D, E;
//	for ( A = 0; A <= 5; A++)
//	{
//		for ( B = 0; B <= 5; B++)
//		{
//			for (C = 0; C <= 5; C++)
//			{
//				for (D = 0; D <= 5; D++)
//				{
//					for (E = 0; E <= 5; E++)
//					{
//						if ((B == 2 && A != 3) || (B != 2 && A == 3) == 1)
//						{
//							if ((B == 2 && E != 4 ) || (B != 2 && E == 4) == 1)
//							{
//								if ((C == 1 && D != 2) || (C != 1 && D == 2) == 1)
//								{
//									if ((C == 5 && D != 3) || (C != 5 && D == 3) == 1)
//									{
//										if ((E == 4 && A != 1) || (E != 4 && A == 1) == 1)
//										{
//											if (120 == A * B * C * D * E)
//											{
//												printf("A=%d B=%d C=%d D=%d E=%d\n", A, B, C, D, E);
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int arr1[32] = { 0 };
//	int arr2[32] = { 0 };
//	int x, y, i, n = 0;
//	scanf("%d.%d", &x, &y);
//	for ( i = 0; i < 32; i++)
//	{
//		arr1[i] = x & 1;
//		x = x >> 1;
//		arr2[i] = y & 1;
//		y = y >> 1;
//	}
//	for ( i = 0; i < 32; i++)
//	{
//		if (arr1[i] != arr2[i])
//		{
//			n++;
//		}
//	}
//	printf("%d\n", n);
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int num = 0;
//	int arr[32] = { 0 };
//	int len = 0;
//	int i;
//	scanf("%d", &num);
//	int tmp = num;
//	while((num % 10) > 0)
//	{
//				len++;
//				num = num / 10;
//    }
//	num = tmp;
//	for ( i = 0; i <= len; i++)
//	{
//		arr[i] = num % 10;
//		num = num / 10;
//	}
//	for (i = len - 1; i >= 0; i--)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int i, j = 0;
//	int arr1[16];
//	int arr2[16];
//	int num = 0;
//	scanf("%d", &num);
//	for ( i = 0; i < 32; i += 2)
//	{
//		arr1[j] = ((num >> i) & 1);
//		j++;
//	}	for (i = 1,j = 0; i < 32; i += 2)
//	{
//		arr2[j] = ((num >> i) & 1);
//		j++;
//	}
//	printf("奇数位为：");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n偶数位为：");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//int count_one_bits(unsigned int num)
//{
//	int n = 0;
//	while (num > 0)
//	{
//		if (1 == num % 2)
//		{
//			n++;
//		}
//		num = num >> 1;
//	}
//	return n;
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	printf("%d\n", count_one_bits(num));
//	system("pause");
//	return 0;
//}

//                                            DAY 07
//
//void gewei(int n)
//{
//	if (n > 9)
//	{
//		gewei(n / 10);
//	}
//	printf("%d ", n % 10);
//	printf("\n");
//}
//int main()
//{
//	gewei(1234);
//	system("pause");
//	return 0;
//}
//
//int jiecheng2(int n)//非递归形式
//{
//	int i, m = 1;
//	for ( i = 1; i <= n; i++)
//	{
//		m = m * i;
//	}
//	return m;
//}
//int jiecheng1(int n)//递归形式
//{
//	if (n > 1)
//	{
//		return n * jiecheng1(n - 1);
//	}
//	return 1;
//}
//int main()
//{
//	printf("%d\n", jiecheng2(5));
//	system("pause");
//	return 0;
//}
//
//int mystrlen2(char* x)//非递归形式
//{
//	int count = 0;
//	while (*x != 0)
//	{
//		count++;
//		x++;
//	}
//	return count;
//}
//int mystrlen1(char* x)//递归形式
//{
//	if (*x == 0)
//	{
//		return 0;
//	}
//	return 1 + mystrlen1(x + 1);
//}
//int main()
//{
//	printf("%d\n", mystrlen1("huangfengyun"));
//	system("pause");
//	return 0;
//}
//
//int DigitSum(int n)
//{
//	if (n)
//	{
//		return n % 10 + DigitSum(n / 10);
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", DigitSum(n));
//	system("pause");
//	return 0;
//}

//int cf(int n, int k)
//{
//	int res;
//	if (k >= 1)
//		return res = n * cf(n,k - 1);
//	if (k == 0)
//		return 1;
//}
//int main()
//{
//	int n, k, res;
//	scanf("%d %d", &n, &k);
//	res = cf(n, k);
//	printf("%d\n", res);
//	system("pause");
//	return 0;
//}

//int fib1(int n)//递归形式
//{
//	int result;
//	if (n > 2)
//	{
//		return result = fib1(n - 1) + fib1(n - 2);
//	}
//	if (n <= 2)
//		return 1;
//}
//int fib2(int n)//非递归形式
//{
//	int result;
//	int pre_result;
//	int next_older_result;
//	result = pre_result = 1;
//	while (n > 2)
//	{
//		n -= 1;
//		next_older_result = pre_result;
//		pre_result = result;
//		result = pre_result + next_older_result;
//	}
//	return result;
//}
//int main()
//{
//	int n, result;
//	printf("请输入需要求得的第n个数：");
//	scanf("%d", &n);
//	result = fib1(n);
//	printf("%d\n", result);
//	system("pause");
//	return 0;
//}

//void init(int* a[],int sz)
//{
//	int i = 0;
//	for ( i = 0; i < sz; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//}
//void empty(int* a[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		a[i] = 0;
//	}
//}
//void reverse(int* a[],int sz)
//{
//	int i = 0;
//	for (i = 0; i <= sz; i++)
//	{
//		a[i] = a[sz - 1 - i];
//	}
//}
//int main()
//{
//	int i = 0;
//	int sz = 0;
//	int arr[10] = { 0 };
//	sz = sizeof(arr) / sizeof(arr[0]);
//	init(arr, sz);
//	for ( i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	reverse(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	empty(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//int num(int a) 
//{
//	int i = 0;
//	for ( i = 2; i < sqrt(a); i++)
//	{
//		if (a%i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int n, m;
//	for ( n = 100; n < 200; n++)
//	{
//		int m = num(n);
//		if (m == 1)
//		{
//			printf("%d ", n);
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//int is_leap_year(int y)
//{
//	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 1;
//	scanf("%d", &year);
//	int i = is_leap_year(year);
//	if (i == 1)
//	{
//		printf("是闰年。\n");
//	}
//	else
//	{
//		printf("不是闰年。\n");
//	}
//	system("pause");
//	return 0;
//}
//
//
//void exchange(int* a, int* b)
//{
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("a=%d , b=%d\n", a, b);
//	exchange(&a, &b);
//	printf("a=%d , b=%d\n", a, b);
//	system("pause");
//	return 0;
//}
//
//
//int main()
//{
//	int x, y;
//	int n = 0;
//	scanf("%d", &n);
//	for ( x = 1; x <= n; x++)
//	{
//		for ( y = 1; y <= x; y++)
//		{
//			printf(" %d*%d = %d ", x, y, x*y);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	printf("输入想要查找的下标(小于10)：");
//	scanf("%d", &k);
//	int left = arr[0];
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] == k)
//		{
//			printf("找到了！下标为：%d", mid);
//			break;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			right = mid - 1;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到！");
//	}
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	char number;
//	while (1)
//	{
//		scanf("%c", &number);
//		if (number >= 'A' && number <= 'Z')
//		{
//			printf("%c", number + 32);
//		}
//		if (number >= 'a'&&number <= 'z')
//		{
//			printf("%c", number - 32);
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int pw = 123;
//	int i, n = 0;
//	printf("请输入密码：");
//	for ( i = 0; i < 3; i++)
//	{
//		scanf("%d", &n);
//		if (pw != n)
//		{
//			printf("密码错误！\n");
//		}
//		if (pw == n)
//			break;
//	}
//	if (i == 3)
//	{
//		printf("密码错误达到三次，退出程序\n");
//	}
//	if (i < 2)
//	{
//		printf("密码正确！");
//	}
//	system("pause");
//	return 0;
//}
//
//int main() 
//{
//	int num, g;
//	srand(time(NULL));
//	num = rand() % 100;
//	do
//	{
//		scanf("%d", &g);
//		if (g > num)
//		{
//			printf("大了\n");
//		}
//		if (g < num)
//		{
//			printf("小了\n");
//		}
//	} while (num != g);
//	printf("猜对了\n");
//	system("pause");
//	return 0;
//}

//int main()
//{
//int  i = 0;
//int  j = 0;
//for (i = 0; i < 7; i++)
//	{
//		for (j = 0; j < 2 * i + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//for (i = 0; i < 6; i++)
//{
//		for (j = 0; j < 11 - 2 * i; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//}
//	system("pause");
//	return 0;
//}
//
//int main() 
//{
//	int x, i;
//	int a, b, c;
//	for (i = 100; i <= 1000; i++)
//	{
//		if (i%100 != 0)
//		{
//			a = i / 100;
//			b = i % 100/10;
//			c = i % 10;
//			x = (a * a * a) + (b * b * b) + (c * c * c);
//			if ( x == i)
//			{
//				printf("%d\n", i);
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int i, a, b, c, d, e, sum;
//	scanf("%d", &i);
//	a = i;
//	b = a + 10 * i;
//	c = b + 100 * i;
//	d = c + 1000 * i;
//	e = d + 10000 * i;
//	sum = a + b + c + d + e;
//	printf("%d", sum);
//	system("pause");
//	return 0;
//}

//int main() {
//	int x, n;
//	for (x = 100; x <= 200; x++)
//	{
//		for (n = 2; n <= x; n++)
//		{
//			if (x%n == 0)
//				break;
//		}
//		if (x == n)
//			printf("%d ", x);
//	}
//	system("pause");
//	return 0;
//}
//
//
//int main() {
//	int x, y;
//	for(x=1;x<=9;x++)
//	{
//		for (y = 1; y <= 9; y++)
//		{
//			printf("%d*%d=%d\n", x, y, x*y);
//	}
//	}
//	system("pause");
//	return 0;
//}
//
//
//
//int main() {
//	int c,a;
//	printf("请随意输入一年：");
//	scanf("%d",&c);
//	if ((c % 4 == 0 %  c % 100 != 0) || c & 400 == 0)
//	a = 1;
//	else
//		a = 0;
//	if (a != 0)
//		printf("%d是闰年\n", c);
//	else
//		printf("%d不是闰年\n", c);
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int x, y, i;
//	scanf("%d %d", &x, &y);
//	i = x;
//	x = y;
//	y = i;
//	printf("%d %d", x, y);
//	system("pause");
//	return 0;
//}
//
//int main() 
//{
//	int x, y;
//	scanf("%d %d", &x, &y);
//	x = x + y;
//	y = x - y;
//	x = x - y;
//	printf("%d %d", x, y);
//	system("pause");
//	return 0;
//}
//
//int main() {
//	int x, max, i;
//	printf("请输入10个整数：\n");
//	scanf("%d", &x);
//	max = x;
//	for(i=1;i<10;i++)
//	{
//		scanf("%d", &x);
//		if (max < x)
//		{
//			max = x;
//		}
//	}
//	printf("最大的数为：%d", max);
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int x, y, z, t;
//	scanf("%d%d%d", &x, &y, &z);
//	if (x < y)
//	{
//		t = x;
//		x = y;
//		y = t;
//	}
//	if (y < z)
//	{
//		t = y;
//		y = z;
//		z = t;
//	}
//	if (x < z)
//	{
//		t = x;
//		x = z;
//		z = t;
//	}
//	printf("%d %d %d", x, y, z);
//	system("pause");
//	return 0;
//}
//
//int main() 
//{
//	int x, y, i,m;
//	scanf("%d %d", &x, &y);
//	if (x > y)
//		m = y;
//	else
//	{
//		m = x;
//	}
//	for (i = m; i > 1; i--)
//	{
//	   if (x%i == 0 && y%i == 0)
//	   break;
//	}
//	printf("%d ", i);
//    system("pause");
//	return 0;
//}
//
//int main()
//{
//	int i, j, k;
//	int A[10];
//	int B[10];
//	int C[10];
//	printf("请输入10个数给A组：");
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &A[i]);
//	}
//	printf("请输入10个数给B组：");
//	for (j = 0; j < 10; j++)
//	{
//		scanf("%d", &B[j]);
//	}
//	for (k = 0; k < 10; k++)
//	{
//		C[k] = A[k]+B[k];
//		B[k] = C[k]-B[k];
//		A[k] = C[k]-A[k];
//	}
//	printf("A组：");
//	for (j = 0; j < 10; j++)
//	{
//		printf("%d ", A[j]);
//	}
//	printf("\n");
//	printf("B组：");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", B[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	double n, i;
//	double s=0.0;
//	for ( i = 1; i <= 99; i++)
//	{
//		s = s + 1 / i;
//	}
//	for ( n = 2; n <= 100 ; n++)
//	{
//		s = s - 1 / n;
//	}
//	printf("%lf\n", s);
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int i, n;
//	int coun = 0;
//	for ( n = 1; n <= 100; n++)
//	{
//		i = n % 10;
//		if (9 == i)
//		{
//			coun++;
//		}
//	}
//	printf("%d\n", coun);
//	system("pause");
//	return 0;
//}