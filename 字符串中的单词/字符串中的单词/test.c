#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//ͳ���ַ����еĵ��ʸ���������ĵ���ָ���������Ĳ��ǿո���ַ���
//��ע�⣬����Լٶ��ַ����ﲻ�����κβ��ɴ�ӡ���ַ���
//ʾ�� :
//���� : "Hello, my name is John"
//��� : 5
//˼·��ÿ�γ��ַǿ��ַ���������һ���ǲ��ǿո�����ǣ������µ��ʡ�
int countSegments(char * s)
{
	int count = 0;
	int len = strlen(s);
	char *p = s;
	if (s == NULL || len == 0)
	{
		return 0;
	}
	while (*s)
	{
		if (*(s + 1) != ' '&& *(s + 1) != '\0')
		{
			if (*(s) == ' ')
			{
				count++;
			}
		}
		s++;
	}
	return (*p == ' ') ? count : (count + 1);
}

int main()
{
	char str[] = "";
	int n = countSegments(str);
	printf("%d\n", n);
	return 0;
}