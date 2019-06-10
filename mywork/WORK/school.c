//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<ctype.h>
//#include<time.h>
//#include<string.h>
//
//                                                                //5.30
////输入一个字符串，检查字符串的内容，如果有空格则删除空格，输出最终的字符串。
//void delblank(char *s)
//{
//	char *p, *b;
//	b = s;
//	p = b;
//	while (*p != '\0')
//	{
//		if (*p != ' ')
//		{
//			*b++ = *p;
//		}
//		p++;
//	}
//	*b = '\0';
//}
//int main()
//{
//	char str[20];
//	printf("input:\n");
//	gets(str);
//	printf("output:\n");
//	puts(str);
//	delblank(str);
//	puts(str);
//	system("pause");
//	return 0;
//}
//
////输入一个字符串，判断是否是“回文”
////（即字符串正读和倒读都是一样的，例如"helleh"就是回文），如果是则输出"yes，否则输出"no"。
//int mirror(const char *s)
//{
//	int len = strlen(s);
//	int mid = 1;
//	char* right = s;
//	char* left = s + len - 1;
//	while (mid < len)
//	{
//		if (*right == *left)
//		{
//			*right++;
//			*left--;
//		}
//		else
//		{
//			return 0;
//		}
//		mid++;
//		len--;
//	}
//	return 1;
//}
//int main()
//{
//	char str[20];
//	printf("input:\n");
//	gets(str);
//	printf("output:\n");
//	puts(str);
//	if (mirror(str))
//	{
//		printf("yes\n");
//	}
//	else
//	{
//		printf("no\n");
//	}
//	system("pause");
//	return 0;
//}
//
//
////输入10个整数存入数组list（定义和调用void arrayin(int *x, int n) {   }来完成）。
////输入一个整数a，在list中查找是否有数据a，如果找到则输出相应的下标值，否则输出“not found”。
////要求定义和调用函数
////其功能是在数组x中查找元素值a，若找到则返回相应的下标值，否则返回 - 1，参数n表示数组中元素的数量。
//void arrayin(int *x, int n)
//{
//	int i;
//	for (i = 1; i <= n; i++)
//		scanf("%d", x++);
//}
//void arrayout(int *x, int n)
//{
//	int i;
//	for (i = 1; i <= n; i++)
//		printf("%d ", *x++);
//}
//int search(int *x, int  n, int a)
//{
//	int tmp;
//	while (*x != '/0')
//	{
//		if (*x == a)
//		{
//			tmp = *x;
//			return *x;
//		}
//		*x++;
//	}
//	return -1;
//}
//int main()
//{
//	int list[10], a, f;
//	printf("input:\n");
//	arrayin(list, 10);
//	printf("output:\n");
//	arrayout(list, 10);
//	printf("\nsearch:\n");
//	scanf("%d", &a);
//	f = search(list, 10, a);
//	if (f >= 0)
//	{
//		printf("found! %d\n", f);
//	}
//	else
//	{
//		printf("not found!\n");
//	}
//	system("pause");
//	return 0;
//}

                                                       //5.23

//double mymax(double x, double y)
//{
//	if (x >= y)
//	{
//		return x;
//	}
//	else
//	{
//		return y;
//	}
//}
//double mymin(double x, double y)
//{
//	if (x >= y)
//	{
//		return y;
//	}
//	else
//	{
//		return x;
//	}
//}
// int main()
//{
//	printf("%lf\n", mymax(15, 12));
//	printf("%lf\n", mymin(5, 12));
//	system("pause");
//	return 0;
//}
//
// int fun(int n)
// {
//	 if (n > 0)
//	 {
//		 return n * fun(n - 1);
//
//	 }
//	 return 1;
// }
// int main()
// {
//	 int n;
//	 scanf("%d", &n);
//	 printf("%d\n", fun(n));
//	 system("pause");
//	 return 0;
// }
//
//int fun(int n)
//{
//	if (n > 0)
//	{
//		return n + fun(n - 1);
//	}
//	else
//	{
//		return 0;
//	}
//	
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", fun(n));
//	system("pause");
//	return 0;
//}
//
//void fun(int n)
//{
//	int x, y;
//	for (x = 1; x <= n; x++)
//	{
//		for (y = 1; y <= x; y++)
//		{
//			printf(" %d*%d = %d ", y, x, x*y);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	fun(n);
//	system("pause");
//	return 0;
//}
//
//double myfsqrt(double a)
//{
//	int i;
//	int x, x2, x1;
//	x = a / 2.0;
//	for (i = 0; ; i++)
//	{
//		x1 = (x + a / x) / 2;
//		x2 = x - x1;
//		if (fabs(x2) < 1e-5)
//			break;
//		x = x1;
//	}
//	return x1;
//}
//int main()
//{
//	double a;
//	scanf("%lf", &a);
//	myfsqrt(a);
//	printf("%lf", myfsqrt(a));
//	system("pause");
//	return 0;
//}


