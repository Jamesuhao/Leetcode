#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int Find_numbers(char *str, int len)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int min = 0;
	int str1[20] = { 0 };
	for (i = 0; i < len; i++)
	{
		for (j = i+1; j < len; j++)
		{
			if (str[i] == str[j])
			{
				str1[k] = j; 
				k++;
				break;
			}
		}
	}
	min = str1[0];
	for (i = 1; i < k; i++)
	{
		if (str1[i] < min)
		{
			min = str1[i];
		}
	}
	return min;
}
int main()
{
	int len = 0;
	int val = 0;
	char str[] = "qywyer23tdd";
	len = strlen(str);
	val = Find_numbers(str,len);
	printf("%c\n", str[val]);
	return 0;
}