#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#include<malloc.h>
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

//
//#if 0
//int MyStrcam(const char* str1, const char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (*str1 != '\0' && *str2 != '\0')
//		{
//			if (*str1 > *str2)
//			{
//				return 1;
//			}
//			else if(*str1 < *str2)
//			{
//				return -1;
//			}
//		}
//		*str1++;
//		*str2++;
//		if (*str1 == '\0' && *str2 != '\0') 
//		{
//			return -1;
//		}
//		else if (*str1 != '\0' && *str2 == '\0')
//		{
//			return 1;
//		}
//		else if (*str1 == '\0' && *str2 == '\0')
//		{
//			return 0;
//		}
//	}
//	if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//char *MyStrcat(char *dest, const char *stc)
//{
//	char* p = *dest;
//	assert(dest != NULL && stc != NULL);
//	while (*dest != '\0')
//	{
//		*dest++;
//	}
//	while (*stc != '\0')
//	{
//		*dest = *stc;
//		*dest++;
//		*stc++;
//	}
//	return p;
//}
//
//
//char* MyStrncpy(char *dest, const char *stc, int n)
//{
//	char* p = *dest;
//	assert(dest != NULL && stc != NULL);
//	while (n > 0)
//	{
//		*dest = *stc;
//		*dest++;
//		*stc++;
//		n--;
//	}
//	//*dest = '/0';
//	return p;
//}
//int MyStrncam(const char* str1, const char* str2,int n)
//{
//	while (n > 1 && *str1 == *str2)
//	{
//		if (*str1 != '\0' && *str2 != '\0')
//		{
//			if (*str1 > *str2)
//			{
//				return 1;
//			}
//			else if (*str1 < *str2)
//			{
//				return -1;
//			}
//		}
//		*str1++;
//		*str2++;
//		n--;
//		if (*str1 == '\0' && *str2 != '\0')
//		{
//			return -1;
//		}
//		else if (*str1 != '\0' && *str2 == '\0')
//		{
//			return 1;
//		}
//		else if (*str1 == '\0' && *str2 == '\0')
//		{
//			return 0;
//		}
//	}
//	if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else if(*str1 < *str2)
//	{
//		return -1;
//	}
//	else if (*str1 == *str2)
//	{
//		return 0;
//	}
//}
//char *MyStrncat(char *dest, const char *stc,int n)
//{
//	char* p = *dest;
//	assert(dest != NULL && stc != NULL);
//	while (*dest != '\0')
//	{
//		*dest++;
//	}
//	while (n > 0 && *stc != '\0')
//	{
//		*dest = *stc;
//		*dest++;
//		*stc++;
//		n--;
//	}
//	return p;
//}
//#endif
//
//#if 0
//char *MyStrstr(const char* str1, const char* str2)
//{
//	char *p = NULL;
//	char *tmp = str2; 
//	char *mid = str1;
//	while (*str2 != '\0')
//	{
//		if (*str1 != *str2)
//		{
//			*str1++;
//			mid = str1;
//		}
//		while (*mid == *str2)
//		{
//			*str2++;
//			*mid++;
//			*str1++;
//		}
//		if (*str2 != '\0')
//		{
//			str2 = tmp;
//		}
//	}
//	if (*str2 == '\0')
//	{
//		p = tmp;
//		memcpy(tmp, mid, strlen(mid) * 4);
//		//printf("%s", strerror(errno));
//	}
//	//while (*str1 != '/0')
//	//{
//	//	while (*p != '\0')
//	//	{
//	//		*p++;
//	//	}
//	//	p = *str1;
//	//	*str1++;
//	//	*p++;
//	//}
//	return p;
//}
//int main()
//{
//	char arr[] = "khekhello";
//	char *arr2 = "hel";
//	char *p = MyStrstr(arr, arr2);
//	//int i = MyStrncam(arr, arr2, 3);
//	//int i = MyStrcam(arr, arr2);
//	//strcat(arr, s);
//	//MyStrcat(arr, arr2);
//	//strncpy(arr, arr2, 2);
//	//strncat(arr, arr2, 2);
//	//MyStrncat(arr, arr2, 2);
//	//printf("%d\n", i);
//	printf("%s\n", p);
//	system("pause");
//	return 0;
//}
//
//
//void *Mymemcpy(void *dest, const void *src, int count)
//{
//	void *ret = dest;
//	while (count != 0)
//	{
//		*(char*)dest = *(char*)src;
//		((char*)dest)++;
//		((char*)src)++;
//		count--;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[20] = { 0 };
//	int arr2[] = { 1,2,3,4,5,6,7,8,9 };
//	char str1[] = "abcdef";
//	char str2[10] = { 0 };
//	memccpy
//}
//#endif
//
//int main()
//{
//	int a[4][4] = { 1,2,8,9,
//					2,4,9,12,
//					4,7,10,13,
//					6,8,11,15 };
//	int s, i, j = 0;
//	int k = 5;
//	for ( i = 0; i <= 4; i++)
//		{
//			if (a[i][j] <= k)
//			{
//				if (a[i + 1][j] >= k)
//				{
//					for ( j = 0; j <= 4; j++)
//					{
//						if (a[i][j] == k)
//						{
//							s = 1;
//						}
//						else
//						{
//							s = 0;
//						}
//					}
//				}
//				else if(a[i][j] == k)
//				{
//					s = 1;
//				}
//				else
//				{
//					s = 0;
//				}
//			}
//			else
//			{
//				s = 0;
//			}
//		}
//	if (s == 1)
//	{
//		printf("找到了\n");
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	system("pause");
//	return 0;
//}


