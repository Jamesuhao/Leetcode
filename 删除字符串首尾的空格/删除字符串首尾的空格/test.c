#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

char *Del_space(char *str,int k)
{
	int i = 0;
	int j = k-1;
	int cur = 0;
	char *p1 = NULL;
	char *p2 = NULL;
	if (str == NULL)
	{
		return "error";
	}
	//ɾ���ַ����е�һ���ַ�ǰ�Ŀո�
	while (str[i] == '*')
	{
		i++;
	}
	//ɾ���ַ��������һ���ַ���Ŀո�
	while (str[j] == '*')
	{
		j--;
	}
	//�޸�str�е��ַ�������ɾ����β�ո����ַ������´洢��str��
	for (cur = 0; i <= j; i++, cur++)
	{
		str[cur] = str[i];
	}
	str[cur] = '\0';
	//p1��¼�ַ����׵�ַ  p2�����޸��ַ���
	p1 = p2 = str;
	//ɾ���ַ����м�ո񣬲�����һ���ո�
	while (*str)
	{
		if (*str != '*')
		{
			*p2 = *str;
			p2++;
		}
		else
		{
			//����һ���ո�
			if (*(p2 - 1) != '*')
			{
				*p2 = *str;
				p2++;
			}
		}
		str++;
	}
	*p2 = '\0';
	return p1;
}
int main()
{
	int k = 0;
	char arr[] = "*****as****adadq*****";
	k = strlen(arr);
	char *p = Del_space(arr,k);
	printf("%s\n", p);
	return 0;
}