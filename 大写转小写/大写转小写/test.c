#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
//示例 1：
//输入 : "Hello"
//输出 : "hello"
//示例 2：
//输入 : "here"
//输出 : "here"
//示例 3：
//输入 : "LOVELY"
//输出 : "lovely"
char * toLowerCase(char * str)
{
	char *ret = str;
	if (str == NULL)
	{
		return NULL;
	}
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
		{
			*str += 32;
		}
		str++;
	}
	return ret;
}
int main()
{
	char str[] = "LOVELY";
	char *ret = toLowerCase(str);
	printf("%s\n", ret);
	return 0;
}