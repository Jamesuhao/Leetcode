#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
//如果不存在最后一个单词，请返回 0 。
//说明：一个单词是指由字母组成，但不包含任何空格的字符串。
//示例 :
//输入 : "Hello World"
//输出 : 5
int lengthOfLastWord(char * s)
{
	int len = strlen(s);
	int count = 0;
	if (s == NULL)
	{
		return 0;
	}

	while (len)
	{
		if (*(s + len - 1) != ' ')
		{
			count++;
			if (len == 1)
			{
				return count;
			}
			if (*(s + len - 2) == ' ')
			{
				return count;
			}
		}

		len--;
	}
	return 0;
}

int main()
{
	char str[] = "Hello World";
	int len = lengthOfLastWord(str);
	printf("%d\n", len);
	return 0;
}