#if 0
int main()
{
	int sum = 3;
	int begin = 2;
	int x = 0;
	int count1 = 0;
	int count2 = 0;
	scanf("%d", &x);
	if (x <= 3)
	{
		return 0;
	}
	while (1)
	{
		int tmp = sum;
		sum = sum + begin;
		begin = tmp;
		if (sum > x)
		{
			if (begin < x)
			{
				break;
			}
		}
	}
	while (sum != x)
	{
		sum--;
		count1++;
	}
	while (begin != x)
	{
		begin++;
		count2++;
	}
	return count1 > count2 ? count2 : count1;
}

int Bubble(int* a, int n)
{
	for (size_t j = n; j > 0; j--)
	{
		int count = 0;
		for (size_t i = 0; i < j - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				count = 1;
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		};
		if (count == 0)
		{
			break;
		}
	}
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int tmp = numsSize;
	int i, j;
	*returnSize = 0;
	int* res = (int*)malloc(sizeof(int) * 10);
	for (i = 0; i < numsSize; i++)
	{
		for (j = 0; j < numsSize; j++)
		{
			if (i == j)
			{

			}
			else
			{
				if (target == nums[i] + nums[j])
				{
					numsSize = numsSize - 2;
					*returnSize = 2;
					break;
				}

			}
		}
	}
	res[0] = i;
	res[1] = j;
	return res;
}
int main()
{
	int a[4] = { 2, 7, 11, 15 };
	int b[4] = { 0 };
	int res = twoSum(a, 4, 9, b);
	system("pause");
	return 0;
}


int reverse(int x) {
	int a[50] = { 0 };
	long long Num = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		a[i] = x % 10;
		x = x / 10;
		if (x == 0)
		{
			break;
		}
	}
	for (; i >= 0; i--)
	{
		Num = Num + a[i] * pow(10, i);
	}
	if (x < 0)
	{
		Num = -Num;
	}
	if (Num < -pow(2, 31) || Num > pow(2, 31) - 1)
	{
		return 0;
	}
	return Num;
}
int main()
{
	printf("%d", reverse(123));
	system("pause");
	return 0;
}


