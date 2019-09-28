#include<stdio.h>
#include<malloc.h>
//����һ���������������������� ������
//ʾ�� :
//����: [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//	���: [1, 3, 2]
	/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct BinaryTreeNode
{
	int val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinaryTreeNode;
int BinaryTreeSize(BinaryTreeNode* root)
{
	if (root==NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
void preOrder(BinaryTreeNode* root, int* a, int* pi)
{
	if (root)
	{
		preOrder(root->left, a, pi);
		a[*pi] = root->val;
		++(*pi);
		preOrder(root->right, a, pi);
	}
}
int* inorderTraversal(BinaryTreeNode* root, int* returnSize)
{
	int i = 0;
	int* a;
	*returnSize = BinaryTreeSize(root);
	a = (int*)malloc(sizeof(int) * (*returnSize));
	preOrder(root, a, &i);
	return a;
}