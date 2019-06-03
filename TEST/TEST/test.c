#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<string.h>

char *mystrcpy(char *des, const char *str)
{
	assert(des != NULL && str != NULL);
	char *p = des;
	while (*str != '\0')
	{
		*des = *str;
		des++;
		str++;
	}
	*des = '/0';
	return p;
}

size_t mystrlen(const char *str)
{
	int count = 0;
	const char *p = str;
	while (*str != '/0')
	{
		count++;
		str++;
	}
	return count;

}

int main()
{
	char str[20] = "abcde";
	char *str2 = 'he';
	//mystrcpy(str, str2);
	
	printf("%s\n", mystrlen(str));
	system("pause");
	return 0;
}