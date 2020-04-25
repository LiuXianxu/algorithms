#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
//#define N 3
//int N;
typedef struct stu_node
{
	char sn[10];
	char sno[10];
	int score;
	struct stu_node *next;
}student;
typedef student *linklist;
student *head;
student *init()
{
	return NULL;
}
void shuru()
{	
	int i,N;
	linklist p,q;
	q=(linklist)malloc(sizeof(student));
	p=head=NULL;
	printf("请输入学生数:");
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		printf("\n");
		printf("请依次输入学生的姓名,学号,成绩:");
		scanf("%s %s %d",&q->sn,&q->sno,&q->score);
		setbuf(stdin,NULL);
		if(head==NULL)
		{
			head=q;
			p=q;
		}
		else
		{
			p->next=q;
			p=q;
		}
	//	free(q);
		q=(linklist)malloc(sizeof(student));
	}
	free(q);
	p->next=NULL;
}
void paixu()
{
	linklist p,q,r;
	student temp;
	r=head;
	while(r)
	{
		p=r;
		q=r->next;
		while(q)
		{
			if(p->score<q->score)
			{
				strcpy(temp.sn,p->sn);
				strcpy(temp.sno,p->sno);
				temp.score=p->score;

				strcpy(p->sn,q->sn);
				strcpy(p->sno,q->sno);
				p->score=q->score;

				strcpy(q->sn,temp.sn);
				strcpy(q->sno,temp.sno);
				q->score=temp.score;
			}
			q=q->next;
		}
		r=r->next;
	}

}
void display()
{
	student *p,*q;
	p=q=head;
	printf("%s","%s",p->sn,p->sno);
//	p=q->next;
//	q=p;
	while(q->next)
	{
		p=q->next;
		q=p;
	}
	if(q->next==NULL)
		printf("%s","%s",p->sn,p->sno);
}
int main()
{
	head=init();
	shuru();
	paixu();
	display();
	return 0;
}
