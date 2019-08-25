#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char  Find_numbers(char str[])
{
	char *p = str;
	int str1[256] = { 0 };
	//1.遍历字符串，统计每个字符出现的次数
	while (*p)
	{
		str1[*p] ++;
		p++;
	}
	//2.查找第一个只出现一次的字符
	p = str;
	while (*p)
	{
		if (str1[*p] == 1)
		{
			return *p;
		}
		p++;
	}
	return '\0';
}

int main()
{
	char arr[] = "bacc";
	printf("第一个仅出现一次的字符为：%c\n", Find_numbers(arr));
	return 0;
}