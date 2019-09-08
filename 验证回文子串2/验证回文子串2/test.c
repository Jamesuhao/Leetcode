#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
//示例 1:
//输入 : "aba"
//输出 : True
//示例 2 :
//输入 : "abca"
//输出 : True
//解释 : 你可以删除c字符。
//解题思路：
//判断回文串显然是用双指针的，index从前往后遍历，len从后往前遍历。
//以"abdda"这个串为例，此时index指向'b'，len指向'd'，发现不对了。但是有一次删除的机会，
//此时子串范围为(index + 1, len)或(index, len - 1)的俩子串只要有任意一个是回文串，则结果就是回文串，否则就不是。
int IsPalindrome(char *s, int index, int len)
{
	while (index<len)
	{
		if (s[index] != s[len])
		{
			return 0;
		}
		index++;
		len--;
	}
	return 1;
}
int validPalindrome(char * s)
{
	int index = 0;
	int len = strlen(s)-1;
	while (index < len)
	{
		if (s[index] != s[len])
		{
			return IsPalindrome(s, index + 1, len) || IsPalindrome(s, index, len - 1);
		}
		index++;
		len--;
	}
	return 1;
}

int main()
{
	char s[] = "abdda";
	int p = validPalindrome(s);
	printf("%d\n", p);
	return 0;
}