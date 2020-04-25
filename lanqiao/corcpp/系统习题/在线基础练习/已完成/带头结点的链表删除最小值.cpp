#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node,*lnode;
void minnodedel(lnode s)
{
	lnode pre=s,t=s->next,q=s->next,pri=s->next;
	int min,flag=0;
	min=t->data;
	while(q->next)
	{
		if(t->data>q->next->data){
			min=q->next->data;
			pre=t;
			t=q->next;
			q=q->next;
			flag=1;
		}
		else
		q=q->next;
		
	}
	printf("最小值为：%d\n",min);
	if(flag){
		pre->next=t->next; 
		free(t);
	}
	else
		pri=t->next;
	printf("删除最小值的结点后输出为:\n");
	while(pri){
		printf("%d ",pri->data);
		pri=pri->next;
	}
}
lnode scanf()
{
	lnode p,head;
	int x;
	head=NULL;
	printf("请输入若干整数序列:\n");
	scanf("%d",&x);
	while(x)
	{
		p=(lnode)malloc(sizeof(node));
		p->data=x;
		p->next=head;
		head=p;
		scanf("%d",&x);
	}
	p=(lnode)malloc(sizeof(node));
	p->data=0;
	p->next=head;
	head=p;
	return head;
}
int main()
{
	lnode head;
	head=scanf();
	minnodedel(head);
	return 0;
}

