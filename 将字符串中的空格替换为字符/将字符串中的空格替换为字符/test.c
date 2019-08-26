#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>


void ReplaceBlank(char *str, int len)
{
	int i = 0;
	int NumBlank = 0;
	int newlen = 0;
	int mlen = 0;
	int indexofMylen = 0;
	int indexofNewlen = 0;
	assert(str != NULL);
	while (str[i] != '\0')
	{
		++mlen;
		if (str[i] == ' ')
		{
			++NumBlank;
		}
		i++;
	}
	newlen = 2 * NumBlank + mlen;
	if (newlen > len)
	{
		return;
	}
	indexofMylen = mlen;
	indexofNewlen = newlen;
	while ((indexofMylen >= 0) && (indexofNewlen>indexofMylen))
	{
		if (str[indexofMylen] == ' ')
		{
			str[indexofNewlen--] = '0';
			str[indexofNewlen--] = '2';
			str[indexofNewlen--] = '%';
		}
		else
		{
			str[indexofNewlen] = str[indexofMylen];
			indexofNewlen--;
		}
		indexofMylen--;
	}
}

int main()
{
	int len = 0;
	char str[12] = "abc de f";
	len = sizeof(str) / sizeof(str[0]);
	ReplaceBlank(str,len);
	printf("%s\n", str);
	return 0;
}