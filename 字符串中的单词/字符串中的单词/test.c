#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
//请注意，你可以假定字符串里不包括任何不可打印的字符。
//示例 :
//输入 : "Hello, my name is John"
//输出 : 5
//思路：每次出现非空字符，看看上一个是不是空格，如果是，则发现新单词。
int countSegments(char * s)
{
	int count = 0;
	int len = strlen(s);
	char *p = s;
	if (s == NULL || len == 0)
	{
		return 0;
	}
	while (*s)
	{
		if (*(s + 1) != ' '&& *(s + 1) != '\0')
		{
			if (*(s) == ' ')
			{
				count++;
			}
		}
		s++;
	}
	return (*p == ' ') ? count : (count + 1);
}

int main()
{
	char str[] = "";
	int n = countSegments(str);
	printf("%d\n", n);
	return 0;
}