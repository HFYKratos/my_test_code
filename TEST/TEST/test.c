#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<string.h>
//
//char *mystrcpy(char *des, const char *str)
//{
//	assert(des != NULL && str != NULL);
//	char *p = des;
//	while (*str != '\0')
//	{
//		*des = *str;
//		des++;
//		str++;
//	}
//	*des = '/0';
//	return p;
//}
//
//size_t mystrlen(const char *str)
//{
//	int count = 0;
//	const char *p = str;
//	while (*str != '/0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//
//}
//int main()
//{
//	char str[20] = "abcde";
//	char *str2 = 'he';
//	//mystrcpy(str, str2);
//	
//	printf("%s\n", mystrlen(str));
//	system("pause");
//	return 0;
//}
void Bullsort(int *arr, int len)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < len; i++)
	{
		int count = 0;
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j]>arr[j-1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				count++;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
}
int Int_cmp(void *base, int len,
	int size,
	int(*p)(const void *elem1, const void *elem2))
{

}
void myqsort(void *base,int len,
	int size,
int(*p)(const void *elem1, const void *elem2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len; i++)
	{
		int count = 0;
		for (j = 0; j < len - 1 - i; j++)
		{
			if (Int_cmp())
			{

		}
		if (count == 0)
		{
			break;
		}
	}
}
int main()
{
	int arr[10] = { 0 };
	return 0;
}