#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//求和
int Func1(int a, int b)
{
	int ret = ((a&b) << 1) + (a^b);
	return ret;
}
//求平均数
int Func2(int a, int b)
{
	int ret = (a&b) + ((a^b) >> 1);
	return ret;
}
int main()
{
	int a = 4;
	int b = 6;
	int ret1 = Func1(a, b);
	int ret2 = Func2(a, b);
	printf("ret1=%d ret2=%d\n", ret1, ret2);
	return 0;
}