bool isPalindrome(int x)
{
	int i = 0;
	int left = 0;
	int right = 0;
	int a[30] = { 0 };
	if (x < 0)
	{
		return false;
	}
	for (i = 0; i < 30; i++)
	{
		a[i] = x % 10;
		x = x / 10;
		if (x == 0)
		{
			break;
		}
	}
	right = i;
	while (left < right)
	{
		if (a[left] != a[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}
int main()
{
	if (isPalindrome(121))
	{
		printf("TRUE");
	}
	system("pause");
	return 0;
}

int romanToInt(char * s)
{
	int sum = 0;
	while (*s)
	{
		if (*s == 'M')
		{
			sum = sum + 1000;
			*s++;
		}
		if (*s == 'D')
		{
			sum = sum + 500;
			*s++;
		}
		if (*s == 'C')
		{
			sum = sum + 100;
			*s++;
			if (*s == 'D')
			{
				sum = sum + 300;
				*s++;
			}
			if (*s == 'M')
			{
				sum = sum + 800;
				*s++;
			}
		}
		if (*s == 'L')
		{
			sum = sum + 50;
			*s++;
		}
		if (*s == 'X')
		{
			sum = sum + 10;
			*s++;
			if (*s == 'L')
			{
				sum = sum + 30;
				*s++;
			}
			if (*s == 'C')
			{
				sum = sum + 80;
				*s++;
			}
		}
		if (*s == 'I')
		{
			sum = sum + 1;
			*s++;
			if (*s == 'V')
			{
				sum = sum + 3;
				*s++;
			}
			if (*s == 'X')
			{
				sum = sum + 8;
				*s++;
			}
		}
	}
	return sum;
}

int main()
{
	char s[6] = "LVIII";
	printf("%d ", romanToInt(s));
	system("pause");
	return 0;
}


//快排
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int PartSort(int* a, int left, int right)
{
	int key = a[left];
	int start = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		while (left < right && a[left] <= key)
		{
			++left;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[start], &a[left]);
	return left;
}

void QuickSort(int* a, int left, int right)
{
	int mid = PartSort(a, left, right);
	if (left < mid - 1)
	{
		QuickSort(a, left, mid - 1);
	}
	if (mid + 1 < right)
	{
		QuickSort(a, mid + 1, right);
	}
}

int main()
{
	int a[10] = { 6,1,2,9,7,3,5,4,10,8 };
	QuickSort(a, 0, 9);
	system("pause");
	return 0;
}

char * strCopy(char * s, int start, int end) {
	// 從原字符串 s 拷貝索引 [start, end) 之間的字符到新字符串
	int len = end - start;
	char * ret = (char *)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
		ret[i] = s[start + i];
	ret[len] = 0;
	return ret;
}

int strLen(char * s) {
	// 計算字符串長度
	int len = 0;
	while (*s != 0) {
		++len;
		++s;
	}
	return len;
}

char * longestCommonPrefix(char ** strs, int strsSize) {
	// 字符串數組爲空時，直接返回空字符串
	if (strsSize == 0)
		return strCopy("", 0, 0);
	// 字符串數組只有一個元素，返回這個元素的拷貝
	else if (strsSize == 1)
		return strCopy(*strs, 0, strLen(*strs));

	int offset = 0; // 字符串下標偏移
	int equal = 1;  // 字符是否相等

	while (equal) {
		// 字符串數組中相鄰兩個字符串兩兩對比
		for (int i = 0; i < strsSize - 1; i++) 
		{
			equal = (strs[i][offset] == strs[i + 1][offset] && strs[i][offset] != 0);
			// 只要有其中兩個不相等，或等於 0，直接跳出循環
			if (equal == 0)
				break;
		}
		// 如果全部相等，增加偏移量
		if (equal) {
			offset++;
		}
	}
	return strCopy(*strs, 0, offset);
}

char* strcopy(char* s, int start, int end)
{
	int len = -(start - end);
	char* ret = (char*)malloc(sizeof(char) * (len + 1));
	for (int i = 0; i < len; i++)
	{
		ret[i] = s[start + i];
	}
	ret[len] = 0;
	return ret;
}

int length(char* strs)
{
	int len = 0;
	while (*strs)
	{
		len++;
		*strs++;
	}
	return len;
}
char * longestCommonPrefix(char** strs, int strsSize)
{
	int same = 1;
	int cur = 0;
	if (strsSize == 0)
	{
		return strcopy("", 0, 0);
	}
	if (strsSize == 1)
	{
		return strcopy(*strs, 0, length(*strs));
	}
	while (same)
	{
		for (int i = 0; i < strsSize - 1; i++)
		{
			if (strs[i][cur] != 0 && strs[i][cur] == strs[i + 1][cur])
			{
				same = 1;
			}
			if (same == 0)
			{
				break;
			}
		}
		if (same == 1)
		{
			cur++;
		}
	}
	return strcopy(*strs, 0, cur);
}
int main()
{
	char* strs[3][10] = { "flower", "flow", "flight" };
	longestCommonPrefix(strs, 3);
	system("pause");
	return 0;
}


bool isValid(char * s)
{
	if (s == NULL || s[0] == '\0')
	{
		return true;
	}
	char *stack = (char*)malloc(4 + 1);
	int top = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			stack[top] = s[i];
			top++;
		}
		else
		{
			if ((--top) < 0)
				return false;//先减减，让top指向栈顶元素
			if (s[i] == ')' && stack[top] != '(')
				return false;
			if (s[i] == ']' && stack[top] != '[')
				return false;
			if (s[i] == '}' && stack[top] != '{')
				return false;
		}
	}
	return (!top);
}
int main()
{
	char* strs = "([)]";
	isValid(strs);
	system("pause");
	return 0;
}

#endif
#if 0

struct ListNode
{
	int val;
	struct ListNode *next;
};
struct ListNode* CreatNode(int x)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newNode->next = NULL;
	newNode->val = x;
	return newNode;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	struct ListNode* a = headA;
	struct ListNode* b = headB;
	struct ListNode* tmp = b;
	struct ListNode* tmp3 = a;

	while (a)
	{
		tmp = b;
		tmp3 = a;
		while (tmp)
		{
			struct ListNode* tmp2 = tmp;
			while (tmp->val == a->val)
			{
				tmp = tmp->next;
				a = a->next;
				if (tmp == NULL && a == NULL)
				{
					return tmp2;
				}
				if (tmp == NULL || a == NULL)
				{
					break;
				}
			}
			a = tmp3;
			tmp = tmp2->next;
		}
		a = a->next;
	}
	return NULL;
}

