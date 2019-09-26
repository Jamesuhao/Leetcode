#include<stdio.h>
#include<assert.h>
char* removeDuplicates(char* S)
{
	int prev = 0;
	int next = 0;
	char ch;
	char top ;
	assert(S);
	while (ch = S[next++])
	{
		if (prev == 0)
		{
			top = 0;
		}
		else
		{
			top = S[prev - 1];
		}
		if (top == ch)
		{
			prev--;
		}
		else
		{
			S[prev++] = ch;
		}
	}
	S[prev] = 0;
	return S;
}
int main()
{
	char s[] = "abbaca";
	char* s1 = removeDuplicates(s);
	printf("%s\n", s1);
	return 0;
}
