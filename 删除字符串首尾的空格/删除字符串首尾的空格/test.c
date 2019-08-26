#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

char *Del_space(char *str,int k)
{
	int i = 0;
	int j = k-1;
	int cur = 0;
	char *p1 = NULL;
	char *p2 = NULL;
	if (str == NULL)
	{
		return "error";
	}
	//删除字符串中第一个字符前的空格
	while (str[i] == '*')
	{
		i++;
	}
	//删除字符串中最后一个字符后的空格
	while (str[j] == '*')
	{
		j--;
	}
	//修改str中的字符串，将删除首尾空格后的字符串重新存储到str中
	for (cur = 0; i <= j; i++, cur++)
	{
		str[cur] = str[i];
	}
	str[cur] = '\0';
	//p1记录字符串首地址  p2用来修改字符串
	p1 = p2 = str;
	//删除字符串中间空格，并保留一个空格
	while (*str)
	{
		if (*str != '*')
		{
			*p2 = *str;
			p2++;
		}
		else
		{
			//保留一个空格
			if (*(p2 - 1) != '*')
			{
				*p2 = *str;
				p2++;
			}
		}
		str++;
	}
	*p2 = '\0';
	return p1;
}
int main()
{
	int k = 0;
	char arr[] = "*****as****adadq*****";
	k = strlen(arr);
	char *p = Del_space(arr,k);
	printf("%s\n", p);
	return 0;
}