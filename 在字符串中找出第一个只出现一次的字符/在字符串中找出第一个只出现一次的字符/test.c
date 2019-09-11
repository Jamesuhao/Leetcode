#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 - 1。
//char  Find_numbers(char str[])
//{
//	char *p = str;
//	int str1[128] = { 0 };
//	//1.遍历字符串，统计每个字符出现的次数
//	while (*p)
//	{
//		str1[*p] ++;
//		p++;
//	}
//	//2.查找第一个只出现一次的字符
//	p = str;
//	while (*p)
//	{
//		if (str1[*p] == 1)
//		{
//			return *p;
//		}
//		p++;
//	}
//	return '\0';
//}
//返回下标法
int Find_numbers(char * s)
{
	int len = strlen(s);
	int i = 0;
	int arr[26] = { 0 };
	if (s == NULL || len == 0)
	{
		return -1;
	}
	for (i = 0; i<len; i++)
	{
		arr[s[i] - 'a']++;
	}
	for (i = 0; i<len; i++)
	{
		if (arr[s[i] - 'a'] == 1)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	char arr[] = "bacc";
	printf("第一个仅出现一次的字符为：%d\n", Find_numbers(arr));
	return 0;
}