//                                       WORK 4
//int main()
//{
//	int arr[4][4] = { 0 };
//	int i, j, k = 0;
//	int res = 1;
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
// 	for ( i = 0; i <= 3; i++)
//	{
//		for (j = 3; j >= k; j--)
//		{
//			if (arr[i][j] != 0)
//			{
//				res = 0;
//			}
//			res = res * 1;
//		}
//		k++;
//	}
//	if (res == 1)
//	{
//		printf("YES!\n");
//	}
//	if (res == 0)
//	{
//		printf("NO!\n");
//	}
//	system("pause");
//	return 0;
//}
//
//int main() 
//{
//	int A[5][4] = { 0 };
//	int x[5] = { 0 };
//	int i, j, k = 0;
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			scanf("%d", &A[i][j]);
//		}
//	}
//	for (i = 0; i <= 4; i++)
//	{
//		for ( j = 0; j <= 3; j++)
//		{
//			x[k] = x[k] + A[i][j];
//		}
//		k++;
//	}
//	for (i = 0; i <= 4; i++)
//	{
//		for (j = 0; j <= 3; j++)
//		{
//			printf("%d ", A[i][j]);
//		}
//		printf("%d\n", x[i]);
//	}
//	system("pause");
//	return 0;
//}
//
//struct vote 
//{
//	char name[5];
//	int count;
//}s[5] = { "A",0,"B",0,"C",0 ,"D",0 ,"E",0 };
//
//int main()
//{
//	int num, max = 0;
//	char vote[50];
//	int i, n, j = 0, k = 0, m = 0;
//	printf("请输入候选人人数：\n");
//	scanf("%d", &num);
//	printf("请输入候选人名字：\n");
//	for (i = 0; i < num; i++)
//	{
//		scanf("%s", s[i].name);
//	}
//	printf("请输入投票人数：\n");
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		printf("No.%d已经投票，名字是:", i + 1);
//		scanf("%s", &vote[i]);
//		for (j = 0; j < num; j++) {
//			if (strcmp(s[j].name , vote) == 0)
//			{
//				s[j].count++;
//				k = s[j].count;
//			}
//			if (max < k)
//			{
//				max = k;
//				m = j;
//			}
//		}
//	}
//	printf("投票结束\n");
//	for (i = 0; i < num; i++)
//	{
//		printf("%s的得票数为%d\n", s[i].name, s[i].count);
//	}
//	printf("优胜者是%s!!!\n得票数为%d\n", s[m].name, max + 1);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	for (i = 0; i < 15; i++)
//	{
//		arr[(15 + i) % n] = arr[i];
//	}
//	for (i = 0; i < 15; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//
//int main() 
//{
//	int ten = 0;
//	int two = 0;
//	printf("请输入一个十进制整数.\n");
//	scanf("%d", &ten);
//	int a[32];
//	while ( ten > 0)
//	{
//		a[two] = ten % 2;
//		two = two + 1;
//		ten = ten / 2;
//	}
//	printf("十进制整数转换为二进制数是:\n");
//	for (two-- ; two >= 0; two--)
//	{
//		printf("%d", a[two]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int x, i, y;
//	int a, b, c;
//	for (i = 100; i <= 1000; i++)
//	{
//		a = i / 100;
//		b = i % 100 / 10;
//		c = i % 10;
//		x = a * b*c;
//		y = a + b + c;
//		if (x > y)
//		{
//			printf("%d\n", i);
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int i = 0, space = 0, num = 0, n = 0, ch = 0;
//	char s[80];
//	printf("请输入一串字符 ");
//	gets(s);
//	while (s[i] != '\0')
//	{
//		if (s[i] == ' ')
//			space++;
//		else if (s[i] <= '9' && s[i] >= '0')
//			num++;
//		else if (s[i] <= 'z' && s[i] >= 'a' || s[i] <= 'Z' && s[i] >= 'A')
//			ch++;
//		else
//			n++;
//		i++;
//	}
//	printf("刚才输入的字符中英文字符个数为 %d\n", ch);
//	printf("刚才输入的字符中空格个数为 %d\n", space);
//	printf("刚才输入的字符中数字个数为 %d\n", num);
//	printf("刚才输入的字符中其他个数为 %d\n", n);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	double x1, a, x2, d;
//	scanf("%lf", &a);
//	x1 = a;
//	do
//	{
//		x2 = 0.5*(x1 + a / x1);
//		d = x1 * x2;
//		x1 = x2;
//	} while (d*d < 0.0001);
//	printf("%lf\n", x1);
//	system("pause");
//	return 0;
//}



