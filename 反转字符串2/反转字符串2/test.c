#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//描述
//给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。
//如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。
//要求 :
//该字符串只包含小写的英文字母。
//给定字符串的长度和 k 在[1, 10000]范围内。
//示例:
//输入 : s = "abcdefg", k = 2
//输出 : "bacdfeg"
void reverse_str(char *s, int low, int high)
{
	while (low<high)
	{
		s[low] ^= s[high];
		s[high] ^= s[low];
		s[low] ^= s[high];
		low++;
		high--;
	}
}

char * reverseStr(char * s, int k)
{
	int i = 0;
	int len = strlen(s);
	if (s == NULL)
	{
		return NULL;
	}
	for (i = 0; i<len; i += 2 * k)
	{
		if (i + 2 * k <= len || i + k <= len)
		{
			reverse_str(s, i, i + k - 1);
		}
		else
		{
			reverse_str(s, i, len - 1);
		}
	}
	return s;
}
int main()
{
	char str[] = "abcdefg";
	char *p = reverseStr(str, 2);
	printf("%s\n", str);
	return 0;
}