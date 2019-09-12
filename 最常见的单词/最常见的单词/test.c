#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//题目：
//给定一个段落(paragraph) 和一个禁用单词列表(banned)。返回出现次数最多，同时不在禁用列表中的单词。题目保证至少有一个词不在禁用列表中，而且答案唯一。
//禁用列表中的单词用小写字母表示，不含标点符号。段落中的单词不区分大小写。答案都是小写字母
//示例：
//输入 :
//paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
//banned = ["hit"]
//输出 : "ball"
// 解释 :
//	"hit" 出现了3次，但它是一个禁用的单词。
//	"ball" 出现了2次(同时没有其他单词出现2次)，所以它是段落里出现次数最多的，且不在禁用列表中的单词。
//	注意，所有这些单词在段落里不区分大小写，标点符号需要忽略（即使是紧挨着单词也忽略， 比如 "ball,"），
//	"hit"不是最终的答案，虽然它出现次数更多，但它在禁用单词列表中
//说明：
//1 <= 段落长度 <= 1000.
//1 <= 禁用单词个数 <= 100.
//1 <= 禁用单词长度 <= 10.
//答案是唯一的, 且都是小写字母 (即使在 paragraph 里是大写的，即使是一些特定的名词，答案都是小写的。)
//paragraph 只包含字母、空格和下列标点符号!? ',;.
//不存在没有连字符或者带有连字符的单词。
//单词里只包含字母，不会出现省略号或者其他标点符号。

//将字符中大写字母转换成小写字母
void toLowerCase(char * str)
{
	char *ret = str;
	if (str == NULL)
	{
		return;
	}
	while (*str)
	{
		if (*str >= 65 && *str <= 90)
		{
			*str += 32;
		}
		str++;
	}
}
//将字符串分割成字符数组
void split(char *src, const char *separator, char **dest, int *num)
{
	/*
	src：源字符串的首地址
	spearator：指定的分割字符
	dest：接受子字符串的数组
	Num：分割后桌子·子字符串的个数
	*/
	char *pNext = NULL;
	int count = 0;
	if (src == NULL || strlen(src) == 0)
	{
		return;
	}
	if (separator == NULL || strlen(separator) == 0)
	{
		return;
	}
	pNext = (char *)strtok(src, separator);
	while (pNext!=NULL)
	{
		*dest++ = pNext;
		++count;
		pNext = (char *)strtok(NULL, separator);
	}
	*num = count;
}
unsigned int BKDRHash(char *str)
{
	unsigned int seed = 131; 
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * seed + (*str++);
	}

	return (hash & 0x7FFFFFFF);
}
int main()
{
	int i = 0;
	unsigned int p = 0;
	char paragraph[] = "Bob hit a ball, the hit BALL flew far after it was hit";
	char *rev[20] = { 0 };
	int num = 0;
	toLowerCase(paragraph);
	split(paragraph, ", ", rev, &num);
	p=BKDRHash(paragraph);
	for (i = 0; i < num; i++)
	{
		printf("%s\n", rev[i]);
	}
	return 0;
}
