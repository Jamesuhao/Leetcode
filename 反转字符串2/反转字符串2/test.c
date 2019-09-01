#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//����
//����һ���ַ�����һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰk���ַ����з�ת��
//���ʣ������ k ���ַ�����ʣ�������ȫ����ת�������С�� 2k �����ڻ���� k ���ַ�����תǰ k ���ַ�������ʣ����ַ�����ԭ����
//Ҫ�� :
//���ַ���ֻ����Сд��Ӣ����ĸ��
//�����ַ����ĳ��Ⱥ� k ��[1, 10000]��Χ�ڡ�
//ʾ��:
//���� : s = "abcdefg", k = 2
//��� : "bacdfeg"
void reverse_str(char *s, int low, int high)
{
	while (low<high)
	{
		s[low] ^= s[high];
		s[high] ^= s[low];
		s[low] ^= s[high];
		low++;
		high--;
	}
}

char * reverseStr(char * s, int k)
{
	int i = 0;
	int len = strlen(s);
	if (s == NULL)
	{
		return NULL;
	}
	for (i = 0; i<len; i += 2 * k)
	{
		if (i + 2 * k <= len || i + k <= len)
		{
			reverse_str(s, i, i + k - 1);
		}
		else
		{
			reverse_str(s, i, len - 1);
		}
	}
	return s;
}
int main()
{
	char str[] = "abcdefg";
	char *p = reverseStr(str, 2);
	printf("%s\n", str);
	return 0;
}