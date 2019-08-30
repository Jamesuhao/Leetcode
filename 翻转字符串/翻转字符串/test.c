#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
//����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���
//ʾ�� 1��
//���룺["h", "e", "l", "l", "o"]
//�����["o", "l", "l", "e", "h"]
//ʾ�� 2��
//���룺["H", "a", "n", "n", "a", "h"]
//�����["h", "a", "n", "n", "a", "H"]
void reverseString(char* s, int sSize)
{
	int len = sSize-1;
	int i = 0;
	if (s == NULL || sSize == 0)
	{
		return ;
	}

	for ( ; i < sSize ; i++)
	{
		s[i] ^= s[len];
		s[len] ^= s[i];
		s[i] ^= s[len--];
	}
}

int main()
{
	char str[] = "HannaH";
	int len = strlen(str);
	reverseString(str, len);
	printf("%s\n", str);
	return 0;
}