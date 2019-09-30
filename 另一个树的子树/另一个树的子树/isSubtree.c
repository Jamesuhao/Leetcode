#include<stdio.h>
#include<stdbool.h>
typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
bool isSameTree(TreeNode* s, TreeNode* t)
{
	if (s == NULL && t == NULL)
	{
		return true;
	}
	if (s == NULL && t != NULL)
	{
		return false;
	}
	if (s != NULL && t == NULL)
	{
		return false;
	}
	if (s->val == t->val)
	{
		return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
	}
	else
	{
		return false;
	}
}
bool isSubTree(TreeNode* s, TreeNode* t)
{
	if (s == NULL)
	{
		return false;
	}
	if (s->val == t->val && isSameTree(s, t))
	{
		return true;
	}
	return isSubTree(s->left, t) || isSubTree(s->right, t);
}
