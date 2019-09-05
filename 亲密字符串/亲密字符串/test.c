#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false 。
//示例 1：
//输入： A = "ab", B = "ba"
//输出： true
//示例 2：
//输入： A = "aaaaaaabc", B = "aaaaaaacb"
//输出： true
//示例 3：
//输入： A = "", B = "aa"
//输出： false
//思路：分三种情况：
//1.字符串长度不相等, 直接返回false
//2.字符串相等的时候, 只要有重复的元素就返回true
//3.A, B字符串有不相等的两个地方, 需要查看它们交换后是否相等即可.
char * buddyStrings(char * A, char * B)
{
	int i = 0;
	int j = 0;
	int count = 0;
	int max = 0;
	int  *dex = (int *)malloc(2 * sizeof(int));
	int  *num = (int *)malloc(27 * sizeof(int));
	memset(dex, 0, 2 * sizeof(int));
	memset(num, 0, 27 * sizeof(int));
	int len1 = strlen(A);
	int len2 = strlen(B);
	if (A == NULL || B == NULL || len1 != len2)
	{
		return "false";
	}
	for (i = 0; i < len1; i++)
	{
		if (A[i] != B[i])
		{
			count++;
			if (count>2)
			{
				return "false";
			}
			dex[j++] = i;
		}
		num[A[i] - 'a']++;
		if (num[A[i] - 'a'] > max)
		{
			max = num[A[i] - 'a'];
		}
	}
	if (count == 0 && max >= 2)
	{
		return "true";
	}
	else if (count == 2)
	{
		A[dex[0]] ^= A[dex[1]];
		A[dex[1]] ^= A[dex[0]];
		A[dex[0]] ^= A[dex[1]];
		for (i = 0; i < len1; i++)
		{
			if (strcmp(A, B) == 0)
			{
				return "true";
			}
		}
	}
	return "false";
}

int main()
{
	char A[] = "ab";
	char N[] = "ab";
	char *p = buddyStrings(A, N);
	printf("%s\n", p);
	return 0;
}