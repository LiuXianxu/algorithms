#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int l,r,max,sum;
	struct node * lchild;
	struct node * rchild;
}Vertex;
void create(Vertex **v,int l,int r)
{
	(*v)=(Vertex*)malloc(sizeof(Vertex));
	(*v)->l=l;
	(*v)->r=r;
	(*v)->max=0;
	(*v)->sum=0;
	if(l==r)return;
	int middle =(l+r)/2;
	create(&(*v)->lchild,l,middle);
	create(&(*v)->rchild,middle+1,r);
}
void print(Vertex *v)
{
	if(v!=NULL)
	{
		if(v->lchild!=NULL)
		print(v->lchild);
		printf("l:%d£¬r:%d\n",v->l,v->r);
		if(v->rchild!=NULL)
		print(v->rchild);
	}
}
int main()
{
	Vertex* head;
	create(&head,1,4);
	print(head);
	return 0;
} 
