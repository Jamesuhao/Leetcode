#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//O(n^2)
//char * Del_string(char *str1, char*str2)
//{
//	char *p1 = str1;
//	char *p2 = str1;
//	while (*str2)
//	{
//		str1 = p1;
//		p2 = p1;
//		while (*str1)
//		{
//			if (*str1 != *str2)
//			{
//				*p2 = *str1;
//				p2++;
//			}
//			str1++;
//		}
//		*p2 = '\0';
//		str2++;
//	}
//	return p1;
//}
//O(n)
//char * DeleteRepeateChar(char *str1, char*str2)
//{
//	char *p = str1;
//	char *q = str1;
//	int str[256] = { 0 };
//	while (*str2!='\0')
//	{
//		str[*str2] = 1;
//		str2++;
//	}
//	while (*p != '\0')
//	{
//		if (str[*p] != 1)
//		{
//			*q++ = *p;
//		}
//		p++;
//	}
//	*q = '\0';
//	return str1;
//}
//int main()
// {
//	char arr1[] = "They are students.";
//	char arr2[] = "aeiou";
//	char *p = DeleteRepeateChar(arr1, arr2);
//	printf("%s\n", p);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	char str[] = "abaccdeff";
//	int len = strlen(str);
//	i = Find_numbers(str, len);
//	printf("%c\n", str[i]);
//	return 0;
//}
//int GetGount(int *arr1,int *arr2 ,int n)
//{
//	int i = 0;
//	int j = 0;
//	arr2[0] = 0;
//	arr2[n] = -1;
//	for (i = 0; i < n; i++)
//	{
//		if (arr2[i] == -1)
//		{
//			continue;
//		}
//		for (j = 1; (j < arr1[i] )&& (i + j <= n); j++)
//		{
//			if (arr2[i + j] == -1 || arr2[i + j]>arr2[i] + 1)
//			{
//				arr2[i + j] = arr2[i] + 1;
//			}
//		}
//	}
//	if (arr2[n] == -1)
//	{
//		return -1;
//	}
//	return arr2[n];
//}
//int  main()
//{
//	int arr1[1000] = { 2,0,1,1,1 };
//	int arr2[1000] = { -1};
//	int count = 0;
//	count = GetGount(arr1, arr2, 5);
//	printf("%d\n", count);
//	return 0;
//}
int read(char a)
{
	switch (a)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default:  printf("Input Error!\n");
		return 0;
	}
}

int romantoint(char *s)
{
	int len = 0;
	int pos = 0;
	int sum = 0;
	int next = 0;
	for (len = 0; s[len] != '\0'; len++);
	while (pos != len)
	{
		printf("pos:%d\n", pos);

			if ((s[pos + 1] != '\0')&&(read(s[pos + 1])>read(s[pos])))
			{
				next = read(s[pos + 1]) - read(s[pos]);
				pos += 2;
				sum += next;
				continue;
			}
		
		next = read(s[pos]);
		pos++;
		sum += next;
	}
	return sum;
}
int main()
{
	char str[30] = "V";
	int p =romantoint(str);
	printf("%d\n", p);
	return 0;
}
