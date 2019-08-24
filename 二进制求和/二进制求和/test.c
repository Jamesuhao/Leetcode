#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * addBinary(char * a, char * b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	char carry = '0';
	char pa;
	char pb;
	int len = len1 > len2 ? len1 : len2;

	if (a == NULL || b == NULL)
	{
		return NULL;
	}
	char *res = (char *)malloc(sizeof(char)*(len + 2));
	res[++len] = 0;
	while (len > 1 || carry == '1')
	{
		pa = len1 > 0 ? a[--len1] : '0';
		pb = len2 > 0 ? b[--len2] : '0';
		res[--len] = pa^pb^carry;
		carry = (pa&carry) | (pb&carry) | (pa&pb);
	}
	return res + len;

}
int main()
{
	char a[] = "1";
	char b[] = "111";
	char *p = addBinary(a, b);
	printf("%s\n", p);
	return 0;
}