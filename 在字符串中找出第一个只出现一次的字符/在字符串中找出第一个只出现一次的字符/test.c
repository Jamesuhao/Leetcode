#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char  Find_numbers(char str[])
{
	char *p = str;
	int str1[256] = { 0 };
	//1.�����ַ�����ͳ��ÿ���ַ����ֵĴ���
	while (*p)
	{
		str1[*p] ++;
		p++;
	}
	//2.���ҵ�һ��ֻ����һ�ε��ַ�
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
	printf("��һ��������һ�ε��ַ�Ϊ��%c\n", Find_numbers(arr));
	return 0;
}