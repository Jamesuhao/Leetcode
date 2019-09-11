#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
//示例 :
//输入 : 38
//输出 : 2
//解释 : 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
//循环：
int addDigits1(int num)
{
	if (num<10)
	{
		return num;
	}
	while (num / 10)
	{
		num = num / 10 + num % 10;
	}
	return num;
}
//递归
int addDigits2(int num)
{
	if (num<10)
	{
		return num;
	}
	return addDigits(num / 10 + num % 10);

}
//规律法：
int addDigits3(int num)
{
	if (num<10)
	{
		return num;
	}
	int ret = num % 9;
	if (ret == 0)
	{
		return 9;
	}
	return ret;
}
int main()
{
	int num = 38;
	int ret = addDigits3(num);
	printf("%d\n", ret);
	return 0;
}