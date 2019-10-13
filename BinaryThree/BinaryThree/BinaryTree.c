#define _CRT_SECURE_NO_WARNINGS

#include"BinaryTree.h"

//int main()
//{
//	TestBinaryTree();
//	system("pause");
//	return 0;
//}
int main()
{
	char str[101];
	int i = 0;
	scanf("%c", str);
	BTNode* a = BinaryTreeCreate(str, &i);
	BinaryTreeInOrder(a);
	return 0;
}

void TestBinaryTree()
{
	int i = 0;
	char pi[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };

	BTNode* a = BinaryTreeCreate(pi, &i);
	BinaryTreePrevOrder(a);
	printf("\n");
	BinaryTreeInOrder(a);
	printf("\n");
	BinaryTreePostOrder(a);
	printf("\n");

	BinaryTreeDestory(&a);
}

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] != '#')
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi);
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else
	{
		return NULL;
	}
}

void BinaryTreeDestory(BTNode** root)
{
	BTNode* curRoot = *root;
	if (*root)
	{
		BinaryTreeDestory(&curRoot->_right);
		BinaryTreeDestory(&curRoot->_left);
		free(curRoot);
		*root = NULL;
	}
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right) + 1;
	}
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root)
	{
		return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
	}
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (root->_data == x)
	{
		return root;
	}
	if (root == NULL)
	{
		return NULL;
	}
	ret = BinaryTreeFind(root->_left, x);
	if (ret)
	{
		return ret;
	}
	ret = BinaryTreeFind(root->_right, x);
	if (ret)
	{
		return ret;
	}
	return NULL;
}


void BinaryTreePrevOrder(BTNode* root)
{
	if (root != NULL)
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
	else
	{
		printf("# ");
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ", root->_data);
		BinaryTreeInOrder(root->_right);
	}
	else
	{
		printf("# ");
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
	else
	{
		printf("# ");
	}
}

void BinaryTreeLevelOrder(BTNode* root)
{
	assert(root);
	char a[100] = 0;
	int cur = 0;
	a[cur] = root->_data;

	if (root->_left)
	{
		a[cur] = root->_left->_data;
		cur++;
	}
	if (root->_right)
	{
		a[cur] = root->_right->_data;
		cur++;
	}
	root = root->_left
}