//int sum()
//{
//	int num1, num2, num;
//	srand(time(NULL));
//	do
//	{
//		num1 = rand() % 100;
//		num2 = rand() % 100;
//		num = num1 + num2;
//	} while (num>100);
//	printf("%d+%d=", num1, num2);
//	return num;
//}
//int jian()
//{
//	int num1, num2, num;
//	srand(time(NULL));
//	do
//	{
//		num1 = rand() % 100;
//		num2 = rand() % 100;
//		num = num1 - num2;
//	} while (num > 100 || num < 0);
//	printf("%d-%d=", num1, num2);
//	return num;
//}
//int main()
//{
//	int y, x, result, i, n;
//	int z = 1;
//	srand(time(NULL));
//	printf("请选择加减法:\n1——加法\n2——减法\n其他——加减法混合\n");
//	scanf("%d", &i);
//	do
//	{
//		if (i == 1)
//		{
//			for (n = 0; n < 10; n++)
//			{
//				result = sum();
//				scanf("%d", &y);
//				if (y == result)
//				{
//					printf("回答正确！\n");
//					system("pause");
//				}
//				else
//				{
//					printf("回答错误！正确答案为%d\n", result);
//					system("pause");
//				}
//			}
//		}
//		if (i == 2)
//		{
//			for (n = 0; n < 10; n++)
//			{
//				result = jian();
//				scanf("%d", &y);
//				if (y == result)
//				{
//					printf("回答正确！\n");
//					system("pause");
//				}
//				else
//				{
//					printf("回答错误！正确答案为%d\n", result);
//					system("pause");
//				}
//			}
//		}
//
//		else
//		{
//			for (n = 0; n < 10; n++)
//			{
//				x = rand() % 2;
//				switch (x)
//				{
//				case 0:result = sum(); break;
//				case 1:result = jian(); break;
//				}
//				scanf("%d", &y);
//				if (y == result)
//				{
//					printf("回答正确！\n");
//					system("pause");
//				}
//				else
//				{
//					printf("回答错误！正确答案为%d\n", result);
//					system("pause");
//				}
//			}
//		}
//		printf("是否重新再计算一遍：\n1——重新\n2——结束");
//		scanf("%d", &z);
//		if (z != 1)
//		{
//			break;
//		}
//	} while (z = 1);
//	system("pause");
//	return 0;
//}




