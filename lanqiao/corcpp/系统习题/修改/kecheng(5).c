#include<stdio.h >
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<conio.h>
#define N 100
typedef struct stulink_node
{
	char sno[12];
	char sname[20];
	char ssex[5];
	float psscore;
	float syscore;
	float qmscore;
	float zpscore;
	struct stulink_node *next;
}student;
typedef student *linklist;

student *head;

void display();

student *init()
{
	return NULL;
}

float average(student *stu)
{
	return (float)(0.4*stu->psscore+0.3*stu->syscore+0.3*stu->qmscore);
}
void dengji()
{	
	linklist p,q;
	char flag='0';
	q=(linklist)malloc(sizeof(student));
	p=head=NULL;
	while(flag=='0')
		{
			printf("\n");
			printf("������ѧ����ѧ��: ");
			scanf("%s",&q->sno);
			printf("������ѧ��������: ");
			scanf("%s",&q->sname);
			printf("������ѧ�����Ա�: ");
		    scanf("%s",&q->ssex);
			printf("������ѧ����ƽʱ�ɼ�: ");
		    scanf("%f",&q->psscore);
			printf("������ѧ����ʵ��ɼ�: ");
		    scanf("%f",&q->syscore);
			printf("������ѧ������ĩ�ɼ�: ");
			scanf("%f",&q->qmscore);
			q->zpscore=average(q);
			setbuf(stdin,NULL);
			while(p&&q)
			{	if (strcmp(q->sno,p->sno)==0)
				{
					printf("ѧ���ظ�,����������!\n");
					//free(q);
					q=NULL;
					break;
				}
				else p=p->next;
			}
			if(head==NULL) 
			{
				head=q;
				p=head;
			}
			else 
			{
				if(q==NULL)  q=p;
				else{
					p->next=q;
					p=q;
					}
			
			}
				free(q);
			q=(linklist)malloc(sizeof(student));
			printf("��0�������룬�����˳�\n");
			flag=getch();
			setbuf(stdin,NULL);
		}
	free(q);
	printf("�������!\n ");
	p->next=NULL;
}
void charu()                               
{
	int j=0,i;
	linklist p,q;
	p=head;
	printf("������Ҫ�����λ��: ");
	scanf("%d",&i);
	if(i<0) printf("����λ�ò��淶!\n");
	else 
	{
		while (p&&i!=j)
		{
			p=p->next;j++;
		}
		if(!p&&i!=0)  printf("δ�ҵ��ý�㲻�ܲ���!");
		else
		{
			q=(linklist)malloc(sizeof(student));
			printf("������ѧ����ѧ��: ");
			scanf("%s",&q->sno);
			printf("������ѧ��������: ");
			scanf("%s",&q->sname);
			printf("������ѧ�����Ա�: ");
			scanf("%s",&q->ssex);
			printf("������ѧ����ƽʱ�ɼ�: ");
			scanf("%f",&q->psscore);
			printf("������ѧ����ʵ��ɼ�: ");
			scanf("%f",&q->syscore);
			printf("������ѧ������ĩ�ɼ�: ");
			scanf("%f",&q->qmscore);
			q->zpscore=average(q);
			if(i==0)
			{
				q->next=head;
				head=q;
			}
			else 
			{
				q->next=p->next;
				p->next=q;
			}
		}
	}

}
void xiugai()
{
	linklist q;
	int m=0;
	char sno[12];
	q=head;
	printf("������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%s",&sno);
	if(!q)  printf("�޸�ʧ��,û��ѧ����Ϣ!\n");
	else 
		while(q!=NULL)
		{
			if(strcmp(q->sno,sno)==0)
			{
				printf("������ѧ����ѧ��: ");
				scanf("%s",&q->sno);
				printf("������ѧ��������: ");
				scanf("%s",&q->sname);
				printf("������ѧ�����Ա�: ");
				scanf("%s",&q->ssex);
				printf("������ѧ����ƽʱ�ɼ�: ");
				scanf("%f",&q->psscore);
				printf("������ѧ����ʵ��ɼ�: ");
				scanf("%f",&q->syscore);
				printf("������ѧ������ĩ�ɼ�: ");
				scanf("%f",&q->qmscore);
				q->zpscore=average(q);
				setbuf(stdin,NULL);
				m=1;
				printf("�޸ĳɹ�!\n\n");
				break;
			}
			else
				q=q->next;	
		}
		if(m==0) printf("�޸�ʧ��,û�и�ѧ����Ϣ!\n\n");
}

