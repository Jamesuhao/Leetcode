#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//ʾ�� 1:
//���� : "A man, a plan, a canal: Panama"
//��� : true
//ʾ�� 2 :
//���� : "race a car"
//��� : false
//˼·��
//��������˫ָ�룬���м��жϣ�
//������������ĸ���ַ���
//����ĸȫ��ת��ΪСд�壬֮���ж�
int isPalindrome(char * s)
{
	int start = 0;
	int index = 0;
	int end = strlen(s) - 1;
	int str[128];
	if (s == NULL)
	{
		return 0;
	}
	for (index = 0; index < 128; index++)
	{
		if ((48 <= index && index <= 57) || (65 <= index && index <= 90) || (97 <= index && index <= 122))
		{
			str[index] = 0;
		}
		else
		{
			str[index] = 1;
		}
	}
	while (start < end)
	{
		while (str[s[start]] && start<end)
		{
			start++;
		}
		while (str[s[end]] && start<end)
		{
			end--;
		}
		if (s[start] != s[end] && s[start] != (s[end] ^ 0x20))
		{
			return 0;
		}
		start++;
		end--;
	}
	return 1;
}
int main()
{
	char s[] = "A man, a plan, a canal: Panama";
	int x = isPalindrome(s);
	if (x == 1)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	return 0;
}