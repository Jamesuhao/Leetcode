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
	printf("��������Ҫ�жϵ���: ");
	scanf("%d", &a);
	value = Judge_palindrome(a);
	if (value)
	{
		printf("%d�ǻ�����\n", a);
	}
	else
	{
		printf("%d���ǻ�����\n", a);
	}
	return 0;
}