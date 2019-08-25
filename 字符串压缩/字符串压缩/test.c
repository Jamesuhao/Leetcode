#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

char *Str_compress(char *str, int len)
{
	char *p1 = str;
	char *p2 = str;
	char count = 1;
	int i = 0;
	assert(str);
	while (*str)
	{
		if (*str == *(str + 1))
		{
			count++;
		}
		else 
		{
			*p2 =  count+'0';
			*(p2+1) = *str;
			p2 += 2;
			count = 1;
		}
		str++;
	}
	*p2 = '\0';
	return p1;
}

int main()
{
	int len = 0;
	char *p = NULL;
	char str[] = "xxxyyyyz";
	len = strlen(str);
	p = Str_compress(str, len);
	printf("%s\n", p);
	return 0;
}