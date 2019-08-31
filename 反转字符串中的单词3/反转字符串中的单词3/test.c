#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
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