#include<stdio.h>
#include<string.h>
//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
//示例 1：
//输入："ab-cd"
//输出："dc-ba"
//示例 2：
//输入："a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"
int isword(char ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	{
		return 1;
	}
	return 0;
}
char* reverseOnlyLetters(char* S)
{
	char* ret = S;
	int i = 0;
	int j = strlen(S) - 1;
	if (S == NULL)
	{
		return NULL;
	}
	while (i < j)
	{
		if (isword(S[i]) && isword(S[j]))
		{
			S[i] ^= S[j];
			S[j] ^= S[i];
			S[i] ^= S[j];
			i++;
			j--;
		}
		if (!isword(S[i]))
		{
			i++;
		}
		if (!isword(S[j]))
		{
			j--;
		}
	}
	return ret;
}
int main()
{
	char str[] = "ab-cd";
	char *ret = reverseOnlyLetters(str);
	printf("%s\n", ret);
	return 0;
}