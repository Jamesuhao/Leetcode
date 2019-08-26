#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//给定一组字符，使用原地算法将其压缩。
//压缩后的长度必须始终小于或等于原数组长度。
//数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
//在完成原地修改输入数组后，返回数组的新长度。
//示例 1：
//输入：
//["a", "a", "b", "b", "c", "c", "c"]
//输出：
//返回6，输入数组的前6个字符应该是：["a", "2", "b", "2", "c", "3"]
//说明：
//"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
//示例 2：
//输入：
//["a"]
//输出：
//返回1，输入数组的前1个字符应该是：["a"]
//说明：
//没有任何字符串被替代

int add_num(char *str, char ch, int num)
{
	if (num == 1)
	{
		str[0] = ch;
		return 1;
	}
	else if (num < 10)
	{
		str[0] = ch;
		str[1] = (char)num + '0';
		return 2;
	}
	else
	{
		sprintf(str, "%c%d", ch, num);
		return strlen(str);
	}
}
int compress(char* chars, int charsSize)
{
	int fast = 0;
	int slow = 0;
	int num = 1;
	if (chars == NULL || charsSize == 0)
	{
		return 0;
	}
	for (fast = 0; fast < charsSize; ++fast)
	{
		if ((fast < charsSize - 1) && (chars[fast] == chars[fast + 1]))
		{
			++num;
		}
		else
		{
			slow += add_num(chars + slow, chars[fast], num);
			num = 1;
		}
	}
	return slow;
}

int main()
{ 
	char chars[] = { 'a', 'a', 'b', 'c', 'c', 'c' };
	int len = sizeof(chars) / sizeof(chars[0]);
	int p = compress(chars, len);
	int i = 0; 
	for (i = 0; i < p; i++)
	{
		printf("%c", chars[i]);
	}
	printf("\n");
	return 0;
}