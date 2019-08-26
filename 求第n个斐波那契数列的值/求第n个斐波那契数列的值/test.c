#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//斐波那契数列
//指的是这样一个数列：1、1、2、3、5、8、13、21、34、……
//在数学上，斐波纳契数列以如下被以递推的方法定义：F(1)=1，F(2)=1, F(n)=F(n-1)+F(n-2)（n>=3，n∈N*）。

//非递归
int Fibonacci(n)
{
	int f1 = 1;
	int f2 = 1;
	int fib = 0;
	int count = 2;
	if (n == 1 || n == 2)
	{
		return f1;
	}
	if (n  >= 3)
	{
		while (count < n)
		{
			fib = f1 + f2;
			f1 = f2;
			f2 = fib;
			count++;
		}
	}
	return fib;
}
//斐波那契数列前n项和
int FibonacciSum(int n)
{
	return Fibonacci(n + 2) - 1;
}
int main()
{
	int n = 0;
	int ret = 0;
	int sum = 0;
	printf("请输入n的值：");
	scanf("%d", &n);
	ret = Fibonacci(n);
	sum = FibonacciSum(n);
	printf("%d %d\n", ret, sum);
	return 0;
}

//递归
int Fibonacci(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
//前n项和
int FfibonacciSum(n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += Fibonacci(i);  //累加前n项
	}
	return sum;
}
int main()
{
	int n = 0;
	int ret = 0;
	int sum = 0;
	printf("请输入n的值：");
	scanf("%d", &n);
	ret = Fibonacci(n);
	sum =FfibonacciSum(n);
	printf("%d %d\n", ret, sum);
	return 0;
}
