#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//µÝ¹é
int JumpFloor(int n)
{
	int step = 0;
	if (n <= 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return n;
	}
	else
	{
		step = JumpFloor(n - 1) + JumpFloor(n - 2);
	}
	return step;
}
//·ÇµÝ¹é
int JumpFloor(int n)
{
	int i = 0;
	int f1 = 1;
	int f2 = 2;
	int f3 = 0;
	if (n <= 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return n;
	}
	for (i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}
int main()
{
	int n = 0;
	int x = 0;
	scanf("%d", &n);
	x = JumpFloor(n);
	printf("%d\n", x);
	return 0;
}