int main()
{
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;
	struct ListNode* next = NULL;
	l1 = CreatNode(4);
	next = l1;
	next->next = CreatNode(1);
	next = next->next;
	next->next = CreatNode(8);
	next = next->next;
	next->next = CreatNode(4);
	next = next->next;
	next->next = CreatNode(5);
	next = next->next;

	next = NULL;
	l2 = CreatNode(5);
	next = l2;
	next->next = CreatNode(0);
	next = next->next;
	next->next = CreatNode(1);
	next = next->next;
	next->next = CreatNode(8);
	next = next->next;
	next->next = CreatNode(4);
	next = next->next;
	next->next = CreatNode(5);

	getIntersectionNode(l1, l2);

	system("pause");
	return 0;
}

#endif

#if 0

int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
	{
		return 0;
	}
	if (numsSize == 1)
	{
		return 1;
	}
	if (numsSize == 2)
	{
		if (nums[0] == nums[1])
		{
			return 1;
		}
		else
			return 2;
	}
	int change = 0;
	for (int i = 0; i < numsSize - 1 - change; i++)
	{
		for (int j = i + 1; j < numsSize - change; j++)
		{
			while (j + change < numsSize && nums[i] == nums[j])
			{
				change++;
				int tmp = j;
				for (; j < numsSize - change; j++)
				{
					nums[j] = nums[j + 1];
				}
				j = tmp;
			}
			break;
		}
	}
	return change;
}

int main()
{
	int a[10] = { 0,0,1,1,1,2,2,3,3,4 };
	int len = 10;
	int a2[3] = { 1,2,2 };
	int len2 = 3;
	//removeDuplicates(a, len);
	removeDuplicates(a2, len2);
	system("pause");
	return 0;
}

int main()
{
	printf("123\n");
	printf("456\t");

	system("pause");
	return 0;
}
#endif