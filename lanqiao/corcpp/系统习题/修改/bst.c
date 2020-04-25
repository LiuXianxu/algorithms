//二叉排序树的实现
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}BSTNode;
//typedef BSTNode* bintree;
//int m=0;
//BSTNode *bt;

void InsertBST(BSTNode **bt,int e)//传进来的是指针的地址 
{
	if(*bt==NULL) //*bt指向结构体的指针 
	{
		*bt=(BSTNode *)malloc(sizeof(BSTNode));
		(*bt)->data=e;
		(*bt)->lchild=(*bt)->rchild=NULL;
		//m++;
		return;
	}
	else if(e==(*bt)->data) 
		return;
	else if(e<(*bt)->data)
		InsertBST(&(*bt)->lchild,e);
	else
		InsertBST(&(*bt)->rchild,e);//(*bt)->rchild指向右子树的指针,在前面加取地址符&，得到指针的地址  
}

BSTNode* CreateBST(int a[],int n)
{
	BSTNode *bt=NULL;
	int i=0;
	while(i<n)
	{
		InsertBST(&bt,a[i]);
		i++;
	}

	return bt;
}

void InOrder(BSTNode *bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->lchild);
		printf("%-3d",bt->data);
		InOrder(bt->rchild);
	}
}

int main()
{
	BSTNode *bt;
	int a[5]={3,5,2,9,6};
	bt=CreateBST(a,5);
	InOrder(bt);
	return 0;
}
