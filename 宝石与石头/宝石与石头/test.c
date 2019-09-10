#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
//J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头
//示例 1:
//输入 : J = "aA", S = "aAAbbbb"
//输出 : 3
//示例 2 :
//输入 : J = "z", S = "ZZ"
//输出 : 0
//注意 :
//S 和 J 最多含有50个字母。
//J 中的字符不重复。
//思路：
//将J中的字符串作为新数组的下标，并给该下标位置元素+1，遍历S，S中为1的即为题目所需
int numJewelsInStones(char * J, char * S)
{
	int arr[128] = { 0 };
	int count = 0;
	if (J == NULL || S == NULL)
	{
		return 0;
	}
	while (*J)
	{
		++arr[(*J)];
		J++;
	}
	while (*S)
	{
		if (arr[*S] == 1)
		{
			count++;
		}
		S++;
	}
	return count;
}

int main()
{
	char str1[] = "aA";
	char str2[] = "aAAbbbb";
	int ret = numJewelsInStones(str1, str2);
	printf("%d\n", ret);
	return 0;
}

