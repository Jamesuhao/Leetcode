#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<malloc.h>
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//注意：
//num1 和num2 的长度都小于 5100.
//num1 和num2 都只包含数字 0 - 9.
//num1 和num2 都不包含任何前导零。
//你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
char * addStrings(char *num1, char *num2)
{
	int i = 0;
	int tmp = 0;
	int carry = 0;
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	char *p1=NULL;
	char *p2 = NULL;
	char *ret = NULL;
	if (len1 > len2)
	{
		p1 = num1 + len1 - 1;
		p2 = num2 + len2 - 1;
	}
	else
	{
		p2 = num1 + len1 - 1;
		p1 = num2 + len2 - 1;
		len1 ^= len2;
		len2 ^= len1;
		len1 ^= len2;
	}
	ret = (char *)malloc((len1 + 2)*sizeof(char));
	memset(ret, 0, (len1 + 2)*sizeof(char));
	for (i = 0; i < len2; ++i)
	{
		tmp = *p1 + *p2 + carry - 96;
		ret[len1 - i] = tmp % 10 + 48;
		carry = tmp / 10;
		p1--;
		p2--;
	}
	for (i = len2; i < len1; ++i)
	{
		tmp = *p1-- + carry - 48;
		ret[len1 - i] = tmp % 10 + 48;
		carry = tmp / 10;
	}
	if (carry)
	{
		ret[0] = '1';
		return ret;
	}
	else
	{
		return ret + 1;
	}
}
int main()
{
	char str1[] = "1234";
	char str2[] = "12345";
	 char * p = addStrings(str1, str2);
	 printf("%s\n", p);
	return 0;
}
