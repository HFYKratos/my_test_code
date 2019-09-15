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
//void Bullsort(int *arr, int len)
//{
//	int i = 0;
//	int j = 0;
//	for ( i = 0; i < len; i++)
//	{
//		int count = 0;
//		for (j = 0; j < len - 1 - i; j++)
//		{
//			if (arr[j]>arr[j-1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				count++;
//			}
//		}
//		if (count == 0)
//		{
//			break;
//		}
//	}
//}
//int Int_cmp(void *base, int len,
//	int size,
//	int(*p)(const void *elem1, const void *elem2))
//{
//
//}
//
//void myqsort(void *base,int len,
//	int size,
//int(*p)(const void *elem1, const void *elem2))
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < len; i++)
//	{
//		int count = 0;
//		for (j = 0; j < len - 1 - i; j++)
//		{
//			if (Int_cmp())
//			{
//
//		}
//		if (count == 0)
//		{
//			break;
//		}
//	}
//}


#if 0
int MyStrcam(const char* str1, const char* str2)
{
	while (*str1 == *str2)
	{
		if (*str1 != '\0' && *str2 != '\0')
		{
			if (*str1 > *str2)
			{
				return 1;
			}
			else if(*str1 < *str2)
			{
				return -1;
			}
		}
		*str1++;
		*str2++;
		if (*str1 == '\0' && *str2 != '\0') 
		{
			return -1;
		}
		else if (*str1 != '\0' && *str2 == '\0')
		{
			return 1;
		}
		else if (*str1 == '\0' && *str2 == '\0')
		{
			return 0;
		}
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

char *MyStrcat(char *dest, const char *stc)
{
	char* p = *dest;
	assert(dest != NULL && stc != NULL);
	while (*dest != '\0')
	{
		*dest++;
	}
	while (*stc != '\0')
	{
		*dest = *stc;
		*dest++;
		*stc++;
	}
	return p;
}


char* MyStrncpy(char *dest, const char *stc, int n)
{
	char* p = *dest;
	assert(dest != NULL && stc != NULL);
	while (n > 0)
	{
		*dest = *stc;
		*dest++;
		*stc++;
		n--;
	}
	//*dest = '/0';
	return p;
}
int MyStrncam(const char* str1, const char* str2,int n)
{
	while (n > 1 && *str1 == *str2)
	{
		if (*str1 != '\0' && *str2 != '\0')
		{
			if (*str1 > *str2)
			{
				return 1;
			}
			else if (*str1 < *str2)
			{
				return -1;
			}
		}
		*str1++;
		*str2++;
		n--;
		if (*str1 == '\0' && *str2 != '\0')
		{
			return -1;
		}
		else if (*str1 != '\0' && *str2 == '\0')
		{
			return 1;
		}
		else if (*str1 == '\0' && *str2 == '\0')
		{
			return 0;
		}
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else if(*str1 < *str2)
	{
		return -1;
	}
	else if (*str1 == *str2)
	{
		return 0;
	}
}
char *MyStrncat(char *dest, const char *stc,int n)
{
	char* p = *dest;
	assert(dest != NULL && stc != NULL);
	while (*dest != '\0')
	{
		*dest++;
	}
	while (n > 0 && *stc != '\0')
	{
		*dest = *stc;
		*dest++;
		*stc++;
		n--;
	}
	return p;
}
#endif

#if 0
char *MyStrstr(const char* str1, const char* str2)
{
	char *p = NULL;
	char *tmp = str2; 
	char *mid = str1;
	while (*str2 != '\0')
	{
		if (*str1 != *str2)
		{
			*str1++;
			mid = str1;
		}
		while (*mid == *str2)
		{
			*str2++;
			*mid++;
			*str1++;
		}
		if (*str2 != '\0')
		{
			str2 = tmp;
		}
	}
	if (*str2 == '\0')
	{
		p = tmp;
		memcpy(tmp, mid, strlen(mid) * 4);
		//printf("%s", strerror(errno));
	}
	//while (*str1 != '/0')
	//{
	//	while (*p != '\0')
	//	{
	//		*p++;
	//	}
	//	p = *str1;
	//	*str1++;
	//	*p++;
	//}
	return p;
}
int main()
{
	char arr[] = "khekhello";
	char *arr2 = "hel";
	char *p = MyStrstr(arr, arr2);
	//int i = MyStrncam(arr, arr2, 3);
	//int i = MyStrcam(arr, arr2);
	//strcat(arr, s);
	//MyStrcat(arr, arr2);
	//strncpy(arr, arr2, 2);
	//strncat(arr, arr2, 2);
	//MyStrncat(arr, arr2, 2);
	//printf("%d\n", i);
	printf("%s\n", p);
	system("pause");
	return 0;
}


void *Mymemcpy(void *dest, const void *src, int count)
{
	void *ret = dest;
	while (count != 0)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
		count--;
	}
	return ret;
}
int main()
{
	int arr1[20] = { 0 };
	int arr2[] = { 1,2,3,4,5,6,7,8,9 };
	char str1[] = "abcdef";
	char str2[10] = { 0 };
	memccpy
}
#endif

int main()
{
	int a[4][4] = { 1,2,8,9,
					2,4,9,12,
					4,7,10,13,
					6,8,11,15 };
	int s, i, j = 0;
	int k = 5;
	for ( i = 0; i <= 4; i++)
		{
			if (a[i][j] <= k)
			{
				if (a[i + 1][j] >= k)
				{
					for ( j = 0; j <= 4; j++)
					{
						if (a[i][j] == k)
						{
							s = 1;
						}
						else
						{
							s = 0;
						}
					}
				}
				else if(a[i][j] == k)
				{
					s = 1;
				}
				else
				{
					s = 0;
				}
			}
			else
			{
				s = 0;
			}
		}
	if (s == 1)
	{
		printf("找到了\n");
	}
	else
	{
		printf("找不到\n");
	}
	system("pause");
	return 0;
}