////int main()
////{
////	int x, i, min;
////	printf("请输入12个数据：\n");
////	scanf("%d", &x);
////	min = x;
////	for (i = 2; i <= 12; i++)
////		{
////			scanf("%d", &x);
////			if (x < min)
////			{
////				min = x;
////			}
////		}
////	printf("输入数据中最小的数：%d\n", min);
////	system("pause");
////	return 0;
////}
////
////
////
////int main()
////{
////	int x=0, i=1;
////	scanf("%d", &x);
////	for (; x > 0;x--)
////	{
////		i = x * i;
////	}
////	printf("%d\n", i);
////	system("pause");
////	return 0;
////}
////
////
////
////
////
////int main()
////{
////	int x, y, i,m;
////	scanf("%d %d", &x, &y);
////	if (x > y)
////		m = y;
////	else
////	{
////		m = x;
////	}
////	for (i = m; i <= m; i++)
////	{
////		if (x%i == 0 && y%i == 0)
////		{
////			printf("%d ", i);
////		}break;
////	}
////	system("pause");
////	return 0;
////}
////
////int main()
////{
////	int x1, x2, x3, y1, y2, y3 ;
////	double S ,a, b, c, q ,k1, k2, k3;
////	printf("请输入指定坐标:");
////	scanf("%d %d",&x1,&y1);
////	printf("请输入指定坐标:");
////	scanf("%d %d",&x2,&y2);
////	printf("请输入指定坐标:");
////	scanf("%d %d",&x3,&y3);
////	a = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1) * (y2 - y1));
////	b = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1) * (y3 - y1));
////	c = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3) * (y2 - y3));
////	k1 = (y2 - y1) / (x2 - x1);
////	k2 = (y3 - y2) / (x3 - x2);
////	k3 = (y3 - y1) / (x3 - x1);
////	q = (a + b + c)/2;
////	S = sqrt(q * (q - a)*(q - b)*(q - c));
////	if (k1 = k2)
////	{
////		if (k2 != k3) 
////		{
////			printf("三角形的面积为%lf\n", S);
////		}
////		else
////			printf("不能组成一个三角形\n");
////	}
////	else
////	{
////		printf("三角形的面积为%lf\n", S);
////	}
////	system("pause");
////	return 0;
////}
////
////
////int main()
////{
////	float r, s, l;
////	int i;
////	printf("*****************************\n1------计算圆的面积\n2------计算圆的周长\n3------计算圆的周长和面积\n******************************\n请选择（1--3）：");
////	scanf("%d", &i);
////	printf("请输入圆的半径：");
////	scanf("%f", &r);
////	if (1 == i)
////	{
////		printf("圆的面积是：%f", 3.14*r*r);
////	}
////	if (2 == i)
////	{
////		printf("圆的周长是：%f", 3.14*2*r);
////	}
////	if (3 == i)
////	{
////		printf("圆的面积和周长是：%f和%f", 3.14*r*r, 3.14 * 2 * r);
////	}
////	system("pause");
////	return 0;
////}
////
////
////
////
////int main() {
////	int x, y;
////	char op;
////	scanf("%d %c %d", &x, &op, &y);
////	switch (op)
////	{
////	case  '+':
////		printf("=%d", x + y);break;
////	case  '-':
////		printf("=%d", x - y);break;
////	case'*':
////		printf("=%d", x*y); break;
////	case'/':
////		if (y=0)
////			printf("Error!");  
////        else { printf("=%d", x / y); 
////		};
////		break;
////	default:
////		printf("error");
////	}
////	system("pause");
////	return 0;
////}
//
//int main() {
//	int a = 0;
//	scanf("请输入一个数%d", &a);
//	if (a % 2 == 0)
//		printf("偶数\n");
//	else
//		printf("奇数\n");
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int a, b, c, t;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a < c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b < c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d", c);
//	system("pause");
//	return 0;
////}
////
//int main() {
//	int a, b, c, t;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a < c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b < c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d %d %d", a, b, c);
//	system("pause");
//	return 0;
//
////}
////
////
//int main() {
//	int ch;
//	ch = getche();
//	if ((ch >= 97) && (ch <= 122))
//		printf(" %c 是小写字母\n", ch);
//	else if ((ch >= 65) && (ch <= 90))
//		printf("\n%c是大写字母\n", ch);
//	else if ((ch >= 48) && (ch <= 57))
//		printf("\n%c是数字字符\n", ch);
//	else
//		printf("\n%c是其他字符\n", ch);
//	system("pause");
//	return 0;
////
////
//	int main() {
//		int p;
//		scanf("请输入分数%d", &p);
//		if ((p >= 90) && (p <= 100))
//			printf("A");
//		else if ((p >= 80) && (p <= 90))
//			printf("B");
//		else if ((p >= 70) && (p <= 80))
//			printf("C");
//		else if ((p >= 60) && (p <= 70))
//			printf("D");
//		else
//			printf("E");
//		system("pause");
//		return 0;
//	}

//
//int main() { 
//	int i, k;
//
//	for (i = 0, k = -1; k = 1; i++, k++)
//
//		printf("*** ");
//	system("pause");
//	return 0;
//}
