#include<stdio.h>
#include<string.h>
//����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��
//ʾ�� 1��
//���룺"ab-cd"
//�����"dc-ba"
//ʾ�� 2��
//���룺"a-bC-dEf-ghIj"
//�����"j-Ih-gfE-dCba"
int isword(char ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	{
		return 1;
	}
	return 0;
}
char* reverseOnlyLetters(char* S)
{
	char* ret = S;
	int i = 0;
	int j = strlen(S) - 1;
	if (S == NULL)
	{
		return NULL;
	}
	while (i < j)
	{
		if (isword(S[i]) && isword(S[j]))
		{
			S[i] ^= S[j];
			S[j] ^= S[i];
			S[i] ^= S[j];
			i++;
			j--;
		}
		if (!isword(S[i]))
		{
			i++;
		}
		if (!isword(S[j]))
		{
			j--;
		}
	}
	return ret;
}
int main()
{
	char str[] = "ab-cd";
	char *ret = reverseOnlyLetters(str);
	printf("%s\n", ret);
	return 0;
}