void shanchu()
{
	linklist pre,q;
	char sno[12];
	pre=head;
	q=head;
	printf("������Ҫɾ����ѧ��ѧ��:");
	scanf("%s",&sno);
	if(!q) printf("û��ѧ����Ϣ,�޷�ɾ��!\n\n");
	else
	{
		while(q)
		{
			if(strcmp(q->sno,sno)==0) 
			{
				//if (q==NULL) head=NULL;
				if(q==head)
				{
				head=q->next;
				free(q);
				}
				else 
				{
				pre->next=q->next;
				free(q);
				}
				printf("ɾ���ɹ�!\n");
				break;
			}
			else
			{
				pre=q;
				q=q->next;
			}
		}
	}	
}

void chaxun()
{
	linklist p;
	char sno[12];
	p=head;
	printf("���������ѯ��ѧ��ѧ��:");
	scanf("%s",&sno);
	if(!p) printf("û��ѧ����Ϣ,�޷���ѯ!\n\n");
	else
	{
		while(p)
		{
			if(strcmp(p->sno,sno)) 
			{
				printf("��ѧ����������ϢΪ:\n");
				printf("ѧ��:%s\n",p->sno);
				printf("����:%s\n",p->sname);
				printf("�Ա�:%s\n",p->ssex);
				printf("ƽʱ�ɼ�:%f\n",p->psscore);
				printf("ʵ��ɼ�:%f\n",p->syscore);
				printf("��ĩ�ɼ�:%f\n",p->qmscore);
				printf("�����ɼ�:%f\n",p->zpscore);
				break;
			}
			else
				p=p->next;
		}
	}
	
}
void paixu()
{
	linklist p,q,r;
	student temp;
	r=head;
	if(r==NULL) printf("û��ѧ���ɼ�,�������ѧ���ɼ�!\n");
	else
	{
	while(r)
	{
		p=r;
		q=r->next;
		while(q)
		{
			if(p->zpscore < q->zpscore)
			{
				strcpy(temp.sno,p->sno);
				strcpy(temp.sname,p->sname);
				strcpy(temp.ssex,p->ssex);
				temp.psscore=p->psscore;
				temp.syscore=p->syscore;
				temp.qmscore=p->qmscore;
				temp.zpscore=p->zpscore;

  				strcpy(p->sno,q->sno);
				strcpy(p->sname,q->sname);
				strcpy(p->ssex,q->ssex);
				p->psscore=q->psscore;
				p->syscore=q->syscore;
				p->qmscore=q->qmscore;
				p->zpscore=q->zpscore;

				strcpy(q->sno,temp.sno);
				strcpy(q->sname,temp.sname);
				strcpy(q->ssex,temp.ssex);
				q->psscore=temp.psscore;
				q->syscore=temp.syscore;
				q->qmscore=temp.qmscore;
				q->zpscore=temp.zpscore;
			}
			q=q->next;
		}
		r=r->next;
	}
	printf("****�������,���ɴ�С�������ɼ�!");
	display();
	}
	
}

void display()
{
	student *p;
	p=head;
	if(!p) printf("����ѧ���ɼ�!\n");
	else
	{
		printf("����ѧ���ɼ�Ϊ:\n");
		while(p)
		{
			printf("ѧ��:%s,����:%s,�Ա�:%s,ƽʱ�ɼ�:%f,ʵ��ɼ�:%f,��ĩ�ɼ�:%f,�����ɼ�:%f\n",p->sno,p->sname,p->ssex,p->psscore,p->syscore,p->qmscore,p->zpscore);
			p=p->next;
		}
	}
}
void menu()
{
	int choose;
//	system("cls");
	printf("**************ѧ����Ϣ����ϵͳ*****************\n");
	printf("*                                             *\n");
	printf("*----------- 1.�Ǽ�ѧ���ɼ� ------------------*\n");
	printf("*----------- 2.����ѧ���ɼ� ------------------*\n");
	printf("*----------- 3.�޸�ѧ���ɼ� ------------------*\n");
	printf("*----------- 4.ɾ��ѧ���ɼ� ------------------*\n");
	printf("*----------- 5.��ѯѧ���ɼ� ------------------*\n");
	printf("*----------- 6.��ѧ���ɼ��������� ------------*\n");
	printf("*----------- 7.���ѧ���ɼ� ------------------*\n");
	printf("*----------- 8.�˳�ϵͳ ----------------------*\n");
	printf("***********************************************\n");
	printf("\n");
	printf("���������ѡ��:");
	scanf("%d",&choose);
	switch(choose)
	{
	case 1:dengji();break;
	case 2:charu();break;
	case 3:xiugai();break;
	case 4:shanchu();break;
	case 5:chaxun();break;
	case 6:paixu();break;
	case 7:display();break;
	case 8:exit(0);break;
	default:printf("��������ȷ����!\n");
	}
	menu();
}

int main()
{
	head=init();
	menu();
	return 0;
}
