#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� - 1��
//char  Find_numbers(char str[])
//{
//	char *p = str;
//	int str1[128] = { 0 };
//	//1.�����ַ�����ͳ��ÿ���ַ����ֵĴ���
//	while (*p)
//	{
//		str1[*p] ++;
//		p++;
//	}
//	//2.���ҵ�һ��ֻ����һ�ε��ַ�
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
//�����±귨
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
	printf("��һ��������һ�ε��ַ�Ϊ��%d\n", Find_numbers(arr));
	return 0;
}