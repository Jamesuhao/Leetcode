#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//示例 1:
//输入 : "A man, a plan, a canal: Panama"
//输出 : true
//示例 2 :
//输入 : "race a car"
//输出 : false
//思路：
//设置左、右双指针，向中间判断；
//跳过非数字字母的字符；
//将字母全部转化为小写体，之后判断
int isPalindrome(char * s)
{
	int start = 0;
	int index = 0;
	int end = strlen(s) - 1;
	int str[128];
	if (s == NULL)
	{
		return 0;
	}
	for (index = 0; index < 128; index++)
	{
		if ((48 <= index && index <= 57) || (65 <= index && index <= 90) || (97 <= index && index <= 122))
		{
			str[index] = 0;
		}
		else
		{
			str[index] = 1;
		}
	}
	while (start < end)
	{
		while (str[s[start]] && start<end)
		{
			start++;
		}
		while (str[s[end]] && start<end)
		{
			end--;
		}
		if (s[start] != s[end] && s[start] != (s[end] ^ 0x20))
		{
			return 0;
		}
		start++;
		end--;
	}
	return 1;
}
int main()
{
	char s[] = "A man, a plan, a canal: Panama";
	int x = isPalindrome(s);
	if (x == 1)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}