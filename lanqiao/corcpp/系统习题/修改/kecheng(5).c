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
			printf("请输入学生的学号: ");
			scanf("%s",&q->sno);
			printf("请输入学生的姓名: ");
			scanf("%s",&q->sname);
			printf("请输入学生的性别: ");
		    scanf("%s",&q->ssex);
			printf("请输入学生的平时成绩: ");
		    scanf("%f",&q->psscore);
			printf("请输入学生的实验成绩: ");
		    scanf("%f",&q->syscore);
			printf("请输入学生的期末成绩: ");
			scanf("%f",&q->qmscore);
			q->zpscore=average(q);
			setbuf(stdin,NULL);
			while(p&&q)
			{	if (strcmp(q->sno,p->sno)==0)
				{
					printf("学号重复,请重新输入!\n");
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
			printf("按0继续输入，否则退出\n");
			flag=getch();
			setbuf(stdin,NULL);
		}
	free(q);
	printf("输入完毕!\n ");
	p->next=NULL;
}
void charu()                               
{
	int j=0,i;
	linklist p,q;
	p=head;
	printf("请输入要插入的位置: ");
	scanf("%d",&i);
	if(i<0) printf("输入位置不规范!\n");
	else 
	{
		while (p&&i!=j)
		{
			p=p->next;j++;
		}
		if(!p&&i!=0)  printf("未找到该结点不能插入!");
		else
		{
			q=(linklist)malloc(sizeof(student));
			printf("请输入学生的学号: ");
			scanf("%s",&q->sno);
			printf("请输入学生的姓名: ");
			scanf("%s",&q->sname);
			printf("请输入学生的性别: ");
			scanf("%s",&q->ssex);
			printf("请输入学生的平时成绩: ");
			scanf("%f",&q->psscore);
			printf("请输入学生的实验成绩: ");
			scanf("%f",&q->syscore);
			printf("请输入学生的期末成绩: ");
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
	printf("请输入要修改的学生学号:");
	scanf("%s",&sno);
	if(!q)  printf("修改失败,没有学生信息!\n");
	else 
		while(q!=NULL)
		{
			if(strcmp(q->sno,sno)==0)
			{
				printf("请输入学生的学号: ");
				scanf("%s",&q->sno);
				printf("请输入学生的姓名: ");
				scanf("%s",&q->sname);
				printf("请输入学生的性别: ");
				scanf("%s",&q->ssex);
				printf("请输入学生的平时成绩: ");
				scanf("%f",&q->psscore);
				printf("请输入学生的实验成绩: ");
				scanf("%f",&q->syscore);
				printf("请输入学生的期末成绩: ");
				scanf("%f",&q->qmscore);
				q->zpscore=average(q);
				setbuf(stdin,NULL);
				m=1;
				printf("修改成功!\n\n");
				break;
			}
			else
				q=q->next;	
		}
		if(m==0) printf("修改失败,没有该学生信息!\n\n");
}

void shanchu()
{
	linklist pre,q;
	char sno[12];
	pre=head;
	q=head;
	printf("请输入要删除的学生学号:");
	scanf("%s",&sno);
	if(!q) printf("没有学生信息,无法删除!\n\n");
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
				printf("删除成功!\n");
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
	printf("请输入需查询的学生学号:");
	scanf("%s",&sno);
	if(!p) printf("没有学生信息,无法查询!\n\n");
	else
	{
		while(p)
		{
			if(strcmp(p->sno,sno)) 
			{
				printf("该学生的所有信息为:\n");
				printf("学号:%s\n",p->sno);
				printf("姓名:%s\n",p->sname);
				printf("性别:%s\n",p->ssex);
				printf("平时成绩:%f\n",p->psscore);
				printf("实验成绩:%f\n",p->syscore);
				printf("期末成绩:%f\n",p->qmscore);
				printf("总评成绩:%f\n",p->zpscore);
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
	if(r==NULL) printf("没有学生成绩,请先添加学生成绩!\n");
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
	printf("****排序完毕,按由大到小的总评成绩!");
	display();
	}
	
}

void display()
{
	student *p;
	p=head;
	if(!p) printf("暂无学生成绩!\n");
	else
	{
		printf("各个学生成绩为:\n");
		while(p)
		{
			printf("学号:%s,姓名:%s,性别:%s,平时成绩:%f,实验成绩:%f,期末成绩:%f,总评成绩:%f\n",p->sno,p->sname,p->ssex,p->psscore,p->syscore,p->qmscore,p->zpscore);
			p=p->next;
		}
	}
}
void menu()
{
	int choose;
//	system("cls");
	printf("**************学生信息管理系统*****************\n");
	printf("*                                             *\n");
	printf("*----------- 1.登记学生成绩 ------------------*\n");
	printf("*----------- 2.插入学生成绩 ------------------*\n");
	printf("*----------- 3.修改学生成绩 ------------------*\n");
	printf("*----------- 4.删除学生成绩 ------------------*\n");
	printf("*----------- 5.查询学生成绩 ------------------*\n");
	printf("*----------- 6.对学生成绩进行排序 ------------*\n");
	printf("*----------- 7.输出学生成绩 ------------------*\n");
	printf("*----------- 8.退出系统 ----------------------*\n");
	printf("***********************************************\n");
	printf("\n");
	printf("请输入你的选择:");
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
	default:printf("请输入正确数字!\n");
	}
	menu();
}

int main()
{
	head=init();
	menu();
	return 0;
}
