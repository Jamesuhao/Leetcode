#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int pow(int a, int b)
//{
//	int z = 1;
//	for (int i = 0; i < b; i++)
//	{
//		z = z*a;
//	}
//	return z;
//}
int mypwo(int x, int y)
{
	int tmp = 0;
	int result = 0;
	if (y == 1)
	{
		return x;
	}
	mypow(x, y / 2);
	if (x & 1 == 0)
	{
		result = tmp*tmp;
	}
	else
	{
		result = x*tmp*tmp;
	}
	return result;
}
int  main()
{
	int x = 0;
	int y = 0;
	int val = 0;
	printf("ÊäÈëx,yµÄÖµ:\n");
	scanf("%d %d", &x, &y);
	val = pow(x, y);
	printf("z=%d",val );
}
