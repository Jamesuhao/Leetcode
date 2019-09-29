//��Ŀ����
//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� �������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������
//�������� :
//�������1���ַ��������Ȳ�����100��
//������� :
//�����ж���������ݣ�����ÿ�����ݣ�
//����������ַ���������������������������У�ÿ���ַ����涼��һ���ո�
//ÿ��������ռһ�С�
//ʾ��1
//����
//abc##de#g##f###
//���
//c b e g d f a
#include<stdio.h>
#include<malloc.h>
typedef struct BinaryTreeNode
{
	char _data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinaryTreeNode;
BinaryTreeNode* BinaryTreeCreate(char* str, int* pi)
{
	if (str[*pi] != '#')
	{
		BinaryTreeNode* root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		root->_data = str[*pi];
		++(*pi);
		root->left = BinaryTreeCreate(str, pi);
		++(*pi);
		root->right = BinaryTreeCreate(str, pi);
		return root;
	}
	else
	{
		return NULL;
	}
}
void Inorder(BinaryTreeNode* root)
{
	if (root != NULL)
	{
		Inorder(root->left);
		printf("%c ", root->_data);
		Inorder(root->right);
	}
}
//abc##de#g##f###
int main()
{
	char str[101] = { 'a','b','c','#','#','d','e','#','g','#','#','f','#','#','#' };
	int i = 0;
	//�����ַ���
	//scanf("%s", str);
	//����������
	BinaryTreeNode* root = BinaryTreeCreate(str, &i);
	//��ӡ������
	Inorder(root);
	printf("\n");
	return 0;
}