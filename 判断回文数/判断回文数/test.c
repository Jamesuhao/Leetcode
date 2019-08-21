#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int  Judge_palindrome(unsigned int a)
{
	int tmp = reverse(a);
	//unsigned int n = a;
	//unsigned int tmp = 0;
	//while (n)
	//{
	//	tmp = (tmp * 10 )+ (n % 10);
	//	n = n / 10;
	//}
	return (tmp == a);
}
int  main()
{
	unsigned int a = 0;
	int value = 0;
	printf("请输入需要判断的数: ");
	scanf("%d", &a);
	value = Judge_palindrome(a);
	if (value)
	{
		printf("%d是回文数\n", a);
	}
	else
	{
		printf("%d不是回文数\n", a);
	}
	return 0;
}