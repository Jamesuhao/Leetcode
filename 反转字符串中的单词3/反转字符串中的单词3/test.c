#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//示例 1 :
//输入 : "Let's take LeetCode contest"
//输出 : "s'teL ekat edoCteeL tsetnoc"
//注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
void reverse_string(char *s, int low, int high)
{
	char tmp = 0;
	if (s == NULL)
	{
		return;
	}
	while (low < high)
	{
		s[low] ^= s[high];
		s[high] ^= s[low];
		s[low] ^= s[high];
		//tmp = s[low];
		//s[low] = s[high];
		//s[high] = tmp;
		low++;
		high--;
	}
}
char * reverseWords(char * s)
{
	int i = 0;
	int j = 0;
	int len = strlen(s);
	while (i < len&&j <= len)
	{
		if (s[j] == ' '||s[j]=='\0')
		{
			reverse_string(s, i, j - 1);
			i = j + 1;
			j = j + 1;
		}
		else
		{
			j++;
		}
	}
	return s;
}
int main()
{
	char s[] = "Let's take LeetCode contest";
	char *p = reverseWords(s);	
	printf("%s\n", p);
	return 0;
}