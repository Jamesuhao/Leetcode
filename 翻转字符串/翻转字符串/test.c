#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
//示例 1：
//输入：["h", "e", "l", "l", "o"]
//输出：["o", "l", "l", "e", "h"]
//示例 2：
//输入：["H", "a", "n", "n", "a", "h"]
//输出：["h", "a", "n", "n", "a", "H"]
void reverseString(char* s, int sSize)
{
	int len = sSize-1;
	int i = 0;
	if (s == NULL || sSize == 0)
	{
		return ;
	}

	for ( ; i < sSize ; i++)
	{
		s[i] ^= s[len];
		s[len] ^= s[i];
		s[i] ^= s[len--];
	}
}

int main()
{
	char str[] = "HannaH";
	int len = strlen(str);
	reverseString(str, len);
	printf("%s\n", str);
	return 0;
}