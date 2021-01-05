#include<stdio.h>
#include<stdlib.h>
typedef struct Tree
{
	char data;
	struct Tree* left;
	struct Tree* right;
}tree;
tree* creat()//use recurrence to creat a tree
{
	char val;
	scanf_s("%c", &val);
	if (val == '#') return NULL;// use # to find the leaf
	else {
		tree* b = NULL;
		b = (tree*)malloc(sizeof(tree));		
		if (b==NULL) exit(0);
		else
		{
			b->data = val;
			b->right = creat();
			b->left = creat();
		}		
		return b;
	}
}
tree* find(char target, tree* tree)// the use of binary tree in find something
{
	if (tree == NULL) return NULL;
	else {
		if (tree->data > target) return find(target, tree->left);// i do not know why there is a 'return'.
		else if (tree->data < target) return find(target, tree->right);
		else 
		{
			return tree;
		}
	}
}
void first(tree* a)// the traversal of tree
{
	if (a==NULL) return;
	else
	{
		printf("%c", a->data);
		first(a->right);
		first(a->left);
	}	
}
tree* findmin(tree* a) // find min
{
	if (a->left == NULL) return a;
	else {
		return findmin(a->left);
	}
}
int later(tree* a)
{
	int i = 0;
	if (!a) return 0;
	else
	{
		i = a->data+later(a->left) + later(a->right);
	}
	return i;
}
tree* insert(char a, tree* b)//insert element
{
	if (b == NULL)// if we find the leaf
	{
		tree* t = NULL;
		t = (tree*)malloc(sizeof(tree));
		if (t == NULL) exit(0);
		else {
			t->data = a;
			t->left = NULL;
			t->right = NULL;
		}		
		return t;
	}
	else // if we do not find the leaf 
	{
		if (b->data > a) {
			b->left = insert(a, b->left);
		}
		else {
			if (b->data < a) {
				b->right = insert(a, b->right);
			}
		}
		return b;
	}		
}
int layer(tree* b,int c)
{
	int leftlayer, rightlayer;
	if (b == NULL) return c;
	else {
		++c;
		 leftlayer =layer(b->left, c);
		 rightlayer = layer(b->right, c);
	}
	return leftlayer > rightlayer ? leftlayer : rightlayer;
}
tree* deletek(tree* a,char data)// delet a element
{
	if (a == NULL) exit(0);
	else 
	{
		if (data > a->data) a->right = deletek(a->right, data);
		else if (data < a->data) a->left = deletek(a->left, data);
		else// find the element
		{
			if (a->right != NULL && a->left != NULL) // not a leaf 
			{
				tree* doubl = a->right; // use right tree data to replace the data
				while (doubl->left != NULL)
				{
					doubl = doubl->left;
				}
				a->data = doubl->data;
				a->right = deletek(a->right, a->data); // delete the data;

			}
			else // it is a leaf
			{
				tree* t = a;
				if (a->right == NULL) a = a->left;
				else  if (a->left == NULL) a = a->right;
				free(t);
			}
		}
		return a;
	}
}
int main()
{
	int i;
	char b;
	tree* aa;
	tree* a = NULL;
	a = creat();
	printf("请输入要找的元素");
	scanf_s(" %c", &b);
	tree* k = NULL;
	if ((k = find(b, a)) == NULL)
	{
		printf("没有该元素");
	}
	else {
		printf("改元素的地址为 %d,值为 %c", k,*k);
	}
	aa = findmin(a);
	printf("\n最小值为%c", aa->data);
	printf("\n请输入要插入的元素\n");
	char kk;
	scanf_s(" %c",&kk);
	insert(kk, a);
	first(a);
	int layerr = layer(a, 0);
	printf("层数为%d", layerr);
	printf("请输入要删的元素\n");
	char number;
	scanf_s(" %c", &number);
	deletek(a, number);
	first(a);
}