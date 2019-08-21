#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int reverse(int x)
{
	int tmp = 0;
	long rev = 0;
	while (x != 0)
	{
		tmp = x % 10;
		x = x / 10;
		rev = rev * 10 + tmp;
		if (rev>(signed int)0x7fffffff || rev<(signed int)0x80000000)
		{
			return 0;
		}

	}
	return rev;

}
