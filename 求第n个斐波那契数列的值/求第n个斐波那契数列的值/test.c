#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//쳲���������
//ָ��������һ�����У�1��1��2��3��5��8��13��21��34������
//����ѧ�ϣ�쳲��������������±��Ե��Ƶķ������壺F(1)=1��F(2)=1, F(n)=F(n-1)+F(n-2)��n>=3��n��N*����

//�ǵݹ�
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
//쳲���������ǰn���
int FibonacciSum(int n)
{
	return Fibonacci(n + 2) - 1;
}
int main()
{
	int n = 0;
	int ret = 0;
	int sum = 0;
	printf("������n��ֵ��");
	scanf("%d", &n);
	ret = Fibonacci(n);
	sum = FibonacciSum(n);
	printf("%d %d\n", ret, sum);
	return 0;
}

//�ݹ�
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
//ǰn���
int FfibonacciSum(n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += Fibonacci(i);  //�ۼ�ǰn��
	}
	return sum;
}
int main()
{
	int n = 0;
	int ret = 0;
	int sum = 0;
	printf("������n��ֵ��");
	scanf("%d", &n);
	ret = Fibonacci(n);
	sum =FfibonacciSum(n);
	printf("%d %d\n", ret, sum);
	return 0;
}
