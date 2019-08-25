 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int pow(int n)
//{
//	int i = 0;
//	if (n < 1)
//	{
//		return 0;
//	}
//	for (i = 0; i < 32; i++)
//	{
//		if (i == n)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
int pow(int n)
{
	int i = 0;
	if (n < 1)
	{
		return 0;
	}
	for (i = 0; i < 32; i<<=1)
	{
		if (i == n)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	printf("%d\n", pow(4));
}