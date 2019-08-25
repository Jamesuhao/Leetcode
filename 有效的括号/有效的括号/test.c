#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//1.左括号必须用相同类型的右括号闭合。
//2.左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//示例1：
//输入: "()"
//输出 : true
//示例 2 :
//输入 : "()[]{}"
//输出 : true
//示例 3 :
//输入 : "(]"
//输出 : false
//示例 4 :
//输入 : "([)]"
//输出 : false
//示例 5 :
// 输入 : "{[]}"
//输出 : true
//方法一：数组模拟栈
char* isValid(char * s)
{
	int i = 0;
	int index = 0;
	int len = strlen(s);
	char *ptr = (char *)malloc(len / 2);
	memset(ptr, 0, len / 2);
	for (i = 0; i < len; i++)
	{
		if ((*(s + i) == '(') || (*(s + i) == '{') || (*(s + i) == '['))
		{
			index++;
			*(ptr + index) = *(s + i);
		}
		else if ((*(s + i) == (*(ptr + index) + 1)) || (*(s + i) == (*(ptr + index) + 2)))
		{
			index--;
		}
		else
		{
			return "false";
		}
	}
	if (index)
	{
		return "false";
	}
	return "true";
}
//方法二：栈
struct Stack
{
	//定义栈的存储结构
	char str[10000];
	int top;  //表示栈顶元素的下标，初始为-1
};

char * isValid(char * s)
{
	struct Stack stacks;
	stacks.top = -1;
	int i = 0;
	if (s == NULL)
	{
		return "true";
	}
	else
	{
		if (s[0] == ')' || s[0] == ']' || s[0] == '}')
		{
			//如果第一个元素就是右括号则直接返回false
			return "false";
		}
		while (s[i] != '\0')
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				//若当前元素为左括号，则压栈
				stacks.top++;
				stacks.str[stacks.top] = s[i];
			}
			else
			{
				if (stacks.top == -1)
				{
					//若当前元素不为左括号且栈为空则返回false，例如："[ ( ) ] }"
					return "false";
				}
				else
				{
					if ((stacks.str[stacks.top] == '(' &&s[i] == ')') || (stacks.str[stacks.top] == '{'&& s[i] == '}')
						|| (stacks.str[stacks.top] == '[' && s[i] == ']')){
						//如果当前元素能够和栈顶元素配对，则将栈顶元素出栈，反之返回false
						stacks.top--;
					}
					else
					{
						return "false";
					}
				}
			}
			i++;
		}
		if (stacks.top != -1){
			//若将元素全部遍历后，栈中仍还有元素说明并未全部匹配则返回false
			return "false";
		}
	}
	return "true";
}

int main()
{
	char s[] = "{[]}";
	char *result = isValid(s);
	printf("%s\n", result);
	